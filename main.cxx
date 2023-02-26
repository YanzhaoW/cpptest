#include <array>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

struct foo
{
    int a[3];
    int b;
};

auto main() -> int
{
    foo b;
    std::cout << b.a[3]++ << std::endl;
}
