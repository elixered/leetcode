class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        stringstream ss1(num1),ss2(num2);
        string a1,b1,a2,b2;
        getline(ss1,a1,'+');
        getline(ss1,b1,'i');
        getline(ss2,a2,'+');
        getline(ss2,b2,'i');
        int x1 = stoi(a1);
        int y1 = stoi(b1);
        int x2 = stoi(a2);
        int y2 = stoi(b2);
        int z1 = x1*x2 - y1*y2;
        int z2 = x1*y2 + x2*y1;
        return to_string(z1)+"+"+to_string(z2)+"i";
    }
};