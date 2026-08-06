#include <iostream>
#include "DoomSecurity.h"

using namespace std;

DoomSecuritySystem::DoomSecuritySystem(int key) {
    secret_key = key;
    cout << "\n[DOOM CORE] Initializing Secure Enclave..." << endl;
}

DoomSecuritySystem::~DoomSecuritySystem() {
    cout << "\n[DOOM CORE] Purging memory buffers. Shutting Down.\n" << endl;
}

bool DoomSecuritySystem::authenticate(int input_key) {
    if (input_key == secret_key) {
        return true;
    }
    return false;
}

void DoomSecuritySystem::bootSystem() {
    cout << "[INFO] DOOM_OS Kernel loaded Successfully.\n" << endl;
}

int DoomSecuritySystem::convertToBinary(int decimal_number) {
    int binary = 0, reminder, i = 1;
    while (decimal_number != 0) {
        reminder = decimal_number % 2;
        decimal_number /= 2;
        binary += reminder * i;
        i *= 10;
    }
    return binary;
}

// linear search algo 
int DoomSecuritySystem::linearSearchThreat(int blacklist[], int size, int suspect_id) {
    for (int i = 0; i < size; i ++) {
        if(blacklist[i] == suspect_id) {
            return i;
       }
    }
    return -1;
}

// Binary search algo 
int DoomSecuritySystem::binarySearchThreat(int sorted_blacklist[], int size, int suspect_id) {
    int low = 0, high = size - 1;
    int steps = 0;

    while (low <= high) {
        steps++;
        int mid = low + (high - low) / 2;

        if (sorted_blacklist[mid] == suspect_id) {
            cout << "[DSA MODULE] Binary Seaech Took " << steps << " steps. \n" << endl;
            return mid;
        }
        if (sorted_blacklist[mid] < suspect_id) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }   
    return -1;
}
double DoomSecuritySystem::calculateMean(int blacklist[], int size) {
    if (size <= 0) return 0.0;

    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += blacklist[i];
    }
    return sum / size;
} 


void DoomSecuritySystem::findThreatRange(int blacklist[], int size, int &min_val, int &max_val) {
    if (size <= 0) return;

    min_val = blacklist[0];
    max_val = blacklist[0];

    for (int i = 1; i < size; i ++) {
        if (blacklist[i] < min_val) {
            min_val = blacklist[i];
        }
        if (blacklist[i] > max_val) {
            max_val = blacklist[i];
        }
    }
}
