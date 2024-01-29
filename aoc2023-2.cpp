#include <charconv>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

using namespace std;
#define xRED 12
#define xGREEN 13
#define xBLUE 14

void parse_string(string &ins, vector<string> &outstrs, char delim) {
  stringstream ss(ins);
  string ls{};
  while (getline(ss, ls, delim))
    outstrs.push_back(ls);
}

void trim_whitespace(string_view &isvw) {
  while (isvw.size() > 0 && isvw[0] == ' ')
    isvw.remove_prefix(1);
  while (isvw.size() > 0 && isvw[isvw.size() - 1] == ' ')
    isvw.remove_suffix(1);
}

void parse_string_invw(string_view ins, vector<string_view> &outstrs,
                       char delim) {
  int b = 0;
  string_view lsv{};
  for (int x = 0; x < ins.size(); x++) {
    if (ins[x] == delim) {
      lsv = string_view(ins.begin() + b, ins.begin() + x);
      trim_whitespace(lsv);
      outstrs.push_back(lsv);
      b = x + 1;
    }
  }
  if (b < ins.size()) {
    lsv = string_view(ins.begin() + b, ins.end());
    trim_whitespace(lsv);
    outstrs.push_back(lsv);
  }
}

int main() {
  ifstream ifs("aoc2023-2b.txt");
  string fl{};
  vector<string_view> vsvw{}, lsvw{}, words{};
  int sum_idx = 0, sum_pow = 0;
  while (getline(ifs, fl)) {
    stringstream fs(fl);
    string fst, sst;
    getline(fs, sst, ':');
    cout << sst << " ---\n ";
    getline(fs, fst, ':');
    cout << fst << " ->\n ";

    parse_string_invw(string_view(fst.begin(), fst.end()), vsvw, ';');
    bool is_possible = true;
    int red = 1, green = 1, blue = 1;
    for (auto b : vsvw) {
      parse_string_invw(b, lsvw, ',');
      cout << b << "> <";
      for (auto d : lsvw) {
        parse_string_invw(d, words, ' ');
        int li;
        from_chars(words[0].data(), words[0].data() + words[0].size(), li);
        cout << d << " " << words.size() << "] [";
        /*if (words[1] == "red" && li > xRED) {
          is_possible = false;
          cout << "*red* " << li << " ";
          words.clear();
          break;
        }

        if (words[1] == "green" && li > xGREEN) {
          cout << "*green* " << li << " ";
          is_possible = false;
          words.clear();
          break;
        }

        if (words[1] == "blue" && li > xBLUE) {
          cout << "*blue* " << li << " ";
          is_possible = false;
          words.clear();
          break;
        }*/
        if (words[1] == "red")
          red = max(li, red);
        if (words[1] == "green")
          green = max(li, green);
        if (words[1] == "blue")
          blue = max(li, blue);
        words.clear();
      }
      lsvw.clear();
      // if (is_possible == false)
      // break;
    }
    int a = red * green * blue;
    cout << "\n===" << a << "===\n";
    sum_pow += a;
    if (is_possible) {
      parse_string_invw(string_view(sst.begin(), sst.end()), words, ' ');
      int li;
      from_chars(words[1].data(), words[1].data() + words[1].size(), li);
      sum_idx += li;
      cout << "\n" << li << "\n";
      words.clear();
    } else
      cout << " np ";
    vsvw.clear();
  }
  cout << "\n" << sum_idx << "\n";
  cout << "\n" << sum_pow << "\n";
  return 0;
}