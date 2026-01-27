class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        int prev_x=points[0][0],prev_y=points[0][1];
        for (auto& dot:points){
            int x=dot[0],y=dot[1];
            int dx=abs(x-prev_x),dy=abs(y-prev_y);
            int dia=min(dx,dy);
            ans+=dia;
            ans+=max(dx,dy)-dia;
            prev_x=x,prev_y=y;
        }
        return ans;
    }
};