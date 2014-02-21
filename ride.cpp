/* ID: pikachu5
   PROG: ride
   LANG: C++
 */

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
  freopen("ride.in", "r", stdin);
  freopen("ride.out", "w", stdout);
  string s1;
  string s2;
  getline(cin, s1);
  getline(cin, s2);

  long long sc1 = 1;
  long long sc2 = 1;

  for (int i = 0; i < s1.length(); i++)
    sc1 = sc1 * (s1[i] - 'A' + 1);
  for (int j = 0; j < s2.length(); j++)
    sc2 = sc2 * (s2[j] - 'A' + 1);

  if ((sc1 % 47) == (sc2 % 47))
    cout << "GO\n";
  else
    cout << "STAY\n";

  return 0;
}