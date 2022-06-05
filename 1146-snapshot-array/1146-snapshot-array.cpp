class SnapshotArray {
public:
    int id;
    vector<vector<vector<int>>> nums;
    SnapshotArray(int length) {
        nums.resize(length);
        id = 0;
    }
    
    void set(int index, int val) {
        nums[index].push_back({id,val});
    }
    
    int snap() {
        id++;
        return id-1;
    }
    
    int get(int index, int snap_id) {
        int low = 0;
        int high = nums[index].size()-1;
        int ans = 0;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(nums[index][mid][0]<=snap_id)
            {
                ans = nums[index][mid][1];
                low = mid+1;
            }
            else
                high = mid-1;
        }
        return ans;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */