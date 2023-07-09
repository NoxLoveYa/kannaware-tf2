#include "esp.h"
#include "../../ext/sdk/interfaces/interfaces.h"
#include <iostream>

void esp::Render()
{
	for (auto i = 1; i <= 64; i++)
	{
		const auto player = interfaces::entityList->GetClientEntity(i);
		if (interfaces::entityList->GetClassNameFromIndex(i))
			printf("id: %d, classId: %d, className: %s\n", i, interfaces::entityList->GetClassIdFromIndex(i), interfaces::entityList->GetClassNameFromIndex(i));
		if (!player)
			continue;
		ImGui::GetBackgroundDrawList()->AddCircleFilled({ float(10 * i), 10 }, 2.f, ImColor(1.f, 1.f, 1.f));
	}
}
