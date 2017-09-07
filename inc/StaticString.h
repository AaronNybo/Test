#ifndef STATIC_STRING_H
#define STATIC_STRING_H

/**
* StaticString class which stores strings
* using fixed-size(static) char arrays.
*
* The char array should be null-terminated so
* as to be compatible with c_string functions.
*
* Certain methods assume an 8-bit ascii char representation.
*
* You are not allowed to remove or rename any of the
* data memebers of methods from this class.  However
* you can add additional data members and methods as
* you see fit.  You can also change the method
* implementations as needed.
*
*/
class StaticString {

public:
	/**
	* Default constructor. Initializes an empty string
	* with the default buffer capacity.
	* @see DEFAULT_CAPACITY
	*/
	StaticString();
	/**
	* c-string constructor. Creates a copy of
	* the provided c-string.  If the string does
	* not fit in the buffer an out_of_range error
	* should be thrown.
	* @param str the c-string to store.
	* @throws out_of_range error if the string does not fit in the buffer
	*/
	StaticString(const char* str);

	/** Get the number of chars in the string */
	int len() const;

	/** Get the total number of chars that can be stored */
	int capacity() const;

	/** Get a pointer to the char buffer */
	const char* c_str() const;

	/** Get a reference to the character at the specified position.
	* @param position the 0-based index to retreive.
	* @return the character at the specified position.
	*/
	char& char_at(int position);

	/** Get a copy of the character at the specified position.
	* @param position the 0-based index to retreive.
	* @return the character at the specified position.
	*/
	char char_at(int position) const;

	/** Get a reference to the character at the specified position.
	* @param position the 0-based index to retreive.
	* @return the character at the specified position.
	*/
	char& operator[](int position);

	/** Get a copy of the character at the specified position.
	* @param position the 0-based index to retreive.
	* @return the character at the specified position.
	*/
	char operator[](int position) const;

	/** Returns true if other is a prefix of this string.
	* @param other the string to check as a prefix.
	* @return bool true if other is a prefix.
	*/
	bool isPrefix(const StaticString& other) const;

	/** Returns true if other is a prefix of this string
	* ignoring character case.
	* @param other the string to check as a prefix.
	* @return bool true if other is a prefix.
	*/
	bool isIPrefix(const StaticString& other) const;

	/** Returns true if other is a suffix of this string.
	* @param other the string to check as a suffix.
	* @return bool true if other is a suffix.
	*/
	bool isSuffix(const StaticString& other) const;

	/** Returns true if other is a suffix of this string
	* ignoring character case.
	* @param other the string to check as a suffix.
	* @return bool true if other is a suffix.
	*/
	bool isISuffix(const StaticString& other) const;

	/** Removes leading and trailing whitespace.
	* The string is modified "in-place".
	* @return the StaticString with all leading and
	* trailing whitespace characters removed.
	*/
	StaticString& trim();

	/** Converts all characters to lowercase.
	* The characters are modified "in-place".
	* @return lowercase StaticString
	*/
	StaticString& toLower();

	/** Converts all characters to uppercase.
	* The characters are modified "in-place".
	* @return uppercase StaticString
	*/
	StaticString& toUpper();

	/** Returns a concatenation of this string and other.
	* The original strings are not modified.
	* @param other the string to append.
	* @returns the concatenated StaticString
	* @throws out_of_range error if the string does not fit in the buffer.
	*/
	StaticString operator+(const StaticString& other) const;

	/** Returns a concatenation of this string and other.
	* The original strings are not modified.
	* @param other the string to append.
	* @returns the concatenated StaticString
	* @throws out_of_range error if the string does not fit in the buffer.
	*/

	StaticString operator+(const char* str) const;

	StaticString concat(const StaticString& other) const;

private:
	static const int CAPACITY = 63;
	/** A pointer to the underlying null terminated char array */
	char cstr[CAPACITY + 1]; //Include a spot for the null character
	int length = 0;

};

#endif
