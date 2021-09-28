/*
 * @lc app=leetcode id=63 lang=c
 *
 * [63] Unique Paths II
 */

// @lc code=start
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int calcPaths(int** table, int** obstacleGrid, int x, int y);

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){

  int i;
  int result;
  int** table = malloc(sizeof(int *) * obstacleGridSize);

  // printf("%d %d %d\n",obstacleGridSize,obstacleGridColSize,*obstacleGridColSize);

  for (i = 0; i < obstacleGridSize; i++){
    table[i] = malloc(sizeof(int) * (*obstacleGridColSize));
    memset(table[i],-1,sizeof(int) * (*obstacleGridColSize));
  }

  result = calcPaths(table,obstacleGrid,obstacleGridSize - 1, (*obstacleGridColSize) - 1);

  free(table);
  return result;
}

int calcPaths(int** table, int** obstacleGrid, int x, int y)
{
  if (x < 0 || y < 0){
    return 0;
  }

  // printf("INIT %d %d %d\n",x,y,table[x][y]);

  if (table[x][y] != -1){
    return table[x][y];
  }

  if (obstacleGrid[x][y] == 1){
    // printf("Obstacle\n");
    table[x][y] = 0;
  }
  else if (x == 0 && y == 0){
    // printf("Start\n");
    table[x][y] = 1;
  }
  else {
    // printf("Recursion\n");
    table[x][y] = calcPaths(table,obstacleGrid,x - 1, y) + calcPaths(table,obstacleGrid, x, y - 1);
  }
  // printf("RESULT %d %d %d\n",x,y,table[x][y]);
  return table[x][y];
}
// @lc code=end

