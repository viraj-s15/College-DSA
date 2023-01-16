#include <iostream>
#include <unordered_map>

using namespace std;


const long long fib(const int n,unordered_map<long long,long long>& memo) {
    if (memo.find(n) != memo.end()) return memo[n];
    if (n <= 2) return 1;
    memo[n] = fib(n-1,memo) + fib(n-2,memo);
    return memo[n]; 
}

int main() {
    unordered_map<long long,long long> memo;
    long long result = fib(500,memo);
    cout << result << endl;
    return 0;
}