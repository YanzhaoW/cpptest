#include "class1.hpp"
#include <array>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

auto main() -> int
{
    const size_t vec_size = 10;
    auto vec = std::vector<int>(vec_size);
    for (const int iter : vec)
    {
        std::cout << iter << std::endl;
    }
    const int value = 0;
    return 0;
}
