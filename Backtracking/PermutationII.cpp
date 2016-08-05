class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty())
            return res;
        sort(nums.begin(), nums.end());
        //vector<bool> v(res.size(), false);
        helper(res, nums, 0, nums.size()-1);
        return res;
    }
    
    void helper(vector<vector<int>> &res, vector<int> nums, int k, int n) {
        if(k == n)
            res.push_back(nums);
        else {
            for(int i = k; i <= n; i++) {
                    if(i!=k && nums[i]==nums[k])
                        continue;
                    
                    swap(nums[k],nums[i]);
                    helper(res, nums, k+1, n);
                    //swap(nums[k],nums[i]);
                    
                    
                    
                }
            }
        }
};
