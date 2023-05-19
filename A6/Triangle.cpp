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
using namespace sf;

Triangle::Triangle() {
    mTriangleColor = Color::White;
    mNumVertices = 3;
    mPCoorList = new Position[3];
}

Triangle::~Triangle() {
    delete[] mPCoorList;
}

void Triangle::setColor(const Color COLOR) {
    mTriangleColor = COLOR;
}

void Triangle::draw(RenderTarget& window) {
    ConvexShape triangle;
    triangle.setFillColor(mTriangleColor);
    triangle.setPointCount(mNumVertices);
    triangle.setPoint(0, Vector2f(mPCoorList[0].x, mPCoorList[0].y));
    triangle.setPoint(1, Vector2f(mPCoorList[1].x, mPCoorList[1].y));
    triangle.setPoint(2, Vector2f(mPCoorList[2].x, mPCoorList[2].y));
    window.draw(triangle);
}