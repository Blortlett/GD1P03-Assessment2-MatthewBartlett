/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cAudioPlayer]
Description : [This singleton class loads and plays all music and sound effects for easy use]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include <iostream>
#include <SFML/Audio.hpp>

class cAudioPlayer
{
private:
	// Private constructor for singleton access
	cAudioPlayer();
	~cAudioPlayer();

	// Music tracks
	sf::Music* CurrentMusic; // Music state
	sf::Music MenuMusic;
	sf::Music MusicLevel1;
	sf::Music MusicLevel2;
	sf::Music MusicLevel3;
	sf::Music MusicLevel4;
	sf::Music MusicLevel5;
	sf::Music MusicLevel6;
	sf::Music MusicLevel7;
	sf::Music MusicLevel8;
	sf::Music MusicLevel9;
	sf::Music MusicEditor;

	// Sound Effects
	//Buffers
	sf::SoundBuffer JumpBuffer;
	sf::SoundBuffer PickupKeyBuffer;
	sf::SoundBuffer ExplosionBuffer;
	sf::SoundBuffer LandFallBuffer;
	// Sounds
	sf::Sound* JumpSound;
	sf::Sound* PickupKeySound;
	sf::Sound* ExplosionSound;
	sf::Sound* LandFallSound;

	// Volumes / mutes
	float MusicVolume = 30.f;
	float SFXVolume = 90.f;
	bool IsMusicMuted = false;
	bool IsSFXMuted = false;
	
	//Level Count
	int LevelCount = 1;

public:
	// Get the single instance of the class
	static cAudioPlayer& GetInstance()
	{
		static cAudioPlayer instance; // Static instance created on first call
		return instance;
	}

	//   -= SFX FUNCTIONS =-
	// Play Sound Effects functions
	void SFXPlayExplosion();
	void SFXPlayJump();
	void SFXPlayLandFall();
	void SFXPlayPickupKey();

	//   -= MUSIC FUNCTIONS =-
	// Swap Tunes
	void PlayMenuMusic();
	void PlayEditorMusic();
	void PlayFirstLevelMusic();
	void PlayLevelMusic();
	// Pause/Play music
	void StopMusic();
	void ResumeMusic();
	// Mute sounds
	void MuteMusic(bool mute);
	void MuteSFX(bool mute);
};