#pragma once

#include <random>

#include "Statki.hpp"

struct Stocznia
{
    Statek* operator()() const
    {
        static std::mt19937 mt{std::random_device{}()};
        if (std::uniform_int_distribution< unsigned >{0, 1}(mt)) {
            constexpr unsigned int zagl_min = 10;
            constexpr unsigned int zagl_max = 20;
            const auto cap = std::uniform_int_distribution< unsigned int >{zagl_min, zagl_max}(mt);
            total_cap += cap;
            return new Zaglowiec{cap};
        }
        else {
            constexpr unsigned int tank_min = 16;
            constexpr unsigned int tank_max = 50;
            const auto cap = std::uniform_int_distribution< unsigned int >{tank_min, tank_max}(mt);
            total_cap += cap;
            return new Tankowiec{cap};
        }
    }

    static unsigned int getTotalCap() { return total_cap; }
    static void         resetTotalCap() { total_cap = 0; }

private:
    static unsigned int total_cap;
};

unsigned int Stocznia::total_cap = 0;
