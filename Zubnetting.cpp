#include "Zubnetting.h"

bool isValidCIDR(const string& cidr) {
    // Check if CIDR is empty or too long
    if (cidr.empty() || cidr.length() > 2) { return false; }

    // Check if all characters are digits
    for (char c : cidr) {
        if (!isdigit(static_cast<unsigned char>(c))) { return false; }
    }

    // Check if digits are within 0-32
    try {
        int cidr_int = stoi(cidr);
        if (cidr_int < 0 || cidr_int > 32) { return false; }
    }
    catch (...) {
        return false;
    }

    return true;
}

bool isValidOctet(const string& octet) {
    // Check if octet is empty or too long
    if (octet.empty() || octet.length() > 3) { return false; }

    // Check if all characters are digits
    for (char c : octet) {
        if (!isdigit(static_cast<unsigned char>(c))) { return false; }
    }

    // No leading zeros
    if (octet.length() > 1 && octet[0] == '0') { return false; }

    // Check if digits are within 0-255
    try {
        int octet_int = stoi(octet);
        if (octet_int < 0 || octet_int > 255) { return false; }
    }
    catch (...) {
        return false;
    }

    return true;
}

bool isValid(const NetworkInput& input) {
    // Check if CIDR is valid
    if (!isValidCIDR(input.cidr)) { return false; }

    stringstream ss(input.ip_address);

    // Check leading or trailing .
    if (input.ip_address.front() == '.' || input.ip_address.back() == '.') {
        return false;
    }

    // Check each octet of the IP address
    string octet; int count = 0;
    while (getline(ss, octet, '.')) {
        if (!isValidOctet(octet)) { return false; }
        count ++;
    }

    return count == 4;
}

void printIsValid(const NetworkInput& input) {
    if (isValid(input)) {
        cout << "Network "; 
        printNetworkInput(input);
        cout << " is valid." << endl; 
    }
    else {
        cout << "Network "; 
        printNetworkInput(input);
        cout << " is not valid." << endl;  
    }
}

NetworkInput getNetworkInput(){
    NetworkInput input;
    cout << "IP Address: "; getline(cin, input.ip_address);
    cout << "CIDR: "; getline(cin, input.cidr);

    return input;
}

void printNetworkInput(const NetworkInput& input) {
    cout << "IP Address: " << input.ip_address << "/"
    << input.cidr;
}