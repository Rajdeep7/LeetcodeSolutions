class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row==0)
            return 0;
        int col = grid[0].size();
        int result = 0;
        vector<vector<bool>> mark(row,vector<bool>(col,true));
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j]=='1' && mark[i][j]==true) {
                    search(i,j,grid,mark);
                    result++;
                }
            }
        }
        return result;
    }
    
    void search(int i, int j, vector<vector<char>>& grid, vector<vector<bool>> &mark) {
        mark[i][j] = false;
        if (i+1<grid.size() && grid[i+1][j]=='1' && mark[i+1][j]==true){
            search(i+1,j,grid,mark);
        }
        if (j+1<grid[0].size() && grid[i][j+1]=='1' && mark[i][j+1]==true){
            search(i,j+1,grid,mark);
        }
        if (i-1>=0 && grid[i-1][j]=='1' && mark[i-1][j]==true){
            search(i-1,j,grid,mark);
        }
        if (j-1>=0 && grid[i][j-1]=='1' && mark[i][j-1]==true){
            search(i,j-1,grid,mark);
    
        }
    }
};
