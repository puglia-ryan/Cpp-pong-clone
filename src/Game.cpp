#include "Game.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <stdexcept>

Game::Game()
  : mWindow({WindowWidth, WindowHeight}, "Pong Clone", sf::Style::Close),
  mPlayer1(sf::Vector2f(10.f, WindowHeight / 2.f), sf::Vector2f(20.f, 100.f), sf::Keyboard::W, sf::Keyboard::S),
  mPlayer2(sf::Vector2f(WindowWidth - 10.f, WindowHeight / 2.f), sf::Vector2f(20.f, 100.f), sf::Keyboard::Up, sf::Keyboard::Down),
  mBall(10.f) {
    if (!mFont.loadFromFile("assets/arial.ttf")) {
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
