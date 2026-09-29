#include "strlib.h"


std::vector<std::string> strSplit(const std::string& str, char splitChar)
{
	// TODO: Complete this function and fix the return
	std::vector<std::string> result;
	std::string builder;
	int index = 0;//keeping track of position in the for each loop
	for (char c : str) { //for each char in the string, add it to the build string, if it reaches a delimiter, push, clear, start over
		if (c == splitChar) {
			result.push_back(builder);
			builder.clear();
		} else {
			builder += c;
		}
		index++;
	}
	result.push_back(builder); //push
	return result;
}

