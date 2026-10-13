
class Solution {
  public:
    bool isBalanced(string& k) {
        stack<char> ans;
      for(int i=0;i<k.size();i++)
      {
          char ch=k[i];
     if(ch=='{'||ch=='('||ch=='[')
          ans.push(ch);
          
      else
      {
          if(!ans.empty())
          {
              char top=ans.top();
              if((ch=='}')&&(top=='{')||(ch==')')&&(top=='(')||(ch==']')&&(top=='['))
              {
              ans.pop();
              }
              else{
                  return false;
              }
          }
          
          else
          {
            return false;
            }
       }
          
      }
      if(ans.empty())
      return true;
      else
      return false;
    }
};