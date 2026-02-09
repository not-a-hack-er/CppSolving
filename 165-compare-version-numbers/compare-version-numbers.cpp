class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1=version1.size(),n2=version2.size();
        int i=0,j=0;
        while(i<n1 || j<n2)
        {
            int val1=0,val2=0;
            while(i<n1 && version1[i] !='.')
            {
                val1=val1*10+(version1[i]-'0');
                i++;
            }
            i++;
             while(j<n2 && version2[j] !='.')
            {
                val2 = val2*10+(version2[j]-'0');
                j++;
            }
            j++;
        
        // vector<int> v1 = splitString(version1,'.');
        // vector<int> v2 = splitString(version2,'.');

        // int val1,val2;

        // for(int i=0;i<v2.size();i++)
        // {
        //     v1 = v1.size() ? v1[i]:0;
        //     v2 = v2.size() ? v2[i]:0;

            if(val1<val2)
            return -1;
            else if(val2<val1)
            return 1;
      

        }
        return 0;
    }
};