#pragma once
#include "MovementStrategy.h"


namespace corsim
{
    class RegularMovementStrategy : public MovementStrategy
    {
    public:
        int movement(int dt, std::vector<Subject>& subjects, int count);
    };
}