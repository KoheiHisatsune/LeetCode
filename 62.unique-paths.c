/*
 * @lc app=leetcode id=62 lang=c
 *
 * [62] Unique Paths
 */

// @lc code=start

int calcPaths(int** memo, int x, int y);

int uniquePaths(int m, int n){

  int i;
  int result;
  int** memo = malloc(sizeof(int *) * m);

  for (i = 0; i < m; i++){
    memo[i] = malloc(sizeof(int) * n);
    memset(memo[i],-1,sizeof(int) * n);
  }

  result = calcPaths(memo,m - 1, n - 1);
  free(memo);

  return result;

}

int calcPaths(int** memo, int x, int y)
{
  if (x < 0 || y < 0){
    return 0;
  }

  if (memo[x][y] == -1){
    memo[x][y] = (x == 0 && y == 0)? 1 : calcPaths(memo,x - 1, y) + calcPaths(memo,x, y - 1);
  }

  return memo[x][y];

}
// @lc code=end

