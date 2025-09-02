#include "Sphere.h"
#include <stdexcept>
#include <cmath>
#include "../Point3D/point3d.h"

template<typename SphereT>
std::string get_spheres_relation(const SphereT& s1, const SphereT& s2) {
    float dx = s1.get_x() - s2.get_x();
    float dy = s1.get_y() - s2.get_y();
    float dz = s1.get_z() - s2.get_z();
    float d = std::sqrt(dx * dx + dy * dy + dz * dz);
    float r1 = s1.get_radius();
    float r2 = s2.get_radius();
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

Sphere::Sphere(const float x, const float y, const float z, const float radius)
    : _x(x), _y(y), _z(z), _radius(radius) {

    if (radius < 0) {
        throw std::invalid_argument("Радиус не может быть отрицательным");
    }
}

Sphere::Sphere(const Point3D& center, float radius)
    : _x(center.get_x()), _y(center.get_y()), _z(center.get_z()), _radius(radius) {
    if (radius < 0) {
        throw std::invalid_argument("Радиус не может быть отрицательным");
    }
}

float Sphere::get_x() const {
    return _x;
}

float Sphere::get_y() const {
    return _y;
}

float Sphere::get_z() const {
    return _z;
}

float Sphere::get_radius() const {
    return _radius;
}

Point3D Sphere::get_center() const {
    return Point3D(_x, _y, _z);
}

void Sphere::set_x(float new_x) {
    _x = new_x;
}

void Sphere::set_y(float new_y) {
    _y = new_y;
}

void Sphere::set_z(float new_z) {
    _z = new_z;
}

void Sphere::set_radius(float new_radius) {
    if (new_radius < 0) {
        throw std::invalid_argument("Радиус не может быть отрицательным");
    }
    _radius = new_radius;
}
