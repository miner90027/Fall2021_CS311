/*
 * dp6.h
 * Aleks McCormick
 * 2021/11/04
 * Fall 2021 CS 311
 * Header file containing template
 *  functions for Project 6
 */

#ifndef FALL2021_CS311_DP6_H
#define FALL2021_CS311_DP6_H

#include <utility>  	// For std::move & std::pair
#include <memory>   	//for std::unique_ptr & std::make_unique
#include "llnode2.h"

// Exercise A - reverseList()
// Reverses the order of the given linked list
// Preconditions:
//  	...
// 
template<typename ValType>
void reverseList(std::unique_ptr<LLNode2<ValType>> & head){

	std::unique_ptr<LLNode2<ValType>> newHead = nullptr;
	std::unique_ptr<LLNode2<ValType>> tempA;
	std::unique_ptr<LLNode2<ValType>> tempB;

	while (head){
		tempA = std::move(newHead);
		tempB = std::move(head -> _next);

		newHead = std::move(head);
		head = std::move(tempB);
		newHead -> _next = std::move(tempA);
	}

	head = std::move(newHead);
}// End reverseList

// Exercise B - LLMap
// A list of associated data sets
// Invariants:
//  	...
//
template<typename KeyType, typename ValueType>
class LLMap{
public:

	LLMap(){}

	LLMap(const LLMap<KeyType, ValueType> & other) = delete;
	LLMap(LLMap<KeyType,ValueType> && other) = delete;
	LLMap & operator=(LLMap<KeyType, ValueType> & other) = delete;
	LLMap & operator=(LLMap<KeyType, ValueType> && other) = delete;

	~LLMap() noexcept{}

	int size() const {
		return 0; // DUMMY
	}

	bool empty() const {
		return size() == 0;
	}

	ValueType* find(const KeyType & k) const{
		return nullptr; // DUMMY
	}
	ValueType* find(const KeyType & k){
		return nullptr; // DUMMY
	}

	void insert (KeyType k, ValueType v){}

	void erase(const KeyType k){}

	template<typename FuncType>
	void traverse(FuncType f){}

private:

	std::unique_ptr<LLNode2<std::pair<KeyType, ValueType>>> _data;
};// End class LLMap

#endif //FALL2021_CS311_DP6_H
