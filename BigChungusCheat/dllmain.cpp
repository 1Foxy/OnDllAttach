// dllmain.cpp : Defines the entry point for the DLL application.
#include "includes.hpp"

DWORD WINAPI OnDllAttach( PVOID base )
{
	Beep(750, 300);

	FreeLibraryAndExitThread(static_cast<HMODULE>(base), 1);
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD dwReason, LPVOID lpReserved )
{
	if (dwReason == DLL_PROCESS_ATTACH) {
		DisableThreadLibraryCalls(hModule);
		CreateThread(nullptr, NULL, OnDllAttach, hModule, NULL, nullptr);
	}

	return TRUE;
}

