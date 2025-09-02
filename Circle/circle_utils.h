#pragma once
#include "circle.h"
#include <cmath>
#include <string>

// Упрощённая функция для определения взаимного расположения двух окружностей
// Возвращает строку с описанием

template<typename CircleT>
std::string get_circles_relation(const CircleT& c1, const CircleT& c2) {
    float dx = c1.get_x() - c2.get_x();
    float dy = c1.get_y() - c2.get_y();
    float d = std::sqrt(dx * dx + dy * dy);
    float r1 = c1.get_radius();
    float r2 = c2.get_radius();
    if (d == 0 && r1 == r2) return "Совпадают";
    if (d == r1 + r2) return "Внешнее касание";
    if (d == std::abs(r1 - r2) && d != 0) return "Внутреннее касание";
    if (std::abs(r1 - r2) < d && d < r1 + r2) return "Пересекаются";
    if (d < std::abs(r1 - r2)) return "Одна внутри другой";
    return "Не пересекаются";
} 