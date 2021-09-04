/*
 * delivery.cpp
 * Aleks McCormick
 * 2021/09/01
 * Fall 2021 CS 311
 * source file for Delivery class
 */

#include "delivery.h"

	/********************************************************************/
	/**							Constructors			 			  ***/
	/********************************************************************/
// Default constructor
// sets the product name, amount, and month of delivery to default values
Delivery::Delivery(): Delivery("UNSPECIFIED", 0, 1)
    {}

//constructor that takes 3 parameters
// takes in the  product name, amount, and month of delivery
Delivery::Delivery(const std::string& prdct, int qunt, int mon)
    {
		assert(qunt >= 0);
		assert(mon >= 1 && mon <= 12);
		setName(prdct);
        setMonth(mon);
        setQuantity(qunt);
    }

	/********************************************************************/
	/**						Modify Data Members			 			  ***/
	/********************************************************************/

//setName
//sets the product name to the string passed
void Delivery::setName(const std::string& prdct){
        _product = prdct;
    }

//setQuantity
//sets the amount of product to the int passed so long as it is positive
void Delivery::setQuantity(int qunt){
		assert(qunt >= 0);
        _quantity = qunt;
    }

//setMonth
//sets the month of delivery to the int passed so long as it is within
// the specified range between 1 && 12
void Delivery::setMonth(int mon){
		assert(mon >= 1 && mon <= 12);
        _month = mon;
    }

	/********************************************************************/
	/***					Read Data Members			 			  ***/
	/********************************************************************/

//getName
//returns the product name as a string
std::string Delivery::getName() const &{
        return _product;
    }

//getQuantity
//returns the amount of product as an int
int Delivery::getQuantity() const &{
		assert(_quantity >= 0);
        return _quantity;
    }

//getMonth
//returns the month of delivery as an int
int Delivery::getMonth() const &{
		assert(_month >= 1 && _month <= 12);
        return _month;
    }

	/********************************************************************/
	/***					Other Member Functions		 			  ***/
	/********************************************************************/

//toStirng
//converts the data stored in a Delivery object into a readable string
//formatted as such: _product (_quantity), _month of the year
std::string Delivery::toString() const{
	assert(getQuantity() >= 0);
	assert(getMonth() >= 1 && getMonth() <= 12);
    std::string output = getName() + " (" + std::to_string(getQuantity()) +"), " + _year[getMonth()];
    return output;
}

//empty
// returns true if the quantity is zero and false if otherwise
bool Delivery::empty() const & {
	assert(getQuantity() >= 0);
    return (_quantity == 0);
}

	/********************************************************************/
	/***				Overloaded Boolean Operators				  ***/
	/********************************************************************/

//operator==
//compares two Delivery objects and returns true if all the data members
// are the same
bool Delivery::operator==(const Delivery &d2) const{
	assert(getQuantity() >= 0);
	assert(getMonth() >= 1 && getMonth() <= 12);
    return (this->getMonth() == d2.getMonth() && this->getQuantity() == d2.getQuantity() && this->getName() == d2.getName());
}

//operator!=
//compares two Delivery objects but returns the opposite of operator==
bool Delivery::operator!=(const Delivery &d2) const{
	assert(getQuantity() >= 0);
	assert(getMonth() >= 1 && getMonth() <= 12);
    return !(*this == d2);
}

	/********************************************************************/
	/***			 Overloaded Mathematical Operators		 		  ***/
	/********************************************************************/

//pre-increment operator++
//increments the quantity of a Delivery object by 1
Delivery &Delivery::operator++() {
	assert(getQuantity() >= 0);
	this->setQuantity(this->getQuantity() +1);
	return *this;
}

//pre-decrement operator--
//decrements the quantity of a Delivery object by 1 if it is greater than 0
Delivery &Delivery::operator--() {
	assert(getQuantity() >= 0);
	if(this->getQuantity() > 0)
		this->setQuantity(this->getQuantity() -1);
	return *this;
}

//post-increment operator++
//increments the quantity of a Delivery object by 1
Delivery Delivery::operator++([[maybe_unused]]int dummy){
	assert(getQuantity() >= 0);
	auto save = *this;
	++(*this);
	return save;
}

//post-decrement operator--
//decrements the quantity of a Delivery object by 1 if it is greater than 0
Delivery Delivery::operator--([[maybe_unused]]int dummy){
	assert(getQuantity() >= 0);
	auto save = *this;
	--(*this);
	return save;
}

	/********************************************************************/
	/**					Global Overloaded Operators		 			  ***/
	/********************************************************************/

//operator<<
// outputs the string created by toString into an output stream
std::ostream &operator<<(std::ostream &os, const Delivery &dliv){
	assert(dliv.getQuantity() >= 0);
	assert(dliv.getMonth() >= 1 && dliv.getMonth() <= 12);
	os << dliv.toString();
    return os;
}
