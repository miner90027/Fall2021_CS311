/*
 * dp6.h
 * Aleks McCormick
 * 2021/11/04
 * Fall 2021 CS 311
 * Header file containing template
 *  functions & Classes for Project 6
 */

#ifndef FALL2021_CS311_DP6_H
#define FALL2021_CS311_DP6_H

#include <utility>  	// For std::move & std::pair
#include <memory>   	// For std::unique_ptr & std::make_unique
#include <cstddef>  	// For std::size_t
#include "llnode2.h"

/******************************************/
/***            Exercise A              ***/
/******************************************/
// Exercise A - reverseList()
// Reverses the order of the given linked list
// Preconditions:
//  	head must point to a non-empty LLNode2 object
// No-Throw Guarantee
template<typename ValType>
void reverseList(std::unique_ptr<LLNode2<ValType>> & head){
	// Temporary variables used to store the pointers being
	//  	moved around
	std::unique_ptr<LLNode2<ValType>> newHead = nullptr;
	std::unique_ptr<LLNode2<ValType>> tempA;
	std::unique_ptr<LLNode2<ValType>> tempB;

	while (head){ // Iterate through the loop while not nullptr
		tempA = std::move(newHead); // Store pointer to the previous node
		tempB = std::move(head -> _next); // Store pointer to the next node

		newHead = std::move(head); // Update the previous node to == current node
		head = std::move(tempB); // Update the current node to == next node
		newHead -> _next = std::move(tempA); // Update the new next pointer of the previous node
	}
	head = std::move(newHead); // Reassign head to equal newHead
}// End reverseList

/******************************************/
/***            Exercise B              ***/
/******************************************/

// Exercise B - LLMap
// A list of associated <key, value> data sets, where the key and value
//  	data types are specified by the client. The list cannot contain duplicate keys;
//  	keys should be tested for equality using the == operator.
// LLMap objects cannot be copied or moved therefore the associated ctors are to be deleted.
// Invariants:
//  	KeyType must be a data type that can be compared using
//  		operator==
//  	_data must be a valid unique_ptr that points to an LLNode2
template<typename KeyType, typename ValueType>
class LLMap{
	/******************************************/
	/***              LLMap:                ***/
	/***          Ctors, Dtor, op=          ***/
	/******************************************/
public:
	// Default Constructor
	// No-Throw Guarantee
	LLMap(): _data(nullptr){}

	// Copy, move, & assigment operators are deleted
	//  	LLMap objects cannot be copied or moved
	// Copy Constructor
	LLMap(const LLMap<KeyType, ValueType> & other) = delete;
	// Move Constructor
	LLMap(LLMap<KeyType,ValueType> && other) = delete;
	// Copy Assignment operator
	LLMap & operator=(LLMap<KeyType, ValueType> & other) = delete;
	// Move Assignment operator
	LLMap & operator=(LLMap<KeyType, ValueType> && other) = delete;

	// Destructor
	// No-Throw Guarantee
	~LLMap() noexcept = default;

	/******************************************/
	/***              LLMap:                ***/
	/***      Public Member Functions       ***/
	/******************************************/

	// size()
	// Calculates the size of the LLMap
	// No-Throw Guarantee
	[[nodiscard]] std::size_t size() const {
		auto item = _data.get(); // Pointer to the current item in the list

		std::size_t counter = 0; // Counter to keep track of how many nodes are iterated over

		while(item){ // Iterate through the loop while not nullptr
			item = item->_next.get(); // Update the current position
			++counter; // increase counter
		}
		// Return the total number of nodes in the list
		//  	AKA: the size of the list
		return counter;
	}

	// empty()
	// Returns true or false depending upon if
	//  	_data is not a nullptr
	// No-Throw Guarantee
	[[nodiscard]] bool empty() const {
		return !_data;
	}

	// find() & find() const
	// No-Throw Guarantee
	const ValueType * find(const KeyType & k) const{
		auto item = _data.get(); // pointer to the current item in the list

		while(item){ // Iterate through the loop while not nullptr
			if(item -> _data.first == k){
				// Check to see if the key of the current item
				//  	equals the key being searched for
				// Return the value for the associated key
				return &item -> _data.second;
			}
			item = item -> _next.get(); // Update the current position
		}
		// Return nullptr if an item with the given key
		//  	cannot be found in the list
		return nullptr;
	}
	ValueType * find(const KeyType & k){
		auto item = _data.get(); // pointer to the current item in the list

		while(item){ // Iterate through the loop while not nullptr
			if(item -> _data.first == k){
				// Check to see if the key of the current item
				//  	equals the key being searched for
				// Return the value for the associated key
				return &item -> _data.second;
			}
			item = item -> _next.get(); // Update the current position
		}
		// Return nullptr if an item with the given key
		//  	cannot be found in the list
		return nullptr;
	}

	// insert()
	// Strong Guarantee
	void insert (KeyType k, ValueType v){
		// Find the location of the value in the list for
		//  	the associated key
		auto found = find(k);

		if(!found){ // Check if the key was not found
			// Make a new pair and add it to the list
			push_front(_data, std::make_pair(k,v));
		}
		else
			// Replace the value of the old item with the new value
			*found = v;
	}

	// erase()
	// No-Throw Guarantee
	void erase(const KeyType k){
		// pointer to the current item in the list
		auto curItem = _data.get();
		// pointer to the previous item in the list
		auto prevItem = _data.get();

		while(curItem){ // Iterate through the loop while not nullptr
			// Determine if the key for the current item matches the key given
			if(curItem -> _data.first == k){
				// Reassign the _next pointer of the previous item to the
				//  	_next pointer of the current item. This deletes the
				//  	current item and changes the previous node to point to
				//  	the next node in the list after the current node.
				prevItem -> _next = std::move(curItem -> _next);
				return; // Exit the function
			}

			prevItem = curItem; // Update the previous Item
			curItem = curItem -> _next.get(); // update the current position
		}
	}

	/******************************************/
	/***              LLMap:                ***/
	/***  Public Template Member Functions  ***/
	/******************************************/

	// traverse()
	// Apply the given function to every item in the list
	// Preconditions:
	//  	FuncType defined by client must have 2 parameters
	//  		of types KeyType & ValType. FuncType is expected
	//  		to return nothing.
	// Basic guarantee
	template<typename FuncType>
	void traverse(FuncType func){
		// used to the location of the head of the list
		auto item = _data.get();
		while (item){ // Iterate through the loop while not nullptr
			// Unknown what func does to the data & what it may throw
			func(item -> _data.first, item -> _data.second);
			item = item -> _next.get(); // update the current position
		}
	}

	/******************************************/
	/***              LLMap:                ***/
	/***        Private Data Members        ***/
	/******************************************/
private:
	// A pointer to the LLNode2 of key/value pairs
	std::unique_ptr<LLNode2<std::pair<KeyType, ValueType>>> _data;
};// End class LLMap

#endif //FALL2021_CS311_DP6_H
