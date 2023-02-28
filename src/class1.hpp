#ifndef CLASS1_HPP
#define CLASS1_HPP

void PrintSomething();

template <typename T>
class MyClass
{
  public:
    MyClass() = default;

    MyClass(const T& p_a, const T& p_b)
        : ma{ p_a }
        , mb{ p_b }
    {
    }

    auto Add() -> T { return ma + mb; }

  private:
    T ma{};
    T mb{};
    T* m;
};

class Product
{
  public:
    Product(double p_1, double p_2)
        : m1(p_1)
        , m2(p_2)
    {
    }
    [[nodiscard]] static auto Get() -> double { return 0; }

  private:
    double m1{};
    double m2{};
};

#endif
