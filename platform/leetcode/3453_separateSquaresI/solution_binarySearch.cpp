class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double min_y=squares[0][1],max_y=squares[0][1]+squares[0][2];
        double sum=0;
        for (auto& square:squares){
            double y=square[1],l=square[2];
            sum+=l*l;
            min_y=min_y<y? min_y:y;
            max_y=max_y>y+l? max_y:y+l;
        }
        double left=min_y,right=max_y;
        double target=sum/2;
        while (right-left>1e-5){
            double mid=left+(right-left)/2;
            double now=0;
            for (auto& square:squares){
                double y=square[1],l=square[2];
                if (mid<=y) continue;
                else if (mid>=y+l) now+=l*l;
                else now+=l*(mid-y);
            }
            now<target? left=mid:right=mid;
        }
        return left+(right-left)/2;
    }
};