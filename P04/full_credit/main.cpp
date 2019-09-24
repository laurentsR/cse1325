#include <iostream>
#include <vector>
#include "coach.h"
#include "locomotive.h"
#include "stock.h"
#include "train.h"

/*
	READ ME: I've been working around bugs for about 6 hours now and I haven't made any real progress. 
	I'm giving up. I know it isn't finished and doesn't run, I'm sorry!
*/

int main()
{
	Train test;
	bool exit = false;
	int locoCount = 0;
	int coachCount = 0;
	//std::vector<std::vector> result(6, std::vector(" "));
	
	while(exit != true)
	{
		int command;
		
		
		std::cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\t\t   The Inheritance Express\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << std::endl;
		
		std::cout << "\n 1 - Add a locomotive\n 2 - Add an empty coach\n 9 - Clear the train\n 0 - EXIT\n\n Command?\n " << std::endl;
		std::cin >> command;
		if(command == 0)
		{
			std::cout << "\n||| T E R M I N A T I N G  P R O G R A M |||\n" << std::endl;
			exit = true;
		}
		else if(command == 1)
		{
			Locomotive newLoco(80000, 13500);
			test.add_locomotive(newLoco);
			locoCount++;
		}
		else if(command == 2)
		{

		}
		else if(command == 9)
		{
		
		}
		else
		{
			std::cout << "\nI'm sorry, that is an unknown command. Please try a new input.\n" << std::endl;
		}
		
	}
}

