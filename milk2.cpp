/* ID: pikachu5
   PROG: milk2
   LANG: C++
 */

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
  freopen("milk2.in", "r", stdin);
  freopen("milk2.out", "w", stdout);

  int ncows;
  cin >> ncows;
  int arr[1000000];
  for (int i = 0; i < 1000000; i++)
    arr[i] = 0;

  int min = 1000000;
  int max = 0;
  for (int i = 0; i < ncows; i++)
  {
    int a;
    int b;
    cin >> a >> b;
    arr[a]++;
    arr[b]--;

    if (b > max)
      max = b;
    if (a < min)
      min = a;
  }

  int idlelong = 0;
  int worklong = 0;
  int start = min;
  int count = arr[min];

  for (int i = min + 1; i <= max; i++)
  {
    int temp = count;
    count = count + arr[i];
    if (temp > 0 && count == 0)
    {
      if (i - start > worklong)
      {
        worklong = i - start;
      }
      start = i;
    }
    else if (temp == 0 && count > 0)
    {
      if (i - start > idlelong)
      {
        idlelong = i - start;
      }
      start = i;
    }
  }
  cout << worklong << " " << idlelong << "\n";
  return 0;
}