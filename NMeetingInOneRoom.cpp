#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& a , vector<int>& b) {
    for (int i = 0; i < a.size(); i++ ){
        auto min = a.at(i);
        for (int j = i + 1; j < a.size(); j++) {
            if (min > a.at(j)) {
                swap(a.at(i), a.at(j));
                swap(b.at(i), b.at(j));
                min = a.at(i);
            }
        }
    }
}

int main() {
    auto numberOfMeetings = 0, temp = 0, temp2 = 0;
    vector<int> startTime, finishTime;
    vector<pair<int, int>> meetingCombinations;
    cin >> numberOfMeetings;
    for (auto i = 0; i < numberOfMeetings; i++) {
        cin >> temp;
        startTime.push_back(temp);
    }
    for (auto i = 0; i < numberOfMeetings; i++) {
        cin >> temp2;
        finishTime.push_back(temp2);
    }

    selectionSort(finishTime, startTime);
    
    auto indexCount = 0,possibleMeetings = 0;
    meetingCombinations.push_back(make_pair(startTime.at(0), finishTime.at(0)));
    for (auto j = 1; j < numberOfMeetings; j++) {
      if (startTime.at(j) >= finishTime.at(indexCount)) {
        auto tempPair = make_pair(startTime.at(j), finishTime.at(j));
        meetingCombinations.push_back(tempPair);
        indexCount++;
      }
    }
    for (auto i : meetingCombinations) {
        cout << i.first << " " << i.second << endl;
        }

    return 0;
}

// Input
// 6
// 1 3 0 5 8 5
// 9 4 2 7 9 6


// Output
// 0 2
// 3 4
// 5 6
// 8 9
