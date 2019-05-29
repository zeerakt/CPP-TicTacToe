#include<iostream>
#include <vector>
#include "tic_tac_toe.h"
#include "Beginner.h"
#include "Intermediate.h"
#include "Super.h"
using namespace std;



int main()
{
	tic_tac_toe* t=nullptr;
	tic_tac_toe g;

	printf("This is a game of Tic-Tac_Toe designed by Insha ur Rehman.\n");
	printf("Enter 1 to play.\nEnter 2 for help/instructions.");
	int option;
	int level, retry;
	scanf_s("%d", &option);
	if (option == 1){
		start:
			printf("Select 1 for beginner, 2 for intermediate, 3 for hard.\n");
			scanf_s("%d", &level);
			switch (level)
			{
			case 1: t = new Beginner; break;
			case 2: t = new Intermediate; break;
			case 3: t = new Super; break;
			default:
				break;
			}
			printf("This is the sample board, which shows the arrangement of the squares.");
			t->sample_board();
			printf("Don't underestimate the computer. Let us play! Good Luck!");

			while (1)
			{
				t->init_board();

				if (t->user_first())
				{	
					t->computer = 'O';
					t->user = 'X';
				}
				else
				{
					t->computer = 'X';
					t->user = 'O';
				}
				t->play_game();
				
				printf("Do you want to play again? 1 for yes, 0 for no\n");
				scanf_s("%d", &retry);
				if (retry){
					system("cls");
					goto start;
				}
				else return 0;
			}
		}
	/*Terminating the "if"*/
	else if (option == 2){
		g.instructions();
		printf("\n\nAre you ready? Press 1 to play!\n");
		int play;
		scanf_s("%d", &play);
		if (play == 1){
			printf("Select 1 for beginner, 2 for intermediate, 3 for hard\n");
			scanf_s("%d", &level);
			switch (level)
			{
			case 1: t = new Beginner; break;
			case 2: t = new Intermediate; break;
			case 3:  t = new Super; break;
			default:
				break;
			}
			printf("This is the sample board, which shows the arrangement of the squares.");
			t->sample_board();
			printf("Don't underestimate the computer. Let us play! Good Luck!");
			while (1)
			{
				t->init_board();

				if (t->user_first())
				{
					t->computer = 'O';
					t->user = 'X';
				}
				else
				{
					t->computer = 'X';
					t->user = 'O';
				}
				t->play_game();
				printf("Do you want to play again? 1 for yes, 0 for no\n");
				scanf_s("%d", &retry);
				if (retry){
					system("cls");
					goto start;
				}
				else return 0;
			}
		}
	}
	else

		return 0;
}

