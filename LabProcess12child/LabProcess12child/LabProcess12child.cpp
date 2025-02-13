#include <windows.h>
#include <conio.h>
#include <iostream>

int main(int argc, char* argv[])
{
	HANDLE hThread;
	char c;
	hThread = (HANDLE)atoi(argv[0]);
	while (true)
	{
		_cputs("Input 't' to terminate the thread: ");
		c = _getch();
		if (c == 't')
		{
			_cputs("t\n");
			break;
		}
	}
	TerminateThread(hThread, 0);
	CloseHandle(hThread);
	_cputs("Press any key to exit.\n");
	_getch();
	return 0;
}