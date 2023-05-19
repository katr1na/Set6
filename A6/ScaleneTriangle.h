#ifndef SCALENETRIANGLE_H
#define SCALENETRIANGLE_H

#include <SFML/Graphics.hpp>
#include "Triangle.h"

class ScaleneTriangle : public Triangle {
    public:
    bool setCoordinates(Position v1, Position v2, Position v3) override;
};

#endif