#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool canSum(long targetSum, vector<long>& nums,unordered_map<long, bool> umap) {
    if (umap.find(targetSum) != umap.end()) return umap.at(targetSum);    
    if (targetSum == 0) return true;
    if (targetSum < 0) return false;
    for (auto const& num : nums) {
        long remainingAmount = targetSum - num;
        if (canSum(remainingAmount, nums, umap)) {
            umap.insert({targetSum, true});
            return true;
        };
    }
    umap.insert({targetSum, false});
    return false;
}

template<typename T>
void getInput(vector<T>& v, int n) {
    for (int i = 0; i < n; i++) {
        long temp;
        cin >> temp;
        v.push_back(temp);
    }
}

int main() {
    long targetSum;
    int n;
    vector<long> nums;
    unordered_map<long, bool> umap;
    cin >> targetSum >> n;
    getInput(nums,n);
    bool result = canSum(targetSum,nums,umap);
    cout << boolalpha << result << endl;
    return 0;
}
