/*
 * @lc app=leetcode id=26 lang=c
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
#include <stdio.h>

void printArray(int* nums, int arrayNum);

int removeDuplicates(int* nums, int numsSize)
{
  int i;
  int j = 0;

  if (numsSize == 0){
    return 0;
  }

  for (i = 0; i < numsSize; i++){
//    printf("i : %d j : %d\n",i,j);
//    printf("nums[i] : %d nums[j] %d\n",nums[i],nums[j]);
    if (nums[j] != nums[i]){
//      printf("Delete Duplicate!\n");
      nums[++j] = nums[i];
    }
  }

//  printArray(nums,numsSize);

  return j + 1;

}

void printArray(int* nums, int arrayNum)
{
  int i;
  for (i = 0; i< arrayNum; i++){
    printf("index %d : %d\n", i,nums[i]);
  }
}
// @lc code=end

