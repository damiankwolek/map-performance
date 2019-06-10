#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <unordered_map>
#include "02.map_common.h"
#include "person.h"

using namespace person;

int main(int, char **)
{
    {
        std::unordered_map<int, int> numbers;
        for (int i=0;i<10;++i)
            numbers[i] = i*10;
        print(numbers);
    }

    {
        std::map<int, Person> people;
        for (int i=0;i<10;++i)
        {
            auto p = get_random_person();
            people[p.age] = p;
        }
        print(people);
    }

    {
        std::unordered_map<int, Person> people;
        for (int i=0;i<10;++i)
        {
            auto p = get_random_person();
            people.emplace(p.age, p);
        }
        print(people);
    }

    {
        std::unordered_map<Person, int, PersonHash> people;
        for (int i=0;i<10;++i)
        {
            auto p = get_random_person();
            people.emplace(p, p.age);
        }
        print(people);
    }
    // zadanie dla chetnych, 
    // co trzeba zmienić, aby poniższa definicja (bez jawnego PersonHash) 
    // zadziałała
    {
        // poniższy kod aktualnie się nie kompiluje
        // std::unordered_map<Person, int> people; 
    }
}
