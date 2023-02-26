#include <iostream>
#include <string>
#include <vector>
// #include <algorithm>
// #include <iterator>

class A{
    public:
        A()
        {
            std::cout << "default construction of A index: " << index << std::endl;
        }
        A(int i) : index{i}
        {
            std::cout << "construction of A index: " << i << std::endl;
        }
        A(const A& copy):index(copy.index)
        {
            std::cout << "copy constructor of A index: " << index << std::endl;
        }
        ~A()
        {
            std::cout << "destruction of A index: " << index << std::endl;
        }
        A& operator=(const A& other)
        {
            index = other.index;
            return *this;
            std::cout << "copy assignment of A index: " << index << std::endl;
        }

        A Add(int i)
        {
            return A{index + i};
        }

        void print () const
        {
            std::cout << "index: " << index << std::endl;
        }
    private:
        int index = 0;
};

int main() {


    auto vec = std::vector<A>{};
    vec.clear();
    auto size = int{3};
    vec.reserve(size);
    for(auto i = 0; i < size; i++)
    {
        vec.emplace_back(i);
    }

    auto vec2 = std::vector<A>{};
    vec2.reserve(size);
    std::transform(vec.begin(), vec.end(), std::back_inserter(vec2), [](A& a){ return a.Add(100);});

    auto vec3 = vec2;


    return 0;
}
