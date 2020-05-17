#include "LockdownMovementStrategy.h"

namespace corsim
{
	int LockdownMovementStrategy::movement(int dt, std::vector<Subject>& subjects int count)
	{
		if (run == NULL) 
		{
			int amount = subjects.size() / 4 * 3;

			for (int i = 0; i < amount; i++)
			{
				subjects.at(i).SetLocked(true)
			}

			run = true
		}

		int numberInfected = 0;
		for (Subject& s : subjects)
		{
			if (s.getLocked() != true)
			{
				s.set_x(s.x() + s.dx() * dt);
				s.set_y(s.y() + s.dy() * dt);
			}
			if (s.infected())
			{
				numberInfected++;
			}
		}
		return numberInfected;
	}
}