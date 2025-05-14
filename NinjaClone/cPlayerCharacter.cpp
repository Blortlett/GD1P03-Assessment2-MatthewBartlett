#include "cPlayerCharacter.h"

const sf::Vector2f cPlayerCharacter::PLAYER_SIZE = sf::Vector2f(24, 32);
const sf::Vector2f cPlayerCharacter::PLAYER_COLLIDER_OFFSET = sf::Vector2f(0, -16);
const sf::FloatRect cPlayerCharacter::PLAYER_BOUNDS = sf::FloatRect(sf::Vector2f(1366, 768) / 2.f, PLAYER_SIZE); /// FloatRectPosition controls player spawn... JANK!
const sf::Vector2f cPlayerCharacter::PLAYER_MAX_VELOCITY = sf::Vector2f(350, 700);

cPlayerCharacter::cPlayerCharacter(sf::Vector2f _position, cPlayerInput& playerInput)
    : cCharacter(eCharacterType::TYPE_PLAYER, _position, PLAYER_BOUNDS, PLAYER_COLLIDER_OFFSET, PLAYER_MAX_VELOCITY)
    , mPlayerInput(playerInput)
    , m_vPlayerInputNormalized(sf::Vector2f(0, 0))
{
    mVelocity = sf::Vector2f(0.0f, 0.0f);
    mMaxVelocity = sf::Vector2f(300, 600);
    mWallslideJumpImpulse = sf::Vector2f(150, 60);
    mDebugColliderShape.setPosition(mPosition);
    mDebugColliderShape.setOutlineColor(sf::Color::Red);
    mDebugColliderShape.setOutlineThickness(2);
    mDebugColliderShape.setFillColor(sf::Color::Transparent);
}

cPlayerCharacter::~cPlayerCharacter()
{
}

void cPlayerCharacter::Update(float DeltaSeconds)
{
    HandleInput();

    // No Input
    if (mIsGrounded && m_vPlayerInputNormalized.x == 0) 
    {
        mPlayerAnimator.SetSliding(true);
        // Velocity deadzone
        if (std::abs(mVelocity.x) < mVelocityDeadzone) {
            // Zero player velocity here
            mVelocity.x = 0.0f;
            mPlayerAnimator.SetSliding(false);
            mPlayerAnimator.SetRunning(false);
        }
        else {
            // slow player horizontal speed
            if (mIsGrounded)
            {
                mVelocity.x *= 1 - mVelocityDampGrounded * DeltaSeconds;

            }
            else
            {
                mVelocity.x *= 1 - mVelocityDampAirborne * DeltaSeconds;
            }
        }
    }
    else
    {   // Input detected, add horizontal speed to player
        mPlayerAnimator.SetSliding(false);
        if (mIsGrounded)
        {
            if (normalize(mVelocity.x) != m_vPlayerInputNormalized.x)
            {
                mPlayerAnimator.SetSliding(true); // if input opptosite to velocity, then set sliding
                mVelocity += mSlowMoveInputGrounded * m_vPlayerInputNormalized * DeltaSeconds;
            }
            else
            {
                mPlayerAnimator.SetRunning(true); // else set running animation
                mVelocity += mMoveInputMultGrounded * m_vPlayerInputNormalized * DeltaSeconds;
            }
        }
        else
        {
            mVelocity += mMoveInputMultAirborne * m_vPlayerInputNormalized * DeltaSeconds;
        }
    }

    CharacterPhysicsUpdate(DeltaSeconds);

    // Tell animator jump peak has been reached
    if (mIsGrounded == false && mVelocity.y < -1 && mVelocity.y > -20)
    {
        mPlayerAnimator.JumpPeak();
    }

    // Face Left/Right
    if (mVelocity.x > 1) {
        mPlayerAnimator.FaceRight();
        mIsFacingRight = true;
    }
    else if (mVelocity.x < -1) {
        mPlayerAnimator.FaceLeft();
        mIsFacingRight = false;
    }

    // Update Animation
    mPlayerAnimator.Animate(mPosition, DeltaSeconds);
}

void cPlayerCharacter::Draw(sf::RenderWindow& renderWindow)
{
    //DrawDebug(renderWindow);
    mPlayerAnimator.Draw(renderWindow);
    cCharacter::DrawDebug(renderWindow);
}

void cPlayerCharacter::Jump()
{
    mIsGrounded = false;
    //mVelocity.y -= mJumpImpulse;
    mVelocity.y -= sqrtf(2.0f * mGravity * mJumpImpulse); // someone said this was good? wrong use case here...
    cAudioPlayer::GetInstance().SFXPlayJump();
}

void cPlayerCharacter::JumpWallsliding()
{
    cAudioPlayer::GetInstance().SFXPlayJump();
    mIsTouchingWall = false;
    mIsWallsliding = false;
    if (mVelocity.y < 0)
    {
        // Player moving up, add jump to up force
        mVelocity.y += -sqrtf(2.0f * mGravity * mWallslideJumpImpulse.y);
    }
    else // Player moving down, set jump force
        mVelocity.y = -sqrtf(2.0f * mGravity * mWallslideJumpImpulse.y);
    if (mIsFacingRight) {
        mVelocity.x = -mWallslideJumpImpulse.x;
    }
    else {
        mVelocity.x = mWallslideJumpImpulse.x;
    }
}

void cPlayerCharacter::HandleInput()
{
    if (cApplicationManager::GetInstance().IsLevelComplete()) return;

    // Arrow Keys
    if (mPlayerInput.IsMoveRightInputPressed()) {
        m_vPlayerInputNormalized.x = 1;
    }
    else if (mPlayerInput.IsMoveLeftInputPressed()) {
        m_vPlayerInputNormalized.x = -1;
    }
    else {
        m_vPlayerInputNormalized.x = 0;
    }
    // Space
    if (mPlayerInput.IsJumpInputPressed() && mIsGrounded)
    {
        mJumpKeyHeld = true;
        mPlayerAnimator.BeginJump();
        Jump();
    }
    else if (mPlayerInput.IsJumpInputPressed() && mIsTouchingWall && !mJumpKeyHeld)
    {
        mJumpKeyHeld = true;
        mPlayerAnimator.BeginJump();
        JumpWallsliding();
    }
    else if (!mPlayerInput.IsJumpInputPressed() && mJumpKeyHeld && mVelocity.y < 0)
    {
        mVelocity.y = mVelocity.y * .7f;
        mJumpKeyHeld = false;
    }
}

void cPlayerCharacter::KillInput()
{
    m_vPlayerInputNormalized = sf::Vector2f(0.f,0.f);
}

void cPlayerCharacter::SetUngrounded()
{
    if (mVelocity.y > 0)
    {
        mIsGrounded = false;
        mIsTouchingWall = false;
        mIsWallsliding = false;
        mPlayerAnimator.StartFall();
    }
}


