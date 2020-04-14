#include <random>
#include "SortingAlgos.hpp"

int main()
{
    std::vector<int> v(50);
    std::generate(v.begin(), v.end(), std::rand);

    std::chrono::duration<double, std::milli> duration = sorting::Sort<int>(sorting::strategies::SELECTION_SORT, v);
    sorting::utilities::PrintElements<int>(v, duration, sorting::strategies::SELECTION_SORT);

    duration = sorting::Sort<int>(sorting::strategies::INSERTION_SORT, v);
    sorting::utilities::PrintElements<int>(v, duration, sorting::strategies::INSERTION_SORT);
    return 0;
}