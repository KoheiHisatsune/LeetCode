/*
 * @lc app=leetcode id=35 lang=c
 *
 * [35] Search Insert Position
 */

// @lc code=start
#include <stdio.h>

int binaryCheck(int* nums, int left, int right, int target);

int searchInsert(int* nums, int numsSize, int target)
{
  int left = 0;
  int right = numsSize - 1;

  return binaryCheck(nums, left, right, target);

}

int binaryCheck(int* nums, int left, int right, int target)
{
  //printf("left : %d, right : %d\n",left,right);
  if (left == right){
  //  printf("index : %d , array : %d target :%d\n",
  //         left,nums[left],target);
    return (nums[left] < target) ? left + 1 :
                                   left;
  }

  int mid = (left + right) / 2;

  //printf("mid: %d arrayMid : %d target : %d\n",
  //       mid, nums[mid],target);

  return (nums[mid] < target) ? binaryCheck(nums,mid + 1, right , target):
                                binaryCheck(nums,left   , mid   , target);

}
// @lc code=end

