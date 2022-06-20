

class Solution {
public:
    
    vector<vector<int>>dir={{2,1},{2,-1},{1,2},{1,-2},{-2,1},{-2,-1},{-1,2},{-1,-2}};
    int minKnightMoves(int x, int y) {
        if(x==0 and y==0) return 0;
        vector<vector<bool>>visitedFromOrigin(605,vector<bool>(605));
        vector<vector<bool>>visitedFromTarget(605,vector<bool>(605));
        queue<pair<int,int>>originQ;
        queue<pair<int,int>>targetQ;
        int levelo=0,levelt=0;
        originQ.push({300,300});
        x=abs(x),y=abs(y);
        visitedFromOrigin[300][300]=true,visitedFromTarget[300+x][300+y]=true;
        targetQ.push({300+abs(x),300+abs(y)});
        while(!originQ.empty() and !targetQ.empty())
        {   
            int sizeO=originQ.size();
            for(int i=0;i<sizeO;i++)
            {
                pair<int,int>front=originQ.front();
                originQ.pop();
                int r=front.first,c=front.second;
                for(auto d:dir)
                {
                    int x1=r+d[0],y1=c+d[1];
                    if(!(x1>=298 and y1>=298 and x1<605 and y1<605))
                    {
                        continue;
                    }
                    if(!visitedFromOrigin[x1][y1])
                    {   
                        originQ.push({x1,y1});
                        if(visitedFromTarget[x1][y1])
                        {
                            return levelo+levelt+1;
                        }
                        visitedFromOrigin[x1][y1]=true;
                    }
                }
            }
            levelo++;
            
            int sizeT=targetQ.size();
            for(int i=0;i<sizeT;i++)
            {
                pair<int,int>front=targetQ.front();
                targetQ.pop();
                int r=front.first,c=front.second;
                for(auto d:dir)
                {
                    int x1=r+d[0],y1=c+d[1];
                    if(!(x1>=0 and y1>=0 and x1<=302+x and y1<=302+y))
                    {
                        continue;
                    }
                    if(!visitedFromTarget[x1][y1])
                    {   
                        targetQ.push({x1,y1});
                        if(visitedFromOrigin[x1][y1])
                        {
                            return levelo+levelt+1;
                        }
                        visitedFromTarget[x1][y1]=true;
                    }
                }
            }
            levelt++;
        }
        return 0;
    }
};