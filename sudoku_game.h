#pragma once
#include <iostream>
#include <vector>
#include <queue> 
using namespace std;

class Game
{
private:
	vector<vector<char>> grid;

public:
	Game();

	void print();
	void change_value(int i, int j, char a);
	bool empty(int i, int j);
	bool can_add(int i, int j, char a);
	bool done();

	bool first_solver(int i=0, int j=0);
	bool second_solver();

	void full_board(int t[9][9]);
	void full_board(char t[9][9]);

	Game& operator=(const int t[9][9]);
	Game& operator=(const char t[9][9]);

	friend ostream& operator<<(ostream& out, const Game& c);
};

