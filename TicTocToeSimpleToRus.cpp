#include <iostream>

char square[10] = { 'o','1','2','3','4','5','6','7','8','9' };

int checkwin();

void board()
{
    system("cls");
    std::cout << "\n\n\t\t>>>> КРЕСТИКИ-НОЛИКИ <<<<\n\n";

    std::cout << "\t>> Игрок №1 - (X)  -  Игрок №2 - (O) <<" << std::endl << std::endl;
    std::cout << std::endl;

    std::cout << "\t\t   _____ _____ _____    " << std::endl;
    std::cout << "\t\t >|     |     |     |<  " << std::endl;
    std::cout << "\t\t " << "<|  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << "  |>  " << std::endl;

    std::cout << "\t\t >|_____|_____|_____|<  " << std::endl;
    std::cout << "\t\t <|     |     |     |>  " << std::endl;

    std::cout << "\t\t " << ">|  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << "  |<  " << std::endl;

    std::cout << "\t\t <|_____|_____|_____|>  " << std::endl;
    std::cout << "\t\t >|     |     |     |<  " << std::endl;

    std::cout << "\t\t " << "<|  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << "  |>  " << std::endl;

    std::cout << "\t\t >|_____|_____|_____|<  " << std::endl << std::endl;
    system("color F0");
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int player = 1, i, choice;

    char mark;
    do
    {
        board();
        player = (player % 2) ? 1 : 2;

        std::cout << "\tИгрок №" << player << ", ваш ход, укажите номер клетки:  ";
        std::cin >> choice;

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')

            square[1] = mark;
        else if (choice == 2 && square[2] == '2')

            square[2] = mark;
        else if (choice == 3 && square[3] == '3')

            square[3] = mark;
        else if (choice == 4 && square[4] == '4')

            square[4] = mark;
        else if (choice == 5 && square[5] == '5')

            square[5] = mark;
        else if (choice == 6 && square[6] == '6')

            square[6] = mark;
        else if (choice == 7 && square[7] == '7')

            square[7] = mark;
        else if (choice == 8 && square[8] == '8')

            square[8] = mark;
        else if (choice == 9 && square[9] == '9')

            square[9] = mark;
        else
        {
            std::cout << "Такой клетки в игре не существует! ";

            player--;
            std::cin.ignore();
            std::cin.get();
        }
        i = checkwin();

        player++;
    } 
    while (i == -1);
    board();
    if (i == 1)

        std::cout << "==>\aИгрок №" << --player << " победил! ";
    else
        std::cout << "==>\aНичья!";

    std::cin.ignore();
    std::cin.get();
    return 0;
}

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
   
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])

        return 1;
    else if (square[7] == square[8] && square[8] == square[9])

        return 1;
    else if (square[1] == square[4] && square[4] == square[7])

        return 1;
    else if (square[2] == square[5] && square[5] == square[8])

        return 1;
    else if (square[3] == square[6] && square[6] == square[9])

        return 1;
    else if (square[1] == square[5] && square[5] == square[9])

        return 1;
    else if (square[3] == square[5] && square[5] == square[7])

        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
        && square[4] != '4' && square[5] != '5' && square[6] != '6'
        && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return -1;
}
