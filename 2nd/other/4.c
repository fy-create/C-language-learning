int distance(int a,int b){
    return (a>b)?(a-b):(b-a);
}
int min(int a,int b){
    return (a>b)?b:a;
}

// 比较函数，用于排序
int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    // for(int i=0;i<numsSize;i++){
    //     for(int j=0;j<numsSize-i-1;j++){
    //         if(nums[j]>nums[j+1]){
    //             int tmp;
    //             tmp=nums[j];
    //             nums[j]=nums[j+1];
    //             nums[j+1]=tmp;
    //         }
    //     }
    // }

    // 先对数组排序
    qsort(nums, numsSize, sizeof(int), compare);

    int closestSum = INT_MAX; // 最接近的三数之和
    int minDiff = INT_MAX;    // 最小的差值

    for (int s = 0; s < numsSize - 2; s++) {
        int p = s + 1;
        int q = numsSize - 1;

        while (p < q) {
            int sum = nums[s] + nums[p] + nums[q];
            int diff = distance(sum, target);

            // 更新最接近的和
            if (diff < minDiff) {
                minDiff = diff;
                closestSum = sum;
            }

            // 移动指针
            if (sum < target) {
                p++;
            }
            else if (sum > target) {
                q--;
            }
            else {
                // 如果差值为0，直接返回目标值
                return target;
            }
        }
    }

    return closestSum;
}