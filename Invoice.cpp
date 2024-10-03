#include "Invoice.h"


// PROB1 INSTRUCTIONS: Your class should have a constructor that initializes the four data members: —a part number(type string), a part description(type string), a quantity of the item being purchased(type int) and a price  per item(type int)."
   //// To create a constructor, use the same name as the class, followed by parentheses ()
Invoice::Invoice(std::string partNumber, std::string partDescription, int quantity, int pricePerItem)
    : partNumber(partNumber), partDescription(partDescription) {  // Constructor must match header declaration
    setQuantity(quantity);  // Using the setter to handle invalid values
    setPricePerItem(pricePerItem);  // Using the setter to handle invalid values
}

// TASK 1.3 add the destructor of class Invoice. (5 points) ~class();
Invoice::~Invoice() {
    // Destructor implementation (if necessary, can be empty)
}

//// Setters and Getters: functions in a class that allow controlled access to private data members. 
// Setters: allows you to assign or update the value of a private data member (qtity and priceperitem have values)
void Invoice::setPartNumber(const std::string& partNum) {
    partNumber = partNum;
}

void Invoice::setPartDescription(const std::string& partDesc) {
    partDescription = partDesc;
}

// PROB1 INSTRUCTIONS: If the quantity is not positive, it should be set to 0.
void Invoice::setQuantity(int qty) {
    if (qty > 0) {
        quantity = qty;
    }
    else {
        quantity = 0;
    }
}
// PROB1 INSTRUCTIONS: If the price per item is not positive, it should be set to 0 .
void Invoice::setPricePerItem(int price) {
    if (price > 0) {
        pricePerItem = price;
    }
    else {
        pricePerItem = 0;
    }
}

// Getters: are meant to only retrieve the value of a data member, not change it.
std::string Invoice::getPartNumber() const {
    return partNumber;
}

std::string Invoice::getPartDescription() const {
    return partDescription;
}

int Invoice::getQuantity() const {
    return quantity;
}

int Invoice::getPricePerItem() const {
    return pricePerItem;
}

// Function to calculate invoice amount (i.e., multiplies the quantity by the price per item)
int Invoice::getInvoiceAmount() const {
    return quantity * pricePerItem;
}

// Clone function returning an identical copy of the current Invoice object
Invoice Invoice::clone() const {
    return Invoice(partNumber, partDescription, quantity, pricePerItem);
}

// Overloaded clone function that takes another Invoice object as a parameter
Invoice Invoice::clone(const Invoice& invoice) const {
    return Invoice(invoice.getPartNumber(), invoice.getPartDescription(), invoice.getQuantity(), invoice.getPricePerItem());
}
