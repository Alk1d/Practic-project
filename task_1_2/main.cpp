#include <QCoreApplication>
#include <iostream>
#include "user.h"
#include <vector> // Данные будут хранится в векторе
#include <Windows.h>
#include <iomanip> // Подключаем для работы функции setw()
using namespace std;

vector<user>userlist;
// Объявляем все функции проекта
void menu(); // Главное меню
void menu_edit(); // Меню изменения параметров
void hline(); // Горизонтальная линия для оформления

void vvod(vector<user>&L); // Ввод данных
void vivod(vector<user>L); // Вывод данных
void edit(vector<user>& L); // Изменение данных в векторе
void del(vector<user>&L); // Удаление данных из вектора
int find_number(vector<user>L, int n); // Нумерование данных в векторе

bool input_continue(); // Проверка продолжения ввода
void access_edit(vector<user>&L); // Изменение параметра доступе (не работает)

int main()
{
    int n = 0;
    while (n!=5) // Вводим цикл для отработки главного меню
    {
        menu();
        cin >> n;
        if (cin.fail())
        {
            cin.clear();
            cin.sync();
            cout << "Error! Type a number!" << endl;
        }
        switch(n)
        {
        case 1:vvod(userlist); break;
        case 2:vivod(userlist); break;
        case 3:edit(userlist); break;
        case 4:del(userlist); break;
        case 5: cout << "Press any key to close"; break;
        default: cout << "Wrong choice" << endl;
        }
    }
}

void menu()
{
    cout << endl << "  Menu  " << endl;
    cout << "1.Input data" << endl;
    cout << "2.Output data" << endl;
    cout << "3.Edit data" << endl;
    cout << "4.Delete data" << endl;
    cout << "5.Exit" << endl;
    cout << "Type a number of menu to continue" << endl;
}

int find_number(vector<user>L, int n)
{
    for (int i = 0; i <= L.size(); i++ )
    {
        if (n==i)
        {
            return --i;
        }
    }
    return -1;
}

void vvod(vector<user>&L)
{
    string login, password, name, surname;
    access_types access = noaccess;
    int flag = 1; // Флаг для проверки логина на оригинальность
    while(cin.get() != '\n');
     // Используем два цикла, в первом вводим и проверяем оригинальность логина, во втором - остальные данные
        while (flag == 1)
        {
            flag = 0;
            string temp_login;
            cout << "Type login" << endl;
            getline(cin, temp_login);
            for (int i = 0; i < L.size(); i++)
            {
                if (temp_login == L[i].get_login())
                {
                    flag = 1;
                    cout << "This login is already used!";
                }
            }
            if (flag == 0) login = temp_login;
            cout << endl;
        }
        while(true)
        {
        cout << "Type password" << endl;
        getline(cin, password);
        cout << endl;
        cout << "Type name" << endl;
        getline(cin, name);
        cout << endl;
        cout << "Type surname" << endl;
        getline(cin, surname);
        cout << endl;
        cout << "Choose access" << endl;
        cout << "No access = 0;  Guest = 1;  Admin = 2" << endl;
        int n;
        cin >> n;
        switch (n)
        {
        case 0: access = noaccess; break;
        case 1: access = guest; break;
        case 2: access = admin; break;
        default: cout << "Wrong choise" << endl; break;
        }

        L.push_back(user(login, password, name, surname, access));
        break;
        }
        input_continue();
}

void vivod(vector<user>L)
{
    cout << "    Users   " << endl;
    hline();
    cout << "| N |     Login     |     Password     |     Name     |     Surname     |   Access   |" << endl;
    hline();
    for (int i = 0; i < L.size(); i++)
    {
        // Используем setw() для выделения места в ячейках таблицы
        cout << "|" << setw(3) << i+1;
        cout << "|" << setw(15) << L[i].get_login();
        cout << "|" << setw(18) << L[i].get_password();
        cout << "|" << setw(14) << L[i].get_name();
        cout << "|" << setw(17) << L[i].get_surname();
        cout << "|" << setw(12) << L[i].get_access() << "|" << endl;
    }
    hline();
}

