/* --------------------------------------------------------
 *    File: breakout1.cpp
 *  Author: Tyler MacPhee
 *   Class: COP 2001, Spring 2022, CRN #10410
 * Purpose: 2D breakout game
 * Audit:
 * 3.29.22 TM added walls to main app file
 * 4.7.22 TM added collision detection to walls
 * 4.26.22 TM added collision detection to paddle
 * 4.30.22 TM added bricks & collision for them, breakout game finished
 * -------------------------------------------------------- */
#include "breakout_defs.h"
#include <cmath>

// Function declarations (prototypes)
// --------------------------------------------------------
void setup(Ball &ball, Borders &border, MovingBlock &paddle, Brick theBricks[BRICK_ROWS][BRICK_COLUMNS]);
Direction processInput();
bool update(Direction &input, Ball &ball, Borders borders,
            Brick theBricks[BRICK_ROWS][BRICK_COLUMNS],
            MovingBlock &paddle, float delta, bool &started);
void render(sf::RenderWindow &window, Ball ball, Borders border,
            Brick theBricks[BRICK_ROWS][BRICK_COLUMNS],
            MovingBlock paddle, float delta);
int getCollisionPoint(Ball* pBall, Block* pBlock);
bool checkCollision(Ball* pBall, Block* pBlock);
bool checkBlockCollision(Block moving, Block stationary);
bool doCollisionChecks(Ball &ball, MovingBlock &paddle, Borders &borders, Brick theBricks[BRICK_ROWS][BRICK_COLUMNS]);

/**
 * The main application
 * @return OS status message (0=Success)
 */
void breakout(sf::RenderWindow &window) {
    // create a 2d graphics window

    // declare a ball variable for setup function
    Ball theBall;
    //Declare border variable for setup function
    Borders theBorder;
    //declare paddle variable for setup function
    MovingBlock paddle;
    //declare bricks variable for setup function
    Brick theBricks[BRICK_ROWS][BRICK_COLUMNS];

    //set variable properties in separate setup function
    setup(theBall, theBorder, paddle, theBricks);

    // timing variables for the main game loop
    sf::Clock clock;
    sf::Time startTime = clock.getElapsedTime();
    sf::Time stopTime = startTime;
    float delta = 0.0;

    bool started = false;
    bool gameOver = false;
    while (!gameOver)
    {
        // calculate frame time
        stopTime = clock.getElapsedTime();
        delta += (stopTime.asMilliseconds() - startTime.asMilliseconds());
        startTime = stopTime;
        // process events
        sf::Event event;
        while (!gameOver && window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                gameOver = true;
        }
        // Process user input
        // ------------------------------------------------
        Direction userInput = processInput();
        if (userInput == Exit)
            gameOver = true;
        // Process Updates
        // ------------------------------------------------
        if (delta >= FRAME_RATE) {    // if we have made it at least a full frametime
            gameOver = update(userInput, theBall, theBorder, theBricks, paddle, delta, started);
            // subtract the frame-rate from the current frame-time
            // for each full frame covered by this update
            while (delta >= FRAME_RATE)
                delta -= FRAME_RATE;
        }
        // Render the window
        // ------------------------------------------------
        render(window, theBall, theBorder, theBricks, paddle, delta);
    } // end main game loop
    // game ending, close the graphics window
    window.close();
} // end main

/**
 * set ball, walls, and paddle properties before game starts
 *
 * @author TM
 *
 * @param ball - the ball that bounces off the walls/paddle
 * @param theBorder - the walls defining the play area
 * @param paddle - the paddle the player is controlling left/right
 * @return void
 */
