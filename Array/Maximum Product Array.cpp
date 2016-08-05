class Solution {
public:
    int maxProduct(vector<int>& a) {
        int result = a[0];
        int M = a[0];
        int m = a[0];
        
        for(int i = 1; i < a.size(); i++) {
            int tmpmax = M;
            int tmpmin = m;
            
            M = max(max(a[i]*tmpmax, a[i]*tmpmin),a[i]);
            m = min(min(a[i]*tmpmax, a[i]*tmpmin),a[i]);
            
            result = max(result, M);
        }
    
        return result;
    }
    
};
