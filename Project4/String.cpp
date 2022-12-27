#include <iostream>
#include "String.h"
#include <cstring>

String::String(const char* data) : _data(new char[strlen(data) + 1]) { // выделяем память под строку + 1 под \'0'
	std::cout << "String(const char* data) constructor\n";
	strcpy(_data, data); //копируем данные из _data в data
}

String::~String() {
	std::cout << "~String() destructor\n";
	if (_data != nullptr) {
		delete[] _data;
	}
}

String::String(String& other) : _data(new char[strlen(other._data) + 1]) {
	std::cout << "Copy constructor was called\n";
	strcpy(_data, other._data);
}

String& String::operator=(String& other) {
	std::cout << "operator= was called\n";
	if (this != &other) {
		if (_data != nullptr){
		delete[] _data;
	}
	_data = new char[strlen(other._data) + 1];
	strcpy(_data, other._data);
	}
	return *this; //возвращаем указатель на str
}
//s[i] == s.data[i];
char String::operator[](size_t index) {
	return _data[index];
}


//Если работаем с указателями, нужно делать проверки на nullptr
/*String String::operator+(String& other) {
	std::cout << "operator+ was called\n";
	
	char* newData = new char[strlen(_data) + strlen(other._data) + 1]; //выделели память на 
	strcpy(newData, _data); //в новую дату положит строку дата и \0
	strcat(newData, other._data); //убирает из конца ньюДата \0, затем дописывает other._data и (в other._data уже лежит \0)
	String resStr(newData); //создаём новый объект, вызываем const char
	delete[] newData;
	return resStr;
	
}*/