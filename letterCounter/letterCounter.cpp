#include <iostream>
#include <cctype>

int main()
{
    std::cout << "Enter a word." << "\n";
    char word[100];
    std::cin.getline(word, sizeof(word));

    int counter = 0;

    for (int i = 0; i < sizeof(word); i++) {
        char c = tolower(word[i]);
        int ascii = int(c);
        if (ascii >= 97 & ascii <= 122){
            counter++;
        }
    }
    std::cout << "This phrase has " << counter << " letters. \n";
    return 0;
}
