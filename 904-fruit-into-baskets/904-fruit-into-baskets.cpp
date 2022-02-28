class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> map;
        int n = fruits.size();
        int i=0, j = 0;
        int ans = 0;
        int count = 0;
        while(j<n)
        {
            if(map.find(fruits[j])!=map.end())
            {
                map[fruits[j]]++;
                ans = max(ans,j-i+1);
                j++;
            }
            else
            {
                if(count<2)
                {
                    count++;
                    map[fruits[j]]++;
                    ans = max(ans,j-i+1);
                    j++;
                }
                else
                {
                    while(count==2 && i<=j)
                    {
                        map[fruits[i]]--;
                        if(map[fruits[i]]==0)
                        {
                            count--;
                            map.erase(map.find(fruits[i]));
                        }
                        i++;
                    }
                    count++;
                    map[fruits[j]]++;
                    ans = max(ans,j-i+1);
                    j++;
                }
            }
                
        }
        return ans;
    }
};