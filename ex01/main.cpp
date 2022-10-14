#include "iter.hpp"

int	main(void)
{
	std::cout << std::endl;
	std::cout << " *** Incrementing all integers of an array *** " << std::endl;
	int	i[5] = {0, 1, 2, 3, 4};
	::iter(i, 5, &plusOne);
	for (int j = 0; j < 5; j++)
		std::cout << i[j];
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << " *** Incrementing all characters of an array *** " << std::endl;
	char	c[5] = {'a', 'b', 'c', 'd', 'e'};
	::iter(c, 5, &plusOne);
	for (int j = 0; j < 5; j++)
		std::cout << c[j];
	std::cout << std::endl;

	std::cout << std::endl;
	return (0);
}
