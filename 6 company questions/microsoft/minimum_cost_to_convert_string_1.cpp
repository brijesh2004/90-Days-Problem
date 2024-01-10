// https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
         const long long inf = 1e18; // Initialize an arbitrarily large constant for infinity
        vector<vector<long long>> c(26,vector<long long>(26,inf)); // Initialize a 2D matrix to store costs between characters
        int m = original.size(); // Get the size of the original character array
        
        // Initialize costs between characters from the original and changed arrays
        for(int i = 0; i < 26; i++)
            c[i][i] = 0; // Setting the cost of transformation of a character to itself as 0
        
        // Set costs based on original and changed characters and their corresponding costs
        for(int i = 0; i < m; i++){
            c[original[i] - 'a'][changed[i] - 'a'] = min(c[original[i] - 'a'][changed[i] - 'a'], 1LL * cost[i]);
        }
        
        // Apply Floyd-Warshall algorithm to find the minimum costs between characters
        for(int k = 0; k < 26; k++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
                }
            }
        }
        
        long long ans = 0; // Initialize the answer variable to store the total cost
        int n = source.length(); // Get the length of the source string
        
        // Calculate the total cost to transform the source string into the target string
        for(int i = 0; i < n; i++){
            ans += c[source[i] - 'a'][target[i] - 'a']; // Accumulate the cost of transforming each character
            if(ans >= inf) return -1; // If the cost exceeds infinity, return -1 indicating it's impossible
        }
        
        return ans; // Return the total cost of transformation
    }
};