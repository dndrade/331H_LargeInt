/*
    Program: Large Int
    Class: CSC 331H Spring 2022
    Student: Thamires L Andrade
    Professor: Anna Salvati
    Description:  program handles large integers (positive and negative)
*/

#include "LargeInt.h";

int main()
{
    /*LargeInt li1(200);
    LargeInt li2("5");
    std::cout << (li1 / li2) << '\n';*/
    
    bool loop = true;
    do {
        std::cout << "\nEnter first operand: ";
        LargeInt li1; std::cin >> li1;
        std::cout << "Enter second operand: ";
        LargeInt li2; std::cin >> li2;

        std::cout << "\n\n    OPERATIONS";
        std::cout << "\n  ----------------\n";
        std::cout << "    Addition: " << (li1 + li2);
        std::cout << "\n    Subtraction: " << (li1 - li2);
        std::cout << "\n    Multiplicaton: " << (li1 * li2);
        std::cout << "\n    Division: " << (li1 / li2);
        std::cout << "\n    Modulus: " << (li1 % li2) << "\n";

        std::cout << "\n\n   COMPARISONS";
        std::cout << "\n  ----------------\n";

        if (li1 > li2) {
            std::cout << "    First is larger than second.\n";
        }
        if (li1 < li2) {
            std::cout << "    First is smaller than second.\n";
        }
        if (li1 == li2) {
            std::cout << "    Both are the same.\n";
        }

        std::cout << "\nContinue (y/n)?\n ";
        char choice; std::cin >> choice;

        if (choice == 'n') {
            loop = false;
        }
    } while (loop);
}