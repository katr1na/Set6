/* CSCI 200: Lab 6B: L6B - SFML: Starcraft
 *
 * Author: Katrina Ngo
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *
 * The goal is to read in data from a file to create stars and place them accordingly
 * in the window with the correct greyscale in SFML.
 */

#include <SFML/Graphics.hpp>
using namespace sf;

#include "Star.h"

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    const int WIDTH = 640;
    const int HEIGHT= 640;
    // create a window
    RenderWindow window( VideoMode(WIDTH, HEIGHT), "Starcraft" );

    // FILE LOADING
    ifstream fileIn;
    fileIn.open("stars.txt");
    if (fileIn.fail()) {
        cerr << "Could not open file" << endl;
        cerr << "Shutting down" << endl;
        return -1;
    } else {
        cout << "File opened successfully!" << endl << endl;
    }

    // create list of all starts in file
    vector<Star> allStars;
    float xCoor;
    float yCoor;
    float input;
    float brightnessVal;
    // read in x and y coordinates and brightness value of all stars
    while (!fileIn.eof()) {
        fileIn >> xCoor;
        fileIn >> yCoor;
        fileIn >> input;
        fileIn >> brightnessVal;
        fileIn >> input >> input;
        // if brightness value is valid, add star to list
        if (brightnessVal >= 0 && brightnessVal <= 8) {
            Star newStar = Star(xCoor, yCoor, brightnessVal);
            allStars.push_back(newStar);
        }
    }
    // find the brightest star in the list
    float brightest_star = allStars.at(0).getBrightness();
    for (int i = 1; i < allStars.size(); i++) {
        if (allStars.at(i).getBrightness() > brightest_star) {
            brightest_star = allStars.at(i).getBrightness();
        }
    }
    // // create an event object once to store future events
    Event event;

    // while the window is open
    while( window.isOpen() ) {
        // clear any existing contents
        window.clear();

        CircleShape starShape;
        starShape.setRadius(2);
        // draw all stars in list
        for (int i = 0; i < allStars.size(); i++) {
            // calculate transformed x and y coordinates for window
            float xPixel = allStars.at(i).getTransformedX(WIDTH);
            float yPixel = allStars.at(i).getTransformedY(HEIGHT);
            starShape.setPosition(Vector2f(xPixel, yPixel));
            // set color of each star to calculated gray scale color
            starShape.setFillColor(allStars.at(i).getGrayscaleColor(brightest_star));
            window.draw(starShape);
        }

        // display the current contents of the window
        window.display();

        // check if any events happened since the last time checked
        while( window.pollEvent(event) ) {
            // if event type corresponds to pressing window X
            if(event.type == Event::Closed) {
                // tell the window to close
                window.close();
            }
            // check addition event types to handle additional events
        }
    }
    return 0;
}