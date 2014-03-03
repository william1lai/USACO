/* ID: pikachu5
   PROG: transform
   LANG: C++
 */

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

bool noChange(string* picture, string* image, int N)
{
  for (int i = 0; i < N; i++)
  {
    if (picture[i] != image[i])
      return false;
  }
  return true;
}

bool rot90(string* picture, string* image, int N)
{
  for (int i = 0; i < N; i++)
  for (int j = 0; j < N; j++)
  {
    if (picture[i][j] != image[N-j-1][i])
      return false;
  }
  return true;
}

bool rot180(string* picture, string* image, int N)
{
  for (int i = 0; i < N; i++)
  for (int j = 0; j < N; j++)
  {
    if (picture[i][j] != image[N-i-1][N-j-1])
      return false;
  }
  return true;
}

bool rot270(string* picture, string* image, int N)
{
  for (int i = 0; i < N; i++)
  for (int j = 0; j < N; j++)
  {
    if (picture[i][j] != image[j][N-i-1])
      return false;
  }
  return true;
}

bool reflect(string* picture, string* image, int N)
{
  for (int i = 0; i < N; i++)
  for (int j = 0; j < N; j++)
  {
    if (picture[i][j] != image[i][N-j-1])
      return false;
  }
  return true;
}

bool combo(string* picture, string* image, int N)
{
  string* refl = new string[N];
  for (int i = 0; i < N; i++)
  {
    refl[i] = picture[i];
    for (int j = 0; j < N; j++)
      refl[i][j] = picture[i][N-j-1];
  }

  bool ans = rot90(refl, image, N) || rot180(refl, image, N) ||
      rot270(refl, image, N);
  return ans;
}


int main()
{
  freopen("transform.in", "r", stdin);
  freopen("transform.out", "w", stdout);

  int N;
  cin >> N;
  cin.ignore(1000, '\n');

  string* picture = new string[N];
  for (int i = 0; i < N; i++)
    getline(cin, picture[i]);

  string* image = new string[N];
  for (int i = 0; i < N; i++)
    getline(cin, image[i]);

  if (rot90(picture, image, N))
    cout << "1\n";
  else if (rot180(picture, image, N))
    cout << "2\n";
  else if (rot270(picture, image, N))
    cout << "3\n";
  else if (reflect(picture, image, N))
    cout << "4\n";
  else if (combo(picture, image, N))
    cout << "5\n";
  else if (noChange(picture, image, N))
    cout << "6\n";
  else
    cout << "7\n";
  return 0;
}