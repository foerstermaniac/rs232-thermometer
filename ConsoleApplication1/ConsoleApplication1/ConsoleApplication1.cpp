// ConsoleApplication1.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>

int main(void) {
	printf("HAllo");

	HANDLE handle;
	char buffer[100];
	DWORD dw;
	DCB dcb;

	handle = CreateFile(COM5, FILE_GENERIC_READ | FILE_GENERIC_WRITE, 0, NULL, OPEN_EXISTING, NULL, NULL);
	if (handle == INVALID_HANDLE_VALUE) {
		//error
	}

	if (!GetCommState(handle, &dcb)) {
		//error
	}

	dcb.BaudRate = CBR_9600;
	dcb.StopBits = 2;
	dcb.ByteSize = 7;
	
	if (!SetCommState(handle, &dcb)) {
		//error
	}

	while (1) {
		if (!ReadFile(handle, buffer, 100, &dw, NULL)) {
			//error
		}

		if (dw != 100) {
			//error
		}

		printf(*buffer);
		Sleep(500);
	}




	//hier daten penetrieren

	if (!WriteFile(handle, buffer, 100, &dw, NULL)) {
		//error
	}

	if (dw != 100) {
		//error
	}

	if (!CloseHandle(handle)) {
		//error
	}



	return 0;
}