#ifndef __PERSON_H
#define __PERSON_H

#include <iostream>
#include <vector>
#include <unordered_map>

namespace person {

class Person {
    public:
        std::string name;
        int age;
        long long pesel;

        Person() = default;

        Person(const std::string & _name, const int _age, const long long _pesel):
            name(_name),age(_age),pesel(_pesel){};

        friend std::ostream& operator<< (std::ostream& s,const Person & p)
        {
            s << p.name << " " << p.age << " " << p.pesel;
            return s;
        };
};

bool operator==(const Person& lhs, const Person& rhs) {
    return (lhs.name == rhs.name) &&
           (lhs.age == rhs.age) &&
           (lhs.pesel == rhs.pesel);
}

struct PersonHash
{
    std::size_t operator()(Person const& p) const noexcept
    {
        std::size_t h1 = std::hash<std::string>{}(p.name);
        std::size_t h2 = std::hash<int>{}(p.age);
        std::size_t h3 = std::hash<long long>{}(p.pesel);
        return h1 ^ (h2 > 1) ^ (h3 > 2);
    }
};

Person get_random_person()
{
    std::vector<std::string> names{"Tomek", "Marcin", "Ania"};
    Person p(names[std::rand()%3],std::rand()%90, std::rand());
    return p;
}

} //namespace person

#endif 
