#include <iostream>
#include "function.h"
#include <cassert>

namespace functions
{
    std::vector<int> map(std::vector<int> numbers, std::function<int(int)> fun1)
    {
        std::vector<int> result;
        for (int i = 0; i < size(numbers); i++)
        {
            result.push_back(fun1(numbers[i]));
        }
        return result;
    }
    
    std::vector<int> filter(std::vector<int> numbers, std::function<bool(int)> fun2)
    {
        std::vector<int> result;
        for (int i = 0; i < size(numbers); i++)
        {
            if (fun2(numbers[i])==true)
            result.push_back (numbers[i]);
        }
        return result;
    }
}

