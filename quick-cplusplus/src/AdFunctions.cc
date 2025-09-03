#include "AdFunctions.h"

#include <cmath>
#include <cstdint>
#include <iostream>

#include "AdConstants.h"

float Ad::Utils::kph_to_mps(const float kph) { return kph * 1000.0f / 3600.0f; }

Ad::Types::VehicleType Ad::Data::init_ego_vehicle() {
  Ad::Types::VehicleType vehicleType;
  vehicleType.id = -1;
  vehicleType.lane = Ad::Types::LaneAssociationType::Center;
  vehicleType.speed = 135.0f;
  vehicleType.relativeDistance = 0.0f;
  return vehicleType;
}

void Ad::Visualize::print_vehicle(const Ad::Types::VehicleType vehicle) {
  std::cout << "Vehicle ID: " << vehicle.id << "\n";
  std::cout << "Lane: " << static_cast<int>(vehicle.lane) << "\n";
  std::cout << "Speed: " << vehicle.speed << " m/s\n";
  std::cout << "Relative Distance: " << vehicle.relativeDistance << " m\n";
}
