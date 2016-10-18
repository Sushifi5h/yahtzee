/*******************************************************************************************
* Student: Vikram Singh StudentID: 11491025                                                *
* Class: CptS 121, Fall  2015; Lab Section 5                                               *
* Programming Assignment 5: Yahtzeee Game   					                           *
* Date: October 09, 2015                                                                   *
* Description: Thie program will try to put two people against each other and play the game*
*yahtzee.																				   *
*																						   *
*Relevant functions:																	   *
*		Generating random numbers for dice roll											   *
*																						   *
*Other Requirements: 2 players              											   *
*	                																	   *	
*******************************************************************************************/

//Include local libaries
#include "yahtzee_functions.h"

/*************************************************************
 * Function: void yahtzee_runner (void) 		             *
 * Date Created: 10/09/15                                    *
 * Date Last Modified: 10/09/15                              *
 * Description: runs games contains all logic 			     *
 * Input parameters: None                                    *
 * Returns: Nothing                                          *
 * Preconditions: calling it.                                *
 * Postconditions: starts game logic                         *
 *************************************************************/
void yahtzee_runner (void)
{
	//variables
	int option_selected = 0, number_of_rounds = 0, player_choice = 0, generic_counter = 0;
	int test_counter = 0;

	//player1
	int player1_score = 0, player1_number_of_rolls = 0; 
	int player1_main_dice_array[size_of_arrays] = {0}; //this will hold all of dice rolls
	int player1_combinations_used[size_of_arrays] = {0}; //this holds all combinations used
	int player1_score_array[size_of_arrays] = {0}; //this holds all score earned
	int player1_sort_array[size_of_arrays] = {0}; //this holds all score earned
	int player1_sum_of_final_score = 0; //final score for player

	//player2
	int player2_score = 0, player2_number_of_rolls = 0;
	int player2_main_dice_array[size_of_arrays] = {0}; //this will hold all of dice rolls
	int player2_combinations_used[size_of_arrays] = {0}; //this holds all combinations used
	int player2_score_array[size_of_arrays] = {0}; //this holds all score earned
	int player2_sort_array[size_of_arrays] = {0}; //this holds all score earned
	int player2_sum_of_final_score = 0; //final score for player
	
	srand ((unsigned int) time (NULL)); //seeds rand so we get different values



	//call game options and get a selection from the player
	option_selected = yahtzee_game_options_selector ();

	//check for game course
	switch (option_selected)
	{

		//print rules case 1
		case 1:
			yahtzee_game_rules (); //prints game rules
			yahtzee_runner (); //reruns game
			break;//breaks out of case 1
			
		//Main game
		case 2:

		//set number of rounds
		number_of_rounds = 1;

		for (number_of_rounds; number_of_rounds < 14; number_of_rounds++)
			{
				//PLAYER 1 IS PLAYING


				//print round
				printf("THIS IS ROUND: %d.\nPlayer: 1 is playing.\n", number_of_rounds);

				//roll dice player 1
				turn_roll_dice ( player1_main_dice_array, &player1_number_of_rolls);

				//set generic counter
				generic_counter = 1;

				//clear screen
				system ("cls");

				//ask player1 if they want to reroll 
				do
				{
					//print number of rolls
					printf ("Roll number: %d.\n", player1_number_of_rolls);

					//print dice values
					print_array_dice (player1_main_dice_array);

					//ask to reroll
					printf ("Would you like reroll(enter: Y/y for yes or N/n for no): ");
					scanf (" %c", &player_choice);

					if ( (player_choice == 'N') || (player_choice == 'n') )
					{
						//will help exit if needed
						generic_counter = 0;
						player_choice = 0;
					}

					if ( (player_choice == 'Y') || (player_choice == 'y') )
					{
						//update player rolls
						player1_number_of_rolls++;

						//reroll dice
						reroll_dice (player1_main_dice_array);	
					}

					//clear screen
					system ("cls");

				} while ( (generic_counter) && (player1_number_of_rolls <= 2) );

				//manage sorted array
				sort_dice_roll_array (player1_main_dice_array, player1_sort_array);

				//combinations
				check_combination_manage_score ( player1_main_dice_array, player1_combinations_used,
													player1_score_array, player1_sort_array, number_of_rounds);

				//clears screen
				system ("cls");

				//PLAYER 2 IS PLAYING


				//print round
				printf("THIS IS ROUND: %d.\nPlayer: 2 is playing.\n", number_of_rounds);

				//roll dice player 2
				turn_roll_dice ( player2_main_dice_array, &player2_number_of_rolls);

				//set generic counter
				generic_counter = 1;

				//clear screen
				system ("cls");

				//ask player2 if they want to reroll 
				do
				{
					//print number of rolls
					printf ("Roll number: %d.\n", player2_number_of_rolls);

					//print dice values
					print_array_dice (player2_main_dice_array);

					//ask to reroll
					printf ("Would you like reroll(enter: Y/y for yes or N/n for no): ");
					scanf (" %c", &player_choice);

					if ( (player_choice == 'N') || (player_choice == 'n') )
					{
						//will help exit if needed
						generic_counter = 0;
						player_choice = 0;
					}

					if ( (player_choice == 'Y') || (player_choice == 'y') )
					{
						//update player rolls
						player2_number_of_rolls++;

						//reroll dice
						reroll_dice (player2_main_dice_array);	
					}

					//clear screen
					system ("cls");

				} while ( (generic_counter) && (player2_number_of_rolls <= 2) );

				//manage sorted array
				sort_dice_roll_array (player2_main_dice_array, player2_sort_array);

				//combinations
				check_combination_manage_score ( player2_main_dice_array, player2_combinations_used,
													player2_score_array, player2_sort_array, number_of_rounds);

				//clears screen
				system ("cls");



				//reset player rolls
				player1_number_of_rolls = 0;
				player2_number_of_rolls = 0;


		}

		//sum the score
		player1_sum_of_final_score = sum_final_score (player1_score_array);
		player2_sum_of_final_score = sum_final_score (player2_score_array);

		//add score and check for 64 for both palyers
		if (player1_sum_of_final_score >= 63)
		{
			player1_sum_of_final_score = player1_sum_of_final_score + 35;
		}

		if (player2_sum_of_final_score >= 63)
		{
			player2_sum_of_final_score = player2_sum_of_final_score + 35;
		}

		//print score
		printf("Final Score.\nPlayer1: %d\nPlayer2: %d\n", player1_sum_of_final_score, 
				player2_sum_of_final_score);

		//print winner
		if (player1_sum_of_final_score == player2_sum_of_final_score)
		{
			printf("BOTH PLAYERS WON!\n");
		}

		if (player1_sum_of_final_score > player2_sum_of_final_score)
		{
			printf("Player 1 won. Don't worry about it Player 2 this is a worthless game.\n");
		}

		if (player1_sum_of_final_score < player2_sum_of_final_score)
		{
			printf("Player 2 won. Don't worry about it Player 1 this is a worthless game.\n");
		}

		//Restart the game after a pause
		printf("Restarting the game after this sort pause.\n");

		//pause game
		system ("pause");

		//clear screen
		system ("cls");

		//start game again
		yahtzee_runner ();


		break; //leave main game after the game finishes

		//exit game
		case 3:
			printf ("You selected Exit. Goodbye.\n"); //print exit message
			system ("pause"); //pause everything
			exit (0); //exit
	}
	
}

