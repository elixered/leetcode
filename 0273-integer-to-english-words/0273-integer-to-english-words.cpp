class Solution {
public:
    
    vector<string> change = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
     vector<string> tens = {"","","Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    string convert(int x){
        string ans;
        if(x/100)
            ans += change[x/100] + " Hundred";
        x %= 100;
        if(x && x< 20){
            if(ans.size() != 0)
                ans += " ";
            ans += change[x];
        }
        else if(x){
            if(ans.size() != 0)
                ans += " ";
            ans += tens[x/10];
            if(x%10)
                ans += " " + change[x%10];
        }
        return ans;
    }
    
    string numberToWords(int num) {
        string ans;
        int x = num/1000000000;
        if(x){
            ans += convert(x) + " Billion";
            num = num%1000000000;
        }
        x = num/1000000;
        if(x){
            if(ans.size() != 0)
                ans += " ";
            ans += convert(x) + " Million";
            num = num%1000000;
        }
        x = num/1000;
        if(x){
            if(ans.size() != 0)
                ans += " ";
            ans += convert(x) + " Thousand";
            num = num%1000;
        }
        if(ans.size() != 0 && num > 0)
            ans += " ";
        ans += convert(num);
        if(ans == " " or ans == "")
            return "Zero";
        return ans;
    }
};