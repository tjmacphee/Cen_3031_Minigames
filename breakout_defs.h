/* --------------------------------------------------------
 *    File: breakout_defs.h
 *  Author: Tyler MacPhee
 *   Class: COP 2001, Spring 2022, CRN #10410
 * Purpose: Stores constants & structs for the breakout game
 * Audit:
 * 4.26.22 - Updated defs for new consts
 * 5.1.22 - TM updated defs for new bricks structure
 * -------------------------------------------------------- */

#include "SFML/include/SFML/Graphics.hpp"

#ifndef COLLISION_BREAKOUT_DEFS_H
#define COLLISION_BREAKOUT_DEFS_H
// Global Constants
// --------------------------------------------------------
// window properties
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;
const sf::Color WINDOW_COLOR = sf::Color::White;
// drawing properties
const float FRAME_RATE = (1.0/30.0) * 1000.0;       // FPS in ms
const sf::Color BALL_COLOR = sf::Color::Blue;
const float BALL_RADIUS = 10.0;
// These are just for fun
// speed that the can accelerate at to span window in
// n-seconds (in ms) broken up for each frame
const float SPEED_TIME = (3.0 * 1000.0) * 30.0;     //
const float BALL_SPEED_X = BALL_RADIUS * 10.0 / 1000.0;    // speed horizontally
const float BALL_SPEED_Y = BALL_RADIUS * 8.5 / 1000.0;   // span vertically

//border properties
const float WALL_THICKNESS = 5.0;
const sf::Color WALL_COLOR = sf::Color::Red;

//paddle properties
const float PADDLE_WIDTH = 80.0;
const float PADDLE_THICKNESS = 10.0;
const sf::Color PADDLE_COLOR = sf::Color::Red;
const float PADDLE_SPEED = PADDLE_WIDTH / 10.0 / 1000.0; //paddle speed left/right

//brick properties
const int BRICK_ROWS = 8;                                               //rows of bricks in rack
const int BRICK_COLUMNS = 14;                                           //number of bricks in row
const float BRICK_WIDTH = WINDOW_WIDTH / BRICK_COLUMNS;                 //width of brick
const float BRICK_HEIGHT = PADDLE_THICKNESS * 2;                        //height of 1 brick (2x paddle)
const float BRICKS_HEIGHT = BRICK_ROWS * BRICK_HEIGHT;                  //height of rack of bricks
const float BRICKS_TOP = WINDOW_HEIGHT / 2.0 - BRICKS_HEIGHT * 0.75;    //top of rack (shift up 3/4 from center)
const float BRICKS_LEFT = WALL_THICKNESS;                               //left of first brick in each row
const float FIRST_BRICK = BRICKS_TOP + (BRICK_ROWS - 1) * BRICK_HEIGHT; //top of lowest brick in each rack

// Type definitions
// --------------------------------------------------------

// direction properties
enum Direction {
    Exit = -1,
    None,
    Left,
    Up,
    Right,
    Down,
    Start
};

// ball properties
struct Ball {
    float radius;
    float coordinateX;
    float coordinateY;
    float velocityX;
    float velocityY;
    sf::Color color;
};

//border wall properties
struct Block {
    float left;
    float top;
    float width;
    float height;
    sf::Color color;
    sf::RectangleShape rectangle;
};

//moving block properties
struct MovingBlock {
    Block block;
    float block_velocityX;
    float block_velocityY;
};

struct Brick {
    Block block;
    bool hit;
    int points;
    float speedAdjust;
};

//border walls
struct Borders {
    Block left_wall;
    Block right_wall;
    Block top_wall;
    Block bottom_wall;
};

void breakout(sf::RenderWindow &window);

#endif //COLLISION_BREAKOUT_DEFS_H
