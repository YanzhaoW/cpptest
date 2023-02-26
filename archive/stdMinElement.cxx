#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// #include <iterator>

class A{
    public:
        A(double a): value{a}
        {}
        double value;
};

int main() {

    std::vector<A> vec = {A{9.4}, A{8.5}, A{1.8}, A{76.5}};
    auto it = std::min_element(vec.begin(), vec.end(), [](A& left, A& right){
            return left.value <  right.value;
            });
    std::cout << "index: " << static_cast<int>(it - vec.begin()) << std::endl;
    std::cout << "value: " << it->value << std::endl;


    return 0;
}
