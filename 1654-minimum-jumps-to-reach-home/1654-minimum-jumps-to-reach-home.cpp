class Solution {
public:
    int mx;
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        mx = 10000;
        queue<pair<int,bool>> q;
        set<pair<int,bool>> visited;
        set<int> forbid(forbidden.begin(),forbidden.end());
        int steps = 0;
        q.push({0,false});
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                auto node = q.front();
                q.pop();
                if(node.first == x) return steps;
                if(visited.find(node)!=visited.end()) continue;
                visited.insert({node});
                if(node.first + a <= mx && forbid.count(node.first+a)==0)
                {
                    q.push({node.first+a,false});
                }
                if(node.first - b >=0 && node.second==false && forbid.count(node.first-b)==0)
                {
                    q.push({node.first-b,true});
                }
            }
            steps++;
        }
        return -1;
    }
};