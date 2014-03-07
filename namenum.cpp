/* ID: pikachu5
   PROG: namenum
   LANG: C++
 */

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

char letToNum(char c)
{
  if (c >= 'A' && c <= 'C')
    return '2';
  else if (c <= 'F')
    return '3';
  else if (c <= 'I')
    return '4';
  else if (c <= 'L')
    return '5';
  else if (c <= 'O')
    return '6';
  else if (c <= 'S')
    return '7';
  else if (c <= 'V')
    return '8';
  else if (c <= 'Y')
    return '9';
  else
    return ' ';
}

int main()
{
  freopen("namenum.in", "r", stdin);

  string N;
  getline(cin, N);

  freopen("dict.txt", "r", stdin);
  freopen("namenum.out", "w", stdout);

  string s;
  int count = 0;

  while (getline(cin, s))
  {
    if (s.length() != N.length())
      continue;
    bool add = true;
    for (int i = 0; i < N.length(); i++)
    {
      if (letToNum(s[i]) != N[i])
      {
        add = false;
        break;
      }
    }
    if (add)
    {
      count++;
      cout << s << "\n";
    }
  }
  if (count == 0)
    cout << "NONE\n"; 
  return 0;
}