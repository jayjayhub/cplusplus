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
  visualize.print_neighbor_vehicles(data.init_vehicles());
  visualize.print_scene(ego_vehicle, data.init_vehicles());
  return 0;
}
