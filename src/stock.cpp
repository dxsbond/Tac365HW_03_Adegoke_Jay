#include "stock.h"

Stock::Stock() {

}

Stock::Stock(std::string inName, std::string inSymbol, const Money &inPurPrice, double inNumShares) {
    mPurchasePrice = inPurPrice;
    mCurrentPrice= inPurPrice;
    mName = inName;
    mSymbol = inSymbol;
    mNumShares = inNumShares;
}

Money Stock::getCurrPrice() const {
    return mCurrentPrice;
}
Money Stock::getPurPrice() const {
    return mPurchasePrice;
}
std::string Stock::getSymbol() const {
    return mSymbol;
}
std::string Stock::getName() const {
    return mName;
}
double Stock::getNumShares() const {
    return mNumShares;
}

Money Stock::getChange() const {
    return (mCurrentPrice - mPurchasePrice);
}
void Stock::setCurrentPrice(const Money& inCurrPrice) {
    mCurrentPrice = inCurrPrice;
}

std::ostream& operator<<(std::ostream& out, const Stock& stock) {
out<< stock.getSymbol() << " " << ":"  << " " << stock.getNumShares() << " @ " << stock.getCurrPrice();
    return out;
}

