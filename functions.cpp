#include <iostream>
#include <string>
#include <sstream>
#include "functions.hpp"

string toString(double number){
    ostringstream sstream;
    sstream.precision(2);
    sstream << fixed;
    sstream << number;
    string varAsString = sstream.str();
    return varAsString;
}

string toString(int number){
    ostringstream sstream;
    sstream << number;
    string varAsString = sstream.str();
    return varAsString;
}
