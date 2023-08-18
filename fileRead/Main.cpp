#include <iostream>;
#include <fstream>;
#include <string>;


//https://cplusplus.com/doc/tutorial/files/
//https://www.geeksforgeeks.org/getline-string-c/
//https://www.digitalocean.com/community/tutorials/convert-string-to-char-array-c-plus-plus
//http://www.java2s.com/ref/cpp/cpp-fstream-read-text-file-character-by-character.html
//https://stackoverflow.com/questions/10712117/how-to-count-the-characters-in-a-text-file
//https://docs.oracle.com/cd/E19059-01/wrkshp50/805-4948/z40002b41acb/index.html

class charInfo {
	public:
		char character;
		int lineNum;
};

int main() {
	std::string line;
	std::fstream file;
	file.open("example.txt");
	file.seekg(0, std::ios::end);
	int endPos = file.tellg();
	//std::cout << endPos << "\n";
	
	//Allocates this much memory for the dynamic array charList
	
	charInfo* charList = (charInfo*)malloc(endPos * sizeof(charInfo));
	
	file.seekg(0, std::ios::beg);
	int charCount = 0;
	int lineCount = 0;
	while (getline(file, line))
	{
		for (int c = 0; c < line.length(); c++) {
			charInfo cInfo;
			cInfo.character = line[c];
			cInfo.lineNum = lineCount;
			charList[charCount] = cInfo;
			charCount++;
		}
		lineCount++;
	}

	std::cout << "Enter search term" << "\n";

	std::string searchTerm;
	std::cin >> searchTerm;

	//Because searchTerm can be any length, need to malloc that too

	charInfo* searchArray = (charInfo*)malloc(searchTerm.length() * sizeof(charInfo));

	//Still need to lowercase the search and charlist characters
	for (int d = 0; d < endPos; d++) {
		if (d+searchTerm.length()-1<endPos) {
			for (int c = 0; c < searchTerm.length(); c++) {
				if (searchTerm[c] != charList[d + c].character) {
					break;
				}
				searchArray[c] = charList[d + c];
				//std::cout << "C " << c << "\n";
				//std::cout << "D " << d << "\n";
				if (c == searchTerm.length()-1) {
					//These will be the line numbers that the search term appears in
					std::cout << searchArray[c].lineNum << "\n";
				}
			}
		}
	}

	/*
	for (int b = 0; b < sizeof(searchArray)/sizeof(charInfo*); b++) {
		std::cout << searchArray[b].lineNum << "\n";
	}
	*/
	
	/*
	for (int b = 0; b < searchTerm.length(); b++) {
		for (int d = 0; d < charCount; d++) {
			if (charList[d].lineNum == searchArray[b].lineNum) {
				std::cout << charList[d].character;
			}
		}
		std::cout << "\n";
	}
	*/
	std::cout << "\n";
	free(searchArray);
	free(charList);
	file.close();
	return 0;
}