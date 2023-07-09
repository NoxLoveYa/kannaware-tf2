#include <Windows.h>

#include "interfaces.h"

namespace interfaces
{
	//variables
	IClientEntityList* entityList;

	template<typename T>
	T* GetInterface(const char* name, const char* module)
	{
		const auto handle = GetModuleHandle(module);
		if (!handle)
			return nullptr;

		const auto CreateInterfaceAddres = GetProcAddress(handle, "CreateInterface");

		using CreateInterfaceFn = T * (*)(const char* name, int* i);
		const auto CreateInterface = reinterpret_cast<CreateInterfaceFn>(CreateInterfaceAddres);

		return CreateInterface(name, nullptr);
	}

	void SetupInterfaces()
	{
		entityList = GetInterface<IClientEntityList>(VCLIENTENTITYLIST_INTERFACE_VERSION, "client.dll");
	}
}