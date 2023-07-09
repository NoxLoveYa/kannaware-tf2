#pragma once
#include "../math/math.h"
#include "../types/types.h"

#include "IClientNetworkable.h"
#include "IClientEntity.h"
#include "IClientEntityList.h"

namespace interfaces
{
	extern IClientEntityList* entityList;

	template <typename T>
	extern T* GetInterface(const char* name, const char* module);
	
	void SetupInterfaces();
}