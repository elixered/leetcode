class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(),amount.end()); 
      int x=amount[0];
      int y=amount[1];
      int z=amount[2];
      int sum=x+y+z;
      if(x+y>z) return (sum+1)/2;
      else return z;
    }
};