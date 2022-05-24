#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"
#include "Object.h"
#include "Environment.h"
#include "Collision.h"
#include "Kinematics.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>


std::vector<Object*> Object::list;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    //making environemtn now
    Environment environment;

    Collision c_detect; // look at later
    Kinematics kinematics;

    sf::RectangleShape base = environment.base(); // look at later

    sf::Color bgColor;
    float color[3] = { 0.f, 0.f, 0.f };

    char windowTitle[255] = "ImGui + SFML = <3";

    window.setTitle(windowTitle);
    window.resetGLStates(); // call it if you only draw ImGui. Otherwise not needed.
    sf::Clock deltaClock;


    // the & in front of environment makes it return the address (pointer) of the environment variable
    Object object(&environment);

    sf::CircleShape circle(10);
    object.setShape(circle);

    object.setPosition({ 100,100 });
    object.setVelocity({ 1, 1 });
    object.setAcceleration({ 0,0 });
    object.setMass(50);

    while (window.isOpen()) {

        // important to make the framerate consistent
        window.setFramerateLimit(60);

        sf::Vector2i mousePos = sf::Mouse::getPosition();

        sf::Event event;

        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }

        }

        // object updates
        for (int i = 0; i < Object::list.size(); i++) {
            Object::list[i]->update();
        }
        c_detect.baseCollision(object);
        c_detect.borderCollision(window, object);

        kinematics.forcesActive(object, environment);

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Sample window"); // begin window

        base.setFillColor(sf::Color::Cyan);

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
            window.setTitle(windowTitle);
        }
        ImGui::End(); // end window

        window.clear(bgColor); // fill background with color

        ImGui::SFML::Render(window);

        window.draw(base);

        window.draw(object.getShape());

        window.display();

        

    }


    ImGui::SFML::Shutdown();
}