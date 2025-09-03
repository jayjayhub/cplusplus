#pragma once

#include "AdTypes.h"

namespace Ad {

class Utils {
 public:
  float kph_to_mps(const float kph);
};

class Data {
 public:
  Ad::Types::VehicleType init_ego_vehicle();
};

class Visualize {
 public:
  void print_vehicle(const Ad::Types::VehicleType vehicle);
};

};  // namespace Ad
