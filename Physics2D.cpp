#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"

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

    /*sf::Texture arrow;
    if (!arrow.loadFromFile("src/arr.png")) {
        std::cout << "TEXTURE SUCKS" << std::endl;
    }*/



    // the & in front of environment makes it return the address (pointer) of the environment variable
    
    sf::CircleShape circle(10);
    sf::CircleShape circle2(10);
    circle2.setFillColor(sf::Color::Red);

    Object object(&environment);
    object.setShape(circle);
    object.setPosition({ 1110, 9 });
    object.setVelocity({ 10, 1 });
    object.setAcceleration({ 0, environment.getGravity() });
    object.setMass(500);

    Object object2(&environment);
    object2.setShape(circle);
    object2.setPosition({ 44, 10 });
    object2.setVelocity({ 1.2, 1 });
    object2.setAcceleration({ 0, environment.getGravity() });
    object2.setMass(50);

    Object object3(&environment);
    object3.setShape(circle2);
    object3.setPosition({ 292, 10 });
    object3.setVelocity({ 5, 1 });
    object3.setAcceleration({ 0, environment.getGravity() });
    object3.setMass(50);

    Object object4(&environment);
    object4.setShape(circle);
    object4.setPosition({ 631, 0});
    object4.setVelocity({ 3, 1 });
    object4.setAcceleration({ 0, environment.getGravity()});
    object4.setMass(50);


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

        kinematics.forcesActive(object, c_detect, environment, window);
        kinematics.forcesActive(object2, c_detect, environment, window);
        kinematics.forcesActive(object3, c_detect, environment, window);
        kinematics.forcesActive(object4, c_detect, environment, window);
        /*kinematics.objectAngle(object);*/

        c_detect.Object2Object(object, object2);
        c_detect.Object2Object(object2, object3);
        c_detect.Object2Object(object, object3);
        c_detect.Object2Object(object, object4);
        c_detect.Object2Object(object2, object4);
        c_detect.Object2Object(object4, object3);
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
        
        window.draw(object2.getShape());
        window.draw(object.getShape());
        window.draw(object3.getShape());
        window.draw(object4.getShape());


        window.display();

        

    }


    ImGui::SFML::Shutdown();
}