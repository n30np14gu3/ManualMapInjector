#include <BlackBone/Process/Process.h>
#include "Injector.h"

#pragma comment(lib, "BlackBone.lib")

#pragma comment(linker, "/EXPORT:InjectFile=?InjectFile@@YA_NPB_WII@Z")
#pragma comment(linker, "/EXPORT:InjectRaw=?InjectRaw@@YA_NIPAEII_N@Z")

using namespace blackbone;

bool InjectFile(const wchar_t* szDll, unsigned int pId, unsigned int flags)
{
	Process processToInject;

	if (!NT_SUCCESS(processToInject.Attach(pId)))
		return false;

	return processToInject.mmap().MapImage(std::wstring(szDll), eLoadFlags(flags)).success();
}

bool InjectRaw(size_t size, byte* buffer, unsigned int pId, unsigned int flags, bool asImage)
{
	Process processToInject;

	if (!NT_SUCCESS(processToInject.Attach(pId)))
		return false;

	return processToInject.mmap().MapImage(size, buffer, asImage, eLoadFlags(flags)).success();
}
