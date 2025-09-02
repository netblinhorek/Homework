#pragma once

class Point {
private:
    float x;
    float y;
    float radius;

public:
    Point(const float _x = 0.0f, const float _y = 0.0f, const float _radius = 0.0f);

    void calculating_the_radius();

    float get_x() const;
    float get_y() const;
    float get_radius() const;

    void set_x(float new_x);
    void set_y(float new_y);

    float distance_to(const Point& other) const;
    bool operator==(const Point& other) const;
};

