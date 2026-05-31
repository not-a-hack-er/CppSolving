class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {

        sort(asteroids.begin(), asteroids.end());

        long long curr = mass;

        for(int x : asteroids) {
            if(curr < x)
                return false;
            curr += x;
        }
        return true;
    }
};