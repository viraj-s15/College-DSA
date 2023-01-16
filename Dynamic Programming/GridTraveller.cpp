#include <iostream>
#include <unordered_map>
#include <cmath>
// Grid Traveller
// You are a traveler who has to traverse a m x n grid. The only way you can move 
// is either by moving right or to the bottom, how many such ways can be found 

using namespace std;

long gridTraveller(long m, long n,unordered_map<long,long>& memo) {
    // creating a unique key from the given numbers 
    long temp = pow(2,m) * pow(3,n);
    if (memo.find(temp) != memo.end()) return memo[temp];
    if (m == 1 and n == 1) return 1;
    if (m == 0 or n == 0) return 0;
    memo[temp] = gridTraveller(m-1,n,memo) + gridTraveller(m,n-1,memo);
    return memo[temp];
}


int main() {
    long m,n;
    unordered_map<long,long> umap = {{}};
    cin >> m >> n;
    long result = gridTraveller(m,n,umap);
    cout << result << endl;
}