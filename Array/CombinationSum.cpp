class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.empty())
            return res;
        sort(candidates.begin(), candidates.end());
        vector<int> nums;
        helper(res, nums, candidates, target, 0);
        return res;
    }
    
    void helper(vector<vector<int>> &res, vector<int> &nums, vector<int> candidates, int target, int i) {
        if(target==0)
            res.push_back(nums);
        else {
            while(i<candidates.size() && target-candidates[i]>=0) {
                nums.push_back(candidates[i]);
                helper(res, nums, candidates, target-candidates[i], i);
                i++;
                nums.pop_back();
                
            }
        }
    }
};
