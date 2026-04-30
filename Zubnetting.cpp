#include "Zubnetting.h"

bool isValid(const NetworkInput& input) {
    // stringstream ss(input);
    // string octet; int count = 0;

    return 0;
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