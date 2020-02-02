#include <BlackBone/Process/Process.h>
#include "Injector.h"

#pragma comment(lib, "BlackBone.lib")

using namespace blackbone;

extern "C"
{
	__declspec(dllexport) int _stdcall InjectFile(const wchar_t* szDll, unsigned int pId, unsigned int flags)
	{
		Process processToInject;

		if (!NT_SUCCESS(processToInject.Attach(pId)))
			return 1;

		return processToInject.mmap().MapImage(std::wstring(szDll), eLoadFlags(flags)).success() ? 0 : 2;
	}

	__declspec(dllexport) int _stdcall InjectRaw(size_t size, byte* buffer, unsigned int pId, unsigned int flags, bool asImage)
	{
		Process processToInject;

		if (!NT_SUCCESS(processToInject.Attach(pId)))
			return 1;

		return processToInject.mmap().MapImage(size, buffer, asImage, eLoadFlags(flags)).success()? 0 : 2;
	}
}