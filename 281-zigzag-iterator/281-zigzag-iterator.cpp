class ZigzagIterator {
public:
    int i,j,m,n;
    bool turn1;
    vector<int> v1,v2;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        i = 0, j = 0;
        m = v1.size();
        n = v2.size();
        turn1 = true;
        this->v1 = v1;
        this->v2 = v2;
    }

    int next() {
        if(turn1){
            turn1 = false;
            return i<m ? v1[i++]:v2[j++];
        }
        else{
            turn1 = true;
            return j<n ? v2[j++]:v1[i++];
        }
    }

    bool hasNext() {
        return i<m or j<n;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */