#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"
#include "Object.h"
#include "Environment.h"
#include "Collision.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>


std::vector<Object*> Object::list;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);
    //making environemtn now
    Environment environment;

    Collision c_detect;

    sf::RectangleShape base = environment.base(window);

    Object object; 
    Object object2;


    sf::CircleShape circle(39);
    circle.setPosition(50, 500);
    object.setShape(circle);

    sf::CircleShape circle2(50);
    circle2.setFillColor(sf::Color::Green);
    object2.setShape(circle2);

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

        //collison detection
        c_detect.baseCollision(object.getShape(), environment.base(window));
        c_detect.Object2Object(object.getShape(), object2.getShape());

        sf::Event event;

        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }

            for (int i = 0; i < Object::list.size(); i++) {
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Button(sf::Mouse::Left))) {
                        if (Object::list[i]->getShape().getGlobalBounds().contains((sf::Vector2f)mousePos)) { //hitbox checker
                            Object::list[i]->setSelected(true);
                        }
                    }
                }
                if (Object::list[i]->getSelected()) {
                    Object::list[i]->select(true); // is "hold" to drag command
                }
                if (event.type == sf::Event::MouseButtonReleased) {
                    Object::list[i]->setSelected(false);
                }
            }
        }
        
  

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Sample window"); // begin window

        

        base.setFillColor(sf::Color::Cyan);

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
        /*float finalVelocity = object.getVelocity(displacement);
        std::cout << object.getAcceleration(initVelocity, finalVelocity) << std::endl;*/
        /*std::cout << object.getShape().getGlobalBounds() << "," << object.getShape().getGlobalBounds() << std::endl;*/
        /*std::cout << object.getShape().getPosition().y << "," << base.getPosition().y << std::endl;*/


        ImGui::SFML::Render(window);

        window.draw(object.getShape());
        window.draw(object2.getShape());
        window.draw(base);

        window.display();
        

    }


    ImGui::SFML::Shutdown();
}