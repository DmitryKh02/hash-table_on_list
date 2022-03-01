#include "Table.h"

int main()
{
	int countElements = 0;
	std::cout << "Enter count elements in table: ";
	std::cin >> countElements;

	HASH_TABLE<std::string> table(countElements * 2);
	std::string example;

	for (size_t i = 0; i < countElements; i++) {
		std::cout << "\nEnter your world: ";
		//std::cout << "\nYou need to enter elements in this form: a0,a1,a2,...an;x\nWhere a is coefficient, x is root: ";
		std::cin >> example;
		table.push(example);
	}

	table.print();

	std::cin.ignore().get();
	return 0;
}