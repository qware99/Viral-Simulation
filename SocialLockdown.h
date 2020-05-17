#pragma once
#include "MovementStrategy.h"


namespace corsim
{
    class SocialLockdown : public MovementStrategy
    {
    public:
        int movement(int dt, std::vector<Subject>& subjects, int count);
    private:
        bool run;
    };
}