/*************************************************************
 * Function: void yahtzee_game_options (void) 		         *
 * Date Created: 10/09/15                                    *
 * Date Last Modified: 10/09/15                              *
 * Description: prints starting game options to screen       *
 * Input parameters: None                                    *
 * Returns: Nothing                                          *
 * Preconditions: calling it.                                *
 * Postconditions: none                                      *
 *************************************************************/
int yahtzee_game_options (void)
{	
	//print message
	printf (
	"We are about to embrack on a game of YAHTZEE!\n"
	"Choose your path traveleer!\n"
		"\t1. Print game rules\n"
		"\t2. Start a game of Yahtzee\n"
		"\t3. Exit\n");
	return 1;
}

/*************************************************************
 * Function: int yahtzee_game_options_selector (void) 		 *
 * Date Created: 10/09/15                                    *
 * Date Last Modified: 10/09/15                              *
 * Description: prints gets input from user & clears screen  *
 * Input parameters: None                                    *
 * Returns: game options                                     *
 * Preconditions: calling it.                                *
 * Postconditions: game directions might change              *
 *************************************************************/
int yahtzee_game_options_selector (void)
 {
 	//local variable
 	int selected_option = 0;

 	//loop to until the option is selected
 	do
 	{
 		yahtzee_game_options (); //print game

 		//ask for input
 		printf ("Please select an option(Example: 1, 2, 3): ");
 		scanf (" %d", &selected_option);

 		system ("cls"); //clear screen

 	} while ( (selected_option <= 0) || (selected_option >= 4) );

 	system ("cls");//clear screen

 	return selected_option;
 }

