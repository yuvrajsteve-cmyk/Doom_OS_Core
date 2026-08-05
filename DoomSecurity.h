#ifndef DOOM_SECURITY_H
#define DOOM_SECURITY_H

class DoomSecuritySystem {
    private:
        int secret_key;
    
    public:
        DoomSecuritySystem();
        void bootSystem();
        bool authenticate(int input_key);
        void convertToBinary(int decimal_number);
        int linearSearchThreat(int blacklist[], int size, int suspect_id);
        int binarySearchThreat(int sorted_blacklist[], int size, int suspect_id);    
};

#endif