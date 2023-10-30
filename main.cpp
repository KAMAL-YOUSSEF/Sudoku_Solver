#include <iostream>
#include <vector>
#include <queue> 
#include <chrono>
using namespace std;

#include "sudoku_game.h"


int main()
{

    cout << "Sudoku to solve \n";
    Game s = Game();
    int hard[9][9] = { { 0, 4, 0, 0, 0, 5, 8, 7, 0 },
                       { 0, 0, 0, 0, 0, 0, 1, 0, 0 },
                       { 0, 9, 0, 0, 0, 0, 0, 0, 2 },
                       { 0, 0, 0, 0, 7, 0, 4, 0, 0 },
                       { 0, 5, 1, 3, 0, 0, 0, 0, 7 },
                       { 0, 0, 3, 0, 0, 6, 0, 0, 0 },
                       { 0, 0, 5, 0, 0, 2, 0, 9, 0 },
                       { 0, 0, 0, 5, 0, 8, 6, 0, 0 },
                       { 0, 0, 0, 0, 6, 4, 0, 0, 0 } };
    int easy[9][9] = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
                       {5, 2, 0, 0, 0, 0, 0, 0, 0},
                       {0, 8, 7, 0, 0, 0, 0, 3, 1},
                       {0, 0, 3, 0, 1, 0, 0, 8, 0},
                       {9, 0, 0, 8, 6, 3, 0, 0, 5},
                       {0, 5, 0, 0, 9, 0, 6, 0, 0},
                       {1, 3, 0, 0, 0, 0, 2, 5, 0},
                       {0, 0, 0, 0, 0, 0, 0, 7, 4},
                       {0, 0, 5, 2, 0, 6, 3, 0, 0} };

    s = easy;
    cout << s;
    chrono::steady_clock::time_point b = chrono::steady_clock::now();
    s.second_solver();
    chrono::steady_clock::time_point e = chrono::steady_clock::now();
    cout << "Solved \n";
    cout << s;
    cout << "Congratulations you solved it in : " << chrono::duration_cast<chrono::microseconds>(e - b).count() << " [us] \n \n";

    return 0;
}