/*************************************************************
 * Function: void yahtzee_game_rules (void) 				 *
 * Date Created: 10/09/15                                    *
 * Date Last Modified: 10/09/15                              *
 * Description: prints yahtzee game rules                    *
 * Input parameters: None                                    *
 * Returns: game options                                     *
 * Preconditions: calling it.                                *
 * Postconditions: none                                      *
 *************************************************************/
void yahtzee_game_rules (void)
 {
 	//taken from http://eecs.wsu.edu/~aofallon/cpts121/progassignments/PA5.htm
 	printf("The Rules of Yahtzee:\n\n"
 		"The scorecard used for Yahtzee is composed of two sections. A upper section and a lower section. A total of thirteen boxes or"
 		"thirteen scoring combinations are divided amongst the sections. The upper section consists of boxes that are scored by"
 		"summing the value of the dice matching the faces of the box. If a player rolls four 3's, then the score placed in the 3's box is"
 		"the sum of the dice which is 12. Once a player has chosen to score a box, it may not be changed and the combination is no"
 		"longer in play for future rounds. If the sum of the scores in the upper section is greater than or equal to 63, then 35 more"
 		"points are added to the players overall score as a bonus. The lower section contains a number of poker like combinations. See"
 		"the table provided below:\n\n"

 		"------Name-------|--------combinations-----------|------------Score----------\n"
 		"Three of a kind  | Three dice with the same face |Sum of all values on 5 dice\n"
 		"Four of a kind   | Four dice with the same face  |Sum of all values on 5 dice\n"
 		" Full house      | One pair and a three of a kind|               25          \n"
 		" Small Straight  |    A sequence of four dice    |               30          \n"
 		" Large Straight  |  A sequence of five dice      |               40          \n"
 		" Yahtzee(5ofkind)|  Five dice with same face     |               50          \n"
 		"  Chance         |May be used for any sequence   |Sum of all values on 5 dice\n\n\n"
 		);
 }

/*************************************************************
 * Function: void turn_roll_dice (array, starting, rolls)    *
 * Date Created: 10/09/15                                    *
 * Date Last Modified: 10/09/15                              *
 * Description: creates 6 random number into array[1-6]      *
 * Input parameters: None                                    *
 * Returns: nothing                                          *
 * Preconditions: array and size exist	                     *
 * Postconditions: popullate array                           *
 *************************************************************/
void turn_roll_dice (int array[], int *number_of_rolls)
{
 	//define a var for starting itteration + 5 to stop loop
 	int counter = 1;

 	//pause and ask to contiune
 	printf ("Please press any key to roll your dices.\n");
 	system ("pause");

 	//roll dice with rand and put it in the array
 	for (counter; counter < 6; counter++)
 	{
 		array[counter] = (rand() % 6) + 1;
 	}

 	//update number of number of rolls since we rolled
 	*number_of_rolls = *number_of_rolls + 1;
 }

/*************************************************************
 * Function: void reroll_dice (array, size)   				 *
 * Date Created: 10/09/15                                    *
 * Date Last Modified: 10/09/15                              *
 * Description: rerolls dice                                 *
 * Input parameters: None                                    *
 * Returns: nothing                                          *
 * Preconditions: array and size exist	                     *
 * Postconditions: change array                              *
 *************************************************************/
 void reroll_dice (int dice_array[])
 {
 	//local var
 	int store_places_to_be_rolled = 0, counter = 1, location = 0;

 	//check for valid answer
 	do{
	 	//ask what to reroll
	 	printf ("How many dices would you like to reroll(choose 1 to 5): ");
	 	scanf (" %d", &store_places_to_be_rolled);

	 } while ( (store_places_to_be_rolled <= 0) || (store_places_to_be_rolled >= 6) );


	//reroll dice
 	do
 	{
 		printf ("Please choose %d of %d dice to reroll: ", counter, store_places_to_be_rolled);
 		scanf ("%d", &location);
 		dice_array[location] = (rand() % 6) + 1;
 		counter++;

 	} while (counter < store_places_to_be_rolled + 1);
 }

