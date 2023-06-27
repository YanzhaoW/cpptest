#include <chrono>
#include <future>
#include <iostream>
#include <mutex>
#include <optional>
#include <ranges>
#include <regex>
#include <set>
#include <string_view>
#include <thread>
#include <vector>

class Iter {
public:
  using difference_type = std::ptrdiff_t;
  using value_type = int;
  using pointer = int *;
  using reference = int &;
  using iterator_category = std::forward_iterator_tag;

  auto operator++() -> Iter & {
    auto temp = sum;
    sum += i;
    i = temp;
    return *this;
  }
  auto operator++(int) -> Iter {
    auto tmp = *this;
    ++*this;
    return tmp;
  }
  auto operator*() const -> const auto & { return sum; }

  auto operator-(const Iter &other) const -> int { return i - other.i; }
  auto operator==(const Iter &) const -> bool = default;

private:
  int i = 0;
  int sum = 1;
};
template <int limit> class Senti {
public:
  friend auto operator==(Iter val, Senti /*sen*/) -> bool {
    return *val >= limit;
  }
};
constexpr int limit = 100;
// constexpr auto fab = std::ranges::subrange<Iter, Senti<limit>>{};
constexpr auto fab = std::ranges::subrange<Iter, std::unreachable_sentinel_t>{};

auto main() -> int {
  constexpr int num = 3;
  constexpr int divider = 5;
  auto filter = [&divider](auto val) { return val % divider == 0; };
  for (const auto &iter :
       fab | std::ranges::views::filter(filter) | std::views::take(num)) {
    std::cout << iter << "\n";
  }
}
