#pragma once
#include "../Point/point.h"
class Circle {
    float _x;
    float _y;
    float _radius;

public:
    Circle() = default;
    Circle(const float x, const float y, const float radius);
    Circle(const Point& center, float radius);

    float get_x() const;
    float get_y() const;
    float get_radius() const;
    Point get_center() const;

    void set_x(float new_x);
    void set_y(float new_y);
    void set_radius(float new_radius);
};