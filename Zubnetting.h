#ifndef ZUBNETTING
#define ZUBNETTING

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

struct NetworkInput {
    string ip_address; 
    string cidr;
};

bool isValidOctet(const string& octet);
bool isValid(const NetworkInput& input);
void printIsValid(const NetworkInput& input);
NetworkInput getNetworkInput();
void printNetworkInput(const NetworkInput& input);

#endif