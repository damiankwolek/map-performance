#include <string>
#include <map>
#include <iostream>

struct Pet
{
    std::string name;
	Pet(const std::string& s) : name(s) { }
//  Pet() = default;
//  Pet(){};
};

void part_1(void) {
    std::map<int, Pet> pets;

    pets.emplace(0, Pet("Pies Azor"));
    pets.insert(std::make_pair(1, Pet("Kot Miauczek")));
//    pets[2] = Pet("Kura Dziobek"); // default constructor needed for this

    for (const auto & pet : pets) {
        std::cout << pet.first << " - " << pet.second.name << std::endl;
    }

    pets.emplace(2, Pet("Pies Azor"));
    pets.emplace(3, Pet("Pies Azor"));

    std::string s("Pies Azor");
    for (auto pet = pets.begin(); pet != pets.end(); ) {
        if (pet->second.name == s) {
            pet = pets.erase(pet);
        } else {
            ++pet;
        }
    }
    
    for (const auto & pet : pets) {
        std::cout << pet.first << " - " << pet.second.name << std::endl;
    }
}

struct PetCmp 
{
    bool operator()(const Pet &lhs, const Pet &rhs)
    {
        return (lhs.name.compare(rhs.name));
    };
};

void part_2(void) {
   
    std::map<Pet, int, PetCmp> pets;

    pets.emplace(Pet("Pies Azor"), 0); // PetCmd needed for this
    pets.insert(std::make_pair(Pet("Kot Miauczek"), 1));
    pets[Pet("Kura Dziobek")] = 2;

    for (const auto & pet : pets) {
        std::cout << pet.first.name << " - " << pet.second << std::endl;
    }
}

int main()
{
    part_1();
    part_2();
	return 0;
}
