/*
ID: zsmount1
TASK: ride
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getMode(const string& s) {
  long long sum = 1;
  for (int i = 0; i < s.size(); i++) {
    sum *= s[i] - 'A' + 1;
  }
  return sum % 47;
}

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a, b;
    fin >> a >> b;
    fout << (getMode(a) == getMode(b) ? "GO" : "STAY") << endl;
    return 0;
}
