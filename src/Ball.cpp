#include "Ball.h"
#include <SFML/Graphics/Color.hpp>

Ball::Ball(float radius)
  : mVelocity(0.f, 0.f)
{
  mShape.setRadius(radius);
  mShape.setOrigin(radius, radius);
  mShape.setFillColor(sf::Color::White);
}

