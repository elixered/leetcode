class Solution {
public:
    class HeapNode{
        public:
        int val;
        int r;
        int c;
        HeapNode(int x, int y, int z)
        {
            val = x;
            r = y;
            c = z;
        }
    };
    struct cmp{
        bool operator()(HeapNode &h1, HeapNode &h2)
        {
            return h1.val > h2.val;
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<HeapNode,vector<HeapNode>,cmp> minHeap;
        for(int i=0; i<min(n,k); i++)
            minHeap.push(HeapNode(matrix[i][0],i,0));
        while(!minHeap.empty())
        {
            k--;
            auto node = minHeap.top();
            minHeap.pop();
            if(k==0)
                return node.val;
            int x = node.r;
            int y = node.c;
            if(y<n-1)
                minHeap.push(HeapNode(matrix[x][y+1],x,y+1));
        }
        return -1;
    }
};