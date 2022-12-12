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
                min = a.at(j);
            }
        }
    }
}

int main() {
    auto numberOfActivities = 0, temp = 0, temp2 = 0;
    vector<int> startTime, finishTime;
    cin >> numberOfActivities;
    for (auto i = 0; i < numberOfActivities; i++) {
        cin >> temp;
        startTime.push_back(temp);
    }
    for (auto i = 0; i < numberOfActivities; i++) {
        cin >> temp2;
        finishTime.push_back(temp2);
    }
    selectionSort(finishTime, startTime);
    auto count = 0;
    cout << count << " ";
    for (auto j = 1; j < numberOfActivities; j++)
    {
      if (startTime.at(j) >= finishTime.at(count))
      {
          cout << j << " ";
          count = j;
      }
    }
    return 0;
}