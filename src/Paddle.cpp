#include "Paddle.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

Paddle::Paddle(const sf::Vector2f& position, const sf::Vector2f&size, sf::Keyboard::Key upKey, sf::Keyboard::Key downKey)
  : mUpKey(upKey), mDownKey(downKey){
    mShape.setSize(size);
    mShape.setOrigin(size.x / 2.f, size.y / 2.f);
    mShape.setPosition(position);
    mShape.setFillColor(sf::Color::White);
  }

void Paddle::update(float dt){
  float dy = 0.f;
  if (sf::Keyboard::isKeyPressed(mUpKey)){
    dy -= mSpeed * dt;
  }
  if (sf::Keyboard::isKeyPressed(mDownKey)){
    dy += mSpeed * dt;
  }
  mShape.move(0.f, dy);
  // Clamp to window bounds
  auto pos = mShape.getPosition();
  auto halfH = mShape.getSize().y / 2.f;
  if (pos.y - halfH < 0.f){
    mShape.setPosition(pos.x, halfH);
  }
  else if (pos.y - halfH > 600.f) {
    mShape.setPosition(pos.x, 600.f - halfH);
  }
}
