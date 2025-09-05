#pragma once

#include <array>
#include <cstdint>

#include "AdConstants.h"

namespace Ad {
namespace Types {
enum class LaneAssociationType { Unknown, Left, Center, Right };
struct VehicleType {
  int id;
  LaneAssociationType lane;
  float speed;
  float relativeDistance;
};

using namespace Ad::Constants;
struct NeighborVehiclesType {
  std::array<VehicleType, NUM_VEHICLES_ON_LANE> leftLaneVehicles{};
  std::array<VehicleType, NUM_VEHICLES_ON_LANE> centerLaneVehicles{};
  std::array<VehicleType, NUM_VEHICLES_ON_LANE> rightLaneVehicles{};
};
};  // namespace Types
};  // namespace Ad