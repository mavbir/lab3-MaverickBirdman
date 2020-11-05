#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "transportujFlota.hpp"

TEST_CASE("test", "[]")
{
    for (size_t towar = 40; towar < 1000; towar += 13) {
        const auto transported = transportujFlota(towar);
        CHECK(transported == CountThis< Zaglowiec >::get());
        CHECK(towar <= Stocznia::getTotalCap());

        CountThis< Zaglowiec >::reset();
        Stocznia::resetTotalCap();
    }
}
