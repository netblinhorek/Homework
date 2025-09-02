#pragma once

class Point3D {
private:
    float x;
    float y;
    float z;
    float radius;

public:
    Point3D(const float _x = 0.0f, const float _y = 0.0f, const float _z = 0.0f, const float _radius = 0.0f);

    void calculating_the_radius();

    float get_x() const;
    float get_y() const;
    float get_z() const;
    float get_radius() const;

    void set_x(float new_x);
    void set_y(float new_y);
    void set_z(float new_z);

    float distance_to(const Point3D& other) const;
    bool operator==(const Point3D& other) const;
};
