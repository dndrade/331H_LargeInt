#pragma once

#include "doublyL.h"

class LargeInt
{
private:
    doublyL<int> data;
    bool sign = true;

    void strip_zeroes(); // to remove zeroes from the result

    friend std::ostream& operator<<(std::ostream&, const LargeInt&);
    friend std::istream& operator>>(std::istream&, LargeInt&);
public:
    // constructors
    LargeInt();
    LargeInt(int);
    LargeInt(const std::string&);

    // comparison
    bool operator==(const LargeInt&) const;
    bool operator<(const LargeInt&) const;
    bool operator<=(const LargeInt&) const;
    bool operator>(const LargeInt&) const;
    bool operator>=(const LargeInt&) const;

    // operations
    LargeInt operator-() const;
    LargeInt operator+(const LargeInt&) const;
    LargeInt operator-(const LargeInt&) const;
    LargeInt operator*(const LargeInt&) const;
    LargeInt operator/(const LargeInt&) const;
    LargeInt operator%(const LargeInt&) const;

};