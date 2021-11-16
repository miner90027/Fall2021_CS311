/*
 * treesorter.h
 * Aleks McCormick
 * 2021/11/08
 * Fall 2021 CS 311
 * Header for function template treesort
 * No source file
 */

#ifndef FALL2021_CS311_TREESORTER_H
#define FALL2021_CS311_TREESORTER_H

#include <iterator> // For std::iterator_traits
#include <memory>   // For std::unique_ptr & std::make_unique

// Node struct
// Contains the value stored in the node and unique_ptr to both the left and right children
// left & right children default to nullptr
template<typename DataType>
struct Node{
	using DataPtrU = std::unique_ptr<Node<DataType>>;
	DataType _data;
	DataPtrU _leftChild = nullptr;
	DataPtrU _rightChild = nullptr;
};

// insert()
// Inserts a value into a binary tree. If head is empty, then insert into current head.
//  	Insert into the left child recursively if the value passed is < current value in head.
//  	Insert into the right child recursively if the value passed is > current value in head.
//  	If the current value is = to the value passed, then to maintain stability, swap the current value with the
//  	passed value & insert the old value into the left child.
// Preconditions:
//  	head must be a valid unique_ptr, or nullptr if empty
// Requirements on types:
//  	DataType must have copy assignment & op< defined
// Strong Guarantee
template<typename DataType>
void insert(const DataType & k, std::unique_ptr<Node<DataType>> & head){
	if(!head){ // Check if head is nullptr
		// Create new unique_ptr to a Node
		head = std::make_unique<Node<DataType>>(); // This could throw
		// Assign the _data member of the node
		head -> _data = k;
	}
	else if(k < head -> _data){ // Check if given value is < value of current head
		// Recursively insert the given value into the left child of the current head
		insert(k, head -> _leftChild);
	}
	else if(head -> _data < k){ // Check if given value is > value of current head
		// Recursively insert the given value into the right child of the current head
		insert(k, head -> _rightChild);
	}
	else { // If the value given is neither < nor > value of current head, then it is =
		// Create temp variable to store value of current node
		auto temp = head -> _data;
		// Replace value of current node with the value passed
		head -> _data = k;
		// Insert previous value of current node into the left child
		insert(temp, head -> _leftChild);
	}
}

// traverse()
// Preforms an inorder traversal of the binary tree given iter value
// Preconditions:
//  	node must be a valid pointer to a binary tree node, or nullptr if empty
// Requirements on types:
//  	DataType must have copy assignment defined
//  	FDIter must have post increment defined
// No-Throw Guarantee
template<typename DataType, typename FDIter>
void traverse(std::unique_ptr<Node<DataType>> & node, FDIter & val){
	if(!node) return; // Check if current node is empty
	// Recursively iterate to the left child of the current node
	traverse(node -> _leftChild, val);
	// increment the FDIter
	*val++ = node -> _data;
	// Recursively iterate to the right child of the current node
	traverse(node -> _rightChild, val);
}


// treesort
// Sort a given range using Treesort.
// Preconditions:
//     Values stored in the range must have op< defined
// Requirements on Types:
//     FDIter must have copy assignment defined
// Exception safety guarantee:
//     Strong Guarantee
template<typename FDIter>
void treesort(FDIter first, FDIter last)
{
	// Value is the type that FDIter points to
	using Value = typename std::iterator_traits<FDIter>::value_type;

	// Create the tree root
	std::unique_ptr<Node<Value>> ptr;

	// Insert every value in the range into the binary tree
	for(FDIter cur = first; cur != last; ++cur){
		insert(*cur, ptr); // Could throw
	}

	// Traverse the binary tree to get the sorted list
	traverse(ptr, first);
}

#endif //FALL2021_CS311_TREESORTER_H