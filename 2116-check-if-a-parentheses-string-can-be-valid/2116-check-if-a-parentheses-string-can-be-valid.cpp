class Solution {
public:
      bool canBeValid(string s, string locked) {
        stack<char> lockedStack, unlockedStack;
        int n = s.size();
        if(n%2!=0)
            return false;
        for(int i=0; i<n; i++)
        {
            if(locked[i]=='0')
            {
                unlockedStack.push(s[i]);
            }
            else if(s[i]=='(')
                lockedStack.push(s[i]);
            else
            {
                if(lockedStack.size()>0)
                    lockedStack.pop();
                else if(unlockedStack.size()>0)
                    unlockedStack.pop();
                else return false;
            }
        }
        if(lockedStack.size()==0 && unlockedStack.size()==0)
            return true;
        while(lockedStack.size())
            lockedStack.pop();
        while(unlockedStack.size())
            unlockedStack.pop();
        for(int i=n-1; i>=0; i--)
        {
             if(locked[i]=='0')
            {
                unlockedStack.push(s[i]);
            }
            else if(s[i]==')')
                lockedStack.push(s[i]);
            else
            {
                if(lockedStack.size()>0)
                    lockedStack.pop();
                else if(unlockedStack.size()>0)
                    unlockedStack.pop();
                else return false;
            }
        }
        int m = lockedStack.size();
          int l = unlockedStack.size();
          if(m>l) return false;
          return ((l-m)%2==0);
    }
};
