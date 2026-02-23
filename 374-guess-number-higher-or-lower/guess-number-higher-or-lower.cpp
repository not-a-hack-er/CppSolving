/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int s=1,l=n;
        
        while(s<=l)
        {
            long long t = s + (l - s) / 2;
            int res=guess(t);
            if(res==0)
            return t;
            else if(res==-1)
            l = t-1;
            else 
            s=t+1;
        }
        return -1;
    }
};