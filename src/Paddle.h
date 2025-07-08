#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
class Paddle{
  public:
    Paddle(const sf::Vector2f& position, const sf::Vector2f& size, sf::Keyboard::Key upKey, sf::Keyboard::Key downKey);
    void update(float dt);
    void draw(sf::RenderWindow&);
    sf::FloatRect getGlobalBounds() const;
    sf::Vector2f getPosition();
  private:
    sf::RectangleShape shape;
    float speed = 400.f;
    sf::Keyboard::Key mUpKey;
    sf::Keyboard::Key mDownKey;
};
