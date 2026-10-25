class Solution {
public:
    vector<vector<int>> visited;
    vector<vector<int>> mat;
    void dfs(int i , int j){
        int m = mat.size();
        int n = mat[0].size();
        if(i<0 || i>=m || j<0 || j>=n || mat[i][j]==1 || visited[i][j]) return;
        visited[i][j]  = true;
        dfs(i+1,j);
        dfs(i-1,j);
        dfs(i,j+1);
        dfs(i,j-1);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n  = grid[0].size();
        visited.assign(m,vector<int>(n,0));
        mat = grid;
        int ans=0;
        for(int i = 0 ; i<m ; i++){
            dfs(i,0);
            dfs(i,n-1);
        }
        for(int j = 0 ; j<n ; j++){
            dfs(0,j);
            dfs(m-1,j);
        }
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j] == 0 && !visited[i][j]){ans++; dfs(i,j);}
            }
        }
        return ans;
    }
};