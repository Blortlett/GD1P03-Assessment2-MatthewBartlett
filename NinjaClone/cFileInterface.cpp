#include "cFileInterface.h"

cFileInterface::cFileInterface(cLevelPlatformsList& platformList)
    : mLevelPlatformList(platformList)
{

}

cFileInterface::~cFileInterface()
{

}

void cFileInterface::SaveLevelDialog() {
    std::wstring filePath;
    if (!ShowFileSaveDialog(filePath, L"JSON files", L"*.json")) {
        return;
    }

    SaveLevelToFile(filePath);
}

void cFileInterface::LoadLevelDialog() {
    std::wstring filePath;
    if (!ShowFileOpenDialog(filePath, L"JSON files", L"*.json")) {
        return;
    }

    LoadLevelFromFile(filePath);
}

void cFileInterface::LoadLevelByName(const std::string& levelName) {
    // Construct file path (e.g., "Levels/levelName.json")
    std::filesystem::path filePath = "Assets/Levels/" + levelName + ".json";
    LoadLevelFromFile(filePath.wstring());
}

bool cFileInterface::ShowFileSaveDialog(std::wstring& outFilePath, const wchar_t* fileTypeDesc, const wchar_t* fileTypeExt) {
    // Initialize COM
    HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
    if (FAILED(hr)) {
        std::cerr << "Failed to initialize COM" << std::endl;
        return false;
    }

    bool result = false;
    // Create Save File Dialog
    IFileSaveDialog* pFileSave = nullptr;
    hr = CoCreateInstance(CLSID_FileSaveDialog, NULL, CLSCTX_ALL,
        IID_IFileSaveDialog, (void**)&pFileSave);

    if (SUCCEEDED(hr)) {
        // Set file types
        COMDLG_FILTERSPEC fileTypes[] = {
            { fileTypeDesc, fileTypeExt },
            { L"All files", L"*.*" }
        };
        pFileSave->SetFileTypes(2, fileTypes);
        pFileSave->SetDefaultExtension(L"json");

        // Show dialog
        hr = pFileSave->Show(NULL);
        if (SUCCEEDED(hr)) {
            IShellItem* pItem;
            hr = pFileSave->GetResult(&pItem);
            if (SUCCEEDED(hr)) {
                PWSTR pszFilePath;
                hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
                if (SUCCEEDED(hr)) {
                    outFilePath = pszFilePath;
                    result = true;
                    CoTaskMemFree(pszFilePath);
                }
                pItem->Release();
            }
        }
        pFileSave->Release();
    }

    CoUninitialize();
    return result;
}

bool cFileInterface::ShowFileOpenDialog(std::wstring& outFilePath, const wchar_t* fileTypeDesc, const wchar_t* fileTypeExt) {
    // Initialize COM
    HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
    if (FAILED(hr)) {
        std::cerr << "Failed to initialize COM" << std::endl;
        return false;
    }

    bool result = false;
    // Create Open File Dialog
    IFileOpenDialog* pFileOpen = nullptr;
    hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL,
        IID_IFileOpenDialog, (void**)&pFileOpen);

    if (SUCCEEDED(hr)) {
        // Set file types
        COMDLG_FILTERSPEC fileTypes[] = {
            { fileTypeDesc, fileTypeExt },
            { L"All files", L"*.*" }
        };
        pFileOpen->SetFileTypes(2, fileTypes);
        pFileOpen->SetDefaultExtension(L"json");

        // Show dialog
        hr = pFileOpen->Show(NULL);
        if (SUCCEEDED(hr)) {
            IShellItem* pItem;
            hr = pFileOpen->GetResult(&pItem);
            if (SUCCEEDED(hr)) {
                PWSTR pszFilePath;
                hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
                if (SUCCEEDED(hr)) {
                    outFilePath = pszFilePath;
                    result = true;
                    CoTaskMemFree(pszFilePath);
                }
                pItem->Release();
            }
        }
        pFileOpen->Release();
    }

    CoUninitialize();
    return result;
}

