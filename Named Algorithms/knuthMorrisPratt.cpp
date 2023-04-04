#include <iostream>
#include <string>

using namespace std;

int *computePrefixFunction(string pattern) {
  int size = pattern.size();
  int *pi = new int[size];
  pi[0] = 0;
  int k = 0;
  for (int i = 1; i < size; i++) {
    while (k > 0 && pattern[k] != pattern[i]) {
      k = pi[k - 1];
    }
    if (pattern[k] == pattern[i]) {
      k = k + 1;
    }
    pi[i] = k;
  }

  return pi;
}

void kmp_matcher(string text, string pattern) {
  int *pi = ComputePrefixFunction(pattern);
  int matched_pos = 0;
  for (int current = 0; current < text.length(); current++) {
    while (matched_pos > 0 && pattern[matched_pos] != text[current])
      matched_pos = pi[matched_pos - 1];

    if (pattern[matched_pos] == text[current])
      matched_pos = matched_pos + 1;

    if (matched_pos == (pattern.length())) {
      cout << "Pattern occurs with shift " << current - (pattern.length() - 1)
           << endl;
      matched_pos = pi[matched_pos - 1];
    }
  }
}

int main() {
  string text = "000010001010001";
  string pattern = "0001";
  kmp_matcher(text, pattern);
  return 0;

  kmp_matcher(text, pattern);

  return 0;
}
