#pragma once
#include "circle.h"
#include <cmath>
#include <string>

// ���������� ������� ��� ����������� ��������� ������������ ���� �����������
// ���������� ������ � ���������

template<typename CircleT>
std::string get_circles_relation(const CircleT& c1, const CircleT& c2) {
    float dx = c1.get_x() - c2.get_x();
    float dy = c1.get_y() - c2.get_y();
    float d = std::sqrt(dx * dx + dy * dy);
    float r1 = c1.get_radius();
    float r2 = c2.get_radius();
    if (d == 0 && r1 == r2) return "���������";
    if (d == r1 + r2) return "������� �������";
    if (d == std::abs(r1 - r2) && d != 0) return "���������� �������";
    if (std::abs(r1 - r2) < d && d < r1 + r2) return "������������";
    if (d < std::abs(r1 - r2)) return "���� ������ ������";
    return "�� ������������";
} 