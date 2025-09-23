
// User function template for C++

class Solution {
  public:
    // Function to check if a string is a palindrome.
    bool isPalindrome(string& s) {
   int i = 0;
        int j = s.size()-1;
        while(i < j)
        {
            if(s[i] != s[j])
            {
                return 0;
            }
            i++;
            j--;
        }
        return 1;
    
    }
};

