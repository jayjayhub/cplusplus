#include <cstdint>
#include <iostream>
#include <vector>

// Type aliases as specified
using It = std::vector<std::int32_t>::iterator;
using DifferenceType = It::difference_type;

namespace mystd {

void advance(It &it, DifferenceType n) {
  // For random access iterators (like vector), we can use arithmetic directly
  // This is O(1) - constant time operation
  it += n;
}

DifferenceType distance(It first, It last) {
  // For random access iterators, this is simple subtraction
  // Returns positive if last > first, negative if first > last
  return last - first;
}

It next(It it, DifferenceType n = 1) {
  // Creates a copy and advances it
  // Note: we're not modifying the original iterator
  it += n;
  return it;
}

It prev(It it, DifferenceType n = 1) {
  // Creates a copy and moves it backward
  // Note: we're not modifying the original iterator
  it -= n;
  return it;
}
}  // namespace mystd