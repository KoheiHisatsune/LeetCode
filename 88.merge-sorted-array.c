/*
 * @lc app=leetcode id=88 lang=c
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
#include <stdlib.h>
#include <stdio.h>

typedef int BOOL;
#define TRUE 1
#define FALSE 0

void printArray(int* array, int nums);


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){

  int mergeLen = m + n;
  int* temp = malloc(sizeof(int) * mergeLen);

  int i = 0;
  int j = 0;
  int k = 0;

  while (i < m || j < n){
    //printf("i : %d j : %d k : %d\n",i,j,k);
    if (i == m){
      temp[k++] = nums2[j++];
      continue;
    }

    if (j == n){
      temp[k++] = nums1[i++];
      continue;
    }

    if (nums1[i] < nums2[j]){
      temp[k++] = nums1[i++];
    }
    else {
      temp[k++] = nums2[j++];
    }
  }

//  printArray(temp,mergeLen);

  memcpy(nums1,temp,mergeLen * sizeof(int));

}

void printArray(int* array, int nums)
{
  int i;
  for (i = 0; i < nums; i++){
    printf("%d\n",array[i]);
  }
}
// @lc code=end

