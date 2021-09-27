/*
 * @lc app=leetcode id=28 lang=c
 *
 * [28] Implement strStr()
 */

// @lc code=start
#include <string.h>

int strStr(char * haystack, char * needle){

  char* indexPtr;
  int index;

  if (needle[0] == '\0'){
    return 0;
  }

  if ((indexPtr =strstr(haystack,needle)) != NULL){
    index = (int)(indexPtr - haystack);
  }
  else {
    index = -1;
  }

  return index;

}
// @lc code=end

