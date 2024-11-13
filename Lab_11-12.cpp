// Lab_11-12.cpp : Створити лінійний односпрямований список з цілих чисел. Видалити зі списку //
//елемент після кожного елемента, який дорівнює 4. Додати число 0 перед кожним числом 1//

#include <iostream>
#include <forward_list>
#include <iomanip> 
#include <windows.h> 
using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    forward_list<int> numberList = { 10, 4, 7, 1, 8, 4, 6 };

    cout << "Список цілих чисел: ";
    for (int number : numberList) {
        cout << setprecision(2) << fixed << number << " ";
    }
    cout << endl;

    auto it = numberList.begin();
    auto prev = numberList.before_begin(); 
    while (it != numberList.end()) {
        if (*it == 4) {
            auto next = it;
            ++next;
            if (next != numberList.end()) {
                numberList.erase_after(it); 
            }
        }
        if (*it == 1) {
            numberList.insert_after(prev, 0); 
        }
        prev = it;
        ++it;
    }

    cout << "Оновлений список: ";
    for (int number : numberList) {
        cout << setprecision(2) << fixed << number << " ";
    }
    cout << endl;

    return 0;
}


