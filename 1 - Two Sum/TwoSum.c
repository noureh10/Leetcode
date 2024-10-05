#include <stdio.h>
#include <stdlib.h>


int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *returnIndices = malloc(sizeof(int) * 2);
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsSize; j++) {
            if (!(i == j) && nums[i] + nums[j] == target) {
                returnIndices[0] = i;
                returnIndices[1] = j;
                *returnSize = 2;
                return returnIndices;
            }
        }
    }
    *returnSize=0;
    return NULL;
}

int main() {
	{
		int nums[] = {3,3};
		int target = 6;
		int returnSize = 2;
		int *returnIndices = twoSum(nums, 4, target, &returnSize);
		printf("Indices: %d, %d\n", returnIndices[0], returnIndices[1]);
	}
	{
		int nums[] = {2,7,11,15};
		int target = 9;
		int returnSize = 2;
		int *returnIndices = twoSum(nums, 4, target, &returnSize);
		printf("Indices: %d, %d\n", returnIndices[0], returnIndices[1]);
	}
	{
		int nums[] = {3,2,4};
		int target = 6;
		int returnSize = 2;
		int *returnIndices = twoSum(nums, 4, target, &returnSize);
		printf("Indices: %d, %d\n", returnIndices[0], returnIndices[1]);
	}
	return 0;
}