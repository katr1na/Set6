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

#include "EquilateralTriangle.h"
#include "Triangle.h"
#include <cmath>
#include <iostream>
using namespace std;
using namespace sf;

bool EquilateralTriangle::setCoordinates(Position v1, Position v2, Position v3) {
    double length1 = sqrt((v2.x-v1.x)*(v2.x-v1.x)+(v2.y-v1.y)*(v2.y-v1.y));
    double length2 = sqrt((v3.x-v2.x)*(v3.x-v2.x)+(v3.y-v2.y)*(v3.y-v2.y));
    double length3 = sqrt((v3.x-v1.x)*(v3.x-v1.x)+(v3.y-v1.y)*(v3.y-v1.y));
    const double EPS = 0.0001;

    if ((length1 != 0 && length2 != 0 && length3 != 0) && 
        ((abs(length1-length2)) < EPS && (abs(length2-length3)) < EPS)) {
        mPCoorList[0] = v1;
        mPCoorList[1] = v2;
        mPCoorList[2] = v3;
        return true;
    }
    return false;
}