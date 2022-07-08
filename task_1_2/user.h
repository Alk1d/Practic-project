#ifndef USER_H
#define USER_H
#pragma once
#include <string>
#include <iostream>
enum access_types
{
    noaccess=0,
    guest,
    admin
};

class user
{
private: // вводим в private для защиты данных переменные класса пользователя
    std::string login; // логин
    std::string password; // пароль
    std::string name; // имя
    std::string surname; // фамилия
    access_types access = access_types::noaccess; // права пользователя

public: // вводим в public конструктор, get-ы и set-ы и метод show для отображения данных
    user(std::string&_login, std::string&_password, std::string&_name, std::string&_surname, access_types&_access);

    std::string get_login() const;
    std::string get_password() const;
    std::string get_name() const;
    std::string get_surname() const;
    access_types get_access() const;

    void set_login(std::string new_login);
    void set_password(std::string new_password);
    void set_name(std::string new_name);
    void set_surname(std::string new_surname);
    void set_access(access_types new_access);
    void show() const;
};

#endif // USER_H
