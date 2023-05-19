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

#include "Star.h"
using namespace std;

Star::Star() {
    mXStar = 0;
    mYStar = 0;
    mBrightness = 0;
}

Star::Star(const float X, const float Y, const float VALUE) {
    mXStar = X;
    mYStar = Y;
    mBrightness = VALUE;
}

double Star::getXCoor() const {
    return mXStar;
}

double Star::getYCoor() const {
    return mYStar;
}

double Star::getBrightness() const {
    return mBrightness;
}

void Star::setXCoor(const float X) {
    mXStar = X;
}

void Star::setYCoor(const float Y) {
    mYStar = Y;
}

void Star::setBrightness(const float VALUE) {
    mBrightness = VALUE;
}

float Star::getTransformedX(const int WIDTH) const {
    return ( mXStar + 1 ) * WIDTH / 2;
}

float Star::getTransformedY(const int HEIGHT) const {
    return ( -mYStar + 1 ) * HEIGHT / 2;
}

sf::Color Star::getGrayscaleColor(const float BRIGHTEST_STAR) {
    // invert brightness of star
    float invertedBrightness = BRIGHTEST_STAR - mBrightness;
    // calculate shade of gray in RGB values
    int shadeOfGray = (int)( ( 255.0 * invertedBrightness ) / BRIGHTEST_STAR );
    return sf::Color(shadeOfGray, shadeOfGray, shadeOfGray);
}