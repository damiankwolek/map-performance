#include <string>
#include <fstream>
#include <iostream>

int main(int, char **)
{
    std::ifstream file;
    file.open ("file_read.cpp");

    std::string word;
    while (file >> word)
    {
//        ...
        std::cout << word << "\n";
    }
}
