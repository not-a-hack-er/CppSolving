class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int key=0;
        int count =0;
        if(ruleKey=="type")key=0;
        else if(ruleKey=="color")key=1;
        else if(ruleKey=="name")key=2;
        for(vector<string> temp: items)
        {
            if(temp[key]==ruleValue)
            {
                count++;
            }
        }

return count;

    }
};