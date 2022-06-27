class Solution {
public:
    string minimizeResult(string expr) {
		int idx = expr.find('+');
        string num1 = expr.substr(0,idx);
        string num2 = expr.substr(idx+1);
		
        int b1=0,b2=0;
        int min =INT_MAX;
        string ans;
		
        int p1,p2;
		
        for(int b1=0;b1<num1.size();b1++)
        {
            for(int b2=0;b2<num2.size();b2++)
            {
                string s1=num1.substr(0,b1);
                string s2=num2.substr(b2+1);
               
			   if(s1.empty())
                    p1=1;
                else
                    p1=stoi(num1.substr(0,b1));
                if(s2.empty())
                    p2=1;
                else
                    p2=stoi(num2.substr(b2+1,b2-num2.size()-1));
					
                int sum=stoi(num1.substr(b1)) + stoi(num2.substr(0,b2+1));
			   int eval=p1*sum*p2;
			   
                if(eval<min){                    
                    min=eval;
                    ans=s1+"("+num1.substr(b1)+"+"+num2.substr(0,b2+1)+")"+s2;
                }
            }
        }
        return ans;        
    }
};