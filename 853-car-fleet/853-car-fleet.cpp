class Solution {
public:
    struct car{
        int pos,speed;
        car(int a, int b)
        {
            pos = a;
            speed = b;
        }
    };
    struct cmp{
        bool operator()(car a, car b)
        {
            return a.pos<b.pos;
        }
    };
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<car> cars;
        for(int i=0; i<n; i++)  
            cars.push_back(car(position[i],speed[i]));
        sort(cars.begin(),cars.end(),cmp());
        stack<float> st;
        int ans = 0;
        for(auto it:cars)
        {
            float time = (float)(target-it.pos)/it.speed;
            while(!st.empty() && time>=st.top())
                st.pop();
            st.push(time);
        }
        return st.size();
    }
};