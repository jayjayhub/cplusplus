#pragma once

#include <vector>

#include "AdTypes.h"

namespace Ad {

class Utils {
 public:
  float kph_to_mps(const float kph);
};

class Data {
 public:
  Ad::Types::VehicleType init_ego_vehicle();
  Ad::Types::NeighborVehiclesType init_vehicles();
  Ad::Types::VehicleType init_vehicle(Ad::Types::VehicleType &vehicle, int id,
                                      float speed, float relativeDistance,
                                      Ad::Types::LaneAssociationType lane);
};

class Visualize {
 public:
  void print_vehicle(const Ad::Types::VehicleType &vehicle);
  void print_vehicles(const std::vector<Ad::Types::VehicleType> &vehicles);
  void print_neighbor_vehicles(const Ad::Types::NeighborVehiclesType &vehicles);
  void print_scene(const Ad::Types::VehicleType &ego_vehicle,
                   const Ad::Types::NeighborVehiclesType &vehicles);
};

};  // namespace Ad
