#include <iostream>
#include "String.h"
#include <cstring>



int main() {

	String str("abc");

	std::cout << "First str: " << str << "\n";

	String str1(str);
	String str2("Bob");
	str = str2;

	std::cout << "Second str: " << str << "\n";

	String str3("Alice");

	/*String str4("AF");
	str4 = (str + str3);
		
	std::cout << "Third str: " << str << "\n";*/        












}