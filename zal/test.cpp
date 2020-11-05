#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "transportujFlota.hpp"

#include <algorithm>
#include <array>
#include <random>

TEST_CASE("test", "[]")
{
    constexpr size_t                    n_cases   = 100;
    constexpr auto                      min_towar = 100u;
    constexpr auto                      max_towar = 1000u;
    std::array< unsigned int, n_cases > towary;
    std::mt19937                        mt{std::random_device{}()};
    std::generate(towary.begin(), towary.end(), [&]() {
        return std::uniform_int_distribution< unsigned int >{min_towar, max_towar}(mt);
    });
    for (const auto& towar : towary) {
        const auto transported = transportujFlota(towar);
        CHECK(transported == CountThis< Zaglowiec >::get());
        CHECK(towar <= Stocznia::getTotalCap());

        CountThis< Zaglowiec >::reset();
        Stocznia::resetTotalCap();
    }
}
