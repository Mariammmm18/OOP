#include <iostream>
#include "function.h"
#include <cassert>

namespace test
{
std::vector<int> map(std::vector<int> numbers, std::function<int(int)> fun)
{
    std::vector<int> result;
    for (int i = 0; i < size(numbers); i++)
    {
        result.push_back(fun(numbers[i]));
    }
    return result;
}

std::vector<int> filter(std::vector<int> numbers, std::function<bool(int)> funn)
{
    std::vector<int> result;
    for (int i = 0; i < size(numbers); i++)
    {
        if (funn(numbers[i])==true)
        result.push_back (numbers[i]);
    }
    return result;
}
}

void tests()
{
    std::vector<int> test = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    std::vector<int> massiv = { 1, 4, 9, 16, 25, 36, 49, 64, 81 };
    assert(test::map(test, [](int x) {return x * x; })==massiv);

    std::vector<int> tested = {  2,  4,  6, 8 };
    assert(test::filter(test, [](int x) {if (x % 2 == 0) return true; else return false; })==tested);
}
int main()
{
    tests();
    std::cout << "tests OK";
    return 0;
}
