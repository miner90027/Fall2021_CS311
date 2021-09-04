/*
 * delivery.h
 * Aleks McCormick
 * 2021/09/01
 * Fall 2021 CS 311
 * Header file for Delivery class
 * Prototype all the functions and data members for the class
 */

#ifndef FALL2021_CS311_DELIVERY_H
#define FALL2021_CS311_DELIVERY_H

#include <string> 	// for std::string
#include <vector> 	// for std::vector
#include <ostream>	// for std::ostream
#include <cassert>  // for assert

class Delivery {
	/********************************************************************/
	/**					Global Overloaded Operators		 			  ***/
	/********************************************************************/
	//operator<<
	// outputs the string created by toString into an output stream
    friend std::ostream &operator<<(std::ostream &os, const Delivery &dliv);

public:
	/********************************************************************/
	/**							Constructors			 			  ***/
	/********************************************************************/
	//default constructor
	// sets the product name, amount, and month of delivery to default values
    Delivery();

	//constructor that takes 3 parameters
	// takes in the  product name, amount, and month of delivery
    Delivery(const std::string& prdct, int qunt, int mon);

	/********************************************************************/
	/**						Modify Data Members			 			  ***/
	/********************************************************************/

	//setName
	//sets the product name to the string passed
    void setName(const std::string& prdct);

	//setQuantity
	//sets the amount of product to the int passed so long as it is positive
    void setQuantity(int qunt);

	//setMonth
	//sets the month of delivery to the int passed so long as it is within
	// the specified range between 1 && 12
    void setMonth(int mon);

	/********************************************************************/
	/***					Read Data Members			 			  ***/
	/********************************************************************/

	//getName
	//returns the product name as a string
    [[nodiscard]] std::string getName() const &;

	//getQuantity
	//returns the amount of product as an int
    [[nodiscard]] int getQuantity() const &;

	//getMonth
	//returns the month of delivery as an int
    [[nodiscard]] int getMonth() const &;

	/********************************************************************/
	/***					Other Member Functions		 			  ***/
	/********************************************************************/

	//toStirng
	//converts the data stored in a Delivery object into a readable string
	//formatted as such: _product (_quantity), _month of the year
    [[nodiscard]] std::string toString() const;

	//empty
	// returns true if the quantity is zero and false if otherwise
    [[nodiscard]] bool empty() const &;

	/********************************************************************/
	/***				Overloaded Boolean Operators				  ***/
	/********************************************************************/

	//operator==
	//compares two Delivery objects and returns true if all the data members
	// are the same
	bool operator==(const Delivery & d2) const;

	//operator!=
	//compares two Delivery objects but returns the opposite of operator==
	bool operator!=(const Delivery & d2) const;

	/********************************************************************/
	/***			 Overloaded Mathematical Operators		 		  ***/
	/********************************************************************/

	//pre-increment operator++
	//increments the quantity of a Delivery object by 1
	Delivery & operator++();

	//pre-decrement operator--
	//decrements the quantity of a Delivery object by 1 if it is greater than 0
	Delivery & operator--();

	//post-increment operator++
	//increments the quantity of a Delivery object by 1
	Delivery operator++([[maybe_unused]]int dummy);

	//post-decrement operator--
	//decrements the quantity of a Delivery object by 1 if it is greater than 0
	Delivery operator--([[maybe_unused]]int dummy);

	/********************************************************************/
	/***						Data Members			 			  ***/
	/********************************************************************/
private:
	//used to store the name of the product
    std::string _product;

	//used to store the amount of a product
	int _quantity = 0;

	//used to store the month of delivery
    int _month = 1;

	//used to store the months in a year
    std::vector<std::string> _year = {"DUMMY","Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
};

#endif //FALL2021_CS311_DELIVERY_H
