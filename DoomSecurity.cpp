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

// logic of the linear search 
int DoomSecuritySystem::linearSearchThreat(int blacklist[], int size, int suspect_id) {
    cout << "\n [DSA MODULE] Inititating Linear Search Radar..." << endl;
    for (int i = 0; i < size; i++) {
        if (blacklist[i] == suspect_id) {
            return i;
        }
    }
    return -1;
}

int DoomSecuritySystem::binarySearchThreat(int sorted_blacklist[], int size, int suspect_id) {
    cout << "\n [DSA MODULE] Intitiating High_Speed Binary Search Radar..." << endl;
    int low = 0;
    int high = size -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (sorted_blacklist[mid] == suspect_id) {
            return mid;
        }
        if (sorted_blacklist[mid] < suspect_id) {
            low == mid + 1;
        } else {
            high = mid -1 ;
        }
    }   
    return - 1;
}