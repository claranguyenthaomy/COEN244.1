#pragma once

#ifndef INVOICE_H_
#define INVOICE_H_
#include <string>

class Invoice //// The class
{

private:            //// Access specifier
    std::string partNumber;
    std::string partDescription;
    int quantity;
    int pricePerItem;

public:             //// Access specifier

    // PROB1 INSTRUCTIONS: Your class should have a constructor that initializes the four data members: —a part number(type string), a part description(type string), a quantity of the item being purchased(type int) and a price  per item(type int)."
   //// To create a constructor, use the same name as the class, followed by parentheses ()
    Invoice(std::string partNumber, std::string partDescription, int quantity, int pricePerItem);

    // TASK 1.2: add the copy constructor of class Invoice. (5 points)
    // Copy constructor: used to create a new object that is an exact copy of an existing object. It takes a reference to an object of the same class and copies all its member variables to the new object.
    //// & = pass-by-reference
    Invoice(const Invoice& invoice) {
        partNumber = invoice.partNumber;
        partDescription = invoice.partDescription;
        quantity = invoice.quantity;
        pricePerItem = invoice.pricePerItem;
    }

    // TASK 1.3 add the destructor of class Invoice. (5 points) ~class();
    ~Invoice();

    //PROB1 INSTRUCTIONS: Provide a set and a get function for each data member.
    //// Setters and Getters: functions in a class that allow controlled access to private data members. 
    // Setters: allows you to assign or update the value of a private data member (qtity and priceperitem have values)
    void setPartNumber(const std::string& partNumber);
    void setPartDescription(const std::string& partDescription);
    void setQuantity(int quantity);
    void setPricePerItem(int pricePerItem);

    // Getters: are meant to only retrieve the value of a data member, not change it.
    std::string getPartNumber() const;
    std::string getPartDescription() const;
    int getQuantity() const;
    int getPricePerItem() const;


    // PROB1 INSTRUCTIONS: Provide a member function named getInvoiceAmount that calculates the invoice amount (multiplies the quantity by the price per item), then returns the amount as an int value
    //// function: what it returns - name () - const/or not; 
    //// const: because it does not modify any of the class's member variables when doing the operation
    int getInvoiceAmount() const;

    // TASK 1.4: define a public member function called clone() that returns an Invoice object with the identical values of the current Invoice object. (5 points)
    Invoice clone() const;

    // TASK 1.5: define a public member function with overloaded form of clone (const Invoice &) that returns an Invoice object with the identical values of the pass - by - referenceInvoice object. (5 points)
    Invoice clone(const Invoice& invoice) const;

};

#endif 