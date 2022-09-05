/*
File:			DSA_Lab2.h
Author(s):
	Base:		Justin Tackett
				jtackett@fullsail.com
	Student:

Created:		11.30.2020
Last Modified:	02.26.2021
Purpose:		Usage of the std::vector class
Notes:			Property of Full Sail University
*/

// Header protection

#pragma once

/***********/
/* Defines */
/***********/

/*
How to use:

	When working on a lab, turn that lab's #define from 0 to 1

		Example:	#define LAB_1	1

	When working on an individual unit test, turn that #define from 0 to 1

		Example:	#define DYNARRAY_DEFAULT_CTOR	1

NOTE: If the unit test is not on, that code will not be compiled!
*/

// Master toggle
#define LAB_2	1

// Individual unit test toggles
#define LAB2_PALINDROME_NUMBER			1
#define LAB2_VECTOR_FILL_FILE			1
#define LAB2_VECTOR_FILL_ARRAY			1
#define LAB2_VECTOR_CLEAR				1
#define LAB2_VECTOR_SORT_ASCENDING		1
#define LAB2_VECTOR_SORT_DESCENDING		1
#define LAB2_VECTOR_BRACKETS			1
#define LAB2_VECTOR_CONTAINS_TRUE		1
#define LAB2_VECTOR_CONTAINS_FALSE		1
#define LAB2_VECTOR_MOVE_PALINDROME		1

/************/
/* Includes */
/************/
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

#if LAB_2

// Checks to see if a number is a palindrome (reads the same forwards and backwards)
//		An example of a palindrome word would be "racecar"
//
// In: _num			The number to check
//
// Return: True, if the number is a palindrome number
inline bool IsPalindromeNumber(unsigned int _num) {
	// TODO: Implement this method
	bool palindrome = true;
	int back = 0;
	int num = _num;
	while (num > 0)
	{
		back = back * 10 + num % 10;
		num /= 10;
	}
	if (_num == back)
	{
		return palindrome;
	}
	else
	{
		palindrome = false;
	}
	return palindrome;
}

class DSA_Lab2
{
	friend class DSA_TestSuite_Lab2;	// Giving access to test code

private:

	std::vector<unsigned int> mValues;		// contains all of the values
	std::vector<unsigned int> mPalindromes;	// contains just the numbers that are palindromes (only used in MovePalindromes method)

public:

	// Fill out the mValues vector with the contents of the binary file
	//		First four bytes of the file are the number of ints in the file
	//
	// In:	_input		Name of the file to open
	void Fill(const char* _input) {
		// TODO: Implement this method
		/*fstream file;

		file.open(_input, ios::binary);
		if (file.good())
		{

			for (int count = 0; count < mValues.size(); count++)
			{
				file.read(reinterpret_cast<char*>(&mValues[count]), sizeof(mValues[count]));
			}
		}
		file.close();*/
	}

	// Fill out the mValues vector with the contents of an array
	//
	// In:	_arr			The array of values
	//		_size			The number of elements in the array
	void Fill(const unsigned int* _arr, size_t _size) {
		// TODO: Implement this method
		for (int i = 0; i < _size; i++)
		{
			mValues.push_back(_arr[i]);
		}
	}

	// Remove all elements from vector and decrease capacity to 0
	void Clear() {
		// TODO: Implement this method
		mValues.clear();
		mValues.shrink_to_fit();
	}

	// Sort the vector 
	//
	// In:	_ascending		To sort in ascending order or not
	//
	// NOTE: Use the std::sort method in this implementation
	void Sort(bool _ascending) {
		// TODO: Implement this method
		if (_ascending == true)
		{
			sort(mValues.begin(), mValues.end());
		}
		else
		{
			sort(mValues.rbegin(), mValues.rend());
		}
	}

	// Get an individual element from the mValues vector
	int operator[](int _index) {
		// TODO: Implement this method
		return mValues[_index];
	}

	// Determine if a value is present in the vector
	// 
	// In:	_val		The value to check for
	//
	// Return: True, if the value is present
	bool Contains(unsigned int _val) const {
		// TODO: Implement this method
		bool hunt = true;
		if (find(mValues.begin(), mValues.end(), _val) != mValues.end())
		{
			return hunt;
		}
		else
		{
			hunt = false;
		}
		return hunt;
	}

	// Move all palindrome numbers from mValues vector to mPalindromes vector
	//
	// Pseudocode:
	//		iterate through the main values vector
	//			if the value is a palindrome
	//				add it to the palindrome vector
	//				remove it from the values vector
	void MovePalindromes() {
		// TODO: Implement this method
		for (int i = 0; i < mValues.size(); i++)
		{
			if (IsPalindromeNumber(mValues[i]) == true)
			{
				mPalindromes.push_back(mValues[i]);
				mValues.erase(mValues.begin() + i);
			}
		}
	}
};

#endif	// End LAB_2