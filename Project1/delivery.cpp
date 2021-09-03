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
        setMonth(mon);
        setQuantity(qunt);
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
    std::string output = getName() + " (" + (char) getQuantity()+") , " + _year[_month];
    return output;
}

bool Delivery::empty() const & {

    return (_quantity == 0);
}

    /*  Overloaded operators */
bool Delivery::operator==(const Delivery &d2) const{
    return (this->getMonth() == d2.getMonth() && this->getQuantity() == d2.getQuantity() && this->getName() == d2.getName());
}

bool Delivery::operator!=(const Delivery &d2) const{

    return !(*this == d2);
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
