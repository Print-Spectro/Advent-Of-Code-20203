#include <iostream>
#include <string>
#include <fstream>
#include <tuple>
#include <vector>
#include <algorithm>

bool compare(char st) {
	char numbers[9]{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	for (auto i : numbers) {
		if (i == st) {
			return 1;
			}
		}
	return 0;
}

void numberinsert(std::string &line) { //fuck off
	std::string numbers[10]{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	int index{1};

	for (std::string i : numbers) {
		std::string templine{""};
		auto pos{ line.find(i) };
		if (pos!=std::string::npos) {
			for (int j{ 0 }; j <= pos-1; j++) {
				templine += line[j];
			}
			templine += std::to_string(index);
			int numberlength = i.length();
			int position = pos;
			int linelength = line.length();
			for (int j{ position + numberlength }; j < linelength; j++) {
				templine += line[j];
			}
		line = templine;
		}
	index++;
	
	}
}

void numberparse(std::vector<std::tuple<int, std::string>> & rownums, std::string row, std::string i, int number, int parse_pos = 0) {
	auto pos{ row.find(i, parse_pos) };
	if (pos != std::string::npos) {
		int(position) = static_cast<int>(pos);
		rownums.push_back({ position, std::to_string(number) });
		numberparse(rownums, row, i, number, position+1);
	}
}

std::string rowparse(std::string row) { //takes each row and extracts all the numbers in order
	std::string numbers[9]{ "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	std::vector<std::tuple<int, std::string>> rownums;
	int number{1};
	for (std::string i : numbers) {
		numberparse(rownums, row, i, number, 0);
		number++;
	}
	int index{0};
	for (char j : row) {
		if (compare(j)) {
			std::string temp{j};
			rownums.push_back({index, temp});
		}
		index ++;
	}
	std::sort(rownums.begin(), rownums.end());
	std::string return_string{};
	for (auto i : rownums) {
		return_string += std::get<1>(i);
	}
	return return_string;
}

int day1puzzle() {
	std::string filename{R"(C:\Users\franc\source\repos\AdventOfCode20203\AdventOfCode20203\Day1Input.txt)"};
	std::ifstream file{filename};
	if (!file.is_open()) {
		std::cout << "Could Not Open File" << std::endl;
		return 0;
	}
	std::string row{};
	int total{};
	while (std::getline(file, row)) {
		std::string rownums{rowparse(row)};
		std::string number{};
		number += rownums[0];
		number += rownums[rownums.length() - 1];
		total += std::stoi(number);
		std::cout << number << std::endl;
	}
	return total;
}


int main() {
	std::cout << day1puzzle();
}