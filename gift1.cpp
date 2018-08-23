/*
ID: zsmount1
TASK: gift1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int np;
    fin >> np;

    map<string, int> persons;
    vector<string> personsInOrder;
    string person;

    for (int i = 0; i < np; i++) {
      fin >> person;
      personsInOrder.push_back(person);
      persons[person] = 0;
    }

    while (fin >> person) {
      int total, num, amount;
      fin >> total >> num;
      if (num == 0 || total == 0) {
        continue;
      }
      amount = total / num;
      persons[person] -= amount * num;
      for (int i = 0; i < num; i++) {
        fin >> person;
        persons[person] += amount;
      } 
    }

    for (int i = 0; i < personsInOrder.size(); i++) {
      fout << personsInOrder[i] << ' ' << persons[personsInOrder[i]] << endl;
    }

    return 0;
}
