#include "DoomSecurity.h"
#include <iostream>

using namespace std;

DoomSecuritySystem::DoomSecuritySystem() {
    secret_key = 1962;
}

void DoomSecuritySystem::bootSystem() {
    cout << "======================" << endl;
    cout << "  WELCOME TO DOOM-OS  " << endl;
    cout << "======================" << endl;
    cout << "[INFO] Loading Digital Electronics Module..." << endl;
    cout << "[INFO] Loading DSA Threat Radar..." << endl;
    cout << "[STATUS] DOOM_OS IS NOW LIVE!\n" << endl;
}

bool DoomSecuritySystem::authenticate(int input_key) {
    return (input_key == secret_key);
}

void DoomSecuritySystem::convertToBinary(int decimal_number) {
    int binary_array[32];
    int i = 0;

    cout << "\n[DIGITAL MODULE] Converting Decimal " << decimal_number << " to Cryptographic Binary..." << endl;

    if (decimal_number == 0) {
        cout << "DOOM-BINARY CODE:  0" << endl;
        return ;
    }

    while (decimal_number > 0) {
        binary_array[i] = decimal_number % 2;
        decimal_number = decimal_number / 2;
        i++;
    }

    cout << "DOOM-BINARY CODE: ";
    for (int j = i - 1; j >= 0; j--) {
        cout << binary_array[j];
    }
    cout << endl;   
}