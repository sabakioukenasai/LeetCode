#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int minPathSam(vector<vector<int>>& grid){
        int row = grid.size(), col = grid[0].size();
        // vector<vector<int>> dp(row, vector<int>(col, 0));
        vector<int> dp(col, 0);
        // dp[row - 1][col - 1] = grid[row - 1][col - 1];
        dp[col - 1] = grid[row - 1][col - 1];

/*
        for (int i = row - 2; i >= 0; i--){
            dp[i][col - 1] = grid[i][col - 1] + dp[i + 1][col - 1];
        }
*/
        
        for (int j = col - 2; j >= 0; j--){
            dp[j] = grid[row - 1][j] + dp[j + 1];
        }
        
/*
        for (int j = col - 2; j >= 0; j--){
            dp[row - 1][j] = grid[row - 1][j] + dp[row - 1][j + 1];
        }

        if (row == 1 || col == 1)
            return dp[0][0];
*/
        
        if (row == 1)
            return dp[0];
        

        for (int i = row - 2; i >= 0; i--)
        {
            dp[col - 1] += grid[i][col - 1];
            for (int j = col - 2; j >= 0; j--)
            {
                // dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
                dp[j] = grid[i][j] + min(dp[j], dp[j + 1]);
            }
        }

        // return dp[0][0];
        return dp[0];
    }
};


int main(){
    vector<vector<int>> grid{{1, 3, 5}, {2, 3, 1}};
    Solution T;
    cout << T.minPathSam(grid) << endl;
}