void setup(Ball &ball, Borders &theBorder, MovingBlock &paddle, Brick theBricks[BRICK_ROWS][BRICK_COLUMNS]) {

    //left border
    theBorder.left_wall.left = 0.0;
    theBorder.left_wall.top = 0.0;
    theBorder.left_wall.width = WALL_THICKNESS;
    theBorder.left_wall.height = WINDOW_HEIGHT;
    theBorder.left_wall.color = WALL_COLOR;
    theBorder.left_wall.rectangle.setSize(sf::Vector2f(theBorder.left_wall.width, theBorder.left_wall.height));
    theBorder.left_wall.rectangle.setPosition(theBorder.left_wall.left, theBorder.left_wall.top);
    theBorder.left_wall.rectangle.setFillColor(WALL_COLOR);

    //right border
    theBorder.right_wall.left = WINDOW_WIDTH - WALL_THICKNESS;
    theBorder.right_wall.top = 0.0;
    theBorder.right_wall.width = WALL_THICKNESS;
    theBorder.right_wall.height = WINDOW_HEIGHT;
    theBorder.right_wall.color = WALL_COLOR;
    theBorder.right_wall.rectangle.setSize(sf::Vector2f(theBorder.right_wall.width, theBorder.right_wall.height));
    theBorder.right_wall.rectangle.setPosition(theBorder.right_wall.left, theBorder.right_wall.top);
    theBorder.right_wall.rectangle.setFillColor(WALL_COLOR);

    //bottom border
    theBorder.bottom_wall.left = 0.0;
    theBorder.bottom_wall.top = WINDOW_HEIGHT - WALL_THICKNESS;
    theBorder.bottom_wall.width = WINDOW_WIDTH;
    theBorder.bottom_wall.height = WALL_THICKNESS;
    theBorder.bottom_wall.color = WALL_COLOR;
    theBorder.bottom_wall.rectangle.setSize(sf::Vector2f(theBorder.bottom_wall.width, theBorder.bottom_wall.height));
    theBorder.bottom_wall.rectangle.setPosition(theBorder.bottom_wall.left, theBorder.bottom_wall.top);
    theBorder.bottom_wall.rectangle.setFillColor(WALL_COLOR);

    //top border
    theBorder.top_wall.left = 0.0;
    theBorder.top_wall.top = 0.0;
    theBorder.top_wall.width = WINDOW_WIDTH;
    theBorder.top_wall.height = WALL_THICKNESS;
    theBorder.top_wall.color = WALL_COLOR;
    theBorder.top_wall.rectangle.setSize(sf::Vector2f(theBorder.top_wall.width, theBorder.top_wall.height));
    theBorder.top_wall.rectangle.setPosition(theBorder.top_wall.left, theBorder.top_wall.top);
    theBorder.top_wall.rectangle.setFillColor(WALL_COLOR);

    //set paddle properties
    paddle.block.left = (WINDOW_WIDTH - PADDLE_WIDTH) / 2.0;
    paddle.block.top = WINDOW_HEIGHT - (2.0 * PADDLE_THICKNESS); //set paddle above bottom wall
    paddle.block.width = PADDLE_WIDTH;
    paddle.block.height = PADDLE_THICKNESS;
    paddle.block.color = PADDLE_COLOR;
    paddle.block.rectangle.setSize(sf::Vector2f(paddle.block.width, paddle.block.height));
    paddle.block.rectangle.setFillColor(PADDLE_COLOR);
    paddle.block_velocityX = 0.0;
    paddle.block_velocityY = 0.0;

    //setup ball properties
    ball.radius = BALL_RADIUS;
    ball.coordinateX = paddle.block.left + (PADDLE_WIDTH / 2.0);
    ball.coordinateY = paddle.block.top - BALL_RADIUS - 1;
    ball.velocityX = 0.0;
    ball.velocityY = 0.0;
    ball.color = BALL_COLOR;

    //setup bricks
    float bricksTop = FIRST_BRICK; //start at lowest brick row

    Brick *pNext = &theBricks[0][0];    //get pointer to first brick

    for (int row = 0; row < BRICK_ROWS; row++) {
        float bricksLeft = BRICKS_LEFT; //start back at far left

        for (int column = 0; column < BRICK_COLUMNS; column++) {

            //offset left & top by 1 to give each a border
            pNext->block.left = bricksLeft + 1;
            pNext->block.top = bricksTop + 1;

            //subtract 2 from width/height to make room for 1-pixel
            //border on each side
            pNext->block.width = BRICK_WIDTH - 2;
            pNext->block.height = BRICK_HEIGHT - 2;

            //set row properties
            if (row < 2) {
                pNext->block.color = sf::Color::Yellow;
                pNext->points = 1;
                pNext->speedAdjust = 0;
            } else if (row < 4) {
                pNext->block.color = sf::Color::Green;
                pNext->points = 3;
                pNext->speedAdjust = 0;
            } else if (row < 6) {
                pNext->block.color = sf::Color(255, 165, 0);
                pNext->points = 5;
                pNext->speedAdjust = 1;
            } else {
                pNext->block.color = sf::Color::Red;
                pNext->points = 7;
                pNext->speedAdjust = 2;
            }

            //set the drawing rectangles
            pNext->block.rectangle.setSize(sf::Vector2f(pNext->block.width, pNext->block.height));
            pNext->block.rectangle.setFillColor(pNext->block.color);
            pNext->block.rectangle.setPosition(pNext->block.left, pNext->block.top);

            //initialize hit flag off so brick is displayed
            pNext->hit = false;

            pNext++;

            bricksLeft += BRICK_WIDTH; //move next brick to right

        } //brick columns

        bricksTop -= BRICK_HEIGHT; //move up to next row

    } //brick rows

}
/**
 * convert user keyboard input into recognized direction values (documented in Keyboard.hpp)
 *
 * for:
 * left=1/Left
 * up=2/UP
 * right=3/Right
 * down=4/Down
 * start=space
 *
 * @return direction - user input (default no-input=0 or 'None', quit=-1 or 'Exit')
 */
