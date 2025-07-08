#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
class Ball{
  public:
    Ball(float radius);
    void update(float dt);
    void draw(sf::RenderWindow&);
    void reset();
  private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
};
