#include <iostream>
#include <string>
#include <vector>
#include <map>
 
int main()
{
    std::map<std::string, int> coding {{"alfa", 1}, {"beta", 3}};
 
    std::cout << "start:\n";
    for (const auto &pair : coding) {
        std::cout << pair.first << ": " << pair.second << '\n';
    }
 
    coding["gamma"] = 3;
    coding["beta"] = 2;

    coding.emplace("delta", 4);

    coding["theta"]+=1;
    coding["theta"]+=1;
 
    std::cout << "stop:\n";
    for (const auto &pair : coding) {
        std::cout << pair.first << ": " << pair.second << '\n';
    }
}


