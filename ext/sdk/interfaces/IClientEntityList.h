#pragma once
#include "interfaces.h"

class IClientNetworkable;

class IClientEntityList
{
public:
	// Get IClientNetworkable interface for specified entity
	virtual IClientNetworkable* GetClientNetworkable(int entnum) = 0;
	virtual void* GetClientNetworkableFromHandle(unsigned long hEnt) = 0;
	virtual void* GetClientUnknownFromHandle(unsigned long hEnt) = 0;

	// NOTE: This function is only a convenience wrapper.
	// It returns GetClientNetworkable( entnum )->GetIClientEntity().
	virtual IClientEntity* GetClientEntity(int entnum) = 0;
	virtual IClientEntity* GetClientEntityFromHandle(unsigned long hEnt) = 0;

	//class shit
	const int GetClassIdFromIndex(int entnum) noexcept
	{
		const auto Networkable = GetClientNetworkable(entnum);
		if (!Networkable)
			return -1;
		return Networkable->GetClientClass()->m_ClassID;
	}
	const char* GetClassNameFromIndex(int entnum) noexcept
	{
		const auto Networkable = GetClientNetworkable(entnum);
		if (!Networkable)
			return nullptr;
		return Networkable->GetClientClass()->GetName();
	}

	// Returns number of entities currently in use
	virtual int	NumberOfEntities(bool bIncludeNonNetworkable) = 0;

	// Returns highest index actually used
	virtual int	GetHighestEntityIndex(void) = 0;

	// Sizes entity list to specified size
	virtual void SetMaxEntities(int maxents) = 0;
	virtual int	GetMaxEntities() = 0;
};

#define VCLIENTENTITYLIST_INTERFACE_VERSION	"VClientEntityList003"