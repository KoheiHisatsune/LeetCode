/*
 * @lc app=leetcode id=58 lang=c
 *
 * [58] Length of Last Word
 */

// @lc code=start
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int lengthOfLastWord(char * s)
{
  int len = strlen(s);

  int i;
  int j = 0;
  int lastLen = 0;

  for (i = 0; i < len; i++){
    if (!isspace(s[i])){
      break;
    }
  }

  for ( ; i < len; i++){
    if (isspace(s[i]) && !isspace(s[i-1])){
      lastLen = j;
      j = 0;
    }
    else if (!isspace(s[i])){
      j++;
    }
  }

  lastLen = (j != 0)? j : lastLen;

  return lastLen;

}
// @lc code=end

