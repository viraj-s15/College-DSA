#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

template<typename T>
void removeDupes(vector<T>& vec) {
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
}

bool strCompare(string s1, string s2) {
 
    if (s1.size() == s2.size()) {
        return s1 < s2;
    }
    else {
        return s1.size() < s2.size();f
    }
}


int unique(string s) { 
    unordered_map<char, int> m; 
    for (int i = 0; i < s.length(); i++) { 
        m[s[i]]++; 
    } 
    return m.size(); 
} 

vector<string> longestPalindrome(const string &word) {
    int start = 0;
    int end = word.length();
    vector<string> words;
    string solution;
    for (auto i = start; i < end; i++) {
        for (auto j = 1; j < end; j++) {
            string str1 = word.substr(i,j);
            string str2 = str1;
            reverse(str1.begin(), str1.end());
            if (str1 == str2 and str1.length() > 2) {
                words.push_back(str1);
            } else if (str1 == str2){
                string temp = str1.substr(0);
                words.push_back(temp);
            }
        }
    }
    removeDupes<string>(words);
    sort(words.begin(), words.end(),strCompare);
    return words;
}

template<typename T>
void printVector(vector<T> v) {
    for (auto const& i : v) {
        cout << i << endl;
    }
}
void processWords(const vector<string>& words,string word) {
    if (words.size() != unique(word)) {
        for (auto i = 0; i < words.size();i++) {
            if (words[i].size() > 2) cout << words[i] << endl;
        }
        cout << "Longest Palindrome is " << words.back() <<  endl;
    } else {
        printVector(words);
        cout << "Longest Palindrome is " << words.front() <<  endl;
    }
}


int main() {
    string word;
    cin >> word;
    vector<string> result = longestPalindrome(word);
    processWords(result,word);

    return 0;
}
