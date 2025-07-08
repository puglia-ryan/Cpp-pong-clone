#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Ball.h"


class Game{
  public:
    Game();
    void run();

  private:
    void processEvent();
    void update(float dt);
    void render();
    void handleCollisions();
    void resetBall();

    static constexpr unsigned WindowWidth = 800;
    static constexpr unsigned WindowHeight = 600;
    static constexpr unsigned WinScore = 10;

    sf::RenderWindow mWindow;
    Paddle mPlayer1;
    Paddle mPlayer2;
    Ball mBall;
    sf::Text mScoreText1;
    sf::Text mScoreText2;
    unsigned mScore1;
    unsigned mScore2;
};