Direction processInput() {
    Direction input = None;  // no input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        input = Left;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        input = Up;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        input = Right;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        input = Down;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
        input = Exit;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        input = Start;
    }
    return input;
} // end getUserInput

/**
 * update the state of game objects
 *
 * @param input - user keyboard input
 * @param ball  - update ball position and speed
 * @param paddle - update paddle position left/right
 * @param delta - current frame time
 * @param started - flag if the game was started according to key-press
 *
 * @return bool - true if ball hits bottom wall & game ends
 */
bool update(Direction &input, Ball &ball, Borders border, Brick theBricks[BRICK_ROWS][BRICK_COLUMNS], MovingBlock &paddle, float delta, bool &started) {

    bool game_over = false;

    // adjust velocity directions for user input
    if (input) {
        switch (input) {
            case Left:
                paddle.block_velocityX -= PADDLE_SPEED;
                break;
            case Right:
                paddle.block_velocityX += PADDLE_SPEED;
                break;
            case Start:
                if (!started) {
                    ball.velocityX = BALL_SPEED_X;
                    ball.velocityY = BALL_SPEED_Y * -1;     //begin moving upwards

                   /**
                    * randomly set horizontal velocity to positive or negative
                    by seeing if the tenths place of current delta
                    (i.e. 1st digit after the decimal) is odd or even.
                    **/
                    if ((int(delta * 10) & 1) % 2) {
                        ball.velocityX *= -1;  // ball goes left if odd
                    }

                    started = true;
                }
                break;
            case None:
                break;
        }
        // clear input
        input = None;
    }
    //adjust location of paddle
    paddle.block.left += paddle.block_velocityX * delta;         //only need to update left since its only left/right

    if (started) {
        // adjust the location of the ball for speed * time
        ball.coordinateX += ball.velocityX * delta;
        ball.coordinateY += ball.velocityY * delta;
    } else {
        ball.coordinateX = paddle.block.left + (PADDLE_WIDTH / 2.0);
        ball.coordinateY = paddle.block.top - BALL_RADIUS - 1;
    }

    game_over = doCollisionChecks(ball, paddle, border, theBricks);

    return game_over;
} // end update

bool doCollisionChecks(Ball &ball, MovingBlock &paddle, Borders &border, Brick theBricks[BRICK_ROWS][BRICK_COLUMNS]) {

    bool game_over = false;
    //Check if there was a collision for each of the walls
    // --- check vertical collisions ---
    if (!checkCollision(&ball, &paddle.block)) {
        if (!checkCollision(&ball, &border.top_wall)) {
            game_over = checkCollision(&ball, &border.bottom_wall);
        }
    }
    // --- check horizontal collisions ---
    if (!checkCollision(&ball, &border.left_wall)) {
        checkCollision(&ball, &border.right_wall);
    }

    if (checkBlockCollision(paddle.block, border.left_wall)) {
        paddle.block_velocityX = 0.0;
        paddle.block.left = border.left_wall.left + border.left_wall.width + 1.0;
    } else if (checkBlockCollision(paddle.block, border.right_wall)) {
        paddle.block_velocityX = 0.0;
        paddle.block.left = border.right_wall.left - paddle.block.width - 1.0;
    }

    Brick *pBrick = &theBricks[0][0];
    for (int row = 0; row < BRICK_ROWS; row++) {
        for (int column = 0; column < BRICK_COLUMNS; column++) {
            if (!pBrick->hit) {
                pBrick->hit = checkCollision(&ball, &pBrick->block);
            }
            pBrick++;
        } //columns
    } //rows

    return game_over;
}


/**
 * calculates the current position of the ball relative to a wall, if it detecs there was a collision, it returns
 * the cardinal degree angle of collision.
 *
 * @author TM
 * @param pBall - pointing to ball for it's coordinates, velocities & radius
 * @param pBlock - pointing to the wall being passed for it dimensions
 * @return int - returns the cardinal degree equivalent of current collision angle,
 *               used to determine which direction to send the ball after collision.
 */
