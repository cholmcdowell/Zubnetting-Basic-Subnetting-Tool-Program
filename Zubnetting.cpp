#include "Zubnetting.h"

bool isValidOctet(const string& octet) {
    // Check if octet is empty or too long
    if (octet.empty() || octet.length() > 3) { return false; }

    // Check if all characters are digits
    for (char c : octet) {
        if (!isdigit(c)) { return false; }
    }

    // No leading zeros
    if (octet.length() > 1 && octet[0] == '0') { return false; }

    // Check if digits are within 0-255
    int octet_int = stoi(octet);
    if (octet_int < 0 || octet_int > 255) { return false; }

    return true;
}

bool isValid(const NetworkInput& input) {
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
    cout << "IP Address: "; cin >> input.ip_address;
    cout << "CIDR: "; cin >> input.cidr;

    return input;
}

void printNetworkInput(const NetworkInput& input) {
    cout << "IP Address: " << input.ip_address << "/"
    << input.cidr;
}