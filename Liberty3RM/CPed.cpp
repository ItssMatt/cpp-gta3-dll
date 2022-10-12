#include "CPed.h"

CPed* g_LocalPlayer;

CPed* CPed::getLocalPlayer(void) {
	return g_LocalPlayer;
}

void CPed::setLocalPlayer() {
    uintptr_t base = (uintptr_t)GetModuleHandle("LibertyCity.exe");
	g_LocalPlayer = (CPed*)((base + 0x04C0B328)); // "LibertyCity.exe"+04C0B328
}

float CPed::getHealth(void) {
	return *(float*)(*(DWORD*)this + 0x428);
}

void CPed::setHealth(float health) {
	*(float*)(*(DWORD*)this + 0x428) = health;
}

float CPed::getArmor(void) {
	return *(float*)(*(DWORD*)this + 0x42C);
}

void CPed::setArmor(float armor) {
	*(float*)(*(DWORD*)this + 0x42C) = armor;
}

CVector CPed::getPosition(void) {
	return *(CVector*)(*(DWORD*)this + 0x38);
}

void CPed::setPosition(CVector position) {
	*(CVector*)(*(DWORD*)this + 0x38) = position;
}

int CPed::getModel(void) {
	return *(int*)(*(DWORD*)this + 0x78);
}

void CPed::setModel(int model) {
	*(int*)(*(DWORD*)this + 0x78) = model;
}