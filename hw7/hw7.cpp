// hw7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <ctype.h>
#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <typeinfo>
#include <fstream>
#include <malloc.h>
#include <cstring>
#include <vector>

using namespace std;
// Создайте класс Worker. Необходимо хранить данные : ФИО, Должность, Год поступления на работу, Зарплата.
// Создать массив объектов.Вывести : ■ список работников, стаж работы которых на данном предприятии превосходит заданное число лет;
// ■ список работников, зарплата которых превосходит заданную; ■ список работников, занимающих заданную должность.
// Используйте explicit конструктор и константные функции - члены(например, для отображения данных о работнике и т.д.)

class Worker {
private:
    string fullname;
    string position;
    int year;
    int seniority;
    size_t salary;

public:
    string getFullname() { return fullname; }
    void seFullname(string _fullname) { fullname = _fullname; }

    string getPosition() { return position; }
    void setPosition(string _position) { position = _position; }

    int getYear() { return year; }
    void setYear(int _year) { year = _year; }

    int getSeniority() { return seniority; }
    void setSeniority(int _seniority) { year = _seniority; }

    size_t getSalary() { return salary; }
    void setSalary(size_t _salary) { salary = _salary; }

    Worker(string _fullname, string _position, int _year, size_t _salary)
    {
        fullname = _fullname;
        position = _position;
        year = _year;
        salary = _salary;
    }

    void showWorker() const
    {
            cout << "\nФИО: " << fullname;
            cout << "\nДолжность: " << position;
            cout << "\nГод поступления на работу: " << year;
            cout << "\nЗарплата: " << salary;
            cout << endl; 
    }

    Worker(int _seniority)
    {

    }
    int seniorityWorker(int seniority)
    {
        int current_year = 2023;
        seniority = current_year - year;
        return seniority;

    }
   
};

int main()
{
	setlocale(LC_ALL, "ru");

    int year, menu;
    size_t salary;
    string position;

    vector<Worker> workers;

    workers.emplace_back(Worker("АА", "Call center specialist", 2020, 50000 ));
    workers.emplace_back(Worker("BB", "Call center specialist", 2016, 50000 ));
    workers.emplace_back(Worker("CC", "Office manager", 2004, 90000));
    workers.emplace_back(Worker("DD", "Office manager", 2015, 90000));
    workers.emplace_back(Worker("EE", "Assistant secretary", 2013, 130000));
    workers.emplace_back(Worker("FF", "Administrator", 2022, 95000));
    workers.emplace_back(Worker("GG", "Assistant manager", 2016, 150000));
    workers.emplace_back(Worker("HH", "Director", 2001, 300000));

    cout << "1 - Поиск по стажу работы на предприятии, превосходящему заданное число лет \n2 - Поиск по зарплате в месяц, превосходящей заданную \n3 - Поиск по должности\n";
    cin >> menu;

    switch (menu)
    {
    case 1:
    {
        cout << "Введите стаж, после которого необходимо найти: ";
        cin >> year;
        for (Worker& w : workers) {
            if (w.seniorityWorker(year) > year)
            {
                w.showWorker();
            }
        }
        break;
    }
    case 2:
    {
        cout << "Введите зарплату, после которой необходимо найти: ";
        cin >> salary;
        for (Worker& w : workers) {
            if (w.getSalary() > salary)
            {
                w.showWorker();
            }
        }
        break;
    }
    case 3:
    {
        cout << "Введите должность, которую необходимо найти: ";
        cin >> position;
        for (Worker& w : workers) {
            if (w.getPosition() == position)
            {
                w.showWorker();
            }
        }
        break;
    }
    default:
        cout << "Ошибка ввода";
        break;
    }
}