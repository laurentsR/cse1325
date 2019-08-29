#include <iostream>
#include <cstdlib>

int main()
{
	const char* userName = std::getenv("USER");
	std::string yesNo;
	
	std::cout << "::Hello, " << userName << "!" << std::endl;
	std::cout << "::That is your name, isn't it? [Y/N] " << std::endl;
	std::getline(std::cin, yesNo);
	if(yesNo == "Y")
	{
		std::cout << "::That's great! I'm glad I got it on the first try. (I don't really have any other ideas..)" << std::endl;
	}
	else if(yesNo == "N")
	{
		std::cout << "::Well that's too bad! I gave it my best shot. Are you sure that's not your name? Your file path says it is.." << std::endl;
	}
	else if(yesNo == "Maybe" || yesNo == "maybe")
	{
		std::cout << "::Smartass. I'm counting that as a yes." << std::endl;
	}
	else
	{
		std::cout << "::Woah woah, that's not an option you can type in! Not cool, I even gave you instructions." << std::endl;
	}
}
