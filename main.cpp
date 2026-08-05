#include <iostream>
#include <string>

using namespace std;

// classes and encapsulations topic 
class DoomSecuritySystem {
    private:
        int secret_key;

    public:
        DoomSecuritySystem() {
            secret_key = 1962;
        }    

        void bootSystem() {
            cout << "=================================" << endl;
            cout << "     WELCOME TO DOOM_OS          " << endl;
            cout << "=================================" << endl;
            cout << "[INFO] Loading Digital Electronics Module..." << endl;
            cout << "[INFO] Loading DSA Threat Radar...." << endl;
            cout << "[STATUS] DOOM_OS IS NOW LIVE!\n" << endl;
        }

        bool authenticate(int input_key) {
            if (input_key == secret_key) {
                return true;
            }
            return false;
        }
};

int main() {
    DoomSecuritySystem doomSystem;

    doomSystem.bootSystem();

    int user_input;
    cout << "Enter Secret Master Key to Access: ";
    cin >> user_input;

    if (doomSystem.authenticate(user_input)) {
        cout << "\n[ACCESS GRANTED]" << endl;
    } else {
        cout << "\n[ACCESS DENIED]" << endl;
    }

    return 0;
}