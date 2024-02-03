//4.2 Visibility and accesebility in the case of inheritance

#include <iostream>

class Base{
    public:
    int x;
    // protected:
    void f(double){ std::cout << 1;}; // Функция из дерайвд перекрывает область видимость этой функции из-за одинакового имени
 public:
    Base(int x): x(x){}
};

class Derived: public Base{
    public:
    using Base::Base; // наследуется конструктор, то есть можно заставить дерайвд конструироваться от всего того, что конструируется бейс. Но не наследуются конструкторы копирования и перемещения
    int x = 1;
    using Base::f; // привносит ф из простравства бейс в паблик, если ф от бейс протектед
    void f(int){ //для функции d.f() не видна функции из Base, даже если Base(double)
        std::cout << 2;
    }

};

int main(){
    Base b;
    Derived d;
    std::cout << d.x; //1 
    std::cout << d.Base::x; //1
    d.f(3); 
    d.Base::f(3.14); 
    return 0;
}