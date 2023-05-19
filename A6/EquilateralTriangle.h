#ifndef EQUILATERALTRIANGLE_H
#define EQUILATERALTRIANGLE_H

#include <SFML/Graphics.hpp>
#include "Triangle.h"

class EquilateralTriangle : public Triangle {
    public:
    bool setCoordinates(Position v1, Position v2, Position v3) override;
};

#endif