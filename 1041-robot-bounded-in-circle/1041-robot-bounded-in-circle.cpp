class Solution {
public:
    bool isRobotBounded(string s) {
        unordered_map<int,int> map;
        int dir = 0;
        for(auto c:s)
        {
             if(c=='L')
                dir = (dir+1)%4;
            else if(c=='R')
                dir = (dir-1+4)%4;
            else
            {
            switch(dir)
            {
                case 0:
                    {
                        map[1]++;
                        break;
                    }
                case 1:
                    {
                        map[2]++;
                        break;
                    }
                case 2:{
                    map[1]--;
                    break;
                }
                case 3:
                    {
                        map[2]--;
                        break;
                    }
            }
            }
        }
        if(map[0]==map[2] && map[1]==map[3])
            return true;
        if(dir!=0)
            return true;
        else return false;
    }
};