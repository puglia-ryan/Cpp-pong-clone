#include "Ball.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdlib>

Ball::Ball(float radius)
  : mVelocity(0.f, 0.f)
{
  mShape.setRadius(radius);
  mShape.setOrigin(radius, radius);
  mShape.setFillColor(sf::Color::White);
}

void Ball::update(float dt) {
  mShape.move(mVelocity * dt);
}

void Ball::draw(sf::RenderWindow& window){
  window.draw(mShape);
}

void Ball::bounceX(){
  mVelocity.x = -mVelocity.x;
}

void Ball::bounceY(){
  mVelocity.y = -mVelocity.y;
}

void Ball::setPosition(float x, float y){
  mShape.setPosition(x, y);
}

void Ball::setVelocity(const sf::Vector2f& velocity){
  mVelocity = velocity;
}

float Ball::getRadius() const {
  return mShape.getRadius();
}

sf::Vector2f Ball::getPosition() const {
  return mShape.getPosition();
}

sf::FloatRect Ball::getGlobalBounds() const {
  return mShape.getGlobalBounds();
}
