#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <cstdio>
#include <iostream>

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Pong Clone",
                          sf::Style::Default);
  sf::RectangleShape player(sf::Vector2f(100, 100));
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        window.close();
        break;
      case sf::Event::Resized:
        printf("New Window Width: %i\nNew Window Height: %i\n",
               event.size.width, event.size.height);
        break;
      case sf::Event::TextEntered:
        if (event.text.unicode < 128) {
          printf("%c\n", event.text.unicode);
        }
        break;
      }
    }
    window.draw(player);
    window.display();
  }
  return 0;
}
