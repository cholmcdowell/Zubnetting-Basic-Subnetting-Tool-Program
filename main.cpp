#include "Zubnetting.h"
using namespace std;

int main() {

    // Gather network intel
    NetworkInput network_0 = getNetworkInput();
    printNetworkInput(network_0);

    cout << isValid(network_0) << endl;

    return 0;
}