void cFileInterface::SaveLevelToFile(const std::wstring& filePath) {
    // Create JSON document
    rapidjson::Document doc;
    doc.SetObject();
    rapidjson::Document::AllocatorType& allocator = doc.GetAllocator();

    // Save all platforms
    SavePlatformsToJson(doc, allocator);

    // Save player spawn
    SavePlayerSpawnToJson(doc, allocator);

    // Save level exit
    SaveLevelExitToJson(doc, allocator);

    // Save level key
    SaveLevelKeyToJson(doc, allocator);

    // Save mines
    SaveMinesToJson(doc, allocator);

    // Save bouncy squares
    SaveBouncySquaresToJson(doc, allocator);

    // Write to JSON string
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    doc.Accept(writer);

    // Write to file
    std::ofstream outFile(filePath);
    if (outFile.is_open()) {
        outFile << buffer.GetString();
        outFile.close();
        std::cout << "Level saved successfully to " << std::string(filePath.begin(), filePath.end()) << std::endl;
    }
    else {
        std::cerr << "Failed to open file for writing: " << std::string(filePath.begin(), filePath.end()) << std::endl;
    }
}

void cFileInterface::LoadLevelFromFile(const std::wstring& filePath) {
    // Read JSON file
    std::ifstream inFile(filePath);
    if (!inFile.is_open()) {
        std::cerr << "Failed to open file: " << std::string(filePath.begin(), filePath.end()) << std::endl;
        return;
    }

    // Read file content into string
    std::string jsonContent((std::istreambuf_iterator<char>(inFile)),
        std::istreambuf_iterator<char>());
    inFile.close();

    // Parse JSON
    rapidjson::Document doc;
    if (doc.Parse(jsonContent.c_str()).HasParseError() || !doc.IsObject()) {
        std::cerr << "Failed to parse JSON file: " << std::string(filePath.begin(), filePath.end()) << std::endl;
        return;
    }

    // Clear existing objects
    mLevelPlatformList.ClearList();

    // Load all platforms
    LoadPlatformsFromJson(doc);

    // Load player spawn
    LoadPlayerSpawnFromJson(doc);

    // Load level exit
    LoadLevelExitFromJson(doc);

    // Load level key
    LoadLevelKeyFromJson(doc);

    // Load mines
    LoadMinesFromJson(doc);

    // Load bouncy squares
    LoadBouncySquaresFromJson(doc);

    std::cout << "Level loaded successfully from " << std::string(filePath.begin(), filePath.end()) << std::endl;
}

void cFileInterface::SavePlatformsToJson(rapidjson::Document& doc, rapidjson::Document::AllocatorType& allocator) {
    // Create platforms array
    rapidjson::Value platformsArray(rapidjson::kArrayType);

    // Add each platform to json list
    for (auto* platform : mLevelPlatformList.mPlatformList) {
        rapidjson::Value platformObj(rapidjson::kObjectType);
        sf::FloatRect bounds = platform->GetColliderCopy().GetBounds();

        platformObj.AddMember("x", bounds.position.x, allocator);
        platformObj.AddMember("y", bounds.position.y, allocator);
        platformObj.AddMember("width", bounds.size.x, allocator);
        platformObj.AddMember("height", bounds.size.y, allocator);

        platformsArray.PushBack(platformObj, allocator);
    }

    doc.AddMember("platforms", platformsArray, allocator);
}

void cFileInterface::SavePlayerSpawnToJson(rapidjson::Document& doc, rapidjson::Document::AllocatorType& allocator) {
    if (mLevelPlatformList.mPlayerSpawn) {
        rapidjson::Value spawnObj(rapidjson::kObjectType);
        sf::Vector2f position = mLevelPlatformList.mPlayerSpawn->GetSpawnPoint();

        spawnObj.AddMember("x", position.x, allocator);
        spawnObj.AddMember("y", position.y, allocator);

        doc.AddMember("playerSpawn", spawnObj, allocator);
    }
}

void cFileInterface::SaveLevelExitToJson(rapidjson::Document& doc, rapidjson::Document::AllocatorType& allocator) {
    if (mLevelPlatformList.mLevelExit) {
        rapidjson::Value exitObj(rapidjson::kObjectType);
        sf::Vector2f position = mLevelPlatformList.mLevelExit->GetPosition();

        exitObj.AddMember("x", position.x, allocator);
        exitObj.AddMember("y", position.y, allocator);

        doc.AddMember("levelExit", exitObj, allocator);
    }
}

