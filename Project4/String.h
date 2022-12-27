#pragma once
#include "String.h"
#include <iostream>

class String
{
public:
	String(const char* data); //параметризованный конструктор
	~String(); //деструктор
	String(String& other); //конструктор копирования
	String& operator=(String& other); //перегрузка оператора присваивания
	//String& operator=(const char* other); //перегружаем оператор ещё раз (когда присваимваем одну объекту другой объект)

	//s[i] == s.operator[](i);
	char operator[](size_t index);
	friend std::ostream& operator<<(std::ostream& os, String& s) {//получили доступ к ф-ции чужого класса, возвращает ссылку 
		for (size_t i = 0; i < strlen(s._data); i++) {
			os << s[i];
		}
		return os;
	}

	//String operator+(String& other);



private:
	char* _data = nullptr;



};

