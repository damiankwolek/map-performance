#include "timer.h"
 
long fibonacci(unsigned n)
{
    if (n < 2) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

void classic(int, char ** argv) {
    unsigned long long input = std::stoull(argv[1]);

    auto start = std::chrono::system_clock::now();
    std::cout << "f(" << input << ") = " << fibonacci(input) << '\n';
    auto end = std::chrono::system_clock::now();
 
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
 
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
}

void own_timer(int, char ** argv) {
    unsigned long long input = std::stoull(argv[1]);
    {
        timer::timer t("my_timer");
        std::cout << "f(" << input << ") = " << fibonacci(input) << '\n';
    }
}
 
int main(int argc, char ** argv)
{
    classic(argc,argv);
    own_timer(argc, argv);
}

