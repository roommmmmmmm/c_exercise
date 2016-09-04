#include <stdio.h>
#include <stdlib.h>
//题目：
// Given nums = [2, 7, 11, 15], target = 9,
//
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].
 int* twoSum(int* nums, int numsSize, int target) {
     int i,j;
     int *index = (int*)malloc(2 * sizeof (int));
     for( i=0; i<numsSize; i++)
     {
         for( j=i+1; j<numsSize; j++)
         {
             if(nums[i] + nums[j] == target)
             {
                 index[0] = i;
                 index[1] = j;
                 return index;
             }
         }
     }
     return NULL;
 }
int main(int argc, char const *argv[]) {
  int nums[] = {2,7,11,15};
  int *p,i;
  int numsSize=sizeof(nums);
  p = twoSum(nums,numsSize,26);
  printf("[%d %d]\n",p[0],p[1] );
  return 0;
}
