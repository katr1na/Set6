#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <SFML/Graphics.hpp>
#include "Position.h"

class Triangle {
    public:
    /**
     * @brief sets the color to white
     * specifies the number of vertices as 3
     * allocates the list to have three elements (if necessary)
     */
    Triangle();
    /**
     * @brief deallocates the list (if necessary)
     */
    virtual ~Triangle();
    /**
     * @brief sets the private color data member
     * 
     * @param color 
     */
    void setColor(const sf::Color color);
    /**
     * @brief creates a ConvexShape
     * sets the points for each coordinate
     * sets the fill color
     * draws it to the provided window
     * @param window 
     */
    void draw(sf::RenderTarget& window);
    /**
     * @brief accepts the (x, y) coordinate for three vertices
     * 
     * @return true 
     * @return false 
     */
    virtual bool setCoordinates(Position v1, Position v2, Position v3) = 0;

    protected:
    int mNumVertices; // number of vertices on triangle
    Position* mPCoorList; // list of (x,y) coordinates

    private:
    sf::Color mTriangleColor; // color of triangle
};

#endif