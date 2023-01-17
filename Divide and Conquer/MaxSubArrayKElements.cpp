#include <iostream>
#include <vector>
#include <climits>

using namespace std;


// dynamic programming approach, more efficient for smaller arrays
// int maxSubarraySumKelements(vector<int>& arr, int numberOfEle, int subArraySize) {
//     if (numberOfEle < subArraySize) return -1;
//     int maxSum = 0;
//     for (int i = 0; i < subArraySize; i++) maxSum += arr[i];
//     int window_sum = maxSum;
//     for (int i = subArraySize; i < numberOfEle; i++) {
//         window_sum += arr[i] - arr[i - subArraySize];
//         maxSum = max(maxSum, window_sum);
//     }
//     return maxSum;
// }


// This does not work for that one -5 test case for some reason

// int maxSubarraySumKelements(vector<int>& arr, int left, int right, int subArraySize) {

//     if (subArraySize > (right - left + 1)) return INT_MIN;

//     // if the subarray size is equal to the total number of elements in the array
//     if (right - left + 1 == subArraySize) {
//         int sum = 0;
//         for (int i = left; i <= right; i++) {
//             sum += arr[i];
//         }
//         return sum;
//     }
//     // base case
//     if (right - left + 1 < subArraySize) return INT_MIN;
//     if (left == right) return arr[left];

//     int mid = left + (right - left) / 2;
//     int maxSum = INT_MIN * subArraySize;
//     int sum = INT_MIN * subArraySize;
//     // right subarray
//     for (int i = mid; i >= left; i--) {
//         sum = max(sum + arr[i], arr[i]);
//         if (mid - i + 1 == subArraySize) maxSum = max(maxSum, sum);
//     }
//     sum = INT_MIN * subArraySize;
//     // left subarray
//     for (int i = mid + 1; i <= right; i++) {
//         sum = max(sum + arr[i], arr[i]);
//         if (i - mid == subArraySize) maxSum = max(maxSum, sum);
//     }
//     int leftSum = maxSubarraySumKelements(arr, left, mid, subArraySize);
//     int rightSum = maxSubarraySumKelements(arr, mid + 1, right, subArraySize);
//     return max(maxSum, max(leftSum, rightSum));
// }


// spaghetti code
int maxSubarraySumKelements(vector<int>& arr, int left, int right, int subArraySize) {
    if (right - left + 1 < subArraySize) return INT_MIN;
    if (left == right) return arr[left];
    int mid = left + (right - left) / 2;
    int leftSum = maxSubarraySumKelements(arr, left, mid, subArraySize);
    int rightSum = maxSubarraySumKelements(arr, mid + 1, right, subArraySize);

    int maxSum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        if (mid - i + 1 >= subArraySize) maxSum = max(maxSum, sum);
    }
    sum = 0;
    for (int i = mid+1; i <= right; i++) {
        sum += arr[i];
        if (i - mid >= subArraySize) maxSum = max(maxSum, sum);
    }
    int subArrSum = 0;
    for(int i = mid; i >= left; i--) {
        subArrSum += arr[i];
        if(mid - i + 1 >= subArraySize) {
            for(int j = i - 1; j >= left && j > i - subArraySize; j--) {
                subArrSum += arr[j];
                maxSum = max(maxSum, subArrSum);
            }
            subArrSum = 0;
        }
    }
    subArrSum = 0;
    for(int i = mid + 1; i <= right; i++) {
        subArrSum += arr[i];
        if(i - mid >= subArraySize) {
            for(int j = i + 1; j <= right && j < i + subArraySize; j++) {
                subArrSum += arr[j];
                maxSum = max(maxSum, subArrSum);
            }
            subArrSum = 0;
    }
}
    for (int i = mid; i >= left; i--) {
        for (int j = mid + 1; j <= right; j++) {
            subArrSum = 0;
            for (int k = i; k <= j; k++) {
                subArrSum += arr[k];
                if (j - i + 1 == subArraySize) {
                    maxSum = max(maxSum, subArrSum);
                }
            }
        }
    }
    return max(max(leftSum, rightSum), maxSum);
}


template <typename T>
void getInput(vector<T> &v,int numOfEle) {
    for (int i = 0; i < numOfEle; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

}

int main() {
    int numberOfEle, subArraySize,result;
    vector<int> arr;
    cin >> numberOfEle >> subArraySize;
    getInput<int>(arr, numberOfEle);
    result = maxSubarraySumKelements(arr,0,arr.size() - 1,subArraySize);
    cout << result;
    return 0;
}
