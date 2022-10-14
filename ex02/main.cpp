#include "Array.hpp"

int	main(void)
{
	std::cout << std::endl;
	std::cout << " *** Create an array of 5 integers *** " << std::endl;
	Array<int>	i(5);
	std::cout << "Setting all integers at 0..." << std::endl;
	for (int j = 0; j < 5; j++)
		i.setElement(j, 0);
	std::cout << "Checking the value of the last element: " << i[4] << std::endl;

	std::cout << std::endl;
	std::cout << " *** Trying to set an element out of bounds *** " << std::endl;
	try { i.setElement(5, 1); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << std::endl;
	std::cout << " *** Trying to get an element out of bounds *** " << std::endl;
	try { i[5]; }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << std::endl;
	std::cout << " *** Create an array of 5 characters *** " << std::endl;
	Array<char>	c(5);
	std::cout << "Setting all characters at 'a'..." << std::endl;
	for (int i = 0; i < 5; i++)
		c.setElement(i, 'a');
	std::cout << "Checking the value of the first element: " << c[0] << std::endl;

	std::cout << std::endl;
	std::cout << " *** Trying to set an element out of bounds *** " << std::endl;
	try { c.setElement(5, 'a'); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << std::endl;
	std::cout << " *** Trying to get an element out of bounds *** " << std::endl;
	try { c[5]; }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << std::endl;
	return (0);
}
