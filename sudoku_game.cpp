#include "sudoku_game.h"

#include <iostream>
#include <queue> 
#include <vector>
using namespace std;


Game::Game() {
    this->grid.resize(9);
	for (int i = 0; i < 9; ++i)
		this->grid[i].resize(9);
}
void Game::change_value(int i, int j, char a)
{
    this->grid[i][j] = a;
}
void Game::full_board(int t[9][9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            this->grid[i][j] = t[i][j]+'0';
        }
    }
}
void Game::full_board(char t[9][9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            this->grid[i][j] = t[i][j];
        }
    }
}
bool Game::empty(int i, int j) { if (this->grid[i][j] != '0') return false; return true; }
bool Game::can_add(int i, int j, char a)
{
    int square_x = (j / 3) * 3;
    int square_y = (i / 3) * 3;
    for (int m = 0; m < 9; m++) {
        if (grid[m][j] == a) return false;
        if (grid[i][m] == a) return false;
        if (grid[i - i % 3 + m / 3][j - j % 3 + m % 3] == a) return false;
    }
    return true;
}
bool Game::done()
{
    for (int i=0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (grid[i][j] == '0') { return false; }
        }
    }
    return true;
}
bool Game::first_solver(int i, int j)
{
    if (i == 9) return true; 
    if (j == 9) return first_solver(i+1,0); // If line finished go next one
    if (this->grid[i][j] != '0') return first_solver(i, j + 1); // Next column

    for (char c = '1'; c <= '9'; ++c) {
        if (can_add(i, j, c)) {
            this->grid[i][j] = c;
            if (first_solver(i, j+1)) return true; 
            this->grid[i][j] = '0';
        }
    }
    return false;
}
bool Game::second_solver()
{
    //queue<char> count;
    char count ;
    for (int j = 0; j < 9; ++j) {
        for (int i = 0; i < 9; ++i) {
            if (this->grid[i][j] == '0') {
                //count = queue<char>();
                count = '0';
                for (char c = '1'; c <= '9'; ++c) {
                    //if (count.size() < 2 && can_add(i, j, c)) {
                    //    count.push(c);
                   // }
                    if (can_add(i, j, c)) {
                        count == '0'? count=c: count='n';
                    }
                }
                if (count != 'n') grid[i][j] = count;
                //if (count.size() == 1) { grid[i][j] = count.front();}
            }      
        }
    }
    return first_solver(0,0);
}

void Game::print()
{
    cout << "-   -   -   -   -   -   -   -   -" << '\n';
    for (int i = 0; i < 9; ++i)
    {
        if (i == 3 || i == 6) {
            for (int k = 0; k < 33; k++) cout << "-";
            cout << '\n';
        }
        for (int j = 0; j < 9; ++j)
        {
            cout << grid[i][j];
            (j == 2 || j == 5) ? cout << " | " : cout << "   ";
        }
        cout << '\n';
    }
}

Game& Game::operator=(const int t[9][9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            this->grid[i][j]=t[i][j]+'0';
        }
    }
    return *this;
}
Game& Game::operator=(const char t[9][9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            this->grid[i][j] = t[i][j];
        }
    }
    return *this;
}


ostream& operator<<(ostream& out, const Game &c) {
    out << "-   -   -   -   -   -   -   -   -" << '\n';
    for (int i = 0; i < 9; ++i)
    {
        if (i == 3 || i == 6) {
            for (int k = 0; k < 33; k++) out << "-";
            out << '\n';
        }
        for (int j = 0; j < 9; ++j)
        {
            out << c.grid[i][j];
            (j == 2 || j == 5) ? out << " | " : out << "   ";
        }
        out << '\n';
    }
    return out;
}

