#include "circle.h"
#include "point.h"
#include "point3d.h"
#include "Sphere.h"
#include "../Circle/circle_utils.h"
#include <iostream>
#include <iostream>
#include <cassert>
#include <iostream>
#include <string>
#include <sstream>  
#include <stdexcept> 
#include <cstdio>
#include <Windows.h>
#include <chrono>
#include <fcntl.h>
#include <io.h>

#define STEP_OF_CAPACITY 15

void set_color(int text_color, int bg_color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bg_color << 4) | text_color);
}

namespace TestSystem {
    int count_success = 0, count_failed = 0;

    void start_test(bool(*test)(), const char* name_of_test) {
        set_color(2, 0);
        std::cout << "[ RUN      ]";
        set_color(7, 0);
        std::cout << name_of_test << std::endl;

        try {
            test();
            set_color(2, 0);
            std::cout << "[       OK ]" << std::endl;
            count_success++;
        }
        catch (const std::exception& e) {
            set_color(4, 0);
            std::cout << "[  FAILED  ] " << e.what() << std::endl;
            count_failed++;
        }
        set_color(7, 0);
    }

    template <class T>
    bool check(const T& expected, const T& actual) {
        if (expected == actual) {
            return true;
        }
        std::stringstream ss;
        ss << "Ожидаемый результат: " << expected << ", фактический результат: " << actual << ".";
        throw std::runtime_error(ss.str());
    }

    void print_init_info() {
        set_color(2, 0);
        std::cout << "[==========] " << std::endl;
        set_color(7, 0);
    }

    void print_final_info() {
        set_color(2, 0);
        std::cout << "[==========] ";
        set_color(7, 0);
        std::cout << count_success + count_failed << " test" << (count_success + count_failed > 1 ? "s" : "") << " ran." << std::endl;
        set_color(2, 0);
        std::cout << "[  PASSED  ] ";
        set_color(7, 0);
        std::cout << count_success << " test" << (count_success > 1 ? "s" : "") << std::endl;
        if (count_failed > 0) {
            set_color(4, 0);
            std::cout << "[  FAILED  ] ";
            set_color(7, 0);
            std::cout << count_failed << " test" << (count_failed > 1 ? "." : ".") << std::endl;
        }
    }
};

enum Status { coincide, Success, Fail };

bool test_circles_coincide() {
    Circle c1(0, 0, 5), c2(0, 0, 5);
    return TestSystem::check(std::string("Совпадают"), get_circles_relation(c1, c2));
}

bool test_circles_externally_touch() {
    Circle c1(0, 0, 5), c2(10, 0, 5);
    return TestSystem::check(std::string("Внешнее касание"), get_circles_relation(c1, c2));
}

bool test_circles_internally_touch() {
    Circle c1(0, 0, 5), c2(3, 0, 2);
    return TestSystem::check(std::string("Внутреннее касание"), get_circles_relation(c1, c2));
}

bool test_circles_intersect() {
    Circle c1(0, 0, 5), c2(6, 0, 5);
    return TestSystem::check(std::string("Пересекаются"), get_circles_relation(c1, c2));
}

bool test_circles_one_inside_another() {
    Circle c1(0, 0, 5), c2(1, 0, 2);
    return TestSystem::check(std::string("Одна внутри другой"), get_circles_relation(c1, c2));
}

bool test_circles_separate() {
    Circle c1(0, 0, 5), c2(20, 0, 5);
    return TestSystem::check(std::string("Не пересекаются"), get_circles_relation(c1, c2));
}

int main() {
	setlocale(LC_ALL, "Russian");
    TestSystem::print_init_info();
    TestSystem::start_test(test_circles_coincide, "Circle.test_circles_coincide");
    TestSystem::start_test(test_circles_externally_touch, "Circle.test_circles_externally_touch");
    TestSystem::start_test(test_circles_internally_touch, "Circle.test_circles_internally_touch");
    TestSystem::start_test(test_circles_intersect, "Circle.test_circles_intersect");
    TestSystem::start_test(test_circles_one_inside_another, "Circle.test_circles_one_inside_another");
    TestSystem::start_test(test_circles_separate, "Circle.test_circles_separate");
    TestSystem::print_final_info();

    return 0;
}