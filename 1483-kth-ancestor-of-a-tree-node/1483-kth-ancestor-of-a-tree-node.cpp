class TreeAncestor {
public:
    vector<vector<int> > P; // P[i][node] :::: [node] 's [2^i]th parent
    TreeAncestor(int n, vector<int>& parent) {
        P.resize(20, vector<int>(parent.size(), -1));
        
        // 2^0
        for(int i = 0; i < parent.size(); i++){
            P[0][i] = parent[i];
        }
        
        // 2^i
        for(int i = 1; i < 20; i++){
            for(int node = 0; node < parent.size(); node ++){
                int nodep = P[i-1][node];
                if(nodep != -1) P[i][node] = P[i-1][nodep];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i = 0; i < 20; i++){
            if(k & (1 << i)){
                node = P[i][node];
                if(node == -1) return -1;
            }
        }

        return node;
    }
};