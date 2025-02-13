#include <windows.h>
#include <conio.h>
#include <iostream>

int main()
{
	const char* file = "race.txt";

	LPWSTR lpszComLine;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	SECURITY_ATTRIBUTES sa;
	DWORD IDThread;
	HANDLE hThread = CreateFileA(file, GENERIC_READ, FILE_SHARE_READ, 
		nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);



	if (hThread == INVALID_HANDLE_VALUE) {
		std::cerr << "Ошибка открытия файла: " << GetLastError << std::endl;
		return 1;
	}

	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;

	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	wsprintf(lpszComLine, L"C:\\ConsoleProcess.exe %d", (int)hThread);


	if (!CreateProcess(NULL,lpszComLine,NULL,NULL,TRUE,CREATE_NEW_CONSOLE,NULL,NULL,&si,&pi))
	{
		_cputs("The new process is not created.\n");
		_cputs("Press any key to finish.\n");
		_getch();
		return GetLastError();
	}

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	WaitForSingleObject(hThread, INFINITE);
	_cputs("Press any key to exit.\n");
	_getch();

	CloseHandle(hThread);
	return 0;
}