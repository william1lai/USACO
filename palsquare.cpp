/* ID: pikachu5
   PROG: palsquare
   LANG: C++
 */

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

bool isPalindrome(string s)
{
  for (int i = 0; i < s.length() / 2; i++)
  {
    if (s[i] != s[s.length() - i - 1])
      return false;
  }
  return true;
}

string convert(int n, int b)
{
  string ret = "";
  while (n > 0)
  {
    int mod = n % b;
    char c;
    if (mod > 9)
      c = (mod - 10) + 'A';
    else
      c = mod + '0';
    ret = c + ret;
    n = n / b;
  }
  return ret;
}

int main()
{
  freopen("palsquare.in", "r", stdin);
  freopen("palsquare.out", "w", stdout);

  int N;
  cin >> N;

  for (int i = 1; i <= 300; i++)
  {
    string orig = convert(i, N);
    string s = convert(i*i, N);
    if (isPalindrome(s))
    {
      cout << orig << " " << s << "\n";
    }
  }
  return 0;
}