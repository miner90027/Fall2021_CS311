/*
 * delivery.h
 * Aleks McCormick
 * 2021/09/01
 * Fall 2021 CS 311
 * Header file for Delivery class
 */

#ifndef FALL2021_CS311_DELIVERY_H
#define FALL2021_CS311_DELIVERY_H

#include <string> // for std::string
#include <cassert> // for assert

class Delivery {
	/*	Global Operators */
    friend std::ostream & operator<< (std::ostream &os, Delivery &dliv);

public:
    /*  Constructors */
    Delivery();

    Delivery(std::string prdct, int qunt, int mon);

    /*  Set data members */
    void setName(std::string prdct);

    void setQuantity(int qunt);

    void setMonth(int mon);

    /*  Get data members */
    std::string getName() const &;

    int getQuantity() const &;

    int getMonth() const &;

    /*  Other member functions */
    std::string toString() const &;

    bool empty() const &;

    /*  Overloaded operators */
	bool operator==(const Delivery & d2) const;

	bool operator!=(const Delivery & d2) const;

	Delivery & operator++();

	Delivery & operator--();

	Delivery operator++([[maybe_unused]]int dummy);

	Delivery operator--([[maybe_unused]]int dummy);

    /*  Data members */
private:
    std::string _product;
    int _month;
    int _quantity;
};


#endif //FALL2021_CS311_DELIVERY_H
