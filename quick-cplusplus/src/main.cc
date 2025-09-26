#include <algorithm>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>

#include "algo.hpp"
#include "utils.h"

int main() {
  auto vec1 = std::vector<std::int32_t>(5, 0);
  auto vec2 = std::vector<std::int32_t>(5, 0);
  std::cout << std::boolalpha
            << mystd::equal(vec1.begin(), vec1.end(), vec2.begin()) << '\n';

  std::cout << "Before: Vector 1: ";
  print_vector(vec1);
  mystd::fill_n(vec1.begin(), 5, 1);
  std::cout << "After: Vector 1: ";
  print_vector(vec1);
  mystd::iota(vec2.begin(), vec2.end(), 0);
  std::cout << "Vector 2: ";
  print_vector(vec2);

  mystd::copy(vec2.begin(), vec2.end(), vec1.begin());
  std::cout << "After copying from vector 2, Vector 1: ";
  print_vector(vec1);
  std::cout << std::boolalpha
            << mystd::equal(vec1.begin(), vec1.end(), vec2.begin()) << '\n';

  const auto sum = mystd::accumulate(vec1.begin(), vec1.end(), 0);
  std::cout << sum << '\n';

  return 0;
}
