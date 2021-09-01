#ifndef SUDOKU_H
#define SUDOKU_H
#include <cstdio>
#include <exception>
#include <cmath>
#include <vector>
#include <cstdint>

class sudoku {
    int n,sqrt_n;
    int* ans=0,*arr=0;
    int64_t *row=0,*col=0,*grid=0;
    bool has_ans=0;
    class invalid_board_exception:public std::exception{
      bool ragged_board=1;
      bool non_perfect_square=1;
      mutable char* err_msg=0;
      public:
        invalid_board_exception(bool a,bool b);
        const char* what() const noexcept;
        ~invalid_board_exception();
    };
    class no_answer:public std::exception{
      mutable char* err_msg=0;
      public:
      const char* what() const noexcept;
      ~no_answer();
    };
    void func(int val);
public:
    std::vector<std::vector<int>> solve_sudoku(std::vector<std::vector<int>>& board);
};
#endif //SUDOKU_H