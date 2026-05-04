#include "Zubnetting.h"
using namespace std;

int main() {

    // Gather network intel
    NetworkInput network_0 = getNetworkInput();
    printIsValid(network_0);

    return 0;
}