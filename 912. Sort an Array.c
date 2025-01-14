int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    int maxNumber = nums[0], minNumber = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > maxNumber) maxNumber = nums[i];
        if (nums[i] < minNumber) minNumber = nums[i];
    }

    int k = maxNumber - minNumber + 1;

    int* newVector = calloc(k, sizeof(int));

    int* sortedArray = malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        newVector[nums[i] - minNumber]++;
    }

    for (int i = 0, j = 0; i < k; i++) {
        while (newVector[i] > 0) {
            sortedArray[j++] = i + minNumber;
            newVector[i]--;
        }
    }

    return sortedArray;
}
