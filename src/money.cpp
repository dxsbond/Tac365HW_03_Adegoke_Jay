#include "money.h"
#include <iostream>

Money::Money() {
    mCents = 0;
}
Money::Money(long long inDollars, long long inCents) {
    mCents = inCents + (inDollars * 100); //1 dollar = 100 cents so multiply the dollars by 100 for cents
}
Money::Money(double inDollars) {
    mCents = std::llround(inDollars*100.0);
}
Money::Money(long long inCents) {
    mCents = inCents;
}
Money::Money(int inCents) {
    mCents = inCents;
}

Money& Money::operator+=(const Money& right) {
    mCents += right.mCents;
    return *this;
}
Money& Money::operator-=(const Money& right) {
   mCents -= right.mCents;
    return *this;
}

Money& Money::operator*=(double right)
{
    // llround to round the double to integer (found online)
    mCents = static_cast<long long>(mCents * right);
    return *this;
}
Money& Money::operator/=(double right)
{
    mCents = static_cast<long long>(mCents / right);
    return *this;
}
bool operator<(const Money& left, const Money& right)
{
    return left.mCents < right.mCents;
}
bool operator>(const Money& left, const Money& right)
{
    return left.mCents > right.mCents;
}
bool operator<=(const Money& left, const Money& right)
{
    return left.mCents <= right.mCents;
}
bool operator>=(const Money& left, const Money& right)
{
    return left.mCents >= right.mCents;
}
bool operator==(const Money& left, const Money& right)
{
    return left.mCents == right.mCents;
}
bool operator!=(const Money& left, const Money& right)
{
    return left.mCents != right.mCents;
}
Money operator+(const Money& left, const Money& right)
{
    Money result;
    result.mCents = left.mCents + right.mCents;
    return result;
}
Money operator-(const Money& left, const Money& right)
{
    Money result;
    result.mCents = left.mCents - right.mCents;
    return result;
}
Money operator*(const Money& left, double right)
{
    Money result;
    result.mCents = static_cast<long long>(left.mCents * right);
    return result;
}
Money operator/(const Money& left, double right)
{
    Money result;
    result.mCents = static_cast<long long>(left.mCents / right);
    return result;
}

Money Money::AbsVal() {
    return std::abs(mCents);
}

std::ostream& operator<<(std::ostream& out, const Money& money) {
    long long cents = money.mCents;
    long long dollars = 0;
    if (std::abs(cents) > 100) { //if cents is more than 1 dollar
        dollars = (cents/100); //cents divided by 100 to get a dollar
        cents = cents - (dollars * 100); //then the leftover cents are the subtraction of the hundreds used to make the dollars
    }
    std::string sign = "$";
    if (cents <0 || dollars <0){sign = "$-";} //making sure that the sign is moved to the front
    if (std::abs(cents) < 10) {
        out << sign << std::abs(dollars) << ".0" << std::abs(cents);
    } else {
        out << sign << std::abs(dollars) << "." << std::abs(cents); //abs to ensure the sign is controlled by the sign variable, not the actual negativity of the numbers
    }
    return out;
}

std::istream& operator>>(std::istream& in, Money& money) {
    double receive = 0.0;
    in >> receive;

    money.mCents = receive*100;
    return in;
}