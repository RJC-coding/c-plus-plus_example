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

	std::cout << "Enter search term" << "\n";

	std::string searchTerm;
	std::cin >> searchTerm;

	//int* foundList = (int*)malloc(lineCount * sizeof(int));

	lineCount = 1;
	int* foundList = (int*)malloc(lineCount * sizeof(int));

	int sameCount = 0;
	int currentLine = 0;
	int c = 0;
	int firstCharOfThisLine = 0;
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
			//Needs more work, but potential is there.
			int* newFoundList = (int*)malloc(lineCount * sizeof(int));
			for (int x = 0; x < lineCount; x++) {
				newFoundList[x] = foundList[x];
			}
			newFoundList[lineCount - 1] = charList[c].lineNum;
			foundList = newFoundList;
			//std::cout << charList[c].character;
			//std::cout << lineList[linePos] << "\n";
		}
		c++;
	}

	for (int i = 0; i < lineCount; i++) {
		std::cout << foundList[i];
	}

	std::cout << "\n";
	free(charList);
	file.close();
	return 0;
}