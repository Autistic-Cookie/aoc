#include <iomanip>
#include <iostream>
#include <random>
#include <ranges>
#include <vector>

using namespace std;

int main() {
  vector<long long> vll{};
  mt19937_64 rndx(23);
  for (int x = 0; x < 100; x++) {
    auto l = rndx();
    cout << l << " ";
    vll.push_back(l);
  }
  sort(vll.begin(), vll.end());
  cout << "\n";
  for (auto b : vll)
    cout << b << " ";
  cout << "\n";

  const std::string text{"    Hello World"};
  std::cout << std::quoted(text) << '\n';

  auto conv =
      std::views::transform(std::views::drop_while(text, ::isspace), ::toupper);

  std::string temp(conv.begin(), conv.end());

  auto tem = text | std::views::drop_while(isspace) |
             std::views::transform(::toupper) | std::ranges::to<std::string>();

  std::cout << std::quoted(temp) << '\n';
}