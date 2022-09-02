class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int maxi =0 ;
        vector<vector<int>> t(n, vector<int>(m));
        for(int i=0 ;i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == '1') {
                    if(i==0 || j==0) {
                        t[i][j] = 1;
                        maxi = max(maxi, t[i][j]);
                    }
                    else {
                        t[i][j] = min(min(t[i-1][j],t[i][j-1]), t[i-1][j-1]) +1;
                        maxi = max(maxi, t[i][j]);
                    }
                }
            }
        }
        return maxi*maxi;
    }
};
