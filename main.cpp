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

        int blacklist_ids[] = {101, 204, 305, 412, 550, 677, 899};
        int total_ids = 7;
        int suspect;

        cout << "\n ======================" << endl;
        cout << " THREAT DETECTION ADAPTER " << endl;
        cout << "==========================" << endl;
        cout << "For Check Enter The Network ID:" << endl;
        cin >> suspect;

        int result_index = doomSystem.binarySearchThreat(blacklist_ids, total_ids, suspect);

        if (result_index != -1) {
            cout << "[ALERT] Found The Danger [" << result_index << "] on this ID " << endl;
            cout << "[ACTION] System Locakdown Activate!" << endl;
        } else {
        cout << "\n [SAFE] ID is Safe! No Threat Found" << endl;
        }
    } else {
        cout << "\n[ACCESS DENIED]" << endl;
    }

    return 0;
}