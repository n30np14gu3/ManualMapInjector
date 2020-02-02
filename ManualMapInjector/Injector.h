#pragma once
bool InjectFile(const wchar_t* szDll, unsigned int pId, unsigned int flags);
bool InjectRaw(size_t size, byte* buffer, unsigned int pId, unsigned int flags, bool asImage);
