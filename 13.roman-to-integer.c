/*
 * @lc app=leetcode id=13 lang=c
 *
 * [13] Roman to Integer
 */

// @lc code=start
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int romanToInt(char * s){

  int len = strlen(s);
  int i;
  int result = 0;

  for (i = 0; i < len; i++){
    if (s[i] == 'C'){
      if (s[i + 1] == 'M'){
        result += 900;
        i++;
        continue;
      }
      else if (s[i + 1] == 'D'){
        result += 400;
        i++;
        continue;
      }
      else {
        result += 100;
      }
    }

    if (s[i] == 'X'){
      if (s[i + 1] == 'L'){
        result += 40;
        i++;
        continue;
      }
      else if (s[i + 1] == 'C'){
        result += 90;
        i++;
        continue;
      }
      else{
        result += 10;
      }
    }

    if (s[i] == 'I'){
      if (s[i + 1] == 'V'){
        result += 4;
        i++;
        continue;
      }
      else if (s[i + 1] == 'X'){
        result += 9;
        i++;
        continue;
      }
      else {
        result += 1;
      }
    }

    if (s[i] == 'V'){
      result += 5;
    }

    if (s[i] == 'L'){
      result += 50;
    }

    if (s[i] == 'D'){
      result += 500;
    }

    if (s[i] == 'M'){
      result += 1000;
    }

    printf("%d %d\n",result);
  }

  return result;

}

// @lc code=end

