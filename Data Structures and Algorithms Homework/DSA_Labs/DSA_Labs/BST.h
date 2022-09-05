/*
File:			BST.h
Author(s):
	Base:		Justin Tackett
				jtackett@fullsail.com
	Student:

Created:		03.05.2021
Last Modified:	03.21.2021
Purpose:		A binary search tree
Notes:			Property of Full Sail University
*/

// Header protection
#pragma once

/************/
/* Includes */
/************/
#include <string>

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
#define LAB_7	1

// Individual unit test toggles
#define BST_CTOR								1
#define BST_NODE_CTOR							1
#define BST_CLEAR								1
#define BST_DTOR								1
#define BST_PUSH_ROOT							1
#define BST_PUSH_ROOT_LEFT						1
#define BST_PUSH_ROOT_RIGHT						1
#define BST_PUSH_LEFT							1
#define BST_PUSH_RIGHT							1
#define BST_CONTAINS_TRUE						1
#define BST_CONTAINS_FALSE						1
#define BST_REMOVE_CASE0_ROOT					1
#define BST_REMOVE_CASE0_LEFT					1
#define BST_REMOVE_CASE0_RIGHT					1
#define BST_REMOVE_CASE1_ROOT_LEFT				1
#define BST_REMOVE_CASE1_ROOT_RIGHT				1
#define BST_REMOVE_CASE1_LEFT_LEFT				1
#define BST_REMOVE_CASE1_LEFT_RIGHT				1
#define BST_REMOVE_CASE1_RIGHT_LEFT				1
#define BST_REMOVE_CASE1_RIGHT_RIGHT			1
#define BST_REMOVE_CASE2_NO_SUBTREE				1
#define BST_REMOVE_CASE2_SUBTREE				1
#define BST_REMOVE								1
#define BST_REMOVE_NOT_FOUND					1
#define BST_IN_ORDER_TRAVERSAL					1
#define BST_ASSIGNMENT_OP						1
#define BST_COPY_CTOR							1


#if LAB_7
// Templated binary search tree
template<typename Type>
class BST {

	friend class DSA_TestSuite_Lab7;	// Giving access to test code

	struct Node {
		Type data;					// The value being stored
		Node* left, * right;		// The left and right nodes
		Node* parent;				// The parent node

		// Constructor
		//		Always creates a leaf node
		//
		// In:	_data		The value to store in this node
		//		_parent		The parent pointer (optional)
		Node(const Type& _data, Node* _parent = nullptr) {
			// TODO: Implement this method
			data = _data;
			parent = _parent;
			left = nullptr;
			right = nullptr;
		}
	};

	// Data members
	Node* mRoot;	// The top-most Node in the tree

public:

	// Default constructor
	//			Always creates an empty tree
	BST() {
		// TODO: Implement this method

	}

	// Destructor
	//			Clear all dynamic memory
	~BST() {
		// TODO: Implement this method
		Clear();
	}

	// Copy constructor
		//			Used to initialize one object to another
		//
		// In:	_copy		The object to copy from
	BST(const BST<Type>& _copy) {
		// TODO: Implement this method
		*this = _copy;
	}

	// Assignment operator
	//			Used to assign one object to another
	//
	// In:	_assign		The object to assign from
	//
	// Return:	The invoking object (by reference)
	//		This allows us to daisy-chain
	BST<Type>& operator=(const BST<Type>& _assign) {
		// TODO: Implement this method
		Copy(_assign.mRoot);
		return *this;
	}

private:
	// Recursive helper method for use with Rule of 3
	// 
	// In:	_curr		The current Node to copy
	//
	// NOTE:	Use pre-order traversal
	void Copy(const Node* _curr) {
		// TODO: Implement this method
		if (_curr == nullptr)
			return;
		Push(_curr->data);
		Copy(_curr->left);
		Copy(_curr->right);
	}

public:

	// Clears out the tree and readies it for re-use
	void Clear() {
		// TODO: Implement this method
		Clear(mRoot);
		mRoot = nullptr;
	}

private:

	// Recursive helper method for use with Clear
	// 
	// In:	_curr		The current Node to clear
	//
	// NOTE:	Use post-order traversal
	void Clear(Node* _curr) {
		// TODO: Implement this method
		if (_curr != nullptr)
		{
			Clear(_curr->right);
			Clear(_curr->left);
			delete[] _curr;
		}
	}

public:

	// Add a value into the tree
	//
	// In:	_val			The value to add
	void Push(const Type& _val) {
		// TODO: Implement this method
		Push(_val, mRoot, nullptr); 
	}

private:

	// Optional recursive helper method for use with Push
	//
	// In:	_val		The value to add
	//		_curr		The current Node being looked at
	void Push(const Type& _val, Node* _curr, Node* _parent) {
		// TODO: Implement this method (Optional)
		Node* start = new Node(_val);
		if (mRoot == nullptr)
		{
			mRoot = start;
			mRoot->parent = nullptr;
		}
		else
		{
			Node* helper = _curr;
			if (start->data < _curr->data)
			{
				if (_curr->left == nullptr)
				{
					start->parent = _curr;
					_curr->left = start;
				}
				else if (_curr->left != nullptr)
				{
					delete start;
					Push(_val, _curr->left, nullptr);
				}
			}
			else
			{
				if (_curr->right == nullptr)
				{
					start->parent = _curr;
					_curr->right = start;
				}
				else if (_curr->right != nullptr)
				{
					delete start;
					Push(_val, _curr->right, nullptr);
				}
			}

		}
	}
	
public:

