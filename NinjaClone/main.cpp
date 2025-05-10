#include "cApplicationManager.h"
#include "cMainMenu.h"
#include "cGameManager.h"
#include "cLevelPlatformsList.h"
#include "cLevelEditorManager.h"
#include "cPlayerInput.h"
#include "cFileInterface.h"
#include "cPauseMenu.h"

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
    // Create PauseMenu
    cPauseMenu PauseMenu(window, LevelPlatformsList);


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(Background);
        GameManager.HandleSystemInputs();

        if (cApplicationManager::GetInstance().IsGameRunning()){
            // Draw / Run game
            GameManager.GameTick();
        }
        else // here: IsGameRunning == false;
        {
            //Draw only do not update gamestates    /// I kinda wanted to stop time instead of this but ahhh well *shrug* // Shits bit busted because i didnt stop time...
            GameManager.DrawOnlyTick();
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
        if (cApplicationManager::GetInstance().IsGamePaused())
        {
            // Draw/update pause menu
            PauseMenu.Update();
        }
        // Draw frame
        window.display();
    }

    return 0;
}