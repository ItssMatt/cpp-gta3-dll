#include <Windows.h>
#include <iostream>

#include "main.h"

class CVeh {

};

typedef void(__stdcall* function)(CVeh* vehicle, int param_2);
uintptr_t base = (uintptr_t)GetModuleHandle("LibertyCity.exe");
function fn1 = (function)(base + 0xFDD440);

void function_hook(CVeh* vehicle, int param_2)
{
    fn1(vehicle, param_2);
    printf("CVeh: %p - param_2: %d\n", vehicle, param_2);
}

ULONG __stdcall mainThread(void* hModule) {
    AllocConsole();
    freopen("CONOUT$", "w", stdout);
    std::cout << "[DEBUG] Console allocated.\n";

    CPed::setLocalPlayer();
    if (CPed::getLocalPlayer()) {
        std::cout << "g_LocalPlayer address: " << CPed::getLocalPlayer() << "\n";
    }

    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach(&(PVOID&)fn1, function_hook);
    DetourTransactionCommit();

    while (!GetAsyncKeyState(VK_END) & 1)
    { 
        if (CPed::getLocalPlayer()) {

        }
        else CPed::setLocalPlayer(); 
       
        if (GetAsyncKeyState(VK_F10) & 1) {

        }


        Sleep(100);
    }
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourDetach(&(PVOID&)fn1, function_hook);
    DetourTransactionCommit();

    std::cout << "[DEBUG] Console freed.\n";

    FreeConsole();
    FreeLibraryAndExitThread(reinterpret_cast<HMODULE>(hModule), 0);
    return 0ul;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)mainThread, hModule, 0, 0);
    }
    return TRUE;
}

