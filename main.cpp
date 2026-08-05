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

        int linear_res = doomSystem.linearSearchThreat(blacklist_ids, total_ids, suspect);
        int binary_res = doomSystem.binarySearchThreat(blacklist_ids, total_ids, suspect);

            if (binary_res != -1) {
                cout << "\n [ALERT] Danger Found! Index:" << binary_res << endl;
            } else {
                cout << "\n [SAFE] No Danger Found" << endl;
            }
        } else {
            cout << "\n [ACCESS DENIED] Attention!" << endl;
        }
    return 0;
    
}
