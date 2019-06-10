#include <map>
#include <unordered_map>
#include <vector>
#include "person.h"
#include "timer.h"
#include <algorithm>
#include <numeric>

// przyklad dla (integer mapowany na Person)
template <class Map>
void prepare_people_map(Map & map, const long elems_no)
{
    for (int i=0;i<elems_no;++i) {
        person::Person p(person::get_random_person());
        map.emplace(i*10 , p);// dzięki zakodowaniu klucza w ten sposób 0,10,20 wiemy jakie id mamy na mapie
    }
}

// przyklad dla szukania odpowiednich osob, pseudokod
template <class Map>
void test_find_for_people(Map & map, std::vector<long long> ids)
{
    std::vector<int64_t> times;

    for (int i = 0; i < 5; ++i)
    {
        auto t_start = std::chrono::steady_clock::now();
        
        for (auto id : ids)
            map.find(id);
        
        auto t_end = std::chrono::steady_clock::now();

        times.push_back(std::chrono::duration_cast<std::chrono::seconds>(t_end - t_start).count());
    }

    std::sort(times.begin(), times.end());
    times.pop_back();
    times.erase(times.begin());

    auto avg = std::accumulate(times.begin(), times.end(), 0) / times.size(); 

    std::cout << "Find test = " << avg << " s";
        // start_time();
        // for (id : ids) map.find(id);
        // stop_time()
        // czas do wektora V
    // sort(V)
    // usunac poczatek/koniec, wyciągnąć średnią, wypisać
}



int main(int argc, char ** argv)
{
    const int N = 100000000;

   {
        std::map<long ,person::Person> m1;
        prepare_people_map(m1,N);
        std::vector<long long> ids;

        for (int i = 0; i < N; ++i)
            ids.push_back(i * 10);

        test_find_for_people(m1, ids);
        // ...
    }
    {
        std::unordered_map<int,person::Person> m1;
        // powtarzamy jak wyzej
    }
}

