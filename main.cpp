#include <fstream>
#include <iostream>
#include "DoomSecurity.h"

using namespace std;

int main() {
    std::ifstream inputFile("config.txt");
    if (!inputFile.is_open()) {
        return 1;
    }

    int my_key = 0;
    inputFile >> my_key;
    inputFile.close();

    DoomSecuritySystem doomSystem(my_key);
    doomSystem.bootSystem();

    int blacklist_ids[] = {101, 204, 305, 412, 550, 677, 899};
    int total_ids = 7;

    double mean_val = doomSystem.calculateMean(blacklist_ids, total_ids);
    int min_threat, max_threat;
    doomSystem.findThreatRange(blacklist_ids, total_ids, min_threat, max_threat);

    cout << "\n-----------------------------------\n";
    cout << "  STATISTICS & ANALYTICS DASHBOARD   \n";
    cout << "-------------------------------------\n";
    cout << "[-] Threat Mean (Average ID) :" << mean_val << endl;
    cout << "[-] Minium Threat ID         :" << min_threat << endl;
    cout << "[-] Maximun Threat ID        :" << max_threat << endl;

    int user_input;
    cout << "Enter Secret Master Key To Access: ";
    cin >> user_input;

    if (doomSystem.authenticate(user_input)) {
        cout << "\n Access Granted: Welcome Master \n" << endl;

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
