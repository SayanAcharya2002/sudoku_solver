#include "sudoku.h"

sudoku::invalid_board_exception::invalid_board_exception(bool a,bool b):ragged_board(a),non_perfect_square(b)
{

}
const char* sudoku::invalid_board_exception::what() const noexcept
{
  err_msg=new char[100];
  if(ragged_board)
  {
    sprintf(err_msg," mismatched board size. ");
  }
  else
  {
    sprintf(err_msg," the board length is not perfect square. ");
  }
  return err_msg;
}
sudoku::invalid_board_exception::~invalid_board_exception()
{
  delete[] err_msg;
}

const char* sudoku::no_answer::what() const noexcept
{
    err_msg=new char[100];
    sprintf(err_msg,"no solution found.");
    return err_msg;
}
sudoku::no_answer::~no_answer()
{
    delete[] err_msg;
}

void sudoku::func(int val)
{
  //debug(val);
    if(val==n*n)
    {
        has_ans=1;
        for(int i=0;i<n*n;++i)
        {
          //cout<<arr[i]<<" ";
          ans[i]=arr[i];
        }
        return;
    }
    // test(reached);
    int i=val/n;
    int j=val%n;
    //debug(i,j);
    //debug(arr[i*n+j]);
    if(arr[i*n+j]!=0)
    {
      //test(reached);
        func(val+1);
        return ;
    }
    //debug(val,i,j);
    for(int x=1;x<=n;++x)
    {
       //debug(x);
        if(!(row[i]&(1ll<<x)) && !(col[j]&(1ll<<x))
          && !(grid[sqrt_n*(i/sqrt_n)+j/sqrt_n]&(1ll<<x)))
        {
            //debug(val,x);
            row[i]^=(1ll<<x);
            col[j]^=(1ll<<x);
            grid[sqrt_n*(i/sqrt_n)+j/sqrt_n]^=(1ll<<x);
            arr[i*n+j]=x;
            func(val+1);
            row[i]^=(1ll<<x);
            col[j]^=(1ll<<x);
            grid[sqrt_n*(i/sqrt_n)+j/sqrt_n]^=(1ll<<x);
            arr[i*n+j]=0;
        }
    }
    // debug(val);
}
std::vector<std::vector<int>> sudoku::solve_sudoku(std::vector<std::vector<int>>& board) {
{
  int maybe_n=board.size();
  for(auto& x:board)
  {
    //debug(x.size(),maybe_n);
    if(x.size()!=maybe_n)
    {
      throw invalid_board_exception(1,0);
    }
  }
  int maybe_sqrt_n=sqrt(maybe_n);
  while((maybe_sqrt_n+1)*(maybe_sqrt_n+1)<=maybe_n)
  {
    ++maybe_sqrt_n;
  }
  // debug(maybe_sqrt_n,maybe_n);
  if((maybe_sqrt_n)*(maybe_sqrt_n)!=maybe_n)
  {
    throw invalid_board_exception(0,1);
  }
  n=maybe_n;
  sqrt_n=maybe_sqrt_n;
  // debug(n,sqrt_n);
}
ans=new int[n*n];
arr=new int[n*n];
row=new int64_t[n]{};
col=new int64_t[n]{};
grid=new int64_t[n]{};
has_ans=0;
for(int i=0;i<n;++i)
{
    for(int j=0;j<n;++j)
    {
      auto& ref=board[i][j];
        if(ref>=1 && ref<=n)
            arr[i*n+j]=ref;
        else
            arr[i*n+j]=0;
        // cout<<arr[i*n+j]<<" ";
        row[i]|=(1ll<<arr[i*n+j]);
        col[j]|=(1ll<<arr[i*n+j]);
        grid[sqrt_n*(i/sqrt_n)+j/sqrt_n]|=(1ll<<arr[i*n+j]);
    }
    // cout<<endl;
}
func(0);
// test(after func);
if(!has_ans)
{
  delete[] ans;
  delete[] arr;
  delete[] row;
  delete[] col;
  delete[] grid;
  //test(err)
  throw no_answer();
}
std::vector<std::vector<int>> solved_sudoku(n,std::vector<int>(n,-1));
for(int i=0;i<n;++i)
{
    for(int j=0;j<n;++j)
    {
      solved_sudoku[i][j]=ans[i*n+j];
    }
}
delete[] ans;
delete[] arr;
delete[] row;
delete[] col;
delete[] grid;
// test(reached);
return solved_sudoku;
}
