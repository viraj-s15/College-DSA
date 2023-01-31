#include <iostream>
#include <string>

using namespace std;

template<typename T>
void printVector(vector<T> v) {
    for (auto const& i : v) {
        cout << i << " ";
    }
}

void naiveStringMatching(string str1,string str2) { 
    int l1 = str1.length();
    int l2 = str2.length(); 
    int j;
    for (int i = 0; i <= l1-l2; i++) { 
      for (j = 0; j < l2; j++) {
        if (str1[i+j] != str2[j]) break; 
      }
      if (j == l2) cout<<"Pattern found at index "<<i<<endl; 
    } 
}
 
int main() {
    string str1,str2;
    getline(cin,str1);
    cin;
    cin >> str2;
    naiveStringMatching(str1,str2);
    return 0;
}