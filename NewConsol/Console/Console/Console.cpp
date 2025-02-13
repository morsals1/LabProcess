// Console.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
#include <string>

int main()
{
    setlocale(LC_ALL, "russian");

    int a = 0;
    std::cout << "Один ход стоит 1 ед.\n" << "Введите сумму ставки\n";
    std::cin >> a;
    

    std::srand(std::time(nullptr));
    char symbols[] = { '7', '$', 'a', 'b'};
    std::string check_symbols;
    int size = sizeof(symbols) / sizeof(symbols[0]);
    int randomIndex = -1;
    char exit;

    while (a > 0) 
    {
        a--;
        for (int j = 0; j < 3; j++)
        {
            randomIndex = std::rand() % size;
            check_symbols += symbols[randomIndex];
            std::cout << symbols[randomIndex];
        }

        if (check_symbols == "777" || check_symbols == "aaa" || check_symbols == "$$$" || check_symbols == "bbb")
        {
            a = a+10;

        }
        else if (check_symbols == "7a7" || check_symbols == "7b7" || check_symbols == "7$7" || check_symbols == "$a$"
            || check_symbols == "$b$" || check_symbols == "$7$" || check_symbols == "aba"
            || check_symbols == "a7a" || check_symbols == "a$a" || check_symbols == "bab"
            || check_symbols == "b7b" || check_symbols == "b$b")
        {
            a = a+2;
        }

        std::cout << "\nЕд. осталось: " << a << "\n";
        std::cout << "Чтобы выйти введите '0': \n" << "Продолжить любой символ\n";
        std::cin >> exit;
        if (exit == '0') {
            break;
            return 0;
        }
        check_symbols = "";
    }

    std::cout << "Итого: " << a << "\n";

    _getch();

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
