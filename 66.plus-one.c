/*
 * @lc app=leetcode id=66 lang=c
 *
 * [66] Plus One
 */

// @lc code=start
#include <stdlib.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){

  int* returnDigits = malloc(sizeof(int) * digitsSize);
  int arraySize;

  int i;
  int carry = 0;
  int remain;
  int tempNum;

  for (i = digitsSize; i > 0; i--){
    tempNum = (i == digitsSize)? digits[i-1] + 1:
                                 digits[i-1] + carry;
    remain = tempNum % 10;
    carry = tempNum / 10;
    returnDigits[i - 1] = remain;
  }

  if (carry != 0){
    int* tempArray = realloc(returnDigits,sizeof(int) * (digitsSize + 1));
    returnDigits = tempArray;
    for (i = digitsSize; i > 0; i--){
      returnDigits[i] = returnDigits[i - 1];
    }
    returnDigits[0] = 1;
    *returnSize = digitsSize + 1;
  }
  else {
    *returnSize = digitsSize;
  }

  return returnDigits;

}
// @lc code=end

