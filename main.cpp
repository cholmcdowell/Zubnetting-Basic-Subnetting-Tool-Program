#include "Zubnetting.h"
using namespace std;

int main() {

    // IPv4 Subnetting Validation Tool

    // Gather network intel
    NetworkInput network_0 = getNetworkInput();
    printIsValid(network_0);
    
    if (!isValid(network_0)) { return 0; } // Exit if input is invalid
    printSubnetBinary(stoi(network_0.cidr));
    printSubnet(stoi(network_0.cidr));

    return 0;
}