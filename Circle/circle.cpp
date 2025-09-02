#pragma once
#include "circle.h"
#include <stdexcept>
#include <cmath>
#include "../Point/point.h"

template<typename CircleT>
std::string get_circles_relation(const CircleT& c1, const CircleT& c2) {
    float dx = c1.get_x() - c2.get_x();
    float dy = c1.get_y() - c2.get_y();
    float d = std::sqrt(dx * dx + dy * dy);
    float r1 = c1.get_radius();
    float r2 = c2.get_radius();
    if (d == 0 && r1 == r2)
    {
        return "Совпадают";
    }

    if (d == r1 + r2) {
        return "Внешнее касание";
    }
    if (d == std::abs(r1 - r2) && d != 0) {
        return "Внутреннее касание";
    }
    if (std::abs(r1 - r2) < d && d < r1 + r2) {
        return "Пересекаются";
    }
    if (d < std::abs(r1 - r2)) {
        return "Одна внутри другой";
    }
    return "Не пересекаются";
} 

Circle::Circle(const float x, const float y, const float radius)
    : _x(x), _y(y), _radius(radius) {

    if (radius < 0) {
        throw std::invalid_argument("Радиус не может быть отрицательным");
    }
}

Circle::Circle(const Point& center, float radius)
    : _x(center.get_x()), _y(center.get_y()), _radius(radius) {
    if (radius < 0) {
        throw std::invalid_argument("Радиус не может быть отрицательным");
    }
}

float Circle::get_x() const {
    return _x;
}

float Circle::get_y() const {
    return _y;
}

float Circle::get_radius() const {
    return _radius;
}

Point Circle::get_center() const {
    return Point(_x, _y);
}

void Circle::set_x(float new_x) {
    _x = new_x;
}

void Circle::set_y(float new_y) {
    _y = new_y;
}

void Circle::set_radius(float new_radius) {
    if (new_radius < 0) {
        throw std::invalid_argument("Радиус не может быть отрицательным");
    }
    _radius = new_radius;
}