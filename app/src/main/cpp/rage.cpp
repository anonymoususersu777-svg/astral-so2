// language: C++, file: rage.cpp, target: Standoff 2 1.0.0
#include <cstdint>
#include <cstring>
#include <sys/mman.h>
#include <unistd.h>

bool g_rageFastFire  = false;
bool g_rageInfAmmo   = false;
bool g_rageWallshot  = false;
bool g_rageNoRecoil  = false;
bool g_rageOneShot   = false;
bool g_rageFastPlant = false;

extern "C" void patchBytes(uintptr_t addr, const uint8_t* p, size_t n) {
    uintptr_t page = addr & ~(uintptr_t)(getpagesize()-1);
    mprotect((void*)page, getpagesize(), PROT_READ|PROT_WRITE|PROT_EXEC);
    memcpy((void*)addr, p, n);
    __builtin___clear_cache((char*)addr, (char*)(addr+n));
}
