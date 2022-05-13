#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"
#include "Object.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "");
    window.setFramerateLimit(8);
    ImGui::SFML::Init(window);

    Object object; 
    sf::CircleShape circle(80);
    object.setShape(circle);
    int diameter = 2 * object.getShape().getRadius();
    bool selected = false; //select 
    sf::Color bgColor;

    float color[3] = { 0.f, 0.f, 0.f };

    // let's use char array as buffer, see next parts
    // for instructions on using std::string with ImGui
    char windowTitle[255] = "ImGui + SFML = <3";

    window.setTitle(windowTitle);
    window.resetGLStates(); // call it if you only draw ImGui. Otherwise not needed.
    sf::Clock deltaClock;
    sf::Vector2f displacement;

    while (window.isOpen()) {
        sf::Vector2f initPos = object.getShape().getPosition();
        sf::Vector2i mousePos = sf::Mouse::getPosition();
        float initVelocity = object.getVelocity(displacement);

        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Button(sf::Mouse::Left))) {
                    if (object.getShape().getGlobalBounds().contains((sf::Vector2f)mousePos)) { //hitbox checker
                        selected = true;
                    }
                }
            }

            if (event.type == sf::Event::MouseButtonReleased) {
                selected = false;
            }
        }

        if (selected == true) {
            object.select(selected); // is "hold" to drag command
        }
  
        



        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Sample window"); // begin window

                                       // Background color edit
        if (ImGui::ColorEdit3("Background color", color)) {
            // this code gets called if color value changes, so
            // the background color is upgraded automatically!
            bgColor.r = static_cast<sf::Uint8>(color[0] * 255.f);
            bgColor.g = static_cast<sf::Uint8>(color[1] * 255.f);
            bgColor.b = static_cast<sf::Uint8>(color[2] * 255.f);
        }

        // Window title text edit
        ImGui::InputText("Properties", windowTitle, 255);

        if (ImGui::Button("Update window title")) {
            // this code gets if user clicks on the button
            // yes, you could have written if(ImGui::InputText(...))
            // but I do this to show how buttons work :)
            window.setTitle(windowTitle);
        }
        ImGui::End(); // end window

        window.clear(bgColor); // fill background with color

        //console outputs
        
        displacement = object.getDisplacement(initPos); // comparsion between old and new pos
        float finalVelocity = object.getVelocity(displacement);
        std::cout << object.getAcceleration(initVelocity, finalVelocity) << std::endl;


        ImGui::SFML::Render(window);

        window.draw(object.getShape());

        window.display();
        

    }

    ImGui::SFML::Shutdown();
}