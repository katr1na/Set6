/* CSCI 200: Lab 6A: L6A - SFML: Bob Ross
 *
 * Author: Katrina Ngo
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *
 * The goal is to get started using SFML and draw a few shapes to the window.
 */

#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
using namespace std;

int main() {
    // create a window
    RenderWindow window( VideoMode(640, 640), "Loofy: The Elephant" );

    // create an event object once to store future events
    Event event;
    double noseRotation = -40;
    Clock programClock;
    Time lastTime = programClock.getElapsedTime();
    bool setWaveDir = false;

    // while the window is open
    while( window.isOpen() ) {
        // clear any existing contents
        window.clear();
    
        CircleShape ear(150, 3);
        ear.setFillColor( Color(100, 100, 100) );
        ear.setRotation(90);
        ear.setPosition( 270, 150 );
        window.draw(ear);

        CircleShape ear2(150, 3);
        ear2.setFillColor( Color(100, 100, 100) );
        ear2.setRotation(270);
        ear2.setPosition(350, 450);
        window.draw(ear2);

        CircleShape face;
        face.setPosition( 150, 150 );
        face.setRadius( 150 );
        face.setFillColor( Color(100, 100, 100) );
        window.draw( face );
                
        CircleShape eye1;
        eye1.setPosition( 235, 250 );
        eye1.setRadius( 20);
        eye1.setFillColor( Color::Black );
        window.draw( eye1 );
                
        CircleShape eye2;
        eye2.setPosition( 325, 250 );
        eye2.setRadius( 20);
        eye2.setFillColor( Color::Black );
        window.draw( eye2 );

        RectangleShape nose;
        nose.setPosition( 270, 300 );
        nose.setRotation(noseRotation);
        nose.setSize( Vector2f( 65, 230 ) );
        nose.setFillColor( Color(128, 128, 128) );
        window.draw( nose );

        Time currTime = programClock.getElapsedTime();
        if( (currTime - lastTime).asMilliseconds() > 10 ) {
            if (setWaveDir) {
                noseRotation--;
            } else {
                noseRotation++;
            }
            if (noseRotation >= 30) {
                setWaveDir = true;
            } else if (noseRotation <= -40) {
                setWaveDir = false;
            }
            lastTime = currTime;
        }

        // Draw a text object called label
        // place in file loading section
        Font myFont;
        if( !myFont.loadFromFile( "data/arial.ttf" ) )
            return -1;
        // place in drawing section
        Text label;
        label.setFont( myFont );
        label.setString( "LOOFY AND HIS CRAZY NOSE" );
        label.setPosition( 100, 550 );
        label.setFillColor( Color::White );
        window.draw( label ); 

        // display the current contents of the window
        window.display();
        // check if any events happened since the last time checked
        while( window.pollEvent(event) ) {
            // if event type corresponds to pressing window X
            if(event.type == Event::Closed) {
                // tell the window to close
                window.close();
            }
        }
    }

    return 0;
}