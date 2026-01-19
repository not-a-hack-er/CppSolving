#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        
        string hexChars = "0123456789abcdef";
        string ans = "";
        unsigned int n = num;
        
        while (n > 0) {
            ans += hexChars[n % 16]; 
            n /= 16;                
        }
        
        reverse(ans.begin(), ans.end()); 
        return ans;
    }
};