class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int max = 0;
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[i].length; j++){
                if(grid[i][j] == 1){
                    int area = helper(grid, i, j);  
                    max = Math.max(area, max);
                }
            }
        }
        return max;
    }
    private int helper(int[][] grid, int i, int j){
        if(i < 0 || j < 0 || i == grid.length || j == grid[0].length || grid[i][j] == 0) return 0;
        grid[i][j] = 0;
        int area = helper(grid, i - 1, j) + helper(grid, i + 1, j)+ helper(grid, i, j-1)+ helper(grid, i, j + 1) + 1;
        System.out.println(area);
        return area;
    }
}