/*************************************************************
 * Function: void print dice (array)                         *
 * Date Created: 10/09/15                                    *
 * Date Last Modified: 10/09/15                              *
 * Description: creates print the dice in the array          *
 * Input parameters: None                                    *
 * Returns: nothing                                          *
 * Preconditions: array             	                     *
 * Postconditions: popullated array                          *
 *************************************************************/
void print_array_dice (int array[])
 {
 	//use enu
 	// enum print_roll_with_enum roll;

 	//local var
 	int counter = 1;

 	// //set counter
 	// counter = 1;

 	// //print dice in a loop using enum
 	// for (counter = 1; counter < 6; counter++)
 	// {
 	// 	if (rolled_one == array[counter])
 	// 	{
 	// 		printf("Dice %d rolled %d.\n",counter, rolled_one );
 	// 	}
 	// 	if (rolled_two == array[counter])
 	// 	{
 	// 		printf("Dice %d rolled %d.\n",counter, rolled_two );
 	// 	}
 	// 	if (rolled_three == array[counter])
 	// 	{
 	// 		printf("Dice %d rolled %d.\n",counter, rolled_three );
 	// 	}
 	// 	if (rolled_four == array[counter])
 	// 	{
 	// 		printf("Dice %d rolled %d.\n",counter, rolled_four );
 	// 	}
 	// 	if (rolled_five == array[counter])
 	// 	{
 	// 		printf("Dice %d rolled %d.\n",counter, rolled_five );
 	// 	}
 	// 	if (rolled_six == array[counter])
 	// 	{
 	// 		printf("Dice %d rolled %d.\n",counter, rolled_six );
 	// 	}

 	// }


 	//another way to print dice roll
 	//set counter
 	counter = 1;

 	//print dice in a loop
 	for (; counter < 6; counter++)
	{
		printf ("Dice %d rolled %d.\n", counter, array[counter]);
	}
 }

/*************************************************************
 * Function: void print_combinations (void)                   *
 * Date Created: 10/09/15                                    *
 * Date Last Modified: 10/09/15                              *
 * Description: Just print combination                       *
 * Input parameters: None                                    *
 * Returns: returns choice                                   *
 * Preconditions: none             	                         *
 * Postconditions: prints to screen returns choice           *
 *************************************************************/
int print_combinations_return_choice (int dice_array_provided[])
{
	//combination from http://eecs.wsu.edu/~aofallon/cpts121/progassignments/PA5.htm
	//local var
	int combination = 0;

	//do-while loop for input
	do
	{
		print_array_dice (dice_array_provided);


		printf(	"Please choose a combination:\n"
				"1. Sum of 1's\t7. Three-of-a-kind\n"
				"2. Sum of 2's\t8. Four-of-a-kind\n"
				"3. Sum of 3's\t9. Full house\n"
				"4. Sum of 4's\t10. Small straight\n"
				"5. Sum of 5's\t11. Large straight\n"
				"6. Sum of 6's\t12. Yahtzee\n"
				"\t13. Chance\n"
			);

		//ask for user input
		printf ("Please make a selection: ");
		scanf (" %d", &combination);
			
	} while ( (combination <= 0) || (combination >= 14) );

	//return combination selected
	return combination;
}

/*************************************************************
 * Function: void check_combination_manage_score (dicearray, *
 *								combinarray, scorearray)     *
 * Date Created: 10/09/15                                    *
 * Date Last Modified: 10/09/15                              *
 * Description: checks for combination update scorearry      *
 * Input parameters: arrays and current round                *
 * Returns: nothing                                          *
 * Preconditions: all arrays exist                           *
 * Postconditions: arrays will have differnet values         *
 *************************************************************/
 void check_combination_manage_score (int dice_array[], int combination_array[]
 										, int score_array[], int sorted_array[], int current_round)
 {
 	//local var
 	int generic_checker = 0, generic_counter = 0, selected_combination = 0,
 	    sum_of_rolls = 0;

 	//set generic checker & counter
 	generic_checker = 1;
 	generic_counter = 1;

 	//do loop to get combination check if has been picked
 	do
 	{
		selected_combination = print_combinations_return_choice (dice_array);

 		//check for chance
 		// if (selected_combination == 13)
 		// {break;}

 		//check for other choices
 		if (combination_array[selected_combination] == 0)
 		{
 			generic_checker = 0;
 		}

 		if (combination_array[selected_combination] == 1)
 		{
 			//print error message
 			printf("Please Choose another combination. %d has already been used\n", selected_combination);

 			//pause so user can read
 			system ("pause");

 			//clear screen
 			system ("cls");

 		}

 	} while (generic_checker);

 	//update array of combination used
 	combination_array[selected_combination] = 1;

 	//set generic checker & counter & sum of dice
 	generic_checker = 1;
 	generic_counter = 1;
 	sum_of_rolls = 0;

 	//evaluate choice 
 	switch (selected_combination)
 	{
 		case 1:
 			//sum of ones
 			 sum_of_rolls = sorted_array[1];
 		break; //break out of case

 		case 2:
 			//sum of 2
 			 sum_of_rolls = sorted_array[1] * 2;

 		break; //break out of case
 		case 3:
 			//sum of 3
 			 sum_of_rolls = sorted_array[1] * 3;

 		break; //break out of case
 		case 4:
 			//sum of 4
 			 sum_of_rolls = sorted_array[1] * 4;

 		break; //break out of case
 		case 5:
 			//sum of 5
 			 sum_of_rolls = sorted_array[1] * 5;

 		break; //break out of case
 		case 6:
 			//sum of 6
 			 sum_of_rolls = sorted_array[1] * 6;

 		break; //break out of case
 		case 7:
 			//Three of a kind
 			//sum of all 5 dice
 			for (generic_counter; generic_counter < 6; generic_counter++)
 			{
 				sum_of_rolls = sum_of_rolls + dice_array[generic_counter];
 			}


 		break; //break out of case
 		case 8:
 			//Four of a kind
 			//sum of all 5 dice
 			for (generic_counter; generic_counter < 6; generic_counter++)
 			{
 				sum_of_rolls = sum_of_rolls + dice_array[generic_counter];
 			}

 		break; //break out of case
 		case 9:
 			//full house
 			sum_of_rolls = 25;

 		break; //break out of case
 		case 10:
 			//small straight
 			sum_of_rolls = 30;

 		break; //break out of case
 		case 11:
 			//large straight
 			sum_of_rolls = 40;

 		break; //break out of case
 		case 12:
 			//Yahtzee
 			sum_of_rolls = 50;

 		break; //break out of case
 		case 13:

 			//change is selected sum of all 5 dice
 			for (generic_counter; generic_counter < 6; generic_counter++)
 			{
 				sum_of_rolls = sum_of_rolls + dice_array[generic_counter];
 			}
 		break; //break out of case
 	}

 	//update score array for round
 	score_array[current_round] = sum_of_rolls;
 }
/*************************************************************
 * Function: void sort_dice_rolls(dicearray,nonsorrtedarray) *
 * Date Created: 10/09/15                                    *
 * Date Last Modified: 10/09/15                              *
 * Description: sort array simple logic                      *
 * Input parameters: dice array and nonsorted array          *
 * Returns: nohting                                          *
 * Preconditions: all arrays exist                           *
 * Postconditions: sorted array has values                   *
 *************************************************************/
 void sort_dice_roll_array (int dice_array[], int nonsorrted_array[])
 {
 	//local var
 	int foo = 0, counter = 0;

 	//inilaize counter
 	counter = 1;

 	for (counter; counter < 6; counter++)
 	{
 		nonsorrted_array[dice_array[counter]]++;
 	}
 }

/*************************************************************
 * Function: int sum_final_score (arrayofscore[]) 		     *
 * Date Created: 10/09/15                                    *
 * Date Last Modified: 10/09/15                              *
 * Description: retruns sums of scores				         *
 * Input parameters: arrayofscor                             *
 * Returns: score                                            *
 * Preconditions: array exist                                *
 * Postconditions: score                                     *
 *************************************************************/
int sum_final_score (int array_of_score[])
 {
 	//local var
 	int sum = 0, counter =0;

 	//set counter
 	counter = 1;

 	//iterate the array
 	for (counter; counter < 14; counter++)
 	{
 		sum = sum + array_of_score[counter];
 	}
 	return sum;
 }