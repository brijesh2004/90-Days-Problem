// https://leetcode.com/problems/image-smoother/

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> result(m, vector<int>(n));
        
        for (int r = 0; r < m; r++) 
        {
            for (int c = 0; c < n; c++) 
            {
                int sum = 0, count = 0;

                // Iterate over the 3x3 neighborhood
                for (int dr = -1; dr <= 1; dr++) 
                {
                    for (int dc = -1; dc <= 1; dc++) 
                    {
                        int nr = r + dr;
                        int nc = c + dc;

                        // Check if the neighbor is within bounds
                        if ((nr >= 0) && (nr < m) && (nc >= 0) && (nc < n)) 
                        {
                            sum += img[nr][nc];
                            count++;
                        }
                    }
                }

                // Calculate the average and update the result matrix
                result[r][c] = (sum / count);
            }
        }

        return result;
    }
};