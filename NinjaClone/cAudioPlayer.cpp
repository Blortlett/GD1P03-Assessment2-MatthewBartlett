#include "cAudioPlayer.h"

cAudioPlayer::cAudioPlayer()
	: CurrentMusic(nullptr)
	, ExplosionSound(nullptr)
	, JumpSound(nullptr)
	, LandFallSound(nullptr)
	, PickupKeySound(nullptr)
{
	// Buffers
	ExplosionBuffer.loadFromFile("Assets/Audio/SFX/explosion.wav");
	JumpBuffer.loadFromFile("Assets/Audio/SFX/jump.wav");
	LandFallBuffer.loadFromFile("Assets/Audio/SFX/land.wav");
	PickupKeyBuffer.loadFromFile("Assets/Audio/SFX/pickupKey.wav");
	// Sounds
	ExplosionSound = new sf::Sound(ExplosionBuffer);
	JumpSound = new sf::Sound(JumpBuffer);
	LandFallSound = new sf::Sound(LandFallBuffer);
	PickupKeySound = new sf::Sound(PickupKeyBuffer);


	// Music
	MenuMusic.openFromFile("Assets/Audio/Music/DavidKBD - InterstellarPack - 01 - Interstellar.ogg");
	MusicLevel1.openFromFile("Assets/Audio/Music/DavidKBD - InterstellarPack - 02 - Plasma Storm.ogg");
	MusicLevel2.openFromFile("Assets/Audio/Music/DavidKBD - InterstellarPack - 03 - Temple of Madness.ogg");
	MusicLevel3.openFromFile("Assets/Audio/Music/DavidKBD - InterstellarPack - 04 - Horsehead Nebula.ogg");
	MusicLevel4.openFromFile("Assets/Audio/Music/DavidKBD - InterstellarPack - 05 - Forgotten Station.ogg");
	MusicLevel5.openFromFile("Assets/Audio/Music/DavidKBD - InterstellarPack - 06 - Hope on the Horizon.ogg");
	PlayMenuMusic();
}

cAudioPlayer::~cAudioPlayer()
{
	delete ExplosionSound;
	delete JumpSound;
	delete LandFallSound;
	delete PickupKeySound;
}

void cAudioPlayer::SFXPlayExplosion()
{
	ExplosionSound->play();
}

void cAudioPlayer::SFXPlayJump()
{
	JumpSound->play();
}

void cAudioPlayer::SFXPlayLandFall()
{
	LandFallSound->play();
}

void cAudioPlayer::SFXPlayPickupKey()
{
	PickupKeySound->play();
}

void cAudioPlayer::PlayMenuMusic()
{
	if (IsMusicMuted) return; // Dont bother if music is muted
	StopMusic();
	CurrentMusic = &MenuMusic;
	CurrentMusic->play();
}

void cAudioPlayer::PlayFirstLevelMusic()
{
	StopMusic();
	LevelCount = 1;
	CurrentMusic = &MusicLevel1;
	CurrentMusic->setVolume(MusicVolume);
	CurrentMusic->play();
}

void cAudioPlayer::PlayLevelMusic()
{
	StopMusic();
	LevelCount++;
	switch (LevelCount) {
		case 1: CurrentMusic = &MusicLevel1; break;
		case 2: CurrentMusic = &MusicLevel2; break;
		case 3: CurrentMusic = &MusicLevel3; break;
		case 4: CurrentMusic = &MusicLevel4; break;
		case 5: CurrentMusic = &MusicLevel5; break;
	}
	CurrentMusic->setVolume(MusicVolume);
	CurrentMusic->play();
}

void cAudioPlayer::StopMusic()
{
	if (CurrentMusic) {
		CurrentMusic->stop();
	}
}

void cAudioPlayer::ResumeMusic()
{
	if (CurrentMusic) {
		CurrentMusic->play();
	}
}

void cAudioPlayer::MuteMusic(bool mute)
{
	IsMusicMuted = mute;
	if (CurrentMusic) {
		if (IsMusicMuted)
		{ // Stop music - its muted
			StopMusic();
		}
		else
		{ // Music unmuted - play those tunes
			ResumeMusic();
		}
	}
}

void cAudioPlayer::MuteSFX(bool mute)
{
	IsSFXMuted = mute;
}