class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        vector<int> left(n,0),right(n,0);
        vector<int> lseen(26,-1),rseen(26,n);
        for(int i=0; i<n; i++)
        {
            left[i] = i - lseen[s[i]-'A'];
            lseen[s[i]-'A'] = i;
        }
        for(int i=n-1; i>=0; i--)
        {
            right[i] = rseen[s[i]-'A']-i;
            rseen[s[i]-'A'] = i;
        }
		int ans = 0; 

		for (int i = 0; i < n; i++){
			ans = (ans + (left[i] * right[i]) );
		}
		return ans;
    }
};