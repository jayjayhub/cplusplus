#include <cstring>
#include <iostream>
#include <numeric>

#include "AdFunctions.h"
#include "AdTypes.h"

int main() {
  Ad::Data data;
  auto ego_vehicle = data.init_ego_vehicle();
  Ad::Visualize visualize;
  visualize.print_vehicle(ego_vehicle);
  return 0;
}