void cFileInterface::SaveLevelKeyToJson(rapidjson::Document& doc, rapidjson::Document::AllocatorType& allocator) {
    if (mLevelPlatformList.mLevelKey) {
        rapidjson::Value keyObj(rapidjson::kObjectType);
        sf::Vector2f position = mLevelPlatformList.mLevelKey->GetPosition();

        keyObj.AddMember("x", position.x, allocator);
        keyObj.AddMember("y", position.y, allocator);

        doc.AddMember("levelKey", keyObj, allocator);
    }
}

void cFileInterface::SaveMinesToJson(rapidjson::Document& doc, rapidjson::Document::AllocatorType& allocator) {
    // Create mines array
    rapidjson::Value minesArray(rapidjson::kArrayType);

    // Add each mine to json list
    for (auto* mine : mLevelPlatformList.mMineList) {
        rapidjson::Value mineObj(rapidjson::kObjectType);
        sf::Vector2f position = mine->GetPosition();

        mineObj.AddMember("x", position.x, allocator);
        mineObj.AddMember("y", position.y, allocator);

        minesArray.PushBack(mineObj, allocator);
    }

    doc.AddMember("mines", minesArray, allocator);
}

void cFileInterface::SaveBouncySquaresToJson(rapidjson::Document& doc, rapidjson::Document::AllocatorType& allocator) {
    // Create bouncy squares array
    rapidjson::Value bouncySquaresArray(rapidjson::kArrayType);

    // Add each bouncy square to json list
    for (auto* square : mLevelPlatformList.mBouncySquareList) {
        rapidjson::Value squareObj(rapidjson::kObjectType);
        sf::Vector2f position = square->GetPosition();

        squareObj.AddMember("x", position.x, allocator);
        squareObj.AddMember("y", position.y, allocator);

        bouncySquaresArray.PushBack(squareObj, allocator);
    }

    doc.AddMember("bouncySquares", bouncySquaresArray, allocator);
}

void cFileInterface::LoadPlatformsFromJson(const rapidjson::Document& doc) {
    // Check for platforms array
    if (!doc.HasMember("platforms") || !doc["platforms"].IsArray()) {
        std::cerr << "No valid platforms array in JSON" << std::endl;
        return;
    }

    const rapidjson::Value& platformsArray = doc["platforms"];
    for (rapidjson::SizeType i = 0; i < platformsArray.Size(); ++i) {
        const rapidjson::Value& platformObj = platformsArray[i];
        if (platformObj.IsObject() &&
            platformObj.HasMember("x") && platformObj["x"].IsFloat() &&
            platformObj.HasMember("y") && platformObj["y"].IsFloat() &&
            platformObj.HasMember("width") && platformObj["width"].IsFloat() &&
            platformObj.HasMember("height") && platformObj["height"].IsFloat()) {
            // Extract platform data
            float x = platformObj["x"].GetFloat();
            float y = platformObj["y"].GetFloat();
            float width = platformObj["width"].GetFloat();
            float height = platformObj["height"].GetFloat();

            // Create new platform
            sf::Vector2f position(x, y);
            sf::Vector2f size(width, height);
            sf::FloatRect bounds(position, size);
            cPlatformRect* platform = new cPlatformRect(bounds);
            mLevelPlatformList.AddPlatform(platform);
        }
        else {
            std::cerr << "Invalid platform object at index " << i << std::endl;
        }
    }

    std::cout << "Loaded " << platformsArray.Size() << " platforms" << std::endl;
}

void cFileInterface::LoadPlayerSpawnFromJson(const rapidjson::Document& doc) {
    if (doc.HasMember("playerSpawn") && doc["playerSpawn"].IsObject()) {
        const rapidjson::Value& spawnObj = doc["playerSpawn"];
        if (spawnObj.HasMember("x") && spawnObj["x"].IsFloat() &&
            spawnObj.HasMember("y") && spawnObj["y"].IsFloat()) {

            float x = spawnObj["x"].GetFloat();
            float y = spawnObj["y"].GetFloat();

            cPlatformLevelStart* playerSpawn = new cPlatformLevelStart(sf::Vector2f(x, y));
            mLevelPlatformList.AddPlayerSpawn(playerSpawn);
            std::cout << "Loaded player spawn point" << std::endl;
        }
    }
    else
    {
        // Add item offscreen
        cPlatformLevelStart* playerSpawn = new cPlatformLevelStart(sf::Vector2f(-500.f, -500.f));
        mLevelPlatformList.AddPlayerSpawn(playerSpawn);
        std::cout << "Added Default spawn point" << std::endl;
    }
}

