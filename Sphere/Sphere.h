#pragma once
#include "Point3D.h"
#include <stdexcept>
#include <string>

class Sphere {
private:
    Point3D center;
    float radius;

public:
    // Конструкторы
    Sphere(float x = 0, float y = 0, float z = 0, float radius = 1);
    Sphere(const Point3D& center, float radius = 1);

    // Методы доступа
    Point3D get_center() const;
    float get_x() const;
    float get_y() const;
    float get_z() const;
    float get_radius() const;

    // Методы изменения
    void set_center(const Point3D& center);
    void set_x(float x);
    void set_y(float y);
    void set_z(float z);
    void set_radius(float radius);

    // Методы вычислений
    float calculate_distance_from_origin() const;
    float volume() const;
    float surface_area() const;

    // Операторы сравнения
    bool operator==(const Sphere& other) const;
    bool operator!=(const Sphere& other) const;
};
template<typename Sphere>
std::string get_spheres_relation(const Sphere& s1, const Sphere& s2);
