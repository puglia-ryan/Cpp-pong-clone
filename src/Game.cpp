#include "Game.h"
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <stdexcept>
#include <string>

Game::Game()
    : mWindow({WindowWidth, WindowHeight}, "Pong Clone", sf::Style::Close),
      mPlayer1(sf::Vector2f(10.f, WindowHeight / 2.f),
               sf::Vector2f(20.f, 100.f), sf::Keyboard::W, sf::Keyboard::S),
      mPlayer2(sf::Vector2f(WindowWidth - 10.f, WindowHeight / 2.f),
               sf::Vector2f(20.f, 100.f), sf::Keyboard::Up, sf::Keyboard::Down),
      mBall(10.f) {
  if (!mFont.loadFromFile(
          "/usr/share/fonts/dejavu-sans-fonts/DejaVuSans.ttf")) {
    throw std::runtime_error("Failed to load font");
  }

  // Set up score texts
  mScoreText1.setFont(mFont);
  mScoreText1.setCharacterSize(30);
  mScoreText1.setPosition(WindowWidth * 0.25f, 10.f);

  mScoreText2 = mScoreText1;
  mScoreText2.setPosition(WindowWidth * 0.75f, 10.f);

  resetBall();
}

void Game::run() {
  sf::Clock clock;
  while (mWindow.isOpen()) {
    float dt = clock.restart().asSeconds();
    processEvents();
    update(dt);
    handleCollisions();
    render();
  }
}

void Game::processEvents() {
  sf::Event event;
  while (mWindow.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      mWindow.close();
    }
  }
}

void Game::update(float dt) {
  mPlayer1.update(dt);
  mPlayer2.update(dt);
  mBall.update(dt);
}

void Game::handleCollisions() {
  // Ball top and bottom
  auto pos = mBall.getPosition();
  if (pos.y - mBall.getRadius() < 0.f ||
      pos.y + mBall.getRadius() > WindowHeight) {
    mBall.bounceY();
  }

  // Ball and Paddles
  if (mBall.getGlobalBounds().intersects(mPlayer1.getGlobalBounds())) {
    mBall.bounceX();
  }
  if (mBall.getGlobalBounds().intersects(mPlayer2.getGlobalBounds())) {
    mBall.bounceX();
  }

  // After scoring
  if (pos.x + mBall.getRadius() < 0.f) {
    ++mScore2;
    resetBall();
  }
  if (pos.x + mBall.getRadius() > WindowWidth) {
    ++mScore1;
    resetBall();
  }

  mScoreText1.setString(std::to_string(mScore1));
  mScoreText2.setString(std::to_string(mScore2));
}

void Game::resetBall() {
  mBall.setPosition(WindowWidth / 2.f, WindowHeight / 2.f);
  // Random initial direction
  float vx = (std::rand() % 2 ? +1 : -1) * 300.f;
  float vy = (std::rand() % 2 ? +1 : -1) * 200.f;
  mBall.setVelocity({vx, vy});
}

void Game::render() {
  mWindow.clear(sf::Color::Black);
  mPlayer1.draw(mWindow);
  mPlayer2.draw(mWindow);
  mBall.draw(mWindow);
  mWindow.draw(mScoreText1);
  mWindow.draw(mScoreText2);
  mWindow.display();
}
