#pragma once

#include "ObjCounter.hpp"

struct Statek
{
    virtual unsigned int transportuj() = 0;
};

class Zaglowiec : Statek, CountThis< Zaglowiec >
{
public:
    unsigned int transportuj() override { return capacity; }

    friend struct Stocznia;

private:
    Zaglowiec(const unsigned int c) : capacity{c} {}
    unsigned int capacity;
};

class Tankowiec : Statek
{
public:
    unsigned int transportuj() override { return capacity; }

    friend struct Stocznia;

private:
    Tankowiec(const unsigned int c) : capacity{c} {}
    unsigned int capacity;
};
