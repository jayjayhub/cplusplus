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

void Ad::Visualize::print_vehicle(const Ad::Types::VehicleType &vehicle) {
  std::cout << "Vehicle ID: " << vehicle.id << "\n";
  std::cout << "Lane: " << static_cast<int>(vehicle.lane) << "\n";
  std::cout << "Speed: " << vehicle.speed << " m/s\n";
  std::cout << "Relative Distance: " << vehicle.relativeDistance << " m\n";
}

Ad::Types::VehicleType Ad::Data::init_vehicle(
    Ad::Types::VehicleType &vehicle, int id, float speed,
    float relativeDistance, Ad::Types::LaneAssociationType lane) {
  vehicle.id = id;
  vehicle.speed = speed;
  vehicle.relativeDistance = relativeDistance;
  vehicle.lane = lane;
  return vehicle;
}

Ad::Types::NeighborVehiclesType Ad::Data::init_vehicles() {
  Ad::Utils utils;
  auto vehicles = Ad::Types::NeighborVehiclesType{};
  init_vehicle(vehicles.leftLaneVehicles[0], 0, utils.kph_to_mps(80.0f), 20.0f,
               Ad::Types::LaneAssociationType::Left);
  init_vehicle(vehicles.leftLaneVehicles[1], 1, utils.kph_to_mps(30.0f), -40.0f,
               Ad::Types::LaneAssociationType::Left);
  init_vehicle(vehicles.centerLaneVehicles[0], 0, utils.kph_to_mps(20.0f),
               60.0f, Ad::Types::LaneAssociationType::Center);
  init_vehicle(vehicles.centerLaneVehicles[1], 1, utils.kph_to_mps(90.0f),
               -80.0f, Ad::Types::LaneAssociationType::Center);
  init_vehicle(vehicles.rightLaneVehicles[0], 0, utils.kph_to_mps(20.0f),
               -10.0f, Ad::Types::LaneAssociationType::Right);
  init_vehicle(vehicles.rightLaneVehicles[1], 1, utils.kph_to_mps(50.0f),
               -50.0f, Ad::Types::LaneAssociationType::Right);
  return vehicles;
}

void Ad::Visualize::print_vehicles(
    const std::vector<Ad::Types::VehicleType> &vehicles) {
  for (const auto &vehicle : vehicles) {
    print_vehicle(vehicle);
  }
}

void Ad::Visualize::print_neighbor_vehicles(
    const Ad::Types::NeighborVehiclesType &vehicles) {
  print_vehicles(std::vector<Ad::Types::VehicleType>(
      vehicles.leftLaneVehicles.begin(), vehicles.leftLaneVehicles.end()));
  print_vehicles(std::vector<Ad::Types::VehicleType>(
      vehicles.centerLaneVehicles.begin(), vehicles.centerLaneVehicles.end()));
  print_vehicles(std::vector<Ad::Types::VehicleType>(
      vehicles.rightLaneVehicles.begin(), vehicles.rightLaneVehicles.end()));
}

using namespace Ad::Constants;

void print_vehicle_on_lane(const Ad::Types::VehicleType *const vehicle,
                           const float range_m, const float offset_m,
                           std::string &string, std::size_t &idx) {
  if ((vehicle != nullptr) && (range_m >= vehicle->relativeDistance) &&
      (vehicle->relativeDistance > (range_m - offset_m))) {
    string[1] = 'V';
    idx++;
  } else if ((vehicle != nullptr) &&
             (std::abs(vehicle->relativeDistance) > VIEW_RANGE_M)) {
    idx++;
  }
}

void Ad::Visualize::print_scene(
    const Ad::Types::VehicleType &ego_vehicle,
    const Ad::Types::NeighborVehiclesType &vehicles) {
  // std::cout << "Ego Vehicle:\n";
  // print_vehicle(ego_vehicle);
  // std::cout << "Neighbor Vehicles:\n";
  // print_neighbor_vehicles(vehicles);
  std::cout << "    \t   L     C     R  \n";

  auto left_idx = std::size_t{0};
  auto center_idx = std::size_t{0};
  auto right_idx = std::size_t{0};

  const auto offset_m = std::int32_t{20};
  const auto view_range_m = static_cast<std::int32_t>(VIEW_RANGE_M);

  for (auto i = view_range_m; i >= -view_range_m; i -= offset_m) {
    const auto range_m = static_cast<float>(i);

    auto left_string = std::string{"   "};
    auto center_string = std::string{"   "};
    auto right_string = std::string{"   "};

    if ((range_m >= ego_vehicle.relativeDistance) &&
        (ego_vehicle.relativeDistance > (range_m - offset_m))) {
      center_string[1] = 'E';
    }

    if (left_idx < NUM_VEHICLES_ON_LANE) {
      print_vehicle_on_lane(&vehicles.leftLaneVehicles[left_idx], range_m,
                            offset_m, left_string, left_idx);
    }
    if (center_idx < NUM_VEHICLES_ON_LANE) {
      print_vehicle_on_lane(&vehicles.centerLaneVehicles[center_idx], range_m,
                            offset_m, center_string, center_idx);
    }
    if (right_idx < NUM_VEHICLES_ON_LANE) {
      print_vehicle_on_lane(&vehicles.rightLaneVehicles[right_idx], range_m,
                            offset_m, right_string, right_idx);
    }

    std::cout << i << "\t| " << left_string << " | " << center_string << " | "
              << right_string << " | \n";
  }
}