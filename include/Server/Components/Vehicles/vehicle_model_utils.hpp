#pragma once

#include "vehicles.hpp"
#include <types.hpp>

namespace Impl
{

/// Efficient handling for unlimited vehicle models (400-100000)
/// Models 400-611: Full detailed data stored
/// Models 612-100000: Return sensible defaults without memory overhead
class VehicleModelUtils
{
public:
	/// Maximum supported vehicle model ID
	static constexpr int MAX_MODEL_ID = 100000;
	
	/// Minimum vehicle model ID
	static constexpr int MIN_MODEL_ID = 400;
	
	/// The boundary where we transition from detailed to default data
	static constexpr int DETAILED_DATA_MAX = 611;
	
	/// Total number of models with detailed data
	static constexpr int DETAILED_MODEL_COUNT = DETAILED_DATA_MAX - MIN_MODEL_ID + 1;
	
	/// Total number of extended models (using defaults)
	static constexpr int EXTENDED_MODEL_COUNT = MAX_MODEL_ID - DETAILED_DATA_MAX;
	
	/// Check if model uses detailed data or defaults
	static inline bool usesDetailedData(int modelid)
	{
		return modelid >= MIN_MODEL_ID && modelid <= DETAILED_DATA_MAX;
	}
	
	/// Check if model uses default data (extended range)
	static inline bool isExtendedModel(int modelid)
	{
		return modelid > DETAILED_DATA_MAX && modelid <= MAX_MODEL_ID;
	}
	
	/// Get default seat count for extend models
	static inline uint8_t getDefaultSeats()
	{
		return 0;  // Driver only
	}
	
	/// Get default color for extended models
	static inline void getDefaultColours(uint32_t& colour1, uint32_t& colour2, uint32_t& colour3, uint32_t& colour4)
	{
		colour1 = colour2 = colour3 = colour4 = 127;  // Default gray
	}
	
	/// Get array index for model data (for models 400-611 only)
	static inline int getDataIndex(int modelid)
	{
		return modelid - MIN_MODEL_ID;
	}
};

}  // namespace Impl
