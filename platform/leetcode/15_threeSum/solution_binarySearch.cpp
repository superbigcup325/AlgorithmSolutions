class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        const int len=nums.size();
        if (len<3) return ans;
        sort(nums.begin(),nums.end());
        if (nums[0]>0) return ans;
        for (int i=0;i<len-2;i++){
            if (nums[i]>0) break;
            if (i>0&&nums[i]==nums[i-1]) continue;
            int l=i+1,r=len-1;
            while (l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if (sum==0){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    while (l<r&&nums[l]==nums[l+1]) l++;
                    while (l<r&&nums[r]==nums[r-1]) r--;
                    l++,r--;
                }
                else {
                    sum>0? r--:l++;
                }
            }
        }
        return ans;
    }
};