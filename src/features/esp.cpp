#include "esp.h"
#include <memoryapi.h>

void esp::Render()
{
	ImGui::GetBackgroundDrawList()->AddCircleFilled({ 500, 500 }, 200.f, ImColor(1.f, 1.f, 1.f));
}
