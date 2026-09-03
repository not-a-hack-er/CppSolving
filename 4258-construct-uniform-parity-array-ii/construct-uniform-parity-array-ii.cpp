class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

       
        bool allEven = true, allOdd = true;
        for(int x : nums) {
            if(x % 2)
            allEven = false;
            else 
            allOdd = false;
        }
        if(allEven || allOdd)
        return true;

        
        bool canOdd = false;
        for(int x : nums) {
            if(x % 2 == 1) {
                canOdd = true;
                break;
            }
        }

        if(canOdd) {
            for(int i = 0; i < n; i++) {
                if(nums[i] % 2 == 0) {
                    bool ok = false;
                    for(int j = 0; j < i; j++) {
                        if(nums[j] % 2 == 1) {
                            ok = true;
                            break;
                        }
                    }
                    if(!ok) canOdd = false;
                }
            }
        }

        
        bool canEven = true;
        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == 1) {
                bool ok = false;
                for(int j = 0; j < i; j++) {
                    if(nums[j] % 2 == 1) {
                        ok = true;
                        break;
                    }
                }
                if(!ok) canEven = false;
            }
        }

        return canOdd || canEven;
    }
};