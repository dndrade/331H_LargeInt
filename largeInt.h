#pragma once

#include "doublyL.h"

class LargeInt
{
public:
    LargeInt();
    LargeInt(int);
    LargeInt(const std::string&);

    bool operator==(const LargeInt&) const;
    bool operator<(const LargeInt&) const;
    bool operator<=(const LargeInt&) const;
    bool operator>(const LargeInt&) const;
    bool operator>=(const LargeInt&) const;

    LargeInt operator-() const;
    LargeInt operator+(const LargeInt&) const;
    LargeInt operator-(const LargeInt&) const;
    LargeInt operator*(const LargeInt&) const;
    LargeInt operator/(const LargeInt&) const;
    LargeInt operator%(const LargeInt&) const;
private:
    doublyL<int> data;
    bool sign = true;

    void strip_zeroes();

    friend std::ostream& operator<<(std::ostream&, const LargeInt&);
    friend std::istream& operator>>(std::istream&, LargeInt&);
};
// #endif