void cFileInterface::LoadLevelExitFromJson(const rapidjson::Document& doc) {
    if (doc.HasMember("levelExit") && doc["levelExit"].IsObject()) {
        const rapidjson::Value& exitObj = doc["levelExit"];
        if (exitObj.HasMember("x") && exitObj["x"].IsFloat() &&
            exitObj.HasMember("y") && exitObj["y"].IsFloat()) {

            float x = exitObj["x"].GetFloat();
            float y = exitObj["y"].GetFloat();

            cLevelExit* levelExit = new cLevelExit(sf::Vector2f(x, y));
            mLevelPlatformList.AddLevelExit(levelExit);
            std::cout << "Loaded level exit" << std::endl;
        }
    }
    else
    {
        // Add item offscreen
        cLevelExit* levelExit = new cLevelExit(sf::Vector2f(-500, -500));
        mLevelPlatformList.AddLevelExit(levelExit);
        std::cout << "Added default level exit" << std::endl;
    }
}

void cFileInterface::LoadLevelKeyFromJson(const rapidjson::Document& doc) {
    if (doc.HasMember("levelKey") && doc["levelKey"].IsObject()) {
        const rapidjson::Value& keyObj = doc["levelKey"];
        if (keyObj.HasMember("x") && keyObj["x"].IsFloat() &&
            keyObj.HasMember("y") && keyObj["y"].IsFloat()) {

            float x = keyObj["x"].GetFloat();
            float y = keyObj["y"].GetFloat();

            cKeyObject* levelKey = new cKeyObject(sf::Vector2f(x, y));
            mLevelPlatformList.AddLevelKey(levelKey);
            std::cout << "Loaded level key" << std::endl;
        }
    }
    else
    {
        // Add item offscreen
        cKeyObject* levelKey = new cKeyObject(sf::Vector2f(-500, -500));
        mLevelPlatformList.AddLevelKey(levelKey);
        std::cout << "Added default level key" << std::endl;
    }
}

void cFileInterface::LoadMinesFromJson(const rapidjson::Document& doc) {
    if (!doc.HasMember("mines") || !doc["mines"].IsArray()) {
        return; // No mines to load
    }

    const rapidjson::Value& minesArray = doc["mines"];
    for (rapidjson::SizeType i = 0; i < minesArray.Size(); ++i) {
        const rapidjson::Value& mineObj = minesArray[i];
        if (mineObj.IsObject() &&
            mineObj.HasMember("x") && mineObj["x"].IsFloat() &&
            mineObj.HasMember("y") && mineObj["y"].IsFloat()) {

            float x = mineObj["x"].GetFloat();
            float y = mineObj["y"].GetFloat();

            cMine* mine = new cMine(sf::Vector2f(x, y));
            mLevelPlatformList.AddEnemyMine(mine);
        }
        else {
            std::cerr << "Invalid mine object at index " << i << std::endl;
        }
    }

    std::cout << "Loaded " << minesArray.Size() << " mines" << std::endl;
}

void cFileInterface::LoadBouncySquaresFromJson(const rapidjson::Document& doc) {
    if (!doc.HasMember("bouncySquares") || !doc["bouncySquares"].IsArray()) {
        return; // No bouncy squares to load
    }

    const rapidjson::Value& squaresArray = doc["bouncySquares"];
    for (rapidjson::SizeType i = 0; i < squaresArray.Size(); ++i) {
        const rapidjson::Value& squareObj = squaresArray[i];
        if (squareObj.IsObject() &&
            squareObj.HasMember("x") && squareObj["x"].IsFloat() &&
            squareObj.HasMember("y") && squareObj["y"].IsFloat()) {

            float x = squareObj["x"].GetFloat();
            float y = squareObj["y"].GetFloat();

            cBouncySquare* bouncySquare = new cBouncySquare(sf::Vector2f(x, y));
            mLevelPlatformList.AddBouncySquare(bouncySquare);
        }
        else {
            std::cerr << "Invalid bouncy square object at index " << i << std::endl;
        }
    }

    std::cout << "Loaded " << squaresArray.Size() << " bouncy squares" << std::endl;
}