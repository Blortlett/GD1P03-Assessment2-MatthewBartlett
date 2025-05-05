#include "cFileInterface.h"

cFileInterface::cFileInterface(cLevelPlatformsList& platformList)
: mLevelPlatformList(platformList)
{

}

cFileInterface::~cFileInterface()
{

}

void cFileInterface::SaveLevelDialog() {
    // Initialize COM
    HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
    if (FAILED(hr)) {
        std::cerr << "Failed to initialize COM" << std::endl;
        return;
    }

    // Create Save File Dialog
    IFileSaveDialog* pFileSave = nullptr;
    hr = CoCreateInstance(CLSID_FileSaveDialog, NULL, CLSCTX_ALL,
        IID_IFileSaveDialog, (void**)&pFileSave);

    if (SUCCEEDED(hr)) {
        // Set file types
        COMDLG_FILTERSPEC fileTypes[] = {
            { L"JSON files", L"*.json" },
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
                    // Create JSON document
                    rapidjson::Document doc;
                    doc.SetObject();
                    rapidjson::Document::AllocatorType& allocator = doc.GetAllocator();

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

                    // Write to JSON string
                    rapidjson::StringBuffer buffer;
                    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
                    doc.Accept(writer);

                    // Write to file
                    std::ofstream outFile(pszFilePath);
                    if (outFile.is_open()) {
                        outFile << buffer.GetString();
                        outFile.close();
                    }

                    CoTaskMemFree(pszFilePath);
                }
                pItem->Release();
            }
        }
        pFileSave->Release();
    }

    CoUninitialize();
}

void cFileInterface::LoadLevelDialog()
{
    // Initialize COM
    HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
    if (FAILED(hr)) {
        std::cerr << "Failed to initialize COM" << std::endl;
        return;
    }

    // Create Open File Dialog
    IFileOpenDialog* pFileOpen = nullptr;
    hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL,
        IID_IFileOpenDialog, (void**)&pFileOpen);

    if (SUCCEEDED(hr)) {
        // Set file types
        COMDLG_FILTERSPEC fileTypes[] = {
            { L"JSON files", L"*.json" },
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
                    // Read JSON file
                    std::ifstream inFile(pszFilePath);
                    if (inFile.is_open()) {
                        // Read file content into string
                        std::string jsonContent((std::istreambuf_iterator<char>(inFile)),
                            std::istreambuf_iterator<char>());
                        inFile.close();

                        // Parse JSON
                        rapidjson::Document doc;
                        if (!doc.Parse(jsonContent.c_str()).HasParseError() && doc.IsObject()) {
                            // Clear existing platforms
                            mLevelPlatformList.ClearList();

                            // Check for platforms array
                            if (doc.HasMember("platforms") && doc["platforms"].IsArray()) {
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
                                        sf::Vector2f position = sf::Vector2f(x, y);
                                        sf::Vector2f size = sf::Vector2f(width, height);
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
                            else {
                                std::cerr << "No valid platforms array in JSON" << std::endl;
                            }
                        }
                        else {
                            std::cerr << "Failed to parse JSON file" << std::endl;
                        }
                    }
                    else {
                        std::cerr << "Failed to open file: " << pszFilePath << std::endl;
                    }
                    CoTaskMemFree(pszFilePath);
                }
                pItem->Release();
            }
        }
        pFileOpen->Release();
    }

    CoUninitialize();
}

void cFileInterface::LoadLevelByName(const std::string& levelName)
{
    // Construct file path (e.g., "Levels/levelName.json")
    std::filesystem::path filePath = "Assets/Levels/" + levelName + ".json";

    // Read JSON file
    std::ifstream inFile(filePath);
    if (!inFile.is_open()) {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        return;
    }

    // Read file content into string
    std::string jsonContent((std::istreambuf_iterator<char>(inFile)),
        std::istreambuf_iterator<char>());
    inFile.close();

    // Parse JSON
    rapidjson::Document doc;
    if (doc.Parse(jsonContent.c_str()).HasParseError() || !doc.IsObject()) {
        std::cerr << "Failed to parse JSON file: " << filePath << std::endl;
        return;
    }

    // Clear existing platforms
    mLevelPlatformList.ClearList();

    // Check for platforms array
    if (!doc.HasMember("platforms") || !doc["platforms"].IsArray()) {
        std::cerr << "No valid platforms array in JSON: " << filePath << std::endl;
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
            std::cerr << "Invalid platform object at index " << i << " in file: " << filePath << std::endl;
        }
    }

    std::cout << "Loaded " << platformsArray.Size() << " platforms from " << filePath << std::endl;
}