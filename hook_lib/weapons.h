#pragma once
#include "Main.hpp"

inline utils::hook::detour PM_WeaponUseAmmo;
void PM_WeaponUseAmmo_Detour(__int64 playerstate, Weapon* weapon, char a3, int a4, int hand);

inline utils::hook::detour cg_overrideimpacteffecttype;
void CG_OverrideImpactEffectType_Detour(uintptr_t localClientNum, unsigned int sourceEntityNum, int* fxImpactType);

inline utils::hook::detour bg_getweapondismembermentenabled;
bool BG_GetWeaponDismembermentEnabled_Detour(Weapon* weapon, bool alt);

TracerDef* GetTracerDef(const char* asset);

void Dump_WeaponDef();

void Load_WeaponDef();