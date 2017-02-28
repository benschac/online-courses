#include <spl/gwindow.h>
#include <spl/gevents.h>
#include <spl/gobjects.h>




int main(void)
{
    GWindow window = newGWindow(320, 240);
    GOval circle = newGOval(110, 110, 20, 20);
    
    setColor(circle, "BLUE");
    setFilled(circle, true);
    add(window, circle);
    
    double velocity = 1.5;
    
    
    while(true)
    {
        // object, x, y axis
        move(circle, 0, velocity);
        if(getY(circle) + getWidth(circle) >= getHeight(window))
        {
            velocity = -velocity;
        }
        
        else if(getY(circle) <= 0)
        {
            velocity = -velocity;
        }
        
        pause(10);
    }
}
