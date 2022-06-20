class Solution {
public:
    typedef pair<int,int> ppi;
    int minKnightMoves(int x, int y) {
        queue<ppi> q;
        set<ppi> st;
        q.push({0,0});
        st.insert({0,0});
        vector<int> dirx = {1,1,-1,-1,2,2,-2,-2};
        vector<int> diry = {2,-2,2,-2,1,-1,1,-1};
        int ans = 0;
        x = abs(x);
        y = abs(y);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto r = q.front().first;
                auto c = q.front().second;
                if(r==x && c==y) return ans;
                q.pop();
                for(int i=0; i<8; i++){
                    int nr = r+dirx[i];
                    int nc = c+diry[i];
                    if(nr<=-2 or nc<=-2) continue;
                    if(st.find({nr,nc})!=st.end()) continue;
                    st.insert({nr,nc});
                    q.push({nr,nc});
                }
            }
            ans++;
        }
        return -1;
    }
};