#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> initTable(string s1,string s2) {
    int l1,l2;
    l1 = s1.size();
    l2 = s2.size();
    vector<vector<int>> solution;
    for (auto i = 0 ; i < l1 + 1; i++) {
        vector<int> temp;
        for (auto j = 0; j < l2 + 1; j++) {
                temp.push_back(0);
            }
        solution.push_back(temp);
        }

    return solution;
}

int createTable(vector<vector<int>>& final,string s1, string s2) {

        int l1 = s1.length();
        int l2 = s2.length();

		int maxLen = 0;
		for (int i = 1; i <= l1; i++) {
			for (int j = 1; j <= l2; j++) {
				if (s1[i - 1] == s2[j - 1]) {
					final[i][j] = 1 + final[i - 1][j - 1];
					maxLen = max(maxLen, final[i][j]);
				} else if (s1[i - 1] != s2[j - 1]) {
                    final[i][j] = max(final[i-1][j], final[i][j-1]);
                }
				else
					final[i][j] = 0;
			}
		}
		
		return maxLen;
	}


void printVector(vector<vector<int>>& v) {
    for (auto i = 0; i < v.size(); i++) {
        for (auto j = 0; j < v[i].size(); j++) {
            cout << v[i][j] <<   " ";
        }
    cout << endl;
    }
}

void longestCommonSubstring(vector<vector<int>>& solution) {
    int l1 = solution.size() - 1;
    int l2 = solution[l1].size() - 1;
    int lenghtOfSub = solution[l1][l2];
    cout << "Length of LCS is " << lenghtOfSub << endl;     
}

int main() {
    string s1,s2;
    vector<vector<int>> finalTable;
    int l1,l2;
    cin >> s1 >> s2;
    l1 = s1.length();
    l2 = s2.length();
    if (l1 < l2) {
        swap(s1,s2);
    }
    finalTable = initTable(s1,s2);
    createTable(finalTable,s1,s2);
    printVector(finalTable);
    longestCommonSubstring(finalTable);

}
