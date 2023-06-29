class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // getting the key lists
        unordered_map<char, int> key_bit;
        int bit_start = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (islower(grid[i][j]))
                    key_bit[grid[i][j]] = bit_start++;
        
        int mask_end = (1 << bit_start) - 1;
        int mask_size = (1 << bit_start);

        // preparing memo vector
        vector<vector<vector<bool>>> memo(m,vector<vector<bool>>(n, 
                                        vector<bool>(mask_size,false)));

        // get the starting point
        vector<int> start;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '@')
                    start = {i,j,0}; // 0 denoting no key state

        // BFS Loop
        queue<vector<int>> q;
        q.push(start);
        int step = 0;
        while (!q.empty())
        {
            int size = q.size();
            for (int k = 0; k < size; k++)
            {
                int row = q.front()[0];
                int col = q.front()[1];
                int mask = q.front()[2];
                q.pop();

                // check if out of bounds
                if (row < 0 || row >= m || col < 0 || col >= n)
                    continue;

                // check if wall
                if (grid[row][col] == '#') continue;

                // check if locked and don't have key
                if (isupper(grid[row][col]))
                    if ((mask & (1 << key_bit[tolower(grid[row][col])])) == 0)
                        continue;

                // if a key is in current position, update state
                if (islower(grid[row][col]))
                    mask = mask | (1 << key_bit[grid[row][col]]);

                // check if mask if complete
                if (mask == mask_end) return step;

                // check if state is already visited
                if (memo[row][col][mask]) continue;
                memo[row][col][mask] = true;

                // moving to neighbouring cells
                q.push({row+1, col, mask});
                q.push({row-1, col, mask});
                q.push({row, col+1, mask});
                q.push({row, col-1, mask});
            }
            step++;
        }
        return -1;
    }
};