#include <iostream>

using std::string;

class Megaphone{
public:
	void printToUpperCase(char **msg)
	{
		for (int i = 0; msg[i]; i++)
		{
			for (int j = 0; msg[i][j]; j++)
				std::cout << (char)toupper(msg[i][j]);
		}
		std::cout << std::endl ;
	}

	void printDefaultMessage()
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
};

int main(int ac, char **av)	
{
	Megaphone megaphone;
	if (ac > 1)
		megaphone.printToUpperCase(++av);
	else
		megaphone.printDefaultMessage();
	return 0;
};
