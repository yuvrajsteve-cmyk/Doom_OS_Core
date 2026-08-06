#ifndef DOOM_SECURITY_H
#define DOOM_SECURITY_H

class DoomSecuritySystem {
    private:
        int secret_key;
    
    public:
        DoomSecuritySystem(int key);
        ~DoomSecuritySystem();
        
        void bootSystem();
        bool authenticate(int input_key);
        int convertToBinary(int decimal_number);
        int linearSearchThreat(int blacklist[], int size, int suspect_id);
        int binarySearchThreat(int sorted_blacklist[], int size, int suspect_id);
        double calculateMean(int blacklist[], int size);
        void findThreatRange(int blacklist[], int size, int &min_val, int &max_val);
        void sortThreats(int arr[], int size);
        int getTwosCompliment(int val);    
};

#endif