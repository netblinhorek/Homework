#pragma once
#include "point3d.h"
class Sphere {
    float _x;
    float _y;
    float _z;
    float _radius;
public:
    Sphere() = default;
    Sphere(const float x, const float y, const float z, const float radius);
    Sphere(const Point3D& center, float radius);

    float get_x() const;
    float get_y() const;
    float get_z() const;
    float get_radius() const;
    Point3D get_center() const;

    void set_x(float new_x);
    void set_y(float new_y);
    void set_z(float new_z);
    void set_radius(float new_radius);
};