#include <iostream>
#include "DoomSecurity.h"

using namespace std;

int main() {
    DoomSecuritySystem doomSystem;
    doomSystem.bootSystem();

    int user_input;
    cout << "Enter Secret Master Key To Access: ";
    cin >> user_input;

    if (doomSystem.authenticate(user_input)) {
        cout << "\n Access Granted: " << endl;

        int test_packet;
        cout << "\n Enter ant number to Security: ";
        cin >> test_packet;
        doomSystem.convertToBinary(test_packet);
    } else {
        cout << "\n [ACCESS DENIED]" << endl;
    }

    return 0;
}