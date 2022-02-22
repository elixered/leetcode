class Solution {
public:
    string reformatDate(string date) {
        stringstream ss(date);
        string temp;
        int d;
        ss >> d;
        getline(ss,temp,' ');
        string mo;
        getline(ss,mo,' ');
        int y;
        ss >> y;
        string ans;
        ans += to_string(y)+"-";
        string month;
        
        if(mo=="Jan")
                month = "01";
        else if(mo=="Feb")
                month = "02";
        else if(mo=="Mar")
                month = "03";
        else if(mo=="Apr")
                month = "04";
        else if(mo=="May")
                month = "05";
        else if(mo=="Jun")
                month = "06";
        else if(mo=="Jul")
                month = "07";
        else if(mo=="Aug")
                month = "08";
        else if(mo=="Sep")
                month = "09";
        else if(mo=="Oct")
                month = "10";
        else if(mo=="Nov")
                month = "11";
        else if(mo=="Dec")
                month = "12";
        ans += month + "-";
        string day = to_string(d);
        if(day.size()==1) day = "0"+day;
        ans += day;
        return ans;
    }
};