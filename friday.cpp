/* ID: pikachu5
   PROG: friday
   LANG: C++
 */

#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

int month_offsets[12] = { 3, 0, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3 };

using namespace std;

int main()
{
  freopen("friday.in", "r", stdin);
  freopen("friday.out", "w", stdout);

  int N;
  cin >> N;

  int count[7];
  for (int i = 0; i < 7; i++)
    count[i] = 0;
  int day = 6; //saturday; sunday is 0
  int month = 0; //january
  int year = 1900;
  for (int i = 0; i < N*12; i++)
  {
    count[day]++;
	if (month == 1 && (year % 4 == 0) && 
        !(year % 100 == 0 && year % 400 != 0))
      day = (day + 1) % 7;
    day = (day + month_offsets[month]) % 7;
    month = (month + 1) % 12;
  
    if (month == 0)
      year = year + 1;
  }

  cout << count[6] << " " << count[0] << " " << count[1] << " " << count[2]
       << " " << count[3] << " " << count[4] << " " << count[5] << "\n";
  return 0;
}