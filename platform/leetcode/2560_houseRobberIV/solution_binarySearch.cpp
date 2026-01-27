class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l=nums[0],r=nums[0],len=nums.size();
        for (int i=0;i<len;i++){
            l=l<nums[i]? l:nums[i];
            r=r>nums[i]? r:nums[i];
        }
        while (l<r){
            int mid=l+(r-l)/2;
            int stolen=0,cnt=0;
            for (int i=0;i<len;i++){
                if (!stolen&&nums[i]<=mid) cnt++,stolen=1;
                else stolen=0;
            }
            cnt>=k? r=mid:l=mid+1;
        }
        return l;
    }
};