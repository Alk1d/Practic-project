#include "user.h"
using namespace std;

//расписывается конструткор
user::user(string&_login, string&_password, string&_name, string&_surname, access_types&_access) : login(_login), password(_password), name(_name), surname(_surname), access(_access) {}

//расписываются get-ы
string user::get_login()const {return login;}
string user::get_password()const {return password;}
string user::get_name()const {return name;}
string user::get_surname()const {return surname;}
access_types user::get_access()const {return access;}

//расписываются set-ы
void user::set_login(string new_login) {login = new_login;}
void user::set_password(string new_password) {password = new_password;}
void user::set_name(string new_name) {name = new_name;}
void user::set_surname(string new_surname) {surname = new_surname;}
void user::set_access(access_types new_access) {access = new_access;}

//расписывается функция show
void user::show() const
{
    cout << "Login:" << login << endl;
    cout << "Password:" << password << endl;
    cout << "Name:" << name << endl;
    cout << "Surname:" << surname << endl;
    cout << "Access:" << access << endl << endl;
}
