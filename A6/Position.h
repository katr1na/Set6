#ifndef POSITION_H
#define POSITION_H

struct Position {
    double x, y; // x and y coordinates of a vertice
    Position() {
        x = 0;
        y = 0;
    }
    Position(const double X, const double Y) {
        x = X;
        y = Y;
    }
};

#endif