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

	ExplosionSound->setVolume(40.f);
	JumpSound->setVolume(35.f);
	LandFallSound->setVolume(65.f);
	PickupKeySound->setVolume(30.f);
	

	// Music
	MenuMusic.openFromFile("Assets/Audio/Music/DavidKBD - InterstellarPack - 01 - Interstellar.ogg");
	MusicLevel1.openFromFile("Assets/Audio/Music/DavidKBD - InterstellarPack - 02 - Plasma Storm.ogg");
	MusicLevel2.openFromFile("Assets/Audio/Music/DavidKBD - InterstellarPack - 03 - Temple of Madness.ogg");
	MusicLevel3.openFromFile("Assets/Audio/Music/DavidKBD - InterstellarPack - 04 - Horsehead Nebula.ogg");
	MusicLevel4.openFromFile("Assets/Audio/Music/DavidKBD - InterstellarPack - 05 - Forgotten Station.ogg");
	MusicLevel5.openFromFile("Assets/Audio/Music/DavidKBD - InterstellarPack - 06 - Hope on the Horizon.ogg");
	MusicLevel6.openFromFile("Assets/Audio/Music/DavidKBD - InterstellarPack - 07 - Electric Firework.ogg");
	MusicLevel7.openFromFile("Assets/Audio/Music/DavidKBD - InterstellarPack - 08 - Synth Kobra.ogg");
	MusicLevel8.openFromFile("Assets/Audio/Music/DavidKBD - InterstellarPack - 09 - Spiral of Plasma.ogg");
	MusicEditor.openFromFile("Assets/Audio/Music/Gymnopedie No.1.ogg");

	MenuMusic.setLooping(true);
	MusicLevel1.setLooping(true);
	MusicLevel2.setLooping(true);
	MusicLevel3.setLooping(true);
	MusicLevel4.setLooping(true);
	MusicLevel5.setLooping(true);
	MusicLevel6.setLooping(true);
	MusicLevel7.setLooping(true);
	MusicLevel8.setLooping(true);
	MusicLevel9.setLooping(true);
	MusicEditor.setLooping(true);

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
	CurrentMusic->setVolume(MusicVolume);
	CurrentMusic->play();
}

void cAudioPlayer::PlayEditorMusic()
{
	if (IsMusicMuted) return; // Dont bother if music is muted
	StopMusic();
	CurrentMusic = &MusicEditor;
	CurrentMusic->setVolume(MusicVolume * 16);
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
		case 6: CurrentMusic = &MusicLevel6; break;
		case 7: CurrentMusic = &MusicLevel7; break;
		case 8: CurrentMusic = &MusicLevel8; break;
		case 9: CurrentMusic = &MusicEditor; break;
	}
	if (LevelCount == 9)
		CurrentMusic->setVolume(MusicVolume * 16);
	else
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