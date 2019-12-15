#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

class TicTacToe
{
private:
	std::vector<std::string> board;
public:
	TicTacToe();
	void printBoard();
	bool makeMove(int position, std::string player);
	int checkWin();
};

TicTacToe::TicTacToe()
{
	for (int i = 0; i < 9; i++)
	{
		board.push_back(std::to_string(i));
	}
}

void TicTacToe::printBoard()
{
	setlocale(LC_ALL, "Russian");
	std::cout << " Крестики-нолики: Игрок №1 отвечает за X, Игрок №2 отвечает за О. Удачи! " << std::endl;
	int pos = 0;
	for (int i = 0; i < 5; i++) 
	{
		if (i % 2 == 0)
		{
			for (int k = 0; k < 5; k++) 
			{
				if (k % 2 == 0)
				{
					std::cout << board[pos++]; 
				}
				else
				{
					std::cout << "|"; 
				}
			}
		}
		else
		{
			for (int k = 0; k < 5; k++) 
			{
				if (k % 2 == 0)
				{
					std::cout << "-";
				}
				else
				{
					std::cout << "+";
				}
			}
		}
		std::cout << std::endl;
	}
}

bool TicTacToe::makeMove(int position, std::string player) 
{
	if (position < board.size() && position >= 0)
	{
		if (board[position] != "X" && board[position] != "O")
		{
			board[position] = player;
			return true;
		}
		else
		{
			std::cout << "Эта ячейка уже занята!" << std::endl;
		}
	}
	else
	{
		std::cout << "Такой ячейки не существует!" << std::endl;
	}
	return false;
}

int TicTacToe::checkWin()
{
	std::string player = "";
	for (int i = 0; i <= 6; i += 3)
	{
		if (board[i] == board[i + 1] && board[i + 1] == board[i + 2])
		{
			player = board[i];
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (board[i] == board[i + 3] && board[i + 3] == board[i + 6])
		{
			player = board[i];
		}
	}
	if (board[0] == board[4] && board[4] == board[8])
	{
		player = board[0];
	}
	if (board[2] == board[4] && board[2] == board[6])
	{
		player = board[2];
	}
	if (player == "X")
	{
		return 1;
	}
	else if (player == "O")
	{
		return 2;
	}
	else 
	{
		return 0;
	}
}

int main()
{
	TicTacToe game1; 
	int gameOver = 0;
	int move = 0;
	for (int i = 0; i < 9; i++) 
	{
		game1.printBoard();
		std::cout << " Игрок №1 , ваш ход: ";
		std::cin >> move;
		while (!game1.makeMove(move, "X")) 
		{
			std::cout << " Игрок №1 , ваш ход: ";
			std::cin >> move;
		}
		i++;
		if (game1.checkWin() != 0) 
		{
			gameOver = game1.checkWin();
			i = 9;
			game1.printBoard();
		}
		else if (i < 9)
		{
			game1.printBoard();
			std::cout << " Игрок №2 , ваш ход: ";
			std::cin >> move;
			while (!game1.makeMove(move, "O")) 
			{
				std::cout << " Игрок №2 , ваш ход: ";
				std::cin >> move;
			}
			if (game1.checkWin() != 0) 
			{
				gameOver = game1.checkWin();
				i = 9;
				game1.printBoard();
			}
		}
	}
	if (gameOver == 0)
		std::cout << "Ничья!" << std::endl;
	else
		std::cout << "Игрок №" << gameOver << " победил!" << std::endl;
}
