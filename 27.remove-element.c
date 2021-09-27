/*
 * @lc app=leetcode id=27 lang=c
 *
 * [27] Remove Element
 */

// @lc code=start


int removeElement(int* nums, int numsSize, int val)
{
  int i;
  int j = 0;

  for (i = 0; i < numsSize; i++){
    if (nums[i] != val){
      nums[j++] = nums[i];
    }
  }

  //printf("%d\n",j);

  return j;

}
// @lc code=end

