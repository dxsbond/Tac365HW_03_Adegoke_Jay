#include "driver.h"
#include "strlib.h"
#include <iostream>
#include <fstream>

bool buyStock(StockPortfolio& inPort, const std::string& inString) {
    std::vector<std::string> split = strSplit(inString,'|'); //split the string
    if (split.size() < 4) return false;
    //rounding the converted string to double after multiplying it by 100 to avoid stoll from rounding the 0.11 to 0.00
    Stock newStock{split[1],split[0],llround(std::stod(split[2])*100),std::stod(split[3])};

    inPort.addStock(newStock);
    return true;
}




bool updateStock(StockPortfolio& inPort, const std::string& inString) {
    std::vector<std::string> split = strSplit(inString,'|');
    if (split.size() < 2) return false;

        if (!split.empty() && split[0].at(0) == '+') {
            split[0] = split[0].substr(1); //remove any leading symbols
        }


    if (inPort.containsStock(split[0])) { //if the stock portfolio already includes the stock, update it
        inPort[split[0]].setCurrentPrice(llround(std::stod(split[1])*100));
        return true;
    } else {
        return false;
    }
}


bool processFile(StockPortfolio& inPort, const std::string& inString) {
    std::ifstream inStream;
    inStream.open(inString);
    if (!inStream.is_open()) return false;
    std::string line;
    while (std::getline(inStream, line)) {
        if (line.empty()) continue;
        if (strSplit(line,'|').size() == 2) {
            updateStock(inPort, line); //if the line is small it should only update
        }
        else if (strSplit(line,'|').size() == 4) { //if the line is full of data, it should make a new one
            buyStock(inPort, line);
        }
    }
    return true;
}