#include <windows.h>
#include <conio.h>
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cerr << "Недостаточно аргументов.\n";
        return 1;
    }

    HANDLE hFile = (HANDLE)atoi(argv[1]);
    if (hFile == INVALID_HANDLE_VALUE) {
        std::cerr << "Ошибка получения дескриптора файла.\n";
        return 1;
    }

    char buffer[1024];
    DWORD bytesRead;
    while (ReadFile(hFile, buffer, sizeof(buffer), &bytesRead, NULL) && bytesRead > 0) {
        std::cout.write(buffer, bytesRead);
    }

    CloseHandle(hFile);
    std::cout << "Файл прочитан. Нажмите любую клавишу для выхода.\n";
    _getch();

    return 0;
}