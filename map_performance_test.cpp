#include <string>
#include <cstdlib>
#include <string>
#include <array>
#include <ctime>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <chrono>
#include <map>
#include <iomanip>


class timer
{
public:
    timer(const std::string& name) : m_name(name) {m_start = std::chrono::system_clock::now();}
    ~timer()
    {
        auto end = std::chrono::system_clock::now();

        std::chrono::duration<double> elapsed_seconds = end-m_start;
 
        std::cout << m_name << " time: " << elapsed_seconds.count() << " s\n";
    }
private:
    std::string m_name;
    std::chrono::time_point<std::chrono::system_clock> m_start;

};

class Person {

public:
    Person(const std::string& name, const std::string& surname, int age ) : m_name(name), m_surname(surname), m_age(age){}

    friend std::ostream& operator<<(std::ostream& out, const Person& person);

    std::string m_name;
    std::string m_surname;
    int m_age;
};

std::ostream& operator<<(std::ostream& out, const Person& person)
{
    out << person.m_name << " " << person.m_surname << " : " << person.m_age << " lat\n";

    return out;
}

Person generate_person()
{
    std::array<std::string, 10> names = {"Donald", "Jarosław", "Hermenegilda", "Genowefa", "Krzystof", "Seba", "Jessica", "Karol", "Wojciech", "Hans"};
    std::array<std::string, 10> surnames = {"Hitler", "Tusk", "Stalin", "Kaczyński", "Petru", "Macierewicz", "Kowalski", "Nowak", "Kwolek", "Brzęczyszczykiewicz"};

    return Person(names[std::rand() % names.size()], surnames[std::rand()%surnames.size()], std::rand());
}

struct PersonHash
{
    std::size_t operator()(const Person& p) const noexcept
    {
        std::size_t h1 = std::hash<std::string>{}(p.m_name);
        std::size_t h2 = std::hash<int>{}(p.m_age);

        return h1 ^ h2;
    }
};

bool operator==(const Person& lhs, const Person& rhs)
{
    return lhs.m_age == rhs.m_age && lhs.m_name == rhs.m_name && lhs.m_surname == rhs.m_surname ;
}

bool operator<(const Person& lhs, const Person& rhs)
{
    return lhs.m_age < rhs.m_age || lhs.m_name < rhs.m_name || lhs.m_surname < rhs.m_surname;
}

Person wanted_person("Grzegorz", "Brzęczyszczykiewicz", 33);
Person fictional_person("Wally", "Waldo", 0);

template<class T>
void prepare_map(T& map, unsigned n)
{
    map.clear();
    timer t("\t\tpreparation");
    map.insert(std::make_pair(wanted_person, 0));
    
    while (map.size() < n) {
        map.insert(std::make_pair(generate_person(), std::rand()));
    }
}

template<class T>
void test_insert(T& map)
{
    timer t("\t\tinsert");
    map.insert(std::make_pair(generate_person(), std::rand()));
}

template<class T>
void test_find(const T& map)
{
    {
        timer t("\t\tsuccessful search");
        map.find(wanted_person);
    }
    {
        timer t("\t\tunsuccessful search");
        map.find(fictional_person);
    }
    
}

template<class T>
void test_erase(T& map)
{
    timer t("\t\terase");
    map.erase(wanted_person);
}

int main()
{
    std::srand(std::time(nullptr));

    std::vector<unsigned> sizes = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

    std::map<Person, int> map;
    std::unordered_map<Person, int, PersonHash> unordered_map;

    for (auto n : sizes)
    {
        std::cout << "n = " << n << std::endl;
        
        std::cout << "\tmap\n";
        prepare_map(map, n);
        test_insert(map);
        test_find(map);
        test_erase(map);
        
        std::cout << "\tunordered_map\n";
        prepare_map(unordered_map, n);
        test_insert(unordered_map);
        test_find(unordered_map);
        test_erase(unordered_map);
    }
    
    
}