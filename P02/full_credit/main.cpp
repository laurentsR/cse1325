//Ryan Laurents - 09/16/2019 - HW 02: Averages
#include "average.h"
#include "average.cpp"
#include <iostream>
#include <cstdlib>


int main()
{
	Average test(0,0);
	bool exit = false;
	
	
	while(exit != true)
	{
		int command;
		int newVal;
		int random;
		std::cout << "     =========================\n" << "     Merely Average Calculator\n" << "     =========================\n" << " The current average is: " << test << "\n 1 - Enter a new value\n" << " 2 - Auto enter a random value\n" << " 9 - Clear the calculator\n" << " 0 - Exit\n\n" << " Command?\n\n";
		std::cin >> command;
		if (command == 0)
		{
			exit = true;
			std::cout << "\n::T E R M I N A T I N G  P R O G R A M::\n";
		}
		else if (command == 1)
		{
			std::cout << " Please enter a value: ";
			std::cin >> newVal;
			std::cout << "\n";
			test._sum += newVal;
			test._values++;
		}
		else if (command == 2)
		{
			random = rand() % 100;
			std::cout << " Random value rolled was: " << random << ". Computing...\n\n";
			test._sum += random;
			test._values++;
		}
		else if (command == 9)
		{
			test._sum = 0;
			test._values = 0;
			std:: cout << " Wiping memory...\n\n";
		}
		else if (command < 0)
		{
			std::cout << " Why such a negative Nancy?? Stay Positive! :)\n\n";
		}
		else if (command == 69)
		{
			std::cout << " Hey.. keep your mind out of the gutter.\n\n";
		}
		else if (command == 100)
		{
			std::cout << " 100.. just like my grade for this homework right?? :D\n\n";
		}
		else if (command == 420)
		{
			std::cout << " Even though it's our mascots name, you can't do that here.\n\n";
		}
		else
		{
			std::cout << "\n Sorry, you've entered an invalid command. Please try again.\n\n";
		}
	}
	
}

