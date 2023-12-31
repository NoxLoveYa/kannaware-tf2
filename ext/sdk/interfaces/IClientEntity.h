#pragma once
#include "interfaces.h"

#include "../class/ClientClass.h"

class IClientEntity
{
public:
	// Delete yourself.
	virtual void Release(void) = 0;

	// Network origin + angles
	virtual const Vector& GetAbsOrigin(void) const = 0;
	virtual const QAngle& GetAbsAngles(void) const = 0;

	//virtual CMouthInfo* GetMouth(void) = 0;

	// Retrieve sound spatialization info for the specified sound on this entity
	// Return false to indicate sound is not audible
	//virtual bool GetSoundSpatialization(SpatializationInfo_t& info) = 0;
};