/*
File:			DList.h
Author(s):
	Base:		Justin Tackett
				jtackett@fullsail.com
	Student:

Created:		12.27.2020
Last Modified:	02.26.2021
Purpose:		A doubly-linked list (similar to std::list)
Notes:			Property of Full Sail University
*/

//Header protection
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
#define LAB_3	1

// Individual unit test toggles
#define LIST_CTOR						1
#define LIST_NODE_CTOR_DEFAULT			1
#define LIST_NODE_CTOR					1
#define LIST_ADDHEAD_EMPTY				1
#define LIST_ADDHEAD					1
#define LIST_ADDTAIL_EMPTY				1
#define LIST_ADDTAIL					1
#define LIST_CLEAR						1
#define LIST_DTOR						1
#define LIST_ITER_BEGIN					1
#define LIST_ITER_END					1
#define LIST_ITER_INCREMENT_PRE			1
#define LIST_ITER_INCREMENT_POST		1
#define LIST_ITER_DECREMENT_PRE			1
#define LIST_ITER_DECREMENT_POST		1
#define LIST_INSERT_EMPTY				1
#define LIST_INSERT_HEAD				1
#define LIST_INSERT						1
#define LIST_ERASE_EMPTY				1
#define LIST_ERASE_HEAD					1
#define LIST_ERASE_TAIL					1
#define LIST_ERASE						1
#define LIST_COPY_CTOR_INT				1
#define LIST_COPY_CTOR_USER_DEFINED		1
#define LIST_ASSIGNMENT_OP_INT			1
#define LIST_ASSIGNMENT_OP_USER_DEFINED	1

#if LAB_3

template<typename T>
class DList {

	friend class DSA_TestSuite_Lab3;	// Giving access to test code

	struct Node {
		T data;
		Node* next, * prev;
		Node(const T& _data, Node* _next = nullptr, Node* _prev = nullptr) {
			// TODO: Implement this method
			data = _data;
			next = _next;
			prev = _prev;
		}
	};

public:

	class Iterator {
	public:

		Node* mCurr;

		// Pre-fix increment operator
		//
		// Return: Invoking object with curr pointing to next node
		// 
		// Example:
		//		I - Iterator's curr
		//		R - Return
		/*
			Before

			0<-[4]<->[5]<->[6]->0
					  I

			After

			0<-[4]<->[5]<->[6]->0
							I
							R
		*/
		Iterator& operator++() {
			// TODO: Implement this method
			mCurr = mCurr->next;
			return *this;
		}

		// Post-fix increment operator
		//
		// In:	(unused)		Post-fix operators take in an unused int, so that the compiler can differentiate
		//
		// Return:	An iterator that has its curr pointing to the "old" curr
		// NOTE:	Will need a temporary iterator 
		//
		// Example:
		//		I - Iterator's curr
		//		R - Return
		/*
			Before

			0<-[4]<->[5]<->[6]->0
					  I

			After

			0<-[4]<->[5]<->[6]->0
					  R		I

		*/
		Iterator operator++(int) {
			// TODO: Implement this method
			DList<int>::Iterator temp = *this;
			mCurr = mCurr->next;
			return temp;
		}

		// Pre-fix decrement operator
		//
		// Return: Invoking object with curr pointing to previous node
		//
		// Example:
		//		I - Iterator's curr
		//		R - Return
		/*
			Before

			0<-[4]<->[5]<->[6]->0
					  I

			After

			0<-[4]<->[5]<->[6]->0
				I
				R
		*/
		Iterator& operator--() {
			// TODO: Implement this method
			mCurr = mCurr->prev;
			return *this;
		}

		// Post-fix decrement operator
		//
		// In:	(unused)		Post-fix operators take in an unused int, so that the compiler can differentiate
		//
		// Return:	An iterator that has its curr pointing to the "old" curr
		// NOTE:	Will need a temporary iterator 
		//
		// Example:
		//		I - Iterator's curr
		//		R - Return
		/*
			Before

			0<-[4]<->[5]<->[6]->0
					  I

			After

			0<-[4]<->[5]<->[6]->0
				I	  R

		*/
		Iterator operator--(int) {
			// TODO: Implement this method
		    DList<int>::Iterator temp = *this;
			mCurr = mCurr->prev;
			return temp;
		}

		// Dereference operator
		//
		// Return: The data the curr is pointing to
		T& operator*() {
			// TODO: Implement this method
			return mCurr;
		}

		// Not-equal operator (used for testing)
		// 
		// In:	_iter		The iterator to compare against
		//
		// Return: True, if the iterators are not pointing to the same node
		bool operator != (const Iterator& _iter) const {
			return mCurr != _iter.mCurr;
		}
	};

	// Data members
	Node* mHead;		// The head (first node) of the list
	Node* mTail;		// The tail (last node) of the list
	size_t mSize;		// Current number of nodes being stored

public:

	// Default constructor
	//		Creates a new empty linked list
	DList() {
		// TODO: Implement this method
		mHead = nullptr;
		mTail = nullptr;
		mSize = 0;
	}

	// Destructor
	//		Cleans up all dynamically allocated memory
	~DList() {
		// TODO: Implement this method
		if (mTail == nullptr)
		{
			mHead = nullptr;
		}
		else
		{
			Node* star = mTail;
			mTail = mTail->prev;
			delete(star);
			mSize--;
			Clear();
		}
	}

	// Copy constructor
	//		Used to initialize one object to another
	//
	// In:	_copy			The object to copy from
	DList(const DList& _copy) {
		// TODO: Implement this method
		*this = _copy;
	}

	// Assignment operator
	//		Used to assign one object to another
	// In:	_asign			The object to assign from
	//
	// Return: The invoking object (by reference)
	//		This allows us to daisy-chain
	DList& operator=(const DList& _assign) {
		// TODO: Implement this method
		Node* mew = _assign.mTail;
		if(this == &_assign)
		{
			return *this;
		}
		while (mew != nullptr)
		{
			AddHead(mew->data);
			mew = mew->prev;
		}
		return *this;
	}

private:

	// Optional recursive helper method for use with Rule of 3
//
// In:	_curr		The current Node to copy
	void RecursiveCopy(const Node* _curr) {
		// TODO (optional): Implement this method

	}

public:

	// Add a piece of data to the front of the list
//
// In:	_data			The object to add to the list
	void AddHead(const T& _data) {
		// TODO: Implement this method
		Node* head2 = new Node(_data, nullptr, nullptr);
		if (mHead == nullptr)
		{
			mHead = head2;
			mTail = head2;
			mSize++;
		}
		else
		{
			head2->next = mHead;
			mHead->prev = head2;
			mHead = head2;
			mSize++;
		}
	}

	// Add a piece of data to the end of the list
//
// In:	_data			The object to add to the list
	void AddTail(const T& _data) {
		// TODO: Implement this method
		Node* tail2 = new Node(_data, nullptr, nullptr);
		if (mTail == nullptr)
		{
			mTail = tail2;
			mHead = tail2;
			mSize++;
		}
		else
		{
			tail2->prev = mTail;
			mTail->next = tail2;
			mTail = tail2;
			mSize++;
		}
	}

	// Clear the list of all dynamic memory
	//			Resets the list to its default state
	void Clear() {
		// TODO: Implement this method
		if (mTail == nullptr)
		{
			mHead = nullptr;
		}
		else
		{
			Node* star = mTail;
			mTail = mTail->prev;
			delete(star);
			mSize--;
			Clear();
		}
	}

private:

	// Optional recursive helper method for use with Clear
	// 
	// In:	_curr		The current Node to clear
	void RecursiveClear(const Node* _curr) {
		// TODO (Optional): Implement this method
		
	}

public:

	// Insert a piece of data *before* the passed-in iterator
	//
	// In:	_iter		The iterator
	//		_data		The value to add
	//
	// Example:
	/*
		Before

			0<-[4]<->[5]<->[6]->0
					  I

		After

			0<-[4]<->[9]<->[5]<->[6]->0
					  I
	*/
	// Return:	The iterator
	// SPECIAL CASE:	Inserting at head or empty list
	// NOTE:	The iterator should now be pointing to the new node created
	Iterator Insert(Iterator& _iter, const T& _data) {
		Node* neo = new Node(_data);
		if (mSize == 0)
		{
			mSize++;
			_iter.mCurr = neo;
			mHead = neo;
			mTail = neo;
		}
		else if (_iter.mCurr == mHead)
		{
			mSize++;
			mHead->prev = neo;
			neo->next = mHead;
			mHead = neo;
			_iter.mCurr = neo;
		}
		else
		{
			mSize++;
			_iter.mCurr->prev->next = neo;
			neo->prev = _iter.mCurr->prev;
			neo->next = _iter.mCurr;
			_iter.mCurr->prev = neo;
			_iter.mCurr = neo;
		}
		return _iter;
	}

	// Erase a Node from the list
	//
	// In:	_iter		The iterator
	//
	// Example
	/*

		Before

			0<-[4]<->[5]<->[6]->0
					  I

		After

			0<-[4]<->[6]->0
					  I
	*/
	// Return:	The iterator
	// SPECIAL CASE:	Erasing head or tail
	// NOTE:	The iterator should now be pointing at the node after the one erased
	Iterator Erase(Iterator& _iter) {
		// TODO: Implement this method
		Node* star = _iter.mCurr;
		if (mSize == 0)
		{

		}
		else if (_iter.mCurr == mHead)
		{
			_iter.mCurr = mHead->next;
			mHead = mHead->next;
			mHead->prev = nullptr;
			delete(star);
			mSize--;
		}
		else if (_iter.mCurr == mTail)
		{
			_iter.mCurr = nullptr;
			mTail = mTail->prev;
			mTail->next = nullptr;
			delete(star);
			mSize--;
		}
		else
		{
			_iter.mCurr->prev->next = _iter.mCurr->next;
			_iter.mCurr->next->prev = _iter.mCurr->prev;
			_iter.mCurr = _iter.mCurr->next;
			delete(star);
			mSize--;
		}
		return _iter;
	}

	// Set an Iterator at the front of the list
	// 
	// Return: An iterator that has its curr pointing to the list's head
	Iterator Begin() {
		// TODO: Implement this method
		DList::Iterator mew;
		mew.mCurr = mHead;
		return mew;
	}

	// Set an Iterator pointing to the end of the list
	// 
	// Return: An iterator that has its curr pointing to a null pointer
	Iterator End() {
		// TODO: Implement this method
		DList::Iterator nya;
		nya.mCurr = nullptr;
		return nya;
	}
};

#endif	// End LAB_3