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
    friend std::ostream & operator<< (std::ostream &os, const Delivery &mon);

public:
    /*  Constructors */
    Delivery();

    Delivery(std::string prdct, int qunt, int mon);

    /*  Set data members */
    void setProduct(std::string prdct);

    void setQuantity(int qunt);

    void setMonth(int mon);

    /*  Get data members */
    std::string getProduct();

    int getQuantity();

    int getMonth();

    /*  Other member functions */
    std::string toStiring();

    bool empty();

    /*  Overloaded operators */
bool operator==(const Delivery & d2);

bool operator!=(const Delivery & d2);

    /*  Data members */
private:
    std::string _product;
    int _month;
    int _quantity;
};


#endif //FALL2021_CS311_DELIVERY_H
