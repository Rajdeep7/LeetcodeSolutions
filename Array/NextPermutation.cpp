class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.empty())
            return;
            
        int k = -1, l = -1;
        
        for(int i = nums.size()-1; i > 0; i--) {
            if(nums[i] > nums[i-1]) {
                k = i-1;
                break;
            }
        }
        
        if(k == -1) {
            sort(nums.begin(), nums.end());
            return;
        }
            
        
        for(int j = k+1; j < nums.size(); j++) {
            if(nums[j]>nums[k]) 
                l = j;
            
        }
        
        swap(&nums[k], &nums[l]);
        
        reverse(nums.begin()+k+1, nums.end());
        
    }
    
    void swap(int *a, int *b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
};
