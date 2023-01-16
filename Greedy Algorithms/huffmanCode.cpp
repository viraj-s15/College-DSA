#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <iterator>
#include <sstream>

using namespace std;

class HeapNode {
    public:

    char ch;
    int frequency;
    HeapNode* leftChild;
    HeapNode* rightChild;

    HeapNode() {
        leftChild = rightChild = nullptr;
    }
    
    HeapNode(char ch, int frequency) : ch(ch), frequency(frequency) {
        leftChild = rightChild = nullptr;
    }
};

template <typename T>
void printVector(vector<T> v) {
    for (auto &i: v) {
        cout << i << endl;
    }
}

struct compare {
    bool operator()(HeapNode *leftChild, HeapNode * rightChild) {
        return leftChild->frequency > rightChild->frequency;
    }
};

void displayOutput(HeapNode *node,string s) {
    if (!node) return;
    if (node->ch != '@') cout << node->ch << " " << s << endl;
    displayOutput(node->leftChild, s + "0");
    displayOutput(node->rightChild, s + "1");
}

void decode(vector<char>& chArray, vector<int>& freqArray) {
    priority_queue<HeapNode *, vector<HeapNode *>, compare > minHeap;
    HeapNode *left,*right,*top;
    for (size_t i = 0; i < freqArray.size();i++) {
        minHeap.push(new HeapNode(chArray.at(i),freqArray.at(i)));
    }
    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        auto sumOfFreq = left->frequency + right->frequency;
        auto temp = new HeapNode('@',sumOfFreq); 
        temp->leftChild = left;    
        temp->rightChild = right;
        minHeap.push(temp);
    }
    displayOutput(minHeap.top(),"");
}



int main() {
    string str,str2;
    cin >> str;
    getline(cin >> ws,str2);
    stringstream lineStream(str2);
    vector<char> ch;
    vector<int> v(istream_iterator<int>(lineStream),{});
    auto vectorInput = 0;
    for (size_t i = 0; i < str.size(); i++) {
        ch.push_back(str[i]);
    }

    // printVector<char>(ch);
    // cout << endl;
    // printVector<int>(v);

    decode(ch,v);

    return 0;
}


