#include "addr_utils.hpp"
#include "screen.h"
#include "debug_output.h"

void CG_DrawWaterMark()
{
	float white[4] = { 1.0f, 1.0f, 1.0f, 0.2f };
}

void CL_ScreenMP_DrawOverlay_Detour()
{
	auto DevGui_Draw = reinterpret_cast<void(*)(int)>(0x1417E5CD0_g);
	auto Con_DrawConsole = reinterpret_cast<void(*)(int)>(0x1415AE0B0_g);

	gameInitialized = true;

	Con_DrawConsole(0);
	DevGui_Draw(0);

	if (show_watermark->current.enabled) {
		CG_DrawWaterMark();
	}

	float white[4] = { 1.0f, 1.0f, 1.0f, 0.075f };
	CL_DrawText(0x14EF2DEA0_g, "Donetsk", 0x7FFFFFFF, *reinterpret_cast<uintptr_t*>(0x14EEB0C68_g), 0, 480, 1, 1, 0.45000001f, 0.45000001f, white, 7);
}