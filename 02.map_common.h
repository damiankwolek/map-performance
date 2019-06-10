#include <map>
#include <string>
#include <iostream>

template <class MapType>
void print(const MapType & map) {
	for (const auto &elem : map) {
		std::cout << elem.first 
			  << " -  " << elem.second << "\n";
	}
}

template <class MapType>
void print_map(const MapType & map) {
	for (const auto &elem : map) {
		std::cout << "\"" << elem.first 
			  << " " << elem.second << "\" ";
	}
	std::cout << std::endl;
}

template
<class TypeMap, class Type>
void print_map_equal_method_1(const TypeMap & map, const Type & value) {
	std::cout << "Equal_range:\n";
	auto key = map.equal_range(value);
	for (auto it = key.first; it != key.second; ++it) {
		std::cout << it->first << ":" << it->second << " ";
	}
	std::cout << "\n";
}

template
<class TypeMap, class Type>
void print_map_equal_method_2(const TypeMap & map, const Type & value) {
	std::cout << "Equal_range:\n";
        auto key = map.equal_range(value);
        while (key.first!=key.second) {
            std::cout << key.first->first << ":" << key.first->second << " ";
            ++key.first;
        }
	std::cout << "\n";
 }

template
<class TypeMap, class Type>
void print_map_lower_bound(const TypeMap & map, const Type & value) {
	std::cout << "Lower bound\n";
        auto key = map.lower_bound(value);
        while (key!=map.end()) {
            std::cout << key->first << ":" << key->second << " ";
            ++key;
        }
	std::cout << "\n";
 }

template
<class TypeMap, class Type>
void print_map_upper_bound(const TypeMap & map, const Type & value) {
	std::cout << "upper bound\n";
        auto key = map.upper_bound(value);
        while (key!=map.end()) {
            std::cout << key->first << ":" << key->second << " ";
            ++key;
        }
	std::cout << "\n";
 }
