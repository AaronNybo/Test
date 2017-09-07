#include "StaticString.h"
#include <cstddef>
#include <stdexcept>
#include <ctype.h>
#include <stdio.h>

using std::out_of_range;

StaticString::StaticString() {
	//Initializes an empty string.
	cstr[0] = '\0';
	length = 0;
}

StaticString::StaticString(const char* str) {
	//Checks length of passed in string and copies it to the private cstr array. Throws out_of_range if the string does not fit.
	int i = 0;
	int j = 0;
	while (*str != '\0' && i < 64) {
		cstr[i] = *str;
		str++;
		i++;
	}
	if (i > 63) {
		throw out_of_range("Out of Bounds");
	}
	else {
		length = i;
		cstr[i] = '\0';
	}
}

int StaticString::len() const {
	//Checks the length of the string in the private cstr array. Returns the length.
	int i = 0;
	while (cstr[i] != '\0' && i < 64) {
		i++;
	}
	return i;
}

int StaticString::capacity() const {
	//Returns the static variable CAPACITY, representing 63, as the capacity of the array.
	return CAPACITY;
}

const char* StaticString::c_str() const {
	//Assigns and returns a pointer to the char buffer of the private cstr varaiable.
	const char* a = "";
	a = &cstr[0];
	return a;
}

char& StaticString::char_at(int position) {
	//After bounds checking, returns a reference to a value at a specific position in the cstr array.
	if (position > length || position < 0) {
		throw out_of_range("Out of Bounds");
	}
	char* a = &cstr[position];
	return *a;
}

char StaticString::char_at(int position) const {
	//After bounds checking, returns a copy of the character at a specific position in the cstr array.
	if (position > length || position < 0) {
		throw out_of_range("Out of Bounds");
	}
	char b = cstr[position];
	return b;
}

char& StaticString::operator[](int position) {
	//After bounds checking, returns a reference to a character at a specific position in the cstr array.
	if (cstr[position] == '\0') {
		throw out_of_range("Out of Bounds");
	}
	char* a = &cstr[position];
	return *a;
}

char StaticString::operator[](int position) const {
	//After bounds checking, returns copy of the character at a specific position in the cstr array.
	if (cstr[position] == '\0') {
		throw out_of_range("Out of Bounds");
	}
	char a = cstr[position];
	return a;
}

bool StaticString::isPrefix(const StaticString& other) const {
	//Returns true if other is a prefix of this string. Checks lengths and compares characters.
	int i = 0;
	while (other.cstr[i] == cstr[i] && other.cstr[i] != '\0') {
		i++;
		if (len() == 0) {
			break;
		}
	}
	if (other.len() > len()) {
		return false;
	}
	else if (other.len() == i || other.cstr[0] == '\0') {
		return true;
	}
}

bool StaticString::isIPrefix(const StaticString& other) const {
	//Returns true if other is a prefix of this string. Checks lengths and compares characters without considering Case.
	int i = 0;
	StaticString a = other;
	StaticString b = *this;
	a.toLower();
	b.toLower();
	while (a.cstr[i] == b.cstr[i] && a.cstr[i] != '\0') {
		i++;
		if (len() == 0) {
			break;
		}
	}
	if (a.len() > b.len()) {
		return false;
	}
	else if (a.len() == i || a.cstr[0] == '\0') {
		return true;
	}
	else {
		return false;
	}
}

bool StaticString::isSuffix(const StaticString& other) const {
	//Returns true if other is a suffix of this string. Checks lengths and compares characters.
	int i = 0;
	if (other.len() <= len()) {
		while (!(i > other.len()) && other.cstr[other.len() - i] == cstr[len() - i]) {
			i++;
		}
		if (len() == 0 || other.len() > len()) {
			return false;
		}
		else if (other.len() == 0) {
			return true;
		}
		else if (other.length < i) {
			return true;
		}
	}
	else {
		return false;
	}
}

bool StaticString::isISuffix(const StaticString& other) const {
	//Returns true if other is a suffix of this string. Checks lengths and compares characters without Considering Case.
	int i = 0;
	StaticString a = other;
	StaticString b = *this;
	a.toLower();
	b.toLower();
	if (a.len() <= b.len()) {
		while (!(i > a.len()) && a.cstr[a.len() - i] == b.cstr[b.len() - i]) {
			i++;
		}
		if (b.len() == 0 || a.len() > b.len()) {
			return false;
		}
		else if (a.len() == 0) {
			return true;
		}
		else if (a.length < i) {
			return true;
		}
	}
	return false;
}

StaticString& StaticString::trim() {
	//Removes taling and leading spaces from a string.
	char c;
	int i = 0;
	int j = len() - 1;
	int k = 0;
	if (isspace(cstr[i])) {
		while (isspace(cstr[i])) {
			i++;
		}
		if (i == len()) {
			cstr[0] = '\0';
			return *this;
		}
		while (isspace(cstr[j])) {
			j--;
		}
		int l = j - i;
		do {
			cstr[k] = cstr[i];
			i++;
			k++;
		} while (i <= j);
		cstr[l + 1] = '\0';
	}
	return *this;
}

StaticString& StaticString::toLower() {
	//Makes all characters of the array lower case.
	int i = 0;
	char c;
	while (cstr[i])
	{
		c = cstr[i];
		cstr[i] = (tolower(c));
		i++;
	}
	return *this;
}

StaticString& StaticString::toUpper() {
	//Makes all characters of the array upper case.
	int i = 0;
	char c;
	while (cstr[i])
	{
		c = cstr[i];
		cstr[i] = (toupper(c));
		i++;
	}
	return *this;
}

StaticString StaticString::operator+(const StaticString& other) const {
	//Overloaded operator that performs a concatenation between two objects of the StaticString class. Includes error handling.
	StaticString a;
	int i = 0;
	if ((other.len() + len()) > 63) {
		throw out_of_range("Out of Bounds");
	}
	while (i < 64) {
		a.cstr[i] = cstr[i];
		if (cstr[i] == '\0') {
			int j = 0;
			while (i < 64) {
				a.cstr[i] = other.cstr[j];
				i++;
				j++;
			}
		}
		i++;
	}
	return a;
}

StaticString StaticString::operator+(const char* str) const {
	//Overloaded operaor that performs a concatenation between an object of the StaticString class and a String. Includes error handling.
	StaticString a;
	int i = 0;
	int j = 0;
	while (*str != '\0') {
		str++;
		j++;
	}
	if ((j + len()) > 63) {
		throw out_of_range("Out of Bounds");
	}
	while (j != 0) {
		str--;
		j--;
	}
	while (i < 64) {
		a.cstr[i] = cstr[i];
		if (cstr[i] == '\0') {
			while (i < 64) {
				a.cstr[i] = *str++;
				i++;
			}
		}
		i++;
	}
	return a;
}

StaticString StaticString::concat(const StaticString& other) const {
	//Performs a concatenation between two objects of the StaticString class.
	StaticString a;
	int i = 0;
	while (i < 64) {
		a.cstr[i] = cstr[i];
		if (cstr[i] == '\0') {
			int j = 0;
			while (i < 64) {
				a.cstr[i] = other.cstr[j];
				i++;
				j++;
			}
		}
		i++;
	}
	return a;
}