class Solution {
public:
    
    double pi = acos(-1.0);
    
    double getAngle(double y, double x)
    {
        return (atan2(y,x)*180)/pi;
    }
    
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int answer = 0;
        vector<double> pointAngles;
        for(auto p : points){
            if(p[0] == location[0] && p[1] == location[1]){
                answer += 1;
            }else {
                double dx = p[0] - location[0];
                double dy = p[1] - location[1];
                double angle = getAngle(dy,dx);
                pointAngles.push_back(angle);
            }
        }
        sort(pointAngles.begin(),pointAngles.end());
        int n = pointAngles.size();
        for(int i= 0; i < n ; ++i) {
            pointAngles.push_back(pointAngles[i] + 360);
        }
        int start = 0;
        int cnt = 0;
        for(int i = 0; i < pointAngles.size(); ++i) {
            if(pointAngles[i] - pointAngles[start] > angle){
                start++;
            }
            cnt = max(cnt, i - start + 1);
        }
        answer += cnt; 
        return answer;
    }
};