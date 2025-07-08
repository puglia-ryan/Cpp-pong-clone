#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
class Ball{
  public:
    Ball(float radius);
    void update(float dt);
    void draw(sf::RenderWindow&);
    void bounceX();
    void bounceY();

    void setPosition(float x,float y);
    void setVelocity(const sf::Vector2f& velocity);

    float getRadius() const;
    sf::Vector2f setPosition() const;
    sf::FloatRect getGlobalBounds() const;

  private:
    sf::CircleShape mShape;
    sf::Vector2f mVelocity;
};
