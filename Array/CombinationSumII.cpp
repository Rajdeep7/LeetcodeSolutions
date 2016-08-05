
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.empty())
            return res;
        sort(candidates.begin(), candidates.end());
        vector<int> nums;
        helper(res, nums, candidates, target, 0);
        return res;
    }
    
    void helper(vector<vector<int>> &res, vector<int> &nums, vector<int> candidates, int target, int st) {
        if(target<0)
            return;
            
        else {
            if(target==0)
                res.push_back(nums);
            else {
                int repeated = -1; 
                for(int i = st; i < candidates.size(); i++) {
                    if(repeated != candidates[i]) {
                        nums.push_back(candidates[i]);
                        helper(res, nums, candidates, target-candidates[i], i+1);
                        repeated = candidates[i];
                        nums.pop_back();
                    }
                
                }
            }
        }
    }
};
