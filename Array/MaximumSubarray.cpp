class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int M = a[0];
        int result = a[0];
        
        for(int i = 1; i < a.size(); i++) {
            int tmp = M;
            M = max(M+a[i], a[i]);
            result = max(result, M);
        }
        return result;
    }
};
