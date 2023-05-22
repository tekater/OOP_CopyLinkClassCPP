#pragma warning(disable:4996)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

using namespace std;

class Date {
    int day, month, year;
public:

    Date(int d, int m, int y) : day{ d }, month{ m }, year{ y } {
        cout << "отработал " << this << " конструктор \n";
    };

    Date() : Date{ 21,07,1981 } {};

    Date(Date& object) :day{ object.day }, month{ object.month }, year{ object.year } { // Поверхностное копирование
        cout << "отработал Ссылочный " << this << " конструктор \n";
    };

    void print() {
        cout << day << "." << month << "." << year << "\n";
    }
    Date& setDay(int day) {
        this->day = day;
        return*this;
    }
    Date& setMonth(int month) {
        this->month = month;
        return*this;
    }
    Date& setYear(int year) {
        this->year = year;
        return*this;
    }
    ~Date(){
        cout << "отработал " << this << " деструктор \n";
    }
};

class Array {
    int* arr;
    int size;
public:
    Array(int usize = 5) : arr{ new int[usize] }, size{ usize }
    {
        randomize(10, 20);
        cout << "Конструктор " << this << " с параметром\n";
    }
    Array(const Array& obj) : arr(obj.arr), size(obj.size) {

    }
    ~Array()
    {
        if (arr)
        {
            delete[]arr;
        }
        cout << "Деструктор\n";
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void randomize(int a, int b) //10 20
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = a + rand() % (b - a + 1); //10-29
        }
    }
    void setElem(int ind, int x)
    {
        arr[ind] = x;
    }
    int getElem(int ind)
    {
        return arr[ind];
    }
};

class Student {
    char* name;
    int* marks;
    int size;
    static int group;
    void createname(const char* uname)
    {
        name = new char[strlen(uname) + 1];
        strcpy_s(name, strlen(uname) + 1, uname);
    }
    void createmarks(int* umarks, int usize)
    {
        marks = new int[usize];
        for (int i = 0; i < usize; i++)
        {
            marks[i] = umarks[i];
        }
        size = usize;
    }
public:
    Student(const char* uname, int* umarks, int usize)
    {
        createname(uname);
        createmarks(umarks, usize);
        cout << "Начал > " << this << "\n";
    }
    Student() : Student{ "Noname", new int[3] { 1,1,1 }, 3 } {}
    Student(const char* uname) : Student{ uname, new int[3] { 1,1,1 }, 3 } {};
    Student(int* umarks, int usize) : Student{ "Noname", umarks, usize } {}

    Student(const Student& first) : name{ new char[strlen(first.name)+1] }, marks{ new int[first.size] }, size{ first.size } { 
        cout << "Начал > " << this << "\n"; 
        strcpy_s(name, strlen(first.name) + 1, first.name);
        for (int i = 0; i < size; i++)
        {
            marks[i] = first.marks[i];
        }

    };
    void print()
    {
        cout << "Имя: " << name << endl;
        cout << "Оценки: ";
        for (int i = 0; i < size; i++)
        {
            cout << marks[i] << " ";
        }
        cout << endl;
        cout << "Группа: " << group << endl;
    }
    void setName(const char* uname)
    {
        delete[]name;
        createname(uname);
    }
    void setMarks(int* umarks, int usize)
    {
        delete[]marks;
        createmarks(umarks, usize);
    }
    void setGroup(int g)
    {
        group = g;
    }
    static int getGroup()
    {
        return group;
    }
    ~Student()
    {
        if (name)
        {
            delete[]name;
        }
        if (marks)
        {
            delete[]marks;
        }
        cout << "Выполнил > " << this << "\n";
    }
};

int Student::group{ 5 };

void main() {

    setlocale(0, "");
    srand(time(NULL));

    int arr[3]{ 5,5,5 };

    Student ars{ "Олег",arr,3 };
    //ars.setGroup(5);
    ars.print(); cout << "\n";

    Student brs{ ars };
    brs.print(); cout << "\n";

}
