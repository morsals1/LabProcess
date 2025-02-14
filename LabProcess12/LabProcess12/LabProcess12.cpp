#include <windows.h>
#include <conio.h>
#include <iostream>

int main() {
    const char* file = "C:\\Users\\st310-11\\Desktop\\меньшиков ПР-32\\LabProcess-main\\LabProcess12\\race.txt";

    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    SECURITY_ATTRIBUTES sa = { sizeof(SECURITY_ATTRIBUTES), NULL, TRUE };

    HANDLE hFile = CreateFileA(file, GENERIC_READ, FILE_SHARE_READ,
        &sa, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

    if (hFile == INVALID_HANDLE_VALUE) {
        std::cerr << "Ошибка открытия файла: " << GetLastError() << std::endl;
        return 1;
    }

    wchar_t cmdline[256];
    swprintf_s(cmdline, L"C:\\Users\\st310-11\\Desktop\\меньшиков ПР-32\\LabProcess-main\\LabProcess12child\\x64\\Debug\\LabProcess12child.exe %d", (int)hFile);

    if (!CreateProcess(NULL, cmdline, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi)) {
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