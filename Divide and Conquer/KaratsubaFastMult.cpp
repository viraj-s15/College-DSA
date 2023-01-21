#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>

#define max(a,b) ((a) > (b) ? (a) : (b))

using namespace std;



string remZeroFromFront(string x){
    for(int i = 0; i < x.size(); i++){
        if(x[i] != '0')
            return x.substr(i, x.size() - i);
    }
    return "0";
}

string addStrings(string x, string y){
    if(x.size() > y.size()) swap(x, y);
    
    int n = x.size();
    int diff = y.size() - x.size();
    string ans;
    int carry = 0;
    for(int i = n-1; i > -1; i--){
        int dSum = (x[i] - '0') + (y[i + diff] - '0') + carry;
        carry = dSum / 10;
        ans.push_back(dSum % 10 + '0');
    }
    for(int i = diff - 1; i > -1; i--){
        int dSum = (y[i] - '0') + carry;
        carry = dSum / 10;
        ans.push_back(dSum % 10 + '0');
    }
    if(carry){
        ans.push_back(carry + '0');
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string substractStrings(string y, string x){
    if(x.size() > y.size()) swap(x, y);
    
    int n = x.size();
    int diff = y.size() - x.size();
    string ans;
    int carry = 0;
    for(int i = n-1; i > -1; i--){
        int diffD = (y[i + diff] - '0') - (x[i] - '0') - carry;
        carry = (diffD < 0);
        diffD += 10 * carry;
        ans.push_back(diffD + '0');
    }
    for(int i = diff - 1; i > -1; i--){
        int diffD = (y[i] - '0') - carry;
        carry = (diffD < 0);
        diffD += 10 * carry;
        ans.push_back(diffD + '0');
    }
    assert(carry == 0);
    reverse(ans.begin(), ans.end());
    return ans;
}


string karatsuba(string x, string y) {
    int length = max(x.size(), y.size());
    while (x.size() < length)
    x.insert(0,"0");
    while (y.size() < length)
    y.insert(0,"0");
    
    if (length == 1)
    return to_string((x[0]-'0')*(y[0]-'0'));
    cout << "X:" << remZeroFromFront(x) << ", Y:" << remZeroFromFront(y) << endl;
    string x1 = x.substr(0,length/2);
    string x2 = x.substr(length/2,length-length/2);
    string y1 = y.substr(0,length/2);
    string y2 = y.substr(length/2,length-length/2);
    cout << "x1=" << remZeroFromFront(x1) << " x2=" << remZeroFromFront(x2) << " y1=" << remZeroFromFront(y1) << " y2=" << remZeroFromFront(y2) << endl;
    cout << endl;
    string a = karatsuba(x1,y1);
    string c = karatsuba(x2,y2);
    string temp = karatsuba(addStrings(x1,x2),addStrings(y1,y2));
    string b = substractStrings(temp,addStrings(a,c));
    cout << "a=" << remZeroFromFront(a) << " b=" << remZeroFromFront(b) << " c=" << remZeroFromFront(c) << endl;
    for (int i = 0; i < 2*(length-length/2); i++) a.append("0");
    for (int i = 0; i < length-length/2; i++) b.append("0");
    string result = addStrings(addStrings(a,c),b);
    cout << "xy: " << remZeroFromFront(result) << endl;    
    cout << endl;
    return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}

int main() {
    string X, Y;
    cin >> X >> Y;
    string output = karatsuba(X,Y);
    cout << X << " * " << Y << " = " << output;
    return 0;
}