// ConsoleApplication1.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>
#include <string.h>



int main(void) {

	HANDLE hComfile;
	char buffer[100];
	DCB comConfig;
	DWORD readBytes;
	hComfile = CreateFile("COM5", GENERIC_READ, 0, NULL, OPEN_EXISTING, NULL, NULL);

	GetCommState(hComfile, &comConfig);

	comConfig.BaudRate = 9600;
	comConfig.ByteSize = 7;
	comConfig.Parity = NOPARITY;
	comConfig.StopBits = TWOSTOPBITS;

	SetCommState(hComfile, &comConfig);
	Sleep(4000);
	

	while (1) {
		ReadFile(hComfile, buffer, 100, &readBytes, NULL);
		//printf(buffer);
		//printf("###%u###", readBytes);
		//memset(buffer, '\0', sizeof(buffer));
	
}
	CloseHandle(hComfile);

	return 0;
}