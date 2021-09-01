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
        setProduct(prdct);
        setQuantity(qunt);
        setMonth(mon);
    }

    /*  Set data members */
void Delivery::setProduct(std::string prdct){
        _product = prdct;
    }

void Delivery::setQuantity(int qunt){
        _quantity = qunt;
    }

void Delivery::setMonth(int mon){
        _month = mon;
    }

    /*  Get data members */
std::string Delivery::getProduct(){
        return _product;
    }

int Delivery::getQuantity(){
        return _quantity;
    }

int Delivery::getMonth(){
        return _month;
    }