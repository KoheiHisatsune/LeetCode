/*
 * @lc app=leetcode id=69 lang=c
 *
 * [69] Sqrt(x)
 */

// @lc code=start

int sqrtSearch(long long left, long long right, long long target);

int mySqrt(int x){

  return sqrtSearch(0,x,x);

}

int sqrtSearch(long long left, long long right, long long target)
{
  long long mid;

  if (right <= left + 1){
    return ((right * right) > target)? left : right;
  }

  mid = (left + right) / 2;

  return ((mid * mid) >= target)? sqrtSearch(left, mid  , target):
                                  sqrtSearch(mid , right, target);

}
// @lc code=end

