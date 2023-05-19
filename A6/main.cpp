/* CSCI 200: Assignment 6: A6 - SFML: Triangle Land
 *
 * Author: Katrina Ngo
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *
 * The main goal is to implement inheritance with an abstract class, Triangle, to read in a triangle data file and 
 * draw the valid triangles to make an image in SFML.
 */

#include "Triangle.h"
#include "ScaleneTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

int main() {
    // create a window
    RenderWindow window( VideoMode(640, 640), "TriangleLand" );

    ifstream fileIn;
    fileIn.open("triangles.dat");
    if (fileIn.fail()) {
        cerr << "Could not open file" << endl;
        cerr << "Shutting down" << endl;
        return -1;
    } else {
        cout << "File opened successfully!" << endl << endl;
    }

    vector<Triangle*> triangleList;
    char T;
    double x1, y1, x2, y2, x3, y3, r, g, b;

    while (!fileIn.eof()) {
        fileIn >> T >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> r >> g >> b;
        if (fileIn.fail()) {
            break;
        }
        Triangle* newTriangle;
        if (T == 'S') {
            newTriangle = new ScaleneTriangle;
        } else if (T == 'I') {
            newTriangle = new IsoscelesTriangle;
        } else {
            newTriangle = new EquilateralTriangle;
        }
        Position v1 = Position(x1, y1);
        Position v2 = Position(x2, y2);
        Position v3 = Position(x3, y3);
        if (newTriangle->setCoordinates(v1, v2, v3)) {
            newTriangle->setColor(Color(r, g, b));
            triangleList.push_back(newTriangle);
        } else {
            cout << "triangle is invalid - " << "\"" << T << " " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << " " << r << " " << g << " " << b << "\"" << endl;
            delete newTriangle;
        }
    }
    fileIn.close();

    Event event;
    while( window.isOpen() ) {
        // clear any existing contents
        window.clear();
        for (int i = 0; i < triangleList.size(); i++) {
            triangleList.at(i)->draw(window);
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