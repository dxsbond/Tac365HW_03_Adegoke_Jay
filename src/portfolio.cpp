#include "portfolio.h"

StockPortfolio::StockPortfolio() {

}


void StockPortfolio::addStock(Stock inStock) {
    mStocks.insert(std::pair<std::string, Stock>(inStock.getSymbol(), inStock)); //inserting the symbol and the stock itself as a pair
}
bool StockPortfolio::containsStock(std::string inSymbol) {
    if (mStocks.find(inSymbol) != mStocks.end()) { //if the symbol is found then return true else if .end() is returned, return false
        return true;
    } else {
        return false;
    }
}
Stock& StockPortfolio::operator[](std::string inSymbol) {
    return mStocks.at(inSymbol);
}
Money StockPortfolio::getTotalValue() const {
    Money totalValue;
    for(std::pair<std::string,Stock> members : mStocks) { //for each pair of a string symbol, and stock object in the portfolio
        totalValue += members.second.getCurrPrice()*members.second.getNumShares(); //add the second member of the pair (stock)'s current price to the total price
    }
    return totalValue;
}
Money StockPortfolio::getOrigValue() const {
    Money totalValue;
    for(std::pair<std::string,Stock> members : mStocks) { //for each pair of a string symbol, and stock object in the portfolio

        totalValue += members.second.getPurPrice()*members.second.getNumShares(); //add the second member of the pair (stock)'s purchase price to the total price
    }
    return totalValue;

}
Money StockPortfolio::getProfit() const {
    Money totalValue;
    for(std::pair<std::string,Stock> members : mStocks) { //for each pair of a string symbol, and stock object in the portfolio

        totalValue += members.second.getChange()*members.second.getNumShares(); //add the second member of the pair (stock)'s change (current price - purchase price) to the total price
    }
    return totalValue;
}

std::vector<std::string> StockPortfolio::getAlphaList() {
    std::vector<std::string> alphaList;
    for(std::pair<std::string,Stock> members : mStocks) { //for each pair in portfolio
        alphaList.push_back(members.second.getSymbol()); //push the symbol of the stock into the list
    }
    return alphaList;
}
std::vector<std::string> StockPortfolio::getValueList() {

    std::vector<std::string> valueList;
    std::vector<std::pair<std::string,Stock>> values;
    for (std::pair<std::string,Stock> pair : mStocks) { //filling the values vector so it can be used
        values.emplace_back(pair.first, pair.second);
    }
    int n = mStocks.size();

    // Move the boundary of the unsorted subarray one by one
    for (int i = 0; i < n - 1; ++i) {
        // find the max element in the unsorted portion
        int max_idx = i; //max index is default the primary index in the beginning of the search range
        for (int j = i + 1; j < n; ++j) {
            if (values[j].second.getCurrPrice() > values[max_idx].second.getCurrPrice()) {
                max_idx = j; //the max is changed if a bigger item is found than the starting index
            }
        }

        // swap the new max or the starting index if it's the max, now to the beginning of the part that isn't sorted
        if (max_idx != i) {
            std::swap(values[i], values[max_idx]);
        }

    }
    for (std::pair<std::string,Stock> members : values) {
        std::cout << members.first << ": " << members.second << std::endl;
        valueList.push_back(members.second.getSymbol());
    }


    return valueList;
}
std::vector<std::string> StockPortfolio::getDiffList() {
    std::vector<std::string> valueList;
    std::vector<std::pair<std::string,Stock>> values;
    for (std::pair<std::string,Stock> pair : mStocks) { //filling the values vector so it can be used
        values.emplace_back(pair.first, pair.second);
    }
    int n = mStocks.size();


    // Move the boundary of the unsorted subarray one by one
    for (int i = 0; i < n - 1; ++i) {
        // find the max element in the unsorted portion
        int max_idx = i; //max index is default the primary index in the beginning of the search range
        for (int j = i + 1; j < n; ++j) {

            if (values[j].second.getChange() > values[max_idx].second.getChange()) {
                max_idx = j; //the max is changed if a bigger item is found than the starting index
            }
        }
        // swap the new max or the starting index if it's the max, now to the beginning of the part that isn't sorted
        if (max_idx != i) {
            std::swap(values[i], values[max_idx]);
        }
    }

    for (std::pair<std::string,Stock> members : values) {
        std::cout << members.first << ": " << members.second << std::endl;
        valueList.push_back(members.second.getSymbol());
    }
    return valueList;
}