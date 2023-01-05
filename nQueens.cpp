#include <iostream>
#include <vector>

using namespace std;

// There are three conditions to be satisfied in this code
// 1) There should be one queen in every row
// 2) There should be one queen in every column
// 3) None of the queens must attack one another

void checkCondition(vector<string>& board, vector<vector<string>>& solution, vector<int>& leftside,vector<int>& upperDiagonal, vector<int>& lowerDiagonal, int col, int n) {
  if (col == n) { solution.push_back(board); return;}
  for (int i = 0; i < n; i++) {
    if (leftside[i] == 0 && lowerDiagonal[i + col] == 0 && upperDiagonal[n - 1 + col - i] == 0) {
      board[i][col] = 'Q';
      leftside[i] = 1;
      lowerDiagonal[i + col] = 1;
      upperDiagonal[n - 1 + col - i] = 1;
      checkCondition(board, solution, leftside, upperDiagonal, lowerDiagonal, col + 1 , n);
      board[i][col] = '.';
      leftside[i] = 0;
      lowerDiagonal[i + col] = 0;
      upperDiagonal[n - 1 + col - i] = 0;
    }
  }
}

vector<vector<string>> solveNQueens(int col) {
  vector <vector<string>> solution;
  vector <string> board(col);
  string s(col, '.');
  for (int i = 0; i < col; i++) {
    board[i] = s;
  }
  vector <int> leftside(col, 0), upperDiagonal(2 * col - 1, 0), lowerDiagonal(2 * col - 1, 0);
  checkCondition(board, solution, leftside, upperDiagonal, lowerDiagonal, 0 , col);
  return solution;
}

template <typename T> 
void printVector(vector<vector<T>> vector) {
    for (auto i = 0; i < vector.size(); i++) {
        cout << "Arrangement number " << i + 1 << endl;
        for (auto j = 0; j < vector[0].size(); j++) {
            cout << vector.at(i).at(j);
            cout << endl;  
        }
        cout << endl;
    }
} 

vector<pair<int,int>> getQueenCoords(vector<vector<string>> v) {
    vector<pair<int,int>> coords;
    for (auto i = 0; i < v.size(); i++) {
        for (auto j = 0; j < v[0].size(); j++) {
                string tempStr = v.at(i).at(j);
                for (auto k = 0; k < tempStr.length(); k++) {
                    pair<int,int> temp;
                    if (tempStr[k] == 'Q') {
                        temp.first = j + 1;
                        temp.second = k + 1;
                        coords.push_back(temp);          
                    }
                }
        }
    }
    return coords;
}

void printCoords(vector<pair<int,int>>& coords, int col) {
    int count = 1;
    for (int i = 0; i < coords.size();i++) {
        if (i % col == 0 || i == 0) cout << "Solution Number: " << count++ <<  endl;
        cout << coords.at(i).first << " " << coords.at(i).second << endl;
        }
}

int main() {
  int n = 8; 
  vector <vector<string>> solution = solveNQueens(n);
  vector<pair<int,int>> coords = getQueenCoords(solution);  
  printVector(solution);
  cout << endl;
  printCoords(coords,n);
  return 0;
}