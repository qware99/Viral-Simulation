#pragma once
#include <vector>
#include "simulation.h"

namespace corsim
{
    class MovementStrategy
    {
    public:
        virtual int movement(int dt, std::vector<Subject>& subjects int count) = 0;
    };

}