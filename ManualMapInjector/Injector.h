#pragma once

extern "C"
{
	__declspec(dllexport) int _stdcall InjectFile(const wchar_t* szDll, unsigned int pId, unsigned int flags);
	__declspec(dllexport) int _stdcall InjectRaw(size_t size, byte* buffer, unsigned int pId, unsigned int flags, bool asImage);
}