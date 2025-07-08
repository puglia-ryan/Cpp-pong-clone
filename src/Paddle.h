#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
class Paddle{
  public:
    Paddle(float x, float y);
    void handleInput(float dt);
    void update(float dt);
    void draw(sf::RenderWindow&);
  private:
    sf::RectangleShape shape;
    float speed = 400.f;
};