void menu_edit()
{
    cout << endl << "Choose editing parametr" << endl;
    cout << "Login: 1" << endl;
    cout << "Password: 2" << endl;
    cout << "Name: 3" << endl;
    cout << "Surname: 4" << endl;
    cout << "Access: 5" << endl;
    cout << "Exit: 6" << endl;
}

void edit(vector<user>& L)
{
    string login, password, name, surname;
    access_types access;
    cout << "Type user number" << endl;
    int n;
    int flag_number = 0;
    while (flag_number == 0)
    {
    flag_number = 1;
    n = -1;
    cin >> n;
    if (cin.fail())
    {
        cin.clear();
        cin.sync();
        flag_number = 0;
        cout << "Error! Type a number!" << endl;
    }
    }
    int ind = find_number(L, n);
    if (ind != -1)
    {
        cout << endl << "User found" << endl;
        L[ind].show();
        int l = 0;
        while (l != 6)
        {
            menu_edit();
            cin >> l;
            if (cin.fail())
            {
                cin.clear();
                cin.sync();
                cout << "Error! Type a number!" << endl;
                break;
            }
            switch(l)
            {
            case 1:
                cout << "Type new login" << endl;;
                while(cin.get() != '\n');
                getline(cin, login);
                L[ind].set_login(login);
                cout << endl;
                break;
            case 2:
                cout << "Type new password" << endl;
                while(cin.get() != '\n');
                getline(cin, password);
                L[ind].set_password(password);
                cout << endl;
                break;
            case 3:
                cout << "Type new name" << endl;
                while(cin.get() != '\n');
                getline(cin, name);
                L[ind].set_name(name);
                cout << endl;
                break;
            case 4:
                cout << "Type new surname" << endl;
                while(cin.get() != '\n');
                getline(cin, surname);
                L[ind].set_surname(surname);
                cout << endl;
                break;
            case 5:
                cout << "Choose new access" << endl;
                cout << "No access = 0;  Guest = 1;  Admin = 2" << endl;
                int choise;
                cin >> choise;
                if (cin.fail())
                {
                    cin.clear();
                    cin.sync();
                    cout << "Error! Type a number!" << endl;
                    break;
                }
                switch(choise)
                {
                case 0: L[ind].set_access(noaccess); break;
                case 1: L[ind].set_access(guest); break;
                case 2: L[ind].set_access(admin); break;
default: cout << "Wrong choise" << endl; break;
                }
                cout << endl;
                break;
            case 6: break;
            default: cout << "Wrong choise" << endl; break;
            }
        }
        cout << endl << "End of edit" << endl;
    }
    else cout << "User not found" << endl;
}

void del(vector <user>&L)
{
    char choise;
    cout << "Type user number" << endl;
    int n;
    cin >> n;
    if (cin.fail())
    {
        cin.clear();
        cin.sync();
        cout << "Error! Type a number!" << endl;
        return;
    }
    int ind = find_number(L, n);
    if (ind != -1)
    {
        cout << "User found" << endl;
        L[ind].show();
        cout << "Delete user? y/n" << endl;
        cin >> choise;
        if (choise == 'y')
        {
            L.erase(L.begin() + ind); // В методе erase()  указываем начало вектора плюс смещение до удаляемого элемента
            cout << "User deleted" << endl;
        }
        if (choise == 'n') return;
    }
    else cout << "User not found" << endl;
}

bool input_continue()
{
    char choise;
    cout << "Continue input? y/n" << endl;
    cin >> choise;
    if (choise == 'y') vvod(userlist);
    if (choise == 'n') return false;
}

void hline()
{
    const int m = 86;
    for (int i = 0; i < m; i++)
        cout << "-";
    cout << endl;
}
