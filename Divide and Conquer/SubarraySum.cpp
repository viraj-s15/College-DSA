#include <iostream>
#include <vector>
using namespace std;

// If left is greater than right, return null as the subarray does not
// exist. It calls itself, twice dividing the array into the left and 
// the right subarray. Prefix sum is used instead of arr sum variable
// , this is done to calculate the sum and keep track of each cycle in
// constant time resulting arr time complexity of O(Nlog(numOfEle))


// This solution also returns the sum but for some reason takes the latter half of the indices,
// even when an answer is already found in the lower indices

// vector<int> subarray_sum(const vector<int>& arr, int totalSum, int left, int right, vector<int> &prefix_sum) {
//     if (left > right) {
//         return {-1, -1};
//     }
//     int mid = (left + right) / 2;
//     int curr_sum = prefix_sum[right] - (left > 0 ? prefix_sum[left - 1] : 0);
//     if (curr_sum == totalSum) {
//         return {left + 1, right + 1};
//     }

//     if (left == right) {
//         return {-1, -1};
//     }

//     vector<int> right_res = subarray_sum(arr, totalSum, mid + 1, right, prefix_sum);
//     if (right_res[0] != -1) {
//         return right_res;
//     } else {
//         return subarray_sum(arr, totalSum, left, mid, prefix_sum);
//     }
// }

vector<int> subarray_sum(vector<int>& arr, int numOfEle, int totalSum) {
    int left = 0, right = 0, sum = arr[0];
    for (int i = 1; i <= numOfEle; i++) {
        while (sum > totalSum && left < i-1) {
            sum -= arr[left];
            left++;
        }
        if (sum == totalSum) {
            return {left+1, i};
        }
        if (i < numOfEle) {
            sum += arr[i];
        }
    }
    return {-1, -1};
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
    vector<int> arr;
    int numberOfElements, sum;
    cin >> numberOfElements >> sum;
    getInput<int>(arr, numberOfElements);
    vector<int> result = subarray_sum(arr,numberOfElements,sum);
    if (result[0] != -1) {
      cout << result[0] << " " << result[1];
    }
    return 0;
}
