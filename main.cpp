#include <iostream>
#include "DoomSecurity.h"

using namespace std;

int main() {
    DoomSecuritySystem doomSystem("config.txt");
    doomSystem.bootSystem();

    int user_input;
    cout << "Enter Secret Master Key To Access: ";
    cin >> user_input;

    if (doomSystem.authenticate(user_input)) {
        cout << "\n Access Granted: Welcome Master \n" << endl;


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
                cout << "\n[!] [ALERT] Danger Found! Index:" << binary_res << endl;
            } else {
                cout << "\n[v] [SAFE] No Danger Found" << endl;
            }
        } else {
            cout << "\n[x] [ACCESS DENIED] Attention! Intruder Alert Triggered! \n" << endl;
        }
int dec_val = 5;
cout << "\n [DIGITAL ELECTRONICS MODULE] Decimal " << dec_val
            << " in Binary is: " << doomSystem.convertToBinary(dec_val) << endl;        
    return 0;
    
}
