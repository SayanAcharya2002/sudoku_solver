#include "sudoku.h"
//need to add the sudoku.cpp as source file while compiling
#include <bits/stdc++.h>
using namespace std;
int main()
{
  // anything provided outside 1 to n means that value is not provided and has to be calculated
  vector<vector<int>> v={
    {0,0,2,0},
    {0,1,0,0},
    {0,0,4,0},
    {0,3,0,0}
  } ;
  // vector<vector<int>> v={
  //   {0,0,0,0},
  //   {0,0,0,0},
  //   {0,0,0,0},
  //   {0,0,0,0}
  // };
  sudoku s;
  auto a=s.solve_sudoku(v);
  for(auto& x:a)
  {
    for(auto& y:x)
    {
      cout<<y<<" ";
    }
    cout<<"\n";
  }
}
