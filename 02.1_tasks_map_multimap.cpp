#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "02.map_common.h"

void map_example(void) {

	std::map<std::string, int> coding {{"alfa", 1}, {"beta", 3}};
	print_map(coding);

	coding.emplace("gamma", 2);
	print_map(coding);

	coding.emplace("gamma", 3);
	print_map(coding);

	coding["gamma"] = 4;
	print_map(coding);

    	coding["gamma"] += 5;
	print_map(coding);
}

void multimap_example(void) {
    std::multimap<std::string, int> coding {{"multi_alfa", 1}, {"beta", 3}};

    print_map(coding);

    coding.emplace("delta", 4);
    print_map(coding);
    
    coding.emplace("delta", 5);
    print_map(coding);

    // no match - as there might be multiple elements with such key
    //coding["zet"]+=1; 
}



void multimap_equal_range_example(void) {
    std::multimap<int, std::string> coding;

    coding.emplace(1,"multimap_equal_zet");
    coding.emplace(1,"delta");
    coding.emplace(2,"delta1");
    coding.emplace(2,"delta1");
    coding.emplace(1,"beta");

    print_map(coding);

    print_map_equal_method_1(coding,1);
    print_map_equal_method_2(coding,2);
    print_map_lower_bound(coding,2);
    print_map_upper_bound(coding,2);
}

int main()
{
	map_example();
	multimap_example();
	multimap_equal_range_example();
}


