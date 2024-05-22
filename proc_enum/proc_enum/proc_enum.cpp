// proc_enum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>

#include <Windows.h>
#include <TlHelp32.h>

int Error(const char* msg) {
    printf("%s (%u)", msg, GetLastError());
    return 1;
}

int FindTarget_using_CreateToolhelp32Snapshot() {
    PROCESSENTRY32 pe32{};
    pe32.dwSize = sizeof(PROCESSENTRY32);
    int pid = 0;
    HANDLE hProcSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (INVALID_HANDLE_VALUE == hProcSnap) {
        return Error("CreateToolhelp32Snapshot error");
    }
    if (!Process32First(hProcSnap, &pe32)) {
        return Error("Process32First fail");
    }
    do {
        printf("| PID: %6u (PPID: %6u) \t Threads %3u %ws | \n", pe32.th32ProcessID, pe32.th32ParentProcessID, pe32.cntThreads, pe32.szExeFile);
    } while (Process32Next(hProcSnap, &pe32));

    CloseHandle(hProcSnap);
    return 0;
}

int main(){
    FindTarget_using_CreateToolhelp32Snapshot();
}

