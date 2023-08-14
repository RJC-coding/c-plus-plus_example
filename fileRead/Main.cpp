#include <iostream>;
#include <fstream>;
#include <string>;

//https://cplusplus.com/doc/tutorial/files/
//https://www.geeksforgeeks.org/getline-string-c/

int main() {
	std::string line;
	std::fstream file;
	file.open("example.txt");
	while (getline(file, line))
	{
		std::cout << line << "\n";
	}
	file.close();
	return 0;
}