#include <SFML/Graphics.hpp>

#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "My window");
    ImGui::SFML::Init(window);

    sf::Clock deltaClock;
    bool b = false;
    // run the program as long as the window is open
    while (window.isOpen())
    {
        window.setFramerateLimit(60);
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Window poops");
        ImGui::Text("fartz");
        ImGui::Checkbox("glarble", &b);
        ImGui::End();

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        ImGui::SFML::Render(window);
        // end the current frame
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}