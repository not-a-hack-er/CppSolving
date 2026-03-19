class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> mp1;
        map<char,int> mp2;
        for(auto it:ransomNote)
        {
            mp1[it]++;
        }
        for(auto it:magazine)
        {
            mp2[it]++;
        }
        for(auto it:mp1)
        {
            if(mp2[it.first]<it.second)
            return false;
        }
        return true;
        
    }
};