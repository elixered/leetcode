class Solution {
public:
    
int check(int v , vector<int>& num ){
    int c = 0;
    for(int i=0;i<num.size();i++){
        c+= num[i]/v;
        if(num[i]%v!=0){
            c++;
        }
    }
    return c;
}

int minimizedMaximum(int n, vector<int>& v) {
    int h=INT_MIN;
    int l =1;
    for(auto& i : v){
        h = max(h , i);
    }
    int ans = 0;
    while(l<=h){
        int mid = (l+h)/2;
      
        int x = check(mid , v);
        if(x<=n){
            ans = mid;
            h = mid-1;
        }else{
            l = mid+1;
        }
    }
    return ans;
}
};