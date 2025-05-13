#pragma once
#include <Windows.h>
#include <ShObjIdl.h>
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <filesystem>
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

	// Helper methods for file dialogs
	bool ShowFileSaveDialog(std::wstring& outFilePath, const wchar_t* fileTypeDesc, const wchar_t* fileTypeExt);
	bool ShowFileOpenDialog(std::wstring& outFilePath, const wchar_t* fileTypeDesc, const wchar_t* fileTypeExt);

	// Core file operations
	void SaveLevelToFile(const std::wstring& filePath);
	void LoadLevelFromFile(const std::wstring& filePath);

	// JSON saving helpers
	void SavePlatformsToJson(rapidjson::Document& doc, rapidjson::Document::AllocatorType& allocator);
	void SavePlayerSpawnToJson(rapidjson::Document& doc, rapidjson::Document::AllocatorType& allocator);
	void SaveLevelExitToJson(rapidjson::Document& doc, rapidjson::Document::AllocatorType& allocator);
	void SaveLevelKeyToJson(rapidjson::Document& doc, rapidjson::Document::AllocatorType& allocator);
	void SaveMinesToJson(rapidjson::Document& doc, rapidjson::Document::AllocatorType& allocator);
	void SaveBouncySquaresToJson(rapidjson::Document& doc, rapidjson::Document::AllocatorType& allocator);

	// JSON loading helpers
	void LoadPlatformsFromJson(const rapidjson::Document& doc);
	void LoadPlayerSpawnFromJson(const rapidjson::Document& doc);
	void LoadLevelExitFromJson(const rapidjson::Document& doc);
	void LoadLevelKeyFromJson(const rapidjson::Document& doc);
	void LoadMinesFromJson(const rapidjson::Document& doc);
	void LoadBouncySquaresFromJson(const rapidjson::Document& doc);
};