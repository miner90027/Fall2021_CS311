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
#include <memory>   	// For std::unique_ptr & std::make_unique
#include <cstddef>  	// For std::size_t
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

	LLMap(): _data(nullptr){}

	LLMap(const LLMap<KeyType, ValueType> & other) = delete;
	LLMap(LLMap<KeyType,ValueType> && other) = delete;
	LLMap & operator=(LLMap<KeyType, ValueType> & other) = delete;
	LLMap & operator=(LLMap<KeyType, ValueType> && other) = delete;

	~LLMap() noexcept = default;


	[[nodiscard]] std::size_t size() const {
		auto item = _data.get();
		std::size_t counter = 0;

		while(item){
			item = item->_next.get();
			++counter;
		}

		return counter;
	}

	[[nodiscard]] bool empty() const {
		return !_data;
	}

	const ValueType * find(const KeyType & k) const{
		auto item = _data.get();

		while(item){
			if(item -> _data.first == k)
				return &item -> _data.second;
			item = item -> _next.get();
		}

		return nullptr; // DUMMY
	}

	ValueType * find(const KeyType & k){
		auto item = _data.get();

		while(item){
			if(item -> _data.first == k)
				return &item -> _data.second;
			item = item -> _next.get();
		}

		return nullptr; // DUMMY
	}

	void insert (KeyType k, ValueType v){
		auto found = find(k);

		if(!found){
			push_front(_data, std::make_pair(k,v));
		}
		else
			*found = v;
	}

	void erase(const KeyType k){
		auto curItem = _data.get();
		auto prevItem = _data.get();

		while(curItem){
			if(curItem -> _data.first == k){
				prevItem -> _next = std::move(curItem -> _next);
				return;
			}

			prevItem = curItem;
			curItem = curItem -> _next.get();
		}
	}

	template<typename FuncType>
	void traverse(FuncType func){
		auto item = _data.get();

		while (item){
			func(item -> _data.first, item -> _data.second);
			item = item -> _next.get();
		}
	}

private:

	std::unique_ptr<LLNode2<std::pair<KeyType, ValueType>>> _data;
};// End class LLMap

#endif //FALL2021_CS311_DP6_H
