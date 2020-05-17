#include "SocialLockdown.h"

namespace corsim
{
	int SocialLockdown::movement(int dt, std::vector<Subject> &subjects, int count)
	{
		int halfOfPopulation = subjects.size() * 0.5;
		int restrictedPopulation = subjects.size() * 0.75;
		int dtSlow = dt * 1 / 3;
		int numberInfected = 0;
		
		for (int i = 0; i < restrictedPopulation; i++) 
		{
			subjects.at(i).setSlow(true);
		}

		for (Subject& s : subjects) 
		{
			if (s.infected()) 
			{
				numberInfected++;
			}
			if (numberInfected < halfOfPopulation) 
			{
				s.set_x(s.x() + s.dx() * dt);
				s.set_y(s.y() + s.dy() * dt);
			}
			else if (numberInfected > halfOfPopulation) 
			{
				if (s.getSlow() == true)
				{
					s.set_x(s.x() + s.dx() * dtSlow);
					s.set_y(s.y() + s.dy() * dtSlow);
				}
				else
				{
					s.set_x(s.x() + s.dx() * dt);
					s.set_y(s.y() + s.dy() * dt);
				}
			}
		}
		return numberInfected;
	}
}