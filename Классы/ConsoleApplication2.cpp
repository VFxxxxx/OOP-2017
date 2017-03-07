// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

class MyClass
{
public:
	MyClass();
	MyClass(double a, double b);
	~MyClass();
	double c();
	void set_a(double a);
	void set_b(double b);
	double get_a();
	double get_b();
private:
	double a;
	double b;
};
MyClass::MyClass()
{
	this->a = 5;
	this->b = 2;
}

MyClass::MyClass(double a, double b)
{
	this->a = a;
	this->b = b;
}

MyClass::~MyClass()
{
	//delete &a;
	//delete &b;
}

double MyClass::c()
{
	return this->a += -this->b;
}

double MyClass::get_a() 
{
	return this->a;
}

double MyClass::get_b() 
{
	return this->b;
}

void MyClass::set_a(double a)
{
	this->a = a;
}

void MyClass::set_b(double b)
{
	this->b = b;
}

int main()
{
	MyClass obj(10.1,5.1);
	std::cout << obj.get_a() << "\n";
	std::cout << obj.get_b() << "\n";
	std::cout << obj.c() << "\n";
	obj.set_a(4.10);
	std::cout << obj.c() << "\n";
    return 0;
}

