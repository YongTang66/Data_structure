#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//��ת����
//https://leetcode.cn/problems/rotate-array/
void reverse(int* nums, int begin, int end)
{
    while (begin < end)
    {
        int tmp = nums[begin];
        nums[begin] = nums[end];
        nums[end] = tmp;


        begin++;
        end--;
    }
}
void rotate(int* nums, int numsSize, int k)
{
    k %= numsSize;
    reverse(nums, 0, numsSize - k - 1);
    reverse(nums, numsSize - k, numsSize - 1);
    reverse(nums, 0, numsSize - 1);
}


//��ʧ������

//https://leetcode.cn/problems/missing-number-lcci/
int missingNumber(int* nums, int numsSize) {
    int n = numsSize;
    int x = 0;
    for (int i = 0; i < numsSize; i++)
    {
        x ^= nums[i];
    }
    for (int j = 0; j < n + 1; j++)
    {
        x ^= j;
    }
    return x;
}
