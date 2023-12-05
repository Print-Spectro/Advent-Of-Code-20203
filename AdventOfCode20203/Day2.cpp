#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <tuple>


bool colourcheck(const std::string row, const std::tuple<int, std::string> i, const int parse_pos = 0)
{
	auto pos{ row.find(std::get<1>(i), parse_pos) };
	if (pos != std::string::npos) {
		std::string temp{""};
		temp += row[pos - 3];
		temp += row[pos - 2];
		int number_drawn = std::stoi(temp);
		int testvalue = std::get<0>(i);
		if (number_drawn > std::get<0>(i)) {
			return 1;
		}
		else {
			int(position) = static_cast<int>(pos + 2);
			return colourcheck(row, i, position);
		}
	}
	return 0;
}

int colourparse(const std::string row) {
	std::vector<std::tuple<int, std::string>> colours{{12, "red"}, { 13, "green" }, { 14, "blue"}};
	for (std::tuple<int, std::string> i : colours) {
		if (colourcheck(row, i)) {
			return 0;
		}
	}
	return 1;
}

int day2() {
	std::string filename{R"(C:\Users\franc\source\repos\AdventOfCode20203\AdventOfCode20203\Day2Input.txt)"};
	std::ifstream file{filename};
	if (!file.is_open()) {
		return 0;
	}

	std::string row{};
	int rowcount{1};
	int total{0};
	while (std::getline(file, row)) {
		
		 if (colourparse(row)) {
		 total+= rowcount;
		 std::cout << rowcount << std::endl;
		 }
		
		rowcount++;
	}
	return total;
}


int main() {
	std::cout << day2();
}


