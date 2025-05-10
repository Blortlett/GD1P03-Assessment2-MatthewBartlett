#include "cApplicationManager.h"
#include "cMainMenu.h"
#include "cGameManager.h"
#include "cLevelPlatformsList.h"
#include "cLevelEditorManager.h"
#include "cPlayerInput.h"
#include "cFileInterface.h"

int main()
{
    // Background texture
    sf::RenderWindow window(sf::VideoMode({ 1366, 768 }), "Ninja Clone");
    sf::RectangleShape Background(sf::Vector2f(window.getSize()));
    Background.setFillColor(sf::Color(150, 150, 150));

    // Shared Level list
    cLevelPlatformsList LevelPlatformsList;
    // Create File Interface
    cFileInterface FileInterface(LevelPlatformsList);
    // Create Game managers
    cPlayerInput PlayerInput;
    cGameManager GameManager(window, PlayerInput, LevelPlatformsList, FileInterface);
    // Create Level Editor
    cLevelEditorManager LevelEditor(window, PlayerInput, LevelPlatformsList, FileInterface);
    // Create Main Menu
    cMainMenu MainMenu(window, FileInterface);


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(Background);
        if (cApplicationManager::GetInstance().IsGameRunning())
        {
            // Draw / Run game
            GameManager.GameTick();
        }
        if (cApplicationManager::GetInstance().IsLevelEditorRunning())
        {
            // Draw / Run level editor
            LevelEditor.Update();
            LevelEditor.Draw();
        }
        if (cApplicationManager::GetInstance().IsMainMenuActive())
        {
            // Draw / Run MainMenu
            MainMenu.Update();
        }
        window.display();
    }

    return 0;
}