int getCollisionPoint(Ball* pBall, Block* pBlock) {

    //Define some local variables to assign the temporary positions, further processing done later.

    int cardinal_heading = 0;

    double check_x;
    double check_y;

    //Checks if top/bottom wall is hit
    if (pBall->radius < pBlock->left) {
        check_x = pBlock->left;
    } else if (pBall->radius > (pBlock->left + pBlock->width)) {
        check_x = pBlock->left + pBlock->width;
    } else {
        check_x = pBall->coordinateX;
    }

    //Checks if left/right wall is hit
    if (pBall->radius < pBlock->top) {
        check_y = pBlock->top;
    } else if (pBall->radius > (pBlock->top + pBlock->height)) {
        check_y = pBlock->top + pBlock->height;
    } else {
        check_y = pBall->coordinateY;
    }

    //Calculate the difference between the temp position & actual, if it's less than the radius, a collision occurred
    int diffX = check_x - pBall->coordinateX;
    int diffY = (WINDOW_HEIGHT - check_y) - (WINDOW_HEIGHT - pBall->coordinateY);

    double distance = std::sqrt(pow(diffX, 2.0) + pow(diffY,2.0));

    if (distance <= pBall->radius) {
        double theta = std::atan2(diffY, diffX);
        double degrees = 90.0 - theta * 180 / M_PI;

        //Handle negative degrees
        if (degrees <= 0) {
            degrees += 360;
        }
        cardinal_heading = int(degrees);
    }

    return cardinal_heading;
}

/**
 * Checks if a collision was detected, if it was, it adjusts the balls position & velocities accordingly
 *
 * @author TM
 *
 * @param pBall - pointing to ball for it's coordinates, velocities & radius
 * @param pBlock - pointing to the wall being passed for it dimensions
 * @return bool - false if no collision, true if there was a collision
 */
bool checkCollision(Ball* pBall, Block* pBlock) {

    //Assign return variable
    bool collision = false;

    int result = getCollisionPoint(pBall, pBlock);
    if (result) {
        collision = true;

        //Horizontal collisions
        if (result > 255 && result < 315) {
            pBall->velocityX *= -1;
            pBall->coordinateX = (pBlock->left + pBlock->width + pBall->radius + 1);
        } else if (result > 45 && result < 135) {
            pBall->velocityX *= -1;
            pBall->coordinateX = (pBlock->left - pBall->radius - 1);
        }

        //Vertical collisions
        if (result >= 315 || result <= 45) {
            pBall->velocityY *= -1;
            pBall->coordinateY = (pBlock->top + pBlock->height + pBall->radius + 1);
        } else if (result >= 135 && result <= 225) {
            pBall->velocityY *= -1;
            pBall->coordinateY = (pBlock->top - pBall->radius - 1);
        }
    }

    return collision;
}

bool checkBlockCollision(Block moving, Block stationary) {

    //Assign return variable
    bool collision = false;

    if (moving.left < stationary.left + stationary.width &&
    moving.left + moving.width > stationary.left &&
    moving.top < stationary.top + stationary.height &&
    moving.top + moving.height > stationary.top)
    {
        collision = true;
    }
    return collision;
}

/**
 * draw the ball on the graphics window
 *
 * @param window - handle to open graphics window
 * @param ball   - structure variable with properties for the ball
 * @param paddle - the player's paddle they're controlling left/right
 * @param delta  - amount of frame time plus lag (in ms)
 */
void render(sf::RenderWindow &window, Ball ball, Borders border, Brick theBricks[BRICK_ROWS][BRICK_COLUMNS], MovingBlock paddle, float delta) {
    // Render drawing objects
    // ------------------------------------------------
    // clear the window with the background color
    window.clear(WINDOW_COLOR);

    //draw borders
    window.draw(border.bottom_wall.rectangle);
    window.draw(border.right_wall.rectangle);
    window.draw(border.top_wall.rectangle);
    window.draw(border.left_wall.rectangle);

    // draw the ball
    // ------------------------------------------------
    sf::CircleShape circle;
    circle.setFillColor(ball.color);
    circle.setRadius(ball.radius);
    // set screen coordinates relative to the center of the circle
    circle.setOrigin(ball.radius, ball.radius);
    // calculate current drawing location relative to speed and frame-time
    float xPosition = ball.coordinateX + ball.velocityX * delta;
    float yPosition = ball.coordinateY + ball.velocityY * delta;
    circle.setPosition(xPosition, yPosition);
    window.draw(circle);

    // draw the paddle
    // ------------------------------------------------
    paddle.block.left += paddle.block_velocityX * delta;         // x-coord of paddle
    paddle.block.top += paddle.block_velocityY * delta;          // y-coord of paddle
    paddle.block.rectangle.setPosition(paddle.block.left, paddle.block.top);
    window.draw(paddle.block.rectangle);

    Brick *pBrick = &theBricks[0][0];
    for (int row = 0; row < BRICK_ROWS; row++) {
        for (int column = 0; column < BRICK_COLUMNS; column++) {
            if (!pBrick->hit) {
                window.draw(pBrick->block.rectangle);
            }
            pBrick++;
        } //columns
    } //rows

    // show the new window
    // ------------------------------------------------
    window.display();
} // end render