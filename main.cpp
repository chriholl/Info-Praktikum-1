/**
 * @file main.cpp
 *
 * Provides functions for the game Reversi
 */

/**
* @mainpage Reversi
*
* Dokumentation des Spiels Reversi im Rahmen des Praktikums Informatik 1.
*
*/

/**Defines the type of a player */
#define HUMAN 1
#define COMPUTER 2

#include "test.h"
#include "config.h"
#include "Reversi_KI.h"
#include <iostream>
#include <stdlib.h>

/**
 * @brief Function providing first initialization of a new field
 *
 * This function fills an existing field with zeros and creates the starting pattern.
 *
 * @param field The field which will be initialized
 */
void initialize_field(int field[SIZE_Y][SIZE_X])
{
	for (int j = 0; j < SIZE_Y; j++)
		{
			for(int i = 0; i < SIZE_X; i++)
			{
				field[j][i] = 0;
			}
		}
		field[SIZE_Y / 2 - 1][SIZE_X / 2 - 1] = 1;
		field[SIZE_Y / 2][SIZE_X / 2 - 1] = 2;
		field[SIZE_Y / 2 - 1][SIZE_X / 2] = 2;
		field[SIZE_Y / 2][SIZE_X / 2] = 1;
}



/**
* @brief Prints the playing field to the console.
*
* This function gets the current playing field as parameter (two dimensional array)
* with entries of 0 (field is empty), 1 (field belongs to player 1), 2 (field belongs to player 2).
* <br>The function prints the playing field, grid included, to the console.
* Crosses symbolize player 1 while circles symbolize player 2.
*
*  @param field  The field which is going to be printed
*/
void show_field(const int field[SIZE_Y][SIZE_X])
{
	std::cout << "  ";

//Start at ASCII 65 = A
	for (int j = 65; j < 65 + SIZE_Y; j++)
		std::cout << ((char) j) << " " ;

	std::cout << std::endl;

	for (int j = 0; j < SIZE_Y; j++)
	{
		std::cout << j + 1;
		for (int i = 0; i < SIZE_X; i++)
		{
			switch (field[j][i])
			{
				case 0:
					std::cout << "  " ;
					break;
				case 1:
					std::cout << " X";
					break;
				case 2:
					std::cout << " O";
					break;
				default:
					std::cout << "Inconsistent data in field!" << std::endl;
					std::cout << "Aborting .... " << std::endl;
					exit(0);
					break;
			}
		};//for i
		std::cout << std::endl;
	}//for j
}

/**
* @brief Determines winner of the game.
*
* This function counts the number of fields each player holds and proves
* which player is winning. Player 1 wins if he holds more fields than Player 2
* Player 2 wins if it is the other way around. 3rd case is a tie
*
* @return Returns 1 if player 1 wins, 2 for player 2, 0 for tie
* @param field The field that is going to be analyzed
*/

int winner (const int field[SIZE_Y][SIZE_X])
{
	int count_p1 = 0;
	int count_p2 = 0;

	for (int j = 0; j < SIZE_Y; j++)
	{
		for (int i = 0; i < SIZE_X; i++)
		{
			 //loop through all fields + counting of X (1) and O (2)
			if (field[j][i]==1) //er testet welcher Spieler welches Feld besetzt
			{
				count_p1++; //zählt die besetzten Felder pro Spieler
			}
			else if (field[j][i]==2)
				count_p2++;
		}
	}
	//Jetzt wird geprüft wer gewonnen hat
	if (count_p1<count_p2)
	{
		return 2;
	}
	else if (count_p2<count_p1)
	{
		return 1;
	}
	else if (count_p1==count_p2)
	{
		return 0;
	}
}

/**
 * @brief Test if turn is valid
 *
 * This function tests wether a turn is allowed to be made or not.
 *
 * @param field Field to play on
 * @param player The player whose turn it is
 * @param pos_y Y-position of the active field
 * @param pos_x X-position of the active field
 */


