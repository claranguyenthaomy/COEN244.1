// FINAL ASMGT 1 COEN244.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
 
#include "Invoice.h"
using namespace std;

std::string message1, message2, message3, message4, message5;
Invoice invoiceTest("12345", "Test part", -4, -2);  // Constructor should handle invalid values (negative quantity and price)

void testInvoiceClass() {
    // Testing constructor and data validation (negative values should be set to 0)
    // This function tests if the constructor properly initializes the invoiceTest object.
    // It checks if: partNumber is "12345", partDescription is "Test part", pricePerItem is 0 (due to the invalid - 1 input), quantity is 0 (due to the invalid - 3 input).
    message1 = (invoiceTest.getPartNumber().compare("12345") == 0 && // 0: if the two  are 0, they're equal
        invoiceTest.getPartDescription().compare("Test part") == 0 && // &&: operator ensures that all conditions in the expression must be true for the entire expression to be true.
        invoiceTest.getPricePerItem() == 0 &&   // Price should be set to 0 because of negative input
        invoiceTest.getQuantity() == 0) ?      // Quantity should also be set to 0
        "Pass!" : "Fail!";

    cout << message1 << endl;
}

void testCopyConstructor() {
    // Copy constructor test
    Invoice copy = invoiceTest;

    message2 = (copy.getPartNumber().compare(invoiceTest.getPartNumber()) == 0 &&
        copy.getPartDescription().compare(invoiceTest.getPartDescription()) == 0 &&
        copy.getPricePerItem() == invoiceTest.getPricePerItem() &&
        copy.getQuantity() == invoiceTest.getQuantity()) ? "Pass!" : "Fail!";

    cout << message2 << endl;
}

void testClone() {
    // Testing clone functionality
    Invoice clonedInvoice = invoiceTest.clone();

    message3 = (clonedInvoice.getPartNumber().compare(invoiceTest.getPartNumber()) == 0 &&
        clonedInvoice.getPartDescription().compare(invoiceTest.getPartDescription()) == 0 &&
        clonedInvoice.getPricePerItem() == invoiceTest.getPricePerItem() &&
        clonedInvoice.getQuantity() == invoiceTest.getQuantity()) ? "Pass!" : "Fail!";

    cout << message3 << endl;
}

void testOverloadedClone() {
    // Testing overloaded clone function
    Invoice anotherInvoice("67890", "Another test part", 5, 10);
    Invoice clonedAnotherInvoice = anotherInvoice.clone(anotherInvoice);

    message4 = (clonedAnotherInvoice.getPartNumber().compare(anotherInvoice.getPartNumber()) == 0 &&
        clonedAnotherInvoice.getPartDescription().compare(anotherInvoice.getPartDescription()) == 0 &&
        clonedAnotherInvoice.getPricePerItem() == anotherInvoice.getPricePerItem() &&
        clonedAnotherInvoice.getQuantity() == anotherInvoice.getQuantity()) ? "Pass!" : "Fail!";

    cout << message4 << endl;
}
void testGetInvoiceAmount() {

    Invoice Ginvoice("11111", "ABCDE", 10, 20);
    int expectedGetInvoiceAmount = 10 * 20;
    message5 = (Ginvoice.getInvoiceAmount() == expectedGetInvoiceAmount) ? "Pass!" : "Fail!";

    cout << message5 << endl;
}
int main()
{

    cout << "-----testInvoiceClass-----" << endl;
    testInvoiceClass();

    cout << "-----testCopyConstructor-----" << endl;
    testCopyConstructor();

    cout << "---------testClone ----------" << endl;
    testClone();

    cout << "-----testOverloadedClone-----" << endl;
    testOverloadedClone();

    cout << "-----testGetInvoiceAmount-----" << endl;
    testGetInvoiceAmount();

    string messages[5];
    int passedTests = 0;

    messages[0] = message1;
    messages[1] = message2;
    messages[2] = message3;
    messages[3] = message4;
    messages[4] = message5;



    for (int i = 0; i < 5; i++) {

        if (messages[i].compare("Pass!") == 0) {
            passedTests++;
        }

    }

    cout << endl << passedTests << "/5 test(s) passed and " << 5 - passedTests << "/5 failed." << endl;

}

