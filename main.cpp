#include "Zubnetting.h"
using namespace std;

int main() {

    // IPv4 Subnetting Validation Tool

    // Gather network intel
    NetworkInput network_0 = getNetworkInput();
    printIsValid(network_0);

    return 0;
}