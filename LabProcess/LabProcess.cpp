#include <iostream>
#include <Windows.h>
#include <conio.h>

int main()
{
    LPCWSTR lpszAppName = L"C:\\Users\\st310-11\\Desktop\\меньшиков ПР-32\\AmoForms\\bin\\Debug\\net8.0-windows\\AmoForms.exe";
    STARTUPINFO si;
    PROCESS_INFORMATION piApp;

    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);

    int a = -1;
    printf("Выбери задачу от 1 до 7\n");
    std::cin >> a;



    switch (a)
    {
    case 1:
        if (!CreateProcess(lpszAppName, NULL, NULL, NULL, FALSE,
            CREATE_NEW_CONSOLE, NULL, NULL, &si, &piApp)) {
            return 0;
        }

        _cputs("The new process is created\n");
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
            _cputs("The new process is not created.\n");
            _cputs("Check a name of the process.\n");
            _cputs("Press any key to finish.\n");
            _getch();
            return 0;
        }
        _cputs("The new process is created.\n");
            while (true)
            {
                char c;
                _cputs("Input 't' to terminate the new console process: ");
                c = _getch();
                if (c == 't')
                {
                    _cputs("t\n");
                    TerminateProcess(piApp.hProcess, 1);
                    break;
                }
            }
        CloseHandle(piApp.hThread);
        CloseHandle(piApp .hProcess);

        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    default:
        printf("Вань ты дурак совсем");
        break;
    }

    return 0;
}