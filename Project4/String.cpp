#include <iostream>
#include "String.h"
#include <cstring>

String::String(const char* data) : _data(new char[strlen(data) + 1]) { // �������� ������ ��� ������ + 1 ��� \'0'
	std::cout << "String(const char* data) constructor\n";
	strcpy(_data, data); //�������� ������ �� _data � data
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
	return *this; //���������� ��������� �� str
}
//s[i] == s.data[i];
char String::operator[](size_t index) {
	return _data[index];
}


//���� �������� � �����������, ����� ������ �������� �� nullptr
/*String String::operator+(String& other) {
	std::cout << "operator+ was called\n";
	
	char* newData = new char[strlen(_data) + strlen(other._data) + 1]; //�������� ������ �� 
	strcpy(newData, _data); //� ����� ���� ������� ������ ���� � \0
	strcat(newData, other._data); //������� �� ����� ������� \0, ����� ���������� other._data � (� other._data ��� ����� \0)
	String resStr(newData); //������ ����� ������, �������� const char
	delete[] newData;
	return resStr;
	
}*/