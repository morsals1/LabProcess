#include <iostream>
#include <Windows.h>
#include <conio.h>

int main()
{
    setlocale(LC_ALL, "russian");

    LPCWSTR lpszAppName = L"C:\\Users\\328-8\\Desktop\\menshikov p32\\LabProcess-main\\NewConsol\\Console\\x64\\Debug\\Console.exe";
    STARTUPINFO si;
    PROCESS_INFORMATION piApp;

    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);

    int a = -1;
    printf("Выбери задачу от 1 до 2\n");
    std::cin >> a;



    switch (a)
    {
    case 1:
        if (!CreateProcess(lpszAppName, NULL, NULL, NULL, FALSE,
            CREATE_NEW_CONSOLE, NULL, NULL, &si, &piApp)) 
        {
            _cputs("Новый процесс не удалось создать.\n");
            _cputs("Провертье имя процесса.\n");
            _cputs("Нажмите любую символ для завершения.\n");
            _getch();
            return 0;
        }

        _cputs("Новый процесс создан.\n");
        std::cout << "PID " << piApp.dwProcessId << "\n";
        std::cout << "Дескриптор " << piApp.hProcess << "\n";

        WaitForSingleObject(piApp.hProcess, INFINITE);

        CloseHandle(piApp.hThread);
        CloseHandle(piApp.hProcess);
        break;
    case 2:

        if (!CreateProcess(lpszAppName, NULL, NULL, NULL, FALSE,
            CREATE_NEW_CONSOLE, NULL, NULL, &si, &piApp))
        {
            _cputs("Новый процесс не удалось создать.\n");
            _cputs("Провертье имя процесса.\n");
            _cputs("Нажмите любую символ для завершения.\n");
            _getch();
            return 0;
        }
        _cputs("Новый процесс создан.\n");
            while (true)
            {
                char c;
                _cputs("Введите 't' чтобы прекратить процесс консоли: ");
                c = _getch();
                if (c == 't')
                {
                    _cputs("t\n");
                    TerminateProcess(piApp.hProcess, 1);
                    break;
                }
            }

        _cputs("Процесс завершил свою работу\n");
        CloseHandle(piApp.hThread);
        CloseHandle(piApp .hProcess);
        break;
    default:
        printf("Вань ты дурак совсем");
        break;
    }

    return 0;
}