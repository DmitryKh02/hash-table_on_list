#pragma once
#include <string>

class POLYNOM {
	int* letters;
	int size;
public:
	POLYNOM(std::string polynom) {
		size = polynom.size();
		letters = new int[size];

		for (size_t i = 0; i < size; i++)
			letters[i] = polynom[i];
		

		/*size = polynom.size();
		root = polynom[size - 1] - '0';
		if (polynom[size - 2] == '-') root *= -1;

		int count = 0;
		for (size_t i = 0; i < size-2; i++)
			if (polynom[i] >= '0' && polynom[i] <= '9') count++;

		coefficient = new int[count];
		int j = 0;

		for (size_t i = 0; i < size - 2; i++) {
			if (polynom[i] >= '0' && polynom[i] <= '9') {
				coefficient[j] = polynom[i] - '0';
				if (i != 0 && polynom[i - 1] == '-') coefficient[j] *= -1;
				j++;
			}
		}
		size = count;
		for (j = 0; j < count; j++)
		{
			std::cout << coefficient[j] << " ";
		}*/
	};

	~POLYNOM() {
		delete[] letters;
	};

	int hashPolynom() {
		int mult = letters[0];
		for (size_t i = 1 ; i < size-1; i++){
		
			mult = mult * 2 + letters[i];
		}
		return abs(mult);
	};
};


