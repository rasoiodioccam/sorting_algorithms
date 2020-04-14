#ifndef SORTING_ALGOS_HPP
#define SORING_ALGOS_HPP

#include <chrono>
#include <algorithm>
#include <vector>
#include <iostream>

namespace sorting
{
enum class strategies
{
    SELECTION_SORT,
    INSERTION_SORT,
    MERGE_SORT,
    QUICK_SORT
};

template <typename T>
std::chrono::duration<double, std::milli> SelectionSort(std::vector<T> &elements)
{
    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < elements.size(); i++)
    {
        size_t min = i;
        for (size_t j = i; j < elements.size(); j++)
            if (elements.at(j) < elements.at(min))
                min = j;
        std::swap(elements.at(i), elements.at(min));
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration{end - start};
    return duration;
}
// Insertion Sort
template <typename T>
std::chrono::duration<double, std::milli> InsertionSort(std::vector<T> &elements)
{
    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 1; i < elements.size(); i++)
    {
        T temp = elements.at(i);
        size_t j = i;
        for (; j > i && elements.at(j - 1) > temp; j--)
            elements.at(j) = elements.at(j - 1);
        elements.at(j) = temp;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration{end - start};
    return duration;
}

template <typename T>
std::chrono::duration<double, std::milli> Sort(strategies strategy, std::vector<T> &vector_to_order)
{
    std::chrono::duration<double, std::milli> duration{0.0};
    switch (strategy)
    {
    case strategies::SELECTION_SORT:
        duration = SelectionSort(vector_to_order); //O(n^2)
        break;
    case strategies::INSERTION_SORT:
        duration = InsertionSort(vector_to_order); //O(n^2)
    default:
        break;
    }
    return duration;
}

namespace utilities
{
template <typename T>
void PrintElements(const std::vector<T> &elements, const std::chrono::duration<double, std::milli> &duration, strategies strategy)
{
    std::cout << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "result with ";
    switch (strategy)
    {
    case sorting::strategies::SELECTION_SORT:
        std::cout << "SELECTION SORT" << std::endl;
        break;
    case sorting::strategies::INSERTION_SORT:
        std::cout << "INSERTION SORT" << std::endl;
        break;
    default:
        break;
    }
    std::cout << std::endl;
    for (size_t i = 0; i < elements.size(); i++)
    {
        if (i == elements.size() - 1)
            std::cout << elements.at(i) << std::endl;
        else
            std::cout << elements.at(i) << ", ";
    }
    std::cout << std::endl;
    std::cout << "duration [ms] = " << duration.count() << "\n";
    std::cout << "----------------------------------------" << std::endl;
    std::cout << std::endl;
}

} //namespace utilities
} //namespace sorting
#endif // SORTING_ALGOS_HPP
