/*
 * delivery.cpp
 * Aleks McCormick
 * 2021/09/01
 * Fall 2021 CS 311
 * cpp file for Delivery class
 */

#include "delivery.h"

    /*  Constructors */
Delivery::Delivery(): Delivery("UNSPECIFIED", 0, 1)
    {}

Delivery::Delivery(std::string prdct, int qunt, int mon)
    {
        setName(prdct);
        setQuantity(qunt);
        setMonth(mon);
    }

    /*  Set data members */
void Delivery::setName(std::string prdct){
        _product = prdct;
    }

void Delivery::setQuantity(int qunt){
        _quantity = qunt;
    }

void Delivery::setMonth(int mon){
        _month = mon;
    }

    /*  Get data members */
std::string Delivery::getName() const &{
        return _product;
    }

int Delivery::getQuantity() const &{
        return _quantity;
    }

int Delivery::getMonth() const &{
        return _month;
    }

    /* Other member functions */
std::string Delivery::toString() const &{
    return "string";
}

bool Delivery::empty() const & {

    return false;
}

    /*  Overloaded operators */
bool Delivery::operator==(const Delivery &d2) const{

    return false;
}

bool Delivery::operator!=(const Delivery &d2) const{

    return false;
}

Delivery &Delivery::operator++() {
	return *this;
}

Delivery &Delivery::operator--() {
	return *this;
}

Delivery Delivery::operator++([[maybe_unused]]int dummy){
	auto save = *this;
	--(*this);
	return save;
}

Delivery Delivery::operator--([[maybe_unused]]int dummy){
	auto save = *this;
	--(*this);
	return save;
}

	/* Global overloaded operators */
std::ostream & operator<< (std::ostream &os, const Delivery &dliv){
	//os << dliv.toString();
    return os;
}


