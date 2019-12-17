#include <iostream>

char cell[10] =
{
	'o','1','2','3','4','5','6','7','8','9'
};
int check();

void board()
{
	system("cls");
	std::cout << "\t\t|'########:'####::'######::'########::::'###:::::'######::'########::'#######::'########:| " << std::endl;
	std::cout << "\t\t|... ##..::. ##::'##... ##:... ##..::::'## ##:::'##... ##:... ##..::'##.... ##: ##.....::| " << std::endl;
	std::cout << "\t\t|::: ##::::: ##:: ##:::..::::: ##:::::'##:. ##:: ##:::..::::: ##:::: ##:::: ##: ##:::::::| " << std::endl;
	std::cout << "\t\t|::: ##::::: ##:: ##:::::::::: ##::::'##:::. ##: ##:::::::::: ##:::: ##:::: ##: ######:::| " << std::endl;
	std::cout << "\t\t|::: ##::::: ##:: ##:::::::::: ##:::: #########: ##:::::::::: ##:::: ##:::: ##: ##...::::| " << std::endl;
	std::cout << "\t\t|::: ##::::: ##:: ##::: ##:::: ##:::: ##.... ##: ##::: ##:::: ##:::: ##:::: ##: ##:::::::| " << std::endl;
	std::cout << "\t\t|::: ##::::'####:. ######::::: ##:::: ##:::: ##:. ######::::: ##::::. #######:: ########:| " << std::endl;
	std::cout << "\t\t|:::..:::::....:::......::::::..:::::..:::::..:::......::::::..::::::.......:::........::| " << std::endl;
	std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t   by OnCe" << std::endl;
	std::cout << "\n\t\t\t\t\t\t> КРЕСТИКИ - НОЛИКИ <\n";
	std::cout << "\t\t\t\t\t>> Игрок №1 - (X)  -  Игрок №2 - (O) <<" << std::endl << std::endl;
	std::cout << std::endl;
	std::cout << "\t\t\t\t\t\t   _____ _____ _____    " << std::endl;
	std::cout << "\t\t\t\t\t\t|>|     |     |     |<|  " << std::endl;
	std::cout << "\t\t\t\t\t\t" << "|<|  " << cell[1] << "  |  " << cell[2] << "  |  " << cell[3] << "  |>|  " << std::endl;
	std::cout << "\t\t\t\t\t\t|>|_____|_____|_____|<|  " << std::endl;
	std::cout << "\t\t\t\t\t\t|<|     |     |     |>|  " << std::endl;
	std::cout << "\t\t\t\t\t\t" << "|>|  " << cell[4] << "  |  " << cell[5] << "  |  " << cell[6] << "  |<|  " << std::endl;
	std::cout << "\t\t\t\t\t\t|<|_____|_____|_____|>|  " << std::endl;
	std::cout << "\t\t\t\t\t\t|>|     |     |     |<|  " << std::endl;
	std::cout << "\t\t\t\t\t\t" << "|<|  " << cell[7] << "  |  " << cell[8] << "  |  " << cell[9] << "  |>|  " << std::endl;
	std::cout << "\t\t\t\t\t\t|>|_____|_____|_____|<|  " << std::endl << std::endl;
	system("color 0E");

}
int main()
{
	setlocale(LC_ALL, "Russian");
	int player = 1, i, pick;
	char point;
	do
	{
		board();
		player = (player % 2) ? 1 : 2;

		std::cout << "\tИгрок №" << player << " ваш ход! Укажите номер клетки:  ";
		std::cin >> pick;

		point = (player == 1) ? 'X' : 'O';

		if (pick == 1 && cell[1] == '1')
			cell[1] = point;

		else if (pick == 2 && cell[2] == '2')
			cell[2] = point;

		else if (pick == 3 && cell[3] == '3')
			cell[3] = point;

		else if (pick == 4 && cell[4] == '4')
			cell[4] = point;

		else if (pick == 5 && cell[5] == '5')
			cell[5] = point;

		else if (pick == 6 && cell[6] == '6')
			cell[6] = point;

		else if (pick == 7 && cell[7] == '7')
			cell[7] = point;

		else if (pick == 8 && cell[8] == '8')
			cell[8] = point;

		else if (pick == 9 && cell[9] == '9')
			cell[9] = point;

		else
		{
			std::cout << "Такой клетки в игре не существует! ";
			player--;
			std::cin.ignore();
			std::cin.get();
		}
		i = check();

		player++;
	} 
	while (i == -1);
	board();
	if (i == 1)
		std::cout << "\t==>\aИгрок №" << --player << " победил! ";
	else
		std::cout << "\t==>\aНичья!";
	std::cin.ignore();
	std::cin.get();
	return 0;
}
int check()
{
	if (cell[1] == cell[2] && cell[2] == cell[3])
		return 1;

	else if (cell[4] == cell[5] && cell[5] == cell[6])
		return 1;

	else if (cell[7] == cell[8] && cell[8] == cell[9])
		return 1;

	else if (cell[1] == cell[4] && cell[4] == cell[7])
		return 1;

	else if (cell[2] == cell[5] && cell[5] == cell[8])
		return 1;

	else if (cell[3] == cell[6] && cell[6] == cell[9])
		return 1;

	else if (cell[1] == cell[5] && cell[5] == cell[9])
		return 1;

	else if (cell[3] == cell[5] && cell[5] == cell[7])
		return 1;

	else if (cell[1] != '1' && cell[2] != '2' && cell[3] != '3'
		&& cell[4] != '4' && cell[5] != '5' && cell[6] != '6'
		&& cell[7] != '7' && cell[8] != '8' && cell[9] != '9')

		return 0;
	else
		return -1;
}