bool turn_valid(const int field[SIZE_Y][SIZE_X], const int player, const int pos_x, const int pos_y)
{
	// Process all possible directions
	int opponent = 3 - player; // the same as: if player = 1 -> opponent = 2 else
							   // if player = 2 -> opponent = 1

	if (field[pos_y][pos_x] != 0) //check if field is currently empty
	{
		return false;
	}

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (field [pos_y+i][pos_x +j] == opponent) //check if you can find an opponents stone in a neighboring field
			{
				int goto_Y = i+i;
				int goto_X = j+j;
				int goneto = 0;

				while ((pos_y+goto_Y) > 0 && (pos_y+goto_Y)< 7
						&& (pos_x+goto_X) > 0 && (pos_x+goto_X)<7) //durchläuft das ganze Feld
				{
					goneto = field[pos_y+goto_Y][pos_x+goto_X];

					if (goneto == player) //letztes Feld vom Player?
					{
						return true;
					}
					else if (goneto == 0) //Lücke in der Reihe des Gegners?
					{
						break;
					}
					goto_Y += i;
					goto_X += j;
				}
			}
		}
	}
	return false;
}

/**
 * @brief Executes turns
 *
 * This function executes a turn and puts a stone on a certain position (pos_y, pos_x).
 * In Addition it turns all stones of the opponent which were between the stone and
 * the new position into player's stones.
 *
 * @param field Active field to play on
 * @param player The player whose turn it is
 * @param pos_y Y-position of the active field
 * @param pos_x X-position of the active field
 */

void execute_turn(int field[SIZE_Y][SIZE_X], const int player, const int pos_x,
		const int pos_y) {

	int opponent = 3 - player;
	field[pos_y][pos_x] = player;

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++) {
			//check if you can find an opponents stone in a neighboring field
			if (field[pos_y + i][pos_x + j] == opponent) {
				int directionY = i + i;
				int directionX = j + j;
				int nextField = 0;
				bool changeStone = false;

				while ((pos_y + directionY) > 0 && (pos_y + directionY) < 7 && (pos_x + directionX) > 0 && (pos_x + directionX) < 7) {

					nextField = field[pos_y + directionY][pos_x + directionX];

					if (nextField == player) {
						changeStone = true;
					}
					if (nextField == 0) {
						break;
					}
					directionY += i;
					directionX += j;
					}
					if (changeStone == true) {


					while ((pos_y + directionY) > 0 && (pos_y + directionY) < 7 && (pos_x + directionX) > 0 && (pos_x + directionX) < 7)
					{
						directionY = i;
						directionX = j;


						nextField = field[pos_y + directionY][pos_x + directionX];

						if (nextField == player)
						{
							break;
						}

						field[pos_y + directionY][pos_x + directionX] = player;

						directionY += i;
						directionX += j;
					}

				}

			}
		}
	}
}

/*
							}
							while ((pos_y+goto_Y) >= 0 && (pos_y+goto_Y)<8 && (pos_x+goto_X) >= 0 && (pos_x+goto_X)<8)
							{
							goto_Y = i;
							goto_X = j;

							goneto = field [pos_y + goto_Y][pos_x + goto_X];

							if (goneto == player)
							{
								break;
							}
							field [pos_y + goto_Y][pos_x + goto_X] = player;

							goto_Y += i;
							goto_X += j;
							}
						}
						if (goneto == 0)
						{
							break;
						}
						goto_Y += i;
						goto_X += j;
					}
				}
			}
		}
} */

/**
 * @brief Counts possible turns
 *
 * @param
 * @param
 */

int possible_turns(const int field[SIZE_Y][SIZE_X], const int player)
{
	int possibleturns = 0;

	for (int j = 0; j < SIZE_Y; ++j)
	{
		for (int i = 0; i < SIZE_X; ++i)
		{
			if (turn_valid (field,player,i,j) == true)
			{
			possibleturns++;
			}
		}
	}
	return possibleturns;
}

