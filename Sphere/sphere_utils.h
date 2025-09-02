#pragma once
#include "Sphere.h"
#include <cmath>
#include <string>


//template<typename SphereT>
//std::string get_spheres_relation(const SphereT& s1, const SphereT& s2) {
//    float dx = s1.get_x() - s2.get_x();
//    float dy = s1.get_y() - s2.get_y();
//    float dz = s1.get_z() - s2.get_z();
//    float d = std::sqrt(dx * dx + dy * dy + dz * dz);
//    float r1 = s1.get_radius();
//    float r2 = s2.get_radius();
//    if (d == 0 && r1 == r2) return "Совпадают";
//    if (d == r1 + r2) return "Внешнее касание";
//    if (d == std::abs(r1 - r2) && d != 0) return "Внутреннее касание";
//    if (std::abs(r1 - r2) < d && d < r1 + r2) return "Пересекаются";
//    if (d < std::abs(r1 - r2)) return "Одна внутри другой";
//    return "Не пересекаются";
//}
