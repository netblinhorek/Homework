#pragma once

class Sphere: public Circle {
	float _first;
	float _second;


public:
	Sphere() = default;
	Sphere(const float, const float);
	Sphere(Sphere& other);


};