#include <algorithm>
#include <charconv>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

int main() {
  ifstream ifs("aoc2023-3b.txt");
  vector<string> vvs{};
  vector<int> asterisks;
  string s;
  map<int, vector<int>> mvi;
  getline(ifs, s);
  vvs.push_back(string(s.size() + 2, '.'));
  vvs.push_back(string("." + s + "."));
  while (getline(ifs, s)) {
    vvs.push_back(string("." + s + "."));
  }
  vvs.push_back(string(s.size() + 2, '.'));
  for (auto b : vvs)
    cout << b << "\n";

  bool addt = false;
  bool hasasterisk = false;
  int suma = 0;
  for (int o = 1; o < vvs.size() - 1; o++) {
    int n = 0;
    for (int i = 1; i < vvs[0].size() - 1; i++) {
      auto c = vvs[o][i];
      if (c >= '0' && c <= '9') {
        n = n * 10 + c - '0';
        for (int o1 = o - 1; o1 <= o + 1; o1++) {
          for (int i1 = i - 1; i1 <= i + 1; i1++) {
            auto ic = vvs[o1][i1];
            if ((ic >= '0' && ic <= '9') || ic == '.') {
            } else {
              addt = true;
              if (ic == '*') {
                // hasasterisk = true;
                asterisks.push_back(o1 * 200 + i1);
              }
            }
          }
        }
        cout << n << " , ";
      } else if (addt == true) {
        if (asterisks.size()) {
          auto ip = unique(asterisks.begin(), asterisks.end());
          asterisks.resize(distance(asterisks.begin(), ip));
          cout << "::" << asterisks[0] << ":: ";
          for (auto b : asterisks)
            mvi[b].push_back(n);
          asterisks.clear();
        } else
          suma += n;

        // cout << "++++added  " << n << " all " << suma << "} ";
        n = 0;
        addt = false;
      } else
        n = 0;
    }
    if (addt == true) {
      if (asterisks.size()) {
        auto ip = unique(asterisks.begin(), asterisks.end());
        asterisks.resize(distance(asterisks.begin(), ip));
        for (auto b : asterisks)
          mvi[b].push_back(n);
        asterisks.clear();
      } else
        suma += n;
    }
  }
  cout << "\n" << suma << "\n";
  suma = 0;
  for (auto b : mvi) {
    if (b.second.size() == 2) {
      suma += b.second[0] * b.second[1];
      cout << "\n" << b.second[0] * b.second[1] << "\n";
    }
    cout << "_" << b.first << " " << b.second.size() << "_";
  }
  cout << "\n" << suma << "\n";
}