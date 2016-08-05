class Solution {
public:
    int longestConsecutive(vector<int>& num) {
        unordered_map<int, bool> m;
        for(int i = 0; i < num.size(); i++) {
            m[num[i]] = true;
        }
        int res = 0;
        for(int i = 0; i < num.size(); i++) {
            int mx = 1;
            int fd = num[i];
            m.erase(num[i]);
            
            while(m.find(fd+1) != m.end()) {
                mx++;
                m.erase(fd+1);
                fd++;    
            }
            fd = num[i];
            while(m.find(fd-1) != m.end()) {
                mx++;
                m.erase(fd-1);
                fd--;   
            }
            res = max(res, mx);
            
        }
        return res;
    }
};
