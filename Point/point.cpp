#include "point.h"
#include <stdexcept>
#include <cmath>
#include <random>

Point::Point(const float _x, const float _y, const float _radius) {
    if (_radius < 0) {
        throw std::invalid_argument("˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜ ˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜˜˜˜");
    }

    x = _x;
    y = _y;
    radius = _radius;
}

void Point::calculating_the_radius() {
    radius = std::sqrt(x * x + y * y);
}

float Point::get_x() const {
    return x;
}

float Point::get_y() const {
    return y;
}

float Point::get_radius() const {
    return radius;
}

void Point::set_x(float new_x) {
    x = new_x;
}

void Point::set_y(float new_y) {
    y = new_y;
}

float Point::distance_to(const Point& other) const {
    float dx = x - other.x;
    float dy = y - other.y;
    return std::sqrt(dx * dx + dy * dy);
}

bool Point::operator==(const Point& other) const {
    return x == other.x && y == other.y && radius == other.radius;
}