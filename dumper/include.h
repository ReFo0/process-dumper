#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include "imports.h"


auto peb_() -> ppeb
{
    return (ppeb)__readgsqword(0x60);
}

auto get_baseaddress() -> HMODULE
{
    return (HMODULE)peb_()->ImageBaseAddress;
}


void show_console(bool onoff)
{
    if (onoff) {
        AllocConsole();
        freopen("CONIN$", "r", stdin);
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);
    }
}
