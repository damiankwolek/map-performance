#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include "02.map_common.h"

int main(int, char **)
{
    std::ifstream file;
    file.open (__FILE__);

    // read file and put to map
    std::map<std::string, int> coding;
    std::string word;
    while (file >> word)     {
	    coding[word]+=1;
    }
    print(coding);

    // put values to multimap
    std::multimap<int, std::string> multi_coding;
    for (const auto &elem: coding) {
	    multi_coding.emplace(elem.second, elem.first);
    }
    print(multi_coding);

    print_map_equal_method_1(multi_coding,2);
    print_map_equal_method_2(multi_coding,2);
    print_map_lower_bound(multi_coding,2);
    print_map_upper_bound(multi_coding,2);
}