bool human_turn(int field[SIZE_Y][SIZE_X], const int player)
{
	if (possible_turns(field, player) == 0)
	{
		return false;
	}

	int px;
	int py;
	bool repeat=false;

	while (true)
	{
		std::string input;
		input.reserve(50);
		std::cout << std::endl << "Your move (e.g. A1): " ;
		input.erase(input.begin(), input.end());
		std::cin >> input;
		px = ((int) input.at(0) ) - 65;
		py = ((int) input.at(1) ) - 49;

		if (turn_valid(field, player, px, py))
		{
			//accept turn;
			break;
		}
		else
		{
			std::cout << std::endl << "Invalid input !" << std::endl;
		}
	}

	execute_turn(field, player, px, py);
	show_field(field);

	return true;
}

/**
 * @brief Executes game
 *
 * Diese Funktion führt Das Spiel aus und ruft dabei die human_turn() Funktion auf.
 * Um zwischen den Spielern zu wechseln werden 2 for-Schleifen verschachtelt, die äußere läuft bis die maximal mögliche
 * Spiellaufzeit zu Ende ist, die innere beginnt nach dem beide Spieler gesetzt haben aufs Neue. Sollte der aktuelle
 * Spieler keinen Zug machen können ist der andere wieder dran. In der 2. for-Schleife wird zuerst geprüft ob Mensch oder Computer spielt
 * bzw. am Zug ist und ruft dementsprechend die Function human_turn() oder computer_turn() auf.
 *
 * @param player_typ[2] Parameter bestimmt ob Mensch/Mensch oder Mensch/Computer spielen
 */
void game(int player_type[2])
{

	int field[SIZE_Y][SIZE_X];

	//Create starting pattern
	initialize_field(field);

	int current_player = 0;
	show_field(field);
	//int noturn = 0;

	for (int f = 0; f < 64; ++f) // Feld ist 8x8 max 64 Spielzüge möglich
		{
			for (int s =1;  s < 3; s++)
			{
				current_player = s;
				if (player_type[s-1] == COMPUTER) //Player sind 1 und 2, im array aber als 0 und 1 abgespeichert --> s-1
				{
					if (!computer_turn(field, current_player))
					{
						break;
					}
				show_field (field); // Das Feld muss nochmal angezeigt werden, damit der Zug des Computers zu sehen ist
				}
				if (player_type[s-1] == HUMAN)
				{
					if (human_turn(field, current_player)==false)
					{
						break;
					}
				//human_turn (field, current_player); falsch da die if Bedingung die Funktion automatisch aufruft
				}
			}
		}


	switch (winner(field))
	{
	case 1:
	std::cout << "Winner is Player 1" << std::endl;
	break;
	case 2:
	std::cout << "Winner is Player 2" << std:: endl;
	break;
	case 0:
	std::cout << " It's a tie!" << std::endl;
	break;
	}
}

/**
 * @brief Testet alle Funktionen und ruft das Spiel auf
 *
 * Alle Tests werden ausgeführt. Sollten alle bestanden sein, wird dies ausgegeben. Nun wurde zusätzlich
 * programmiert, dass man auswählen kann, ob Mensch/Mensch, Computer/Mensch, Computer/Computer spielen sollen.
 * Dies kann der Benutzer selber entscheiden. Die Entscheidung wird im Array player_type festgehalten und in
 * der Funktion game() aufgegriffen.
 *
 */
int main(void)
{
	if (TEST == 1)
	{
		bool result = run_full_test();
		if (result == true)
		{
			std::cout << "ALL TESTS PASSED!" << std::endl;
		}
		else
		{
			std::cout << "TEST FAILED!" << std::endl;
		}
	}


	int field[SIZE_Y][SIZE_X];

	initialize_field(field);

	show_field(field);

	 int player_type[2] = { HUMAN, HUMAN };  //Contains information wether players are HUMAN(=1) or COPMUTER(=2)

	 std::cout  << "Choose: Human (1) or Computer (2):" << std::endl;

		std::cin >> player_type[0];

	std::cout  << "Choose again for second player:" << std::endl;

		std::cin >> player_type[1];

	 game(player_type);
	return 0;
}

