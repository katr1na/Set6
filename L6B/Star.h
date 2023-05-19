#ifndef STAR_H
#define STAR_H

#include <SFML/Graphics.hpp>

class Star {
    public:
    /**
     * @brief Construct a new Star object setting all members to 0
     * 
     */
    Star();
    /**
     * @brief Construct a new Star object setting all members accordingly
     * 
     * @param X 
     * @param Y 
     * @param VALUE 
     */
    Star(const float X, const float Y, const float VALUE);
    /**
     * @brief return x coordinate of star
     * 
     * @return double 
     */
    double getXCoor() const;
    /**
     * @brief return y coordinate of star
     * 
     * @return double 
     */
    double getYCoor() const;
    /**
     * @brief return brightness value of star
     * 
     * @return double 
     */
    double getBrightness() const;
    /**
     * @brief set x coordinate of star to X
     * 
     * @param X 
     */
    void setXCoor(const float X);
    /**
     * @brief set y coordinate of star to Y
     * 
     * @param Y 
     */
    void setYCoor(const float Y);
    /**
     * @brief set brightness value of star to VALUE
     * 
     * @param VALUE 
     */
    void setBrightness(const float VALUE);
    /**
     * @brief return the raw star x coordinate transformed in to the window coordinate
     * 
     * @param WIDTH 
     * @return float 
     */
    float getTransformedX(const int WIDTH) const;
    /**
     * @brief return the raw star y coordinate transformed in to the window coordinate
     * 
     * @param HEIGHT 
     * @return float 
     */
    float getTransformedY(const int HEIGHT) const;
    /**
     * @brief create the grayscale Color object in RGB
     * 
     * @param BRIGHTEST_STAR 
     * @return sf::Color 
     */
    sf::Color getGrayscaleColor(const float BRIGHTEST_STAR);

    private:
    float mXStar; //x coordinate of star
    float mYStar; // y coordinate of star
    float mBrightness; // brightness value of star
};

#endif