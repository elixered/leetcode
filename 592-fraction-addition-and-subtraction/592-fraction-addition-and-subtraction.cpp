class Solution {
public:

void add(int& a, int& b, int c, int d) {
    int nume = a*d + c*b, deno = b*d;
    int gd = gcd(abs(nume), abs(deno));
    a = nume / gd;
    b = deno / gd;
}
string fractionAddition(string expression) {
    stringstream ss(expression);
    char op;
    int a, b, c, d;
    ss >> a; 
    ss >> op; 
    ss >> b;
    while(ss >> c) {
        ss >> op; 
        ss >> d;
        add(a, b, c, d);
    }
    return to_string(a) + "/" + to_string(b);
}
};