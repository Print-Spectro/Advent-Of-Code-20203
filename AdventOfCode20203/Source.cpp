#include <iostream>
#include <string>
#include <fstream>

bool compare(char st) {
	char numbers[10]{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	for (auto i : numbers) {
		if (i == st) {
			return 1;
			}
		}
	return 0;
}

int day1puzzle1() {
	std::string filename{R"(C:\Users\franc\source\repos\AdventOfCode20203\AdventOfCode20203\Day1Input.txt)"};
	std::ifstream file{filename};
	if (!file.is_open()) {
		std::cout << "Could Not Open File" << std::endl;
		return 0;
	}
	std::string row{};
	int total{};
	while (std::getline(file, row)) {
		std::string rownums{};
		for (char i : row) {
			if (compare(i)) {
				rownums += i;
			}
		}
		std::string number{};
		number += rownums[0];
		number += rownums[rownums.length() - 1];
		total += std::stoi(number);
	}
	return total;
}


int main() {
	std::cout << day1puzzle1();
}