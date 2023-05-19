#ifndef ISOSCELESTRIANGLE_H
#define ISOSCELESTRIANGLE_H

#include <SFML/Graphics.hpp>
#include "Triangle.h"

class IsoscelesTriangle : public Triangle {
    public:
    bool setCoordinates(Position v1, Position v2, Position v3) override;
};

#endif