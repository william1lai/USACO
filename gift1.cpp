/* ID: pikachu5
   PROG: gift1
   LANG: C++
 */

#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
  freopen("gift1.in", "r", stdin);
  freopen("gift1.out", "w", stdout);

  int NP;
  cin >> NP;
  cin.ignore(1000, '\n');
  vector<string> names;
  vector<int> money;

  for (int i = 0; i < NP; i++)
  {
    string s;
    getline(cin, s);
    names.push_back(s);
    money.push_back(0);
  }

  for (int i = 0; i < NP; i++)
  {
    string s;
    getline(cin, s);
    int share_amount;
    int npeople;
    cin >> share_amount >> npeople;
    cin.ignore(1000, '\n');

	if (npeople == 0 || share_amount == 0)
		continue;
    
    for (int j = 0; j < NP; j++)
    {
      if (names[j] == s)
      {
        money[j] = money[j] - share_amount + (share_amount % npeople);
        break;
      }
    }
    
    for (int j = 0; j < npeople; j++)
    {
      string ss;
      getline(cin, ss);
      for (int k = 0; k < NP; k++)
      {
        if (names[k] == ss)
        {
          money[k] = money[k] + (share_amount / npeople);
          break;
        }
      }
    }
  }

  for (int i = 0; i < NP; i++)
    cout << names[i] << " " << money[i] << "\n";

  return 0;
}