#include "Zubnetting.h"

bool isValid(const NetworkInput& input) {
    stringstream ss(input.ip_address);
    string octet; int count = 0;

    while (getline(ss, octet, '.')) {
        // Check if octet is empty or too long
        if (octet.empty() || octet.length() > 3)
            return false;

        // Check if all characters are digits
        for (char c : octet) {
            if (!isdigit(c)) { return false; }
            }

        // Check if digits are within 0-255
        int octet_int = stoi(octet);
        if (octet_int < 0 || octet_int > 255) { return false; }

        count ++;
    }

    return count == 4;
}

NetworkInput getNetworkInput(){
    NetworkInput input;
    cout << "IP Address: "; cin >> input.ip_address;
    cout << "CIDR: "; cin >> input.cidr;

    return input;
}

void printNetworkInput(const NetworkInput& input) {
    cout << "IP Address: " << input.ip_address << "/"
    << input.cidr << endl;
}