	// Checks to see if a value is in the tree
	//
	// In:	_val		The value to search for
	//
	// Return:	True, if found
	bool Contains(const Type& _val) {
		// TODO: Implement this method
		Node* temp = mRoot;
		bool cont = false;
		while (temp != nullptr)
		{
			if (_val < temp->data)
			{
				temp = temp->left;
			}
			else if (_val == temp->data)
			{
				cont = true;
				break;
			}
			else
			{
				temp = temp->right;
			}
		}
		return cont;
	}

private:

	// Optional helper method for use with Contains and Remove methods
	//
	// In:	_val		The value to search for
	//
	// Return: The node containing _val (or nullptr if not found)
	Node* FindNode(const Type& _val) {
		// TODO: Implement this method (Optional)
		Node* mew = mRoot;
		while (mew != nullptr)
		{
			if (mew->data == _val)
			{
				return mew;
			}
			else if (_val < mew->data)
			{
				mew = mew->left;
			}
			else
			{
				mew = mew->right;
			}
		}
		return nullptr;
	}

	// Remove a leaf node from the tree
	//		Case 0
	// 	   
	// In:	_node		The Case 0 node to remove
	//
	// Note: The node being passed in will always be a Case 0
	//		Remember to check all 3 subcases
	//		1. Root only
	//		2. Left leaf node
	//		3. Right leaf node
	void RemoveCase0(Node* _node) {
		// TODO: Implement this method
		if (_node == mRoot)
		{
			mRoot = nullptr;
		}
		else
		{
			if (_node->parent->left == _node)
			{
				_node->parent->left = nullptr;
			}
			else
			{
				_node->parent->right = nullptr;
			}
		}
		delete _node;
		_node = nullptr;
	}

	// Remove a node from the tree that has only one child
	//		Case 1
	//
	// In:	_node		The Case 1 node to remove
	//
	// Note: The node being passed in will always be a Case 1
	//		Remember to check all 6 subcases
	//		1. Root with left child
	//		2. Root with right child
	//		3. Left node with left child
	//		4. Left node with right child
	//		5. Right node with left child
	//		6. Right node with right child
	void RemoveCase1(Node* _node) {
		// TODO: Implement this method
		if (_node == mRoot)
		{
			if (mRoot->right == nullptr)
			{
				mRoot = mRoot->left;
			}
			else
			{
				mRoot = mRoot->right;

			}
			mRoot->parent = nullptr;
		}
		else
		{
			Node* mew = nullptr;
			if (_node->parent->left == _node)
			{
				if (_node->left != nullptr)
				{
					mew = _node->left;
					mew->parent = _node->parent;
					_node->parent->left = mew;

				}
				else
				{
					mew = _node->right;
					mew->parent = _node->parent;
					_node->parent->left = mew;
				}

			}
			else if (_node->parent->right == _node)
			{
				if (_node->left != nullptr)
				{
					mew = _node->left;
					mew->parent = _node->parent;
					_node->parent->right = mew;
				}
				else
				{
					mew = _node->right;
					mew->parent = _node->parent;
					_node->parent->right = mew;
				}
			}
		}
		delete _node;
	}

	// Remove a node from the tree that has both children
	//		Case 2
	//
	// In:	_node		The Case 2 node to remove
	//
	// Note: The node being passed in will always be a Case 2
	void RemoveCase2(Node* _node) {
		// TODO: Implement this method
		Node* mew = _node;
		Node* neo = _node->right;
		while (neo->left != nullptr)
		{
			neo = neo->left;
		}
		mew->data = neo->data;
		if (neo->right == nullptr && neo->left == nullptr)
		{
			RemoveCase0(neo);
		}
		else
		{
			RemoveCase1(neo);
		}
	}

public:

	// Removes a value from tree (first instance only)
	//
	// In:	_val			The value to search for
	//
	// Return:	True, if a Node was removed
	//
	// Note: Can use FindNode to get the node* to remove, 
	//		 and then call one of the RemoveCase methods
	bool Remove(const Type& _val) {
		// TODO: Implement this method
		Node* mew = FindNode(_val);
		bool removed = false;
		if (mew == nullptr)
		{
			removed = false;
		}
		else if (mew->right == nullptr && mew->left == nullptr)
		{
			RemoveCase0(mew);
			removed = true;
		}
		else if (mew->right == nullptr || mew->left == nullptr)
		{
			RemoveCase1(mew);
			removed = true;
		}
		else if (mew->right != nullptr || mew->left != nullptr)
		{
			RemoveCase2(mew);
			removed = true;
		}

		return removed;
	}

	// Returns a space-delimited string of the tree in order
	/*
	 Example:
			 24
			/ \
		   10  48
			\   \
			12   50

	 Should return: "10 12 24 48 50"
	*/
	// Note:	Use to_string to convert an int to its string equivelent
	//			Don't forget about the trailing space!

	std::string InOrder() {
		// TODO: Implement this method
		std::string mew;
		InOrder(mRoot, mew);
		mew.pop_back();
		return mew;
	}

private:

	// Recursive helper method to help with InOrder
	//
	// In:	_curr		The current Node being looked at
	//		_str		The string to add to
	//
	// NOTE:	Use in-order traversal
	void InOrder(Node* _curr, std::string& _str) {
		// TODO: Implement this method
		if (_curr->left != nullptr)
		{
			InOrder(_curr->left, _str);
		}
		_str += std::to_string(_curr->data) + (" ");
		if (_curr->right != nullptr)
		{
			InOrder(_curr->right, _str);
		}
	}
};

#endif	// End LAB_7