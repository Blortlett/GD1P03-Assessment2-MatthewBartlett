#pragma once
#include <Windows.h>
#include <ShObjIdl.h>
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "cLevelPlatformsList.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

class cFileInterface
{
public:
	cFileInterface(cLevelPlatformsList& platformList);
	~cFileInterface();
	void SaveLevelDialog();
	void LoadLevelDialog();
	void LoadLevelByName(const std::string& levelName);

private:
	cLevelPlatformsList& mLevelPlatformList;
};