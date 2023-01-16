#include <iostream>
#include <vector>
#include <unordered_map>
// #include <optional>

using namespace std;

template<typename T>
void getInput(vector<T>& v, int n) {
    for (int i = 0; i < n; i++) {
        long temp;
        cin >> temp;
        v.push_back(temp);
    }
}

template<typename T>
void printVector(vector<T> v) {
    for (auto const& i : v) {
        cout << i << " ";
    }
}

// one solution if you want to return the vector itself but this requires a few complications
// optional<vector<long>> 
// howSum(long targetSum, const vector<long>& nums) {
//   if (targetSum == 0) 
//     return vector<long>{};
//   if (targetSum < 0) 
//     return nullopt;
//   for (auto numer : nums) {
//     const auto remainder = targetSum - numer;
//     auto remainderResult = howSum(remainder, nums);
//     if (remainderResult) {
//       remainderResult->push_back(targetSum);
//       return remainderResult;
//     }
//   }
//   return nullopt;
// }


bool howSum(long targetSum, const vector<long>& nums, vector<long>& result,unordered_map<long, bool>& umap){
    result.clear();
    if (umap.find(targetSum) != umap.end()) return umap.at(targetSum);
    if (targetSum == 0) return true;
    if (targetSum < 0) return false;
    for (long num : nums) {
        const long remainder = targetSum - num;
        bool remainingElements = howSum(remainder, nums, result,umap);
        if (remainingElements) {
            result.push_back(num);
            umap.insert({targetSum, true});
            return true;
        }
    }
    umap.insert({targetSum, false});
    return false;
}

int main() {
    long targetSum;
    int n;
    vector<long> nums;
    vector<long> output;
    unordered_map<long, bool> umap;
    cin >> targetSum >> n;
    getInput(nums,n);
    bool result = howSum(targetSum,nums,output,umap);
    cout << boolalpha << result << endl;
    printVector(output);
    return 0;
}
