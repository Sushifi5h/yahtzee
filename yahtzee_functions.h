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

//The next to lines help this header file from being called over and also know as (Including gaurd) //Learned from wikki and youtube (https://en.wikipedia.org/wiki/Include_guard)
#ifndef YAHTZEE_FUNCTIONS_H
#define YAHTZEE_FUNCTIONS_H

//Doing this stop annoying errors
#define _CRT_SECURE_NO_WARNINGS //Stop unwanted printf errors

//Define Array
#define size_of_arrays 20 //can we be used as single on all arrays I like differnet definitions tho

//Including libarises that will be used to write this program
#include <stdio.h> //Fuctions that will be used but not limited to scanf (), printf (), fopen (), fclose (), fscanf (), fprintf ()
#include <stdlib.h> //Need to generate rand numbers and clearing screen and pausing program
#include <time.h> //Need to seed different values for srand

//Maybe we used later to set values
// enum print_roll_with_enum 
// 	{
// 	rolled_one = 1,
// 	rolled_two,
// 	rolled_three,
// 	rolled_four,
// 	rolled_five,
// 	rolled_six,
// 	};


//Prototypes
void yahtzee_runner (void); //contains games logic
int yahtzee_game_options (void); //prints starting game options
int yahtzee_game_options_selector (void); // gets the option selected by the player
void yahtzee_game_rules (void); //game rules from PA 5 website
void turn_roll_dice (int dice_roll[], int number_of_rolls); //rolls dice for turn 1
void print_array_dice (int array[]); //print dice
int print_combinations_return_choice (int dice_array_provided[]); //just prints combination
void reroll_dice (int dice_array[]); //rerolls dice
void check_combination_manage_score (int dice_array[], int combination_array[], int score_array[], int sorted_array[], int current_round); //manages combination selection and score array
void sort_dice_roll_array (int dice_array[], int nonsorrted_array[]); //sorts array to manage which combos were rolled
int sum_final_score (int array_of_score[]); //gets teh sum of ints in array



#endif //This statement ends the gaurd