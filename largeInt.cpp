#include "LargeInt.h"

LargeInt::LargeInt() : LargeInt(0) {}

LargeInt::LargeInt(const std::string& str)
{
    int index = 0;
    if (str[0] == '-')
    {
        sign = false;
        index = 1;
    }

    for (; index < str.size(); ++index)
    {
        data.insertBack(str[index] - '0');
    }
}

LargeInt::LargeInt(int i)
{
    if (i < 0)
    {
        sign = false;
        i = -i;
    }
    while (i)
    {
        data.insertFront(i % 10);
        i /= 10;
    }
}

std::ostream& operator<<(std::ostream& os, const LargeInt& large_int)
{
    if (!large_int.sign)
    {
        os << '-';
    }
    for (auto it = large_int.data.begin(); it != large_int.data.end(); ++it)
    {
        os << *it;
    }

    // for(auto digit : large_int.data)
    // {
    // 	os << digit;
    // }

    return os;
}

std::istream& operator>>(std::istream& is, LargeInt& large_int)
{
    std::string temp;
    is >> temp;
    int index = 0;
    if (temp[0] == '-')
    {
        large_int.sign = false;
        index = 1;
    }
    for (; index < temp.size(); ++index)
    {
        large_int.data.insertBack(temp[index] - '0');
    }

    // for(auto c : temp)
    // {
    // 	large_int.data.insertBack(c - '0');
    // }

    return is;
}

bool LargeInt::operator==(const LargeInt& other) const
{
    if (sign != other.sign)
    {
        return false;
    }
    if (data.getLength() != other.data.getLength())
    {
        return false;
    }
    for (auto it1 = data.begin(), it2 = other.data.begin(); it1 != data.end() && it2 != data.end(); ++it1, ++it2)
    {
        if (*it1 != *it2)
        {
            return false;
        }
    }
    return true;
}

bool LargeInt::operator<(const LargeInt& other) const
{
    if (sign != other.sign)
    {
        if (!sign)
        {
            return true;
        }
        if (!other.sign)
        {
            return false;
        }
    }
    if (!sign && !other.sign)
    {
        return -other < -(*this);
    }
    if (data.getLength() != other.data.getLength())
    {
        return data.getLength() < other.data.getLength();
    }
    for (auto it1 = data.begin(), it2 = other.data.begin(); it1 != data.end() && it2 != data.end(); ++it1, ++it2)
    {
        if (*it1 < *it2)
        {
            return true;
        }
        if (*it1 > *it2)
        {
            return false;
        }
    }
    return false;
}

bool LargeInt::operator<=(const LargeInt& other) const
{
    return !(other < *this);
}

bool LargeInt::operator>(const LargeInt& other) const
{
    return other < *this;
}

bool LargeInt::operator>=(const LargeInt& other) const
{
    return !(*this < other);
}

LargeInt LargeInt::operator-() const
{
    LargeInt result = *this;
    result.sign = !result.sign;
    return result;
}

LargeInt LargeInt::operator+(const LargeInt& other) const
{
    if (sign != other.sign)
    {
        if (!sign)
        {
            return other - *this;
        }
        else
        {
            return *this - other;
        }
    }
    if (!sign && !other.sign)
    {
        return -(-(*this) + -(other));
    }
    if (data.getLength() < other.data.getLength())
    {
        return other + *this;
    }
    int carry = 0;
    LargeInt result;
    auto it1 = data.tend();
    auto it2 = other.data.tend();
    for (; it1 && it2; --it1, --it2)
    {
        int temp = *it1 + *it2 + carry;
        result.data.insertFront(temp % 10);
        carry = temp / 10;
    }
    for (; it1; --it1)
    {
        int temp = *it1 + carry;
        result.data.insertFront(temp % 10);
        carry = temp / 10;
    }
    if (carry)
    {
        result.data.insertFront(carry);
    }
    return result;
}

LargeInt LargeInt::operator-(const LargeInt& other) const
{
    if (sign != other.sign)
    {
        if (sign)
        {
            return *this + -other;
        }
        else
        {
            return other + -*this;
        }
    }
    if (!sign && !other.sign)
    {
        return -(-(*this) - -(other));
    }
    if (*this < other)
    {
        return -(other - *this);
    }
    int carry = 0;
    LargeInt result;
    auto it1 = data.tend();
    auto it2 = other.data.tend();
    for (; it1 && it2; --it1, --it2)
    {
        int temp = *it1 - *it2 - carry;
        if (temp < 0)
        {
            carry = 1;
            result.data.insertFront(temp + 10);
        }
        else
        {
            result.data.insertFront(temp);
        }
    }
    for (; it1; --it1)
    {
        int temp = *it1 - carry;
        if (temp < 0)
        {
            carry = 1;
            result.data.insertFront(temp + 10);
        }
        else
        {
            result.data.insertFront(temp);
        }
    }
    result.strip_zeroes();
    return result;
}

LargeInt LargeInt::operator*(const LargeInt& other) const
{
    LargeInt result;
    int count = 0;
    for (auto it = other.data.tend(); it; --it)
    {
        ++count;
        int carry = 0;
        LargeInt temp_li;
        for (auto it1 = data.tend(); it1; --it1)
        {
            int temp = *it1 * *it + carry;
            temp_li.data.insertFront(temp % 10);
            carry = temp / 10;
        }
        if (carry)
        {
            temp_li.data.insertFront(carry);
        }
        for (auto i = 1; i < count; ++i)
        {
            temp_li.data.insertBack(0);
        }
        result = result + temp_li;
    }
    result.sign = (sign == other.sign);
    return result;
}

LargeInt LargeInt::operator/(const LargeInt& other) const
{
    LargeInt result;
    LargeInt temp_this = *this;
    temp_this.sign = true;
    LargeInt temp_other = other;
    temp_other.sign = true;
    while (temp_this > temp_other)
    {
        temp_this = temp_this - temp_other;
        result = result + 1;
    }
    result.sign = (sign == other.sign);
    result.strip_zeroes();
    return result;
}

LargeInt LargeInt::operator%(const LargeInt& other) const
{
    LargeInt result = *this;
    result.sign = true;
    LargeInt temp_other = other;
    temp_other.sign = true;
    while (result > temp_other)
    {
        result = result - temp_other;
    }
    result.sign = (sign == other.sign);
    return result;
}

void LargeInt::strip_zeroes()
{
    while (data.begin() && *(data.begin()) == 0)
    {
        data.deleteItem(0);
    }
    if (data.getLength() == 0)
    {
        data.insertBack(0);
    }
}