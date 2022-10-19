/************************************************************************************************
** File created by QxEntityEditor 1.2.6 (2022/10/18 16:53) : please, do NOT modify this file ! **
************************************************************************************************/

#ifdef _MSC_VER

#include <windows.h>

extern "C"
int WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID /* lpReservedt */)
{
   (void)hInstance;
   (void)dwReason;

#ifndef _QX_NO_TRACE_DLL_ATTACH_DETACH
   switch (dwReason)
   {
      case DLL_PROCESS_ATTACH:   ::OutputDebugStringA("LBP.DllMain() ---> DLL_PROCESS_ATTACH\n");  break;
      case DLL_PROCESS_DETACH:   ::OutputDebugStringA("LBP.DllMain() ---> DLL_PROCESS_DETACH\n");  break;
      case DLL_THREAD_ATTACH:    ::OutputDebugStringA("LBP.DllMain() ---> DLL_THREAD_ATTACH\n");   break;
      case DLL_THREAD_DETACH:    ::OutputDebugStringA("LBP.DllMain() ---> DLL_THREAD_DETACH\n");   break;
   }
#endif // _QX_NO_TRACE_DLL_ATTACH_DETACH

   return 1;
}

#endif // _MSC_VER
