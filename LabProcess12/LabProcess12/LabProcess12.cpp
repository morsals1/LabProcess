#include <windows.h>
#include <conio.h>
#include <iostream>

int main()
{
    setlocale(LC_ALL, "russian");

    const char* file = "race.txt";

    STARTUPINFOA si;
    PROCESS_INFORMATION pi;
    SECURITY_ATTRIBUTES sa;
    HANDLE hFile = CreateFileA(file, GENERIC_READ, FILE_SHARE_READ,
        nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

    if (hFile == INVALID_HANDLE_VALUE) {
        std::cerr << "Ошибка открытия файла: " << GetLastError() << std::endl;
        return 1;
    }

    sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    sa.lpSecurityDescriptor = NULL;
    sa.bInheritHandle = TRUE;

    ZeroMemory(&si, sizeof(STARTUPINFOA));
    si.cb = sizeof(STARTUPINFOA);

    char cmdLine[256];
    sprintf_s(cmdLine, "ChildProcess.exe %d", (int)hFile);

    if (!CreateProcessA(NULL, cmdLine, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
    {
        std::cerr << "Ошибка создания процесса: " << GetLastError() << std::endl;
        CloseHandle(hFile);
        return 1;
    }

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    WaitForSingleObject(pi.hProcess, INFINITE);
    std::cout << "Дочерний процесс завершен. Нажмите любую клавишу для выхода.\n";
    _getch();

    CloseHandle(hFile);
    return 0;
}