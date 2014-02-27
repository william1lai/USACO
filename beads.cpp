/* ID: pikachu5
   PROG: beads
   LANG: C++
 */

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
  freopen("beads.in", "r", stdin);
  freopen("beads.out", "w", stdout);

  int len;
  cin >> len;
  cin.ignore(1000, '\n');
  string s;
  getline(cin, s);
  s = s + s;

  int max = 0;
  for (int i = 0; i < s.length(); i++)
  {
	  int frontw = 0;
	  int j = i;
	  while (s[j] == 'w' && j < i + len)
	  {
		j++;
		frontw++;
	  }
          if (frontw == len)
          { 
            max = len;
            break;
          }
	  int cur = 0;
	  if (s[j] == 'r')
	  {
		  while ((s[j] == 'r' || s[j] == 'w') && j < i + len)
		  {
			  j++;
			  cur++;
		  }
		  while ((s[j] == 'b' || s[j] == 'w') && j < i + len)
		  {
			  j++;
			  cur++;
		  }
	  }
	  else if (s[j] == 'b')
	  {
		  while ((s[j] == 'b' || s[j] == 'w') && j < i + len)
		  {
			  j++;
			  cur++;
		  }
		  while ((s[j] == 'r' || s[j] == 'w') && j < i + len)
		  {
			  j++;
			  cur++;
		  }
	  }
	  if (cur + frontw > max)
		  max = cur + frontw;
  }
  cout << max << "\n";
  return 0;
}