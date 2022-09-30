#include "include.h"





void start_dumper(bool onoff)
{
    if (onoff) {
        auto base_adress = get_baseaddress();
        auto dosheader = (PIMAGE_DOS_HEADER)((uintptr_t)base_adress);
        auto ntheader = (PIMAGE_NT_HEADERS)((uintptr_t)dosheader->e_lfanew + (uintptr_t)base_adress);
        auto size = ntheader->OptionalHeader.SizeOfImage;
        char* allocated = new char[size];
        memcpy(allocated, (const void*)base_adress, size);
        auto dosheadernew = (PIMAGE_DOS_HEADER)((uintptr_t)allocated);
        auto ntheadernew = (PIMAGE_NT_HEADERS)((uintptr_t)dosheadernew->e_lfanew + (uintptr_t)allocated);

        PIMAGE_SECTION_HEADER SectionHeader = IMAGE_FIRST_SECTION(ntheadernew);

        for (int i = 0; i < ntheadernew->FileHeader.NumberOfSections; i++, SectionHeader++)
        {
            SectionHeader->PointerToRawData = SectionHeader->VirtualAddress;
            SectionHeader->SizeOfRawData = SectionHeader->Misc.VirtualSize;
        }
        char dumped_name[MAX_PATH];
        GetModuleFileNameA(0, dumped_name, MAX_PATH);
        sprintf_s(dumped_name, "%s_dump.exe", dumped_name);
        std::ofstream file(dumped_name, std::ios::binary);
        file.write((char*)allocated, size);
        file.close();
        std::cout << "dumper work completed\n";
        std::cout << "see injected process folder\n";
    }
    else
    {
        std::cout << "dumper closed.\n";
    }
}

BOOL APIENTRY DllMain(HMODULE dll, DWORD call, LPVOID reserved)
{
    DisableThreadLibraryCalls(dll);
    if (call == 1) {
        show_console(true);
        start_dumper(true);
    }
    return 1;
}