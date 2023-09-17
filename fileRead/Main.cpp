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
	
	file.clear();
	file.seekg(0, std::ios::beg);

	file.clear();
	int charCount = 0;
	int lineCount = 0;
	file.seekg(0, std::ios::beg);
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

	std::cout << "Enter a search term" << "\n";

	std::string searchTerm;
	std::cin >> searchTerm;

	//int* foundList = (int*)malloc(lineCount * sizeof(int));

	//lineCount = 0;
	//int* foundList = (int*)malloc(sizeof(int));

	int* foundList = (int*) malloc(sizeof(int));
	int foundListLength = 1;

	int sameCount = 0;
	int currentLine = 0;
	int c = 0;
	int firstCharOfThisLine = 0;
	int searchLines = 0;

	while (c < endPos) {
		if (c > 0) {
			if (charList[c].lineNum != charList[c - 1].lineNum) {
				lineCount++;
				firstCharOfThisLine = charList[c].lineNum;
			}
		}
		for (int d = 0; d < searchTerm.length(); d++) {
			if (tolower(charList[c + d].character) == tolower(searchTerm[d])) {
				sameCount++;
			}
		}
		if (sameCount == searchTerm.length()) {
			currentLine = charList[c].lineNum;
		} else {
			sameCount = 0;
		}
		if (currentLine == charList[c].lineNum) {
			int* newFoundList = (int*)malloc((foundListLength + 1) * (sizeof(int)));
			for (int i = 0; i < foundListLength; i++) {
				newFoundList[i] = foundList[i];
			}
			newFoundList[foundListLength - 1] = charList[c].lineNum;
			foundList = newFoundList;
			foundListLength++;

			searchLines++;
		}
		c++;
	}

	for (int i = 0; i < foundListLength-1; i++) {
		if (i > 0) {
			if (foundList[i] != foundList[i - 1]) {
				std::cout << foundList[i] << "\n";
			}
		}
		else {
			std::cout << foundList[i] << "\n";
		}
	}

	std::cout << "\n";
	free(foundList);
	free(charList);
	file.close();
	return 0;
}