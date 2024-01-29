#include <bit>
#include <fstream>
#include <iostream>
#include <string>
#include <string_view>

using namespace std;

int chckn(string_view istr) {
  cout << istr << " ";
  if (istr.starts_with("one"))
    return 1;
  if (istr.starts_with("two"))
    return 2;
  if (istr.starts_with("three"))
    return 3;
  if (istr.starts_with("four"))
    return 4;
  if (istr.starts_with("five"))
    return 5;
  if (istr.starts_with("six"))
    return 6;
  if (istr.starts_with("seven"))
    return 7;
  if (istr.starts_with("eight"))
    return 8;
  if (istr.starts_with("nine"))
    return 9;
  return 0;
}
int x=55;
//\\countl_zero(ii);
int main() {

  ifstream ifs("aoc2023-1b.txt");
  string ins{};
  int suma = 0;
  while (getline(ifs, ins)) {
    int res;
    cout << ins << "\n";
    for (int x = 0; x < ins.size(); x++) {
      char c = ins[x];
      if (c >= '0' && c <= '9') {
        res = (c - '0') * 10;
        break;
      }
      int cw = chckn(string_view(ins.begin() + x, ins.end()));
      if (cw) {
        res = cw * 10;
        break;
      }
    }
    for (int x = ins.size() - 1; x >= 0; x--) {
      char c = ins[x];
      if (c >= '0' && c <= '9') {
        res += c - '0';
        break;
      }
      int cw = chckn(string_view(ins.begin() + x, ins.end()));
      if (cw) {
        res += cw;
        break;
      }
    }
    cout << res << " * ";
    suma += res;
  }

  cout << "\n" << suma << "\n";
  return 0;
}
