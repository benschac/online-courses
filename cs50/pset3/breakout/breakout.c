//
// breakout.c
// Benjamin Schachter
// benschac@gmail.com
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// padding
#define PADDING 4


// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;
    
    double velocityX = 2.0;
    double velocityY = 2.0;

    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
    
        GEvent event = getNextEvent(MOUSE_EVENT);

        if (event != NULL)
        {
           
            if (getEventType(event) == MOUSE_MOVED)
            {
                // move paddle with Mouse Moved
                setLocation(paddle, getX(event) - (55/2), 570);
                add(window, paddle);
            }
        }
        
        
        move(ball, velocityX, 0);
        move(ball, 0, velocityY);



            // bounce off right edge of window
            if (getX(ball) + getWidth(ball) >= getWidth(window) || getX(ball) <= 0 )
            {
                velocityX = -velocityX;
            }

            pause(10);
            
            if (getY(ball) + getHeight(ball) <= 0)
            {
                velocityY = -velocityY;
            }
            
            if ((getHeight(ball) + getY(ball) >= HEIGHT))
            {
                lives--;
                setLocation(ball, (WIDTH / 2) - RADIUS,(HEIGHT / 2) - RADIUS);
                setLocation(paddle, (WIDTH / 2) - 45, 570);
                waitForClick();
            }
            pause(10);
            
            GObject collisionObject = detectCollision(window, ball);
            
            if (collisionObject != NULL && strcmp(getType(collisionObject), "GRect") == 0)
            {
                velocityY = -velocityY;
                
                if (collisionObject != paddle)
                {
                    removeGWindow(window, collisionObject);
                    bricks--;
                    points++;
                    updateScoreboard(window, label, points);
                }
            }
        
    }
    // wait for click before exiting
    waitForClick();
    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    // done
    int x = (PADDING + 2);
    int y = 75;
    
    for(int height = 0; height < ROWS; height++)
    {
        char* colors[] = {"RED", "ORANGE", "YELLOW", "GREEN", "CYAN"};
        for(int width = 0; width < COLS; width++)
        {
          GRect rect = newGRect(x, y, 35, 15);
          setFilled(rect, true);
          setColor(rect, colors[height]);
          add(window, rect);
          x+= (35 + PADDING);
        }
        y += (15 + PADDING);
        x = (PADDING + 2);
    }
    
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    GOval ball = newGOval((WIDTH / 2) - RADIUS, (HEIGHT/2) - RADIUS,RADIUS, RADIUS);
    setFilled(ball, true);
    setColor(ball, "BLACK");
    add(window, ball);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{

    GRect paddle = newGRect((WIDTH / 2) - 45, 570, 55, 15);
    setFilled(paddle, true);
    setColor(paddle, "BLACK");
    add(window, paddle);
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    GLabel label = newGLabel("");
    setFont(label, "SansSerif-36");
    add(window, label);

        // update label
        setLabel(label, "0");

        // center label
        double x = (getWidth(window) - getWidth(label)) / 2;
        double y = (getHeight(window) - getHeight(label)) / 2;
        setLocation(label, x, y);

        // linger for 100 milliseconds
        pause(100);
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
