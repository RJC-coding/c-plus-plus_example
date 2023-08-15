#include <iostream>;
#include <fstream>;
#include <string>;


//https://cplusplus.com/doc/tutorial/files/
//https://www.geeksforgeeks.org/getline-string-c/
//https://www.digitalocean.com/community/tutorials/convert-string-to-char-array-c-plus-plus

int main() {
	std::string line;
	std::fstream file;
	std:char charList[] = "";
	file.open("example.txt");
	while (getline(file, line))
	{
		for (int c = 0; c < line.length(); c++) {
			std::cout << line[c];
		}
		std::cout << "\n";
	}
	file.close();
	return 0;
}