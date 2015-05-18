#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string> 

using namespace std;


void DFA();
/******************************************************************
The main Function will be used to ask the user if he wants to enter 
a string  if the user chooses yes then we will call the 
DFA function if the user declines the program will terminate.
******************************************************************/
int main(int argc, char *argv[])
{
	string asn;// Variable used to decide if the program will run
	
	cout << "Do you want to enter a string?\n y for yes, or n for no \n";
	getline(cin, asn);
	
	while ( (asn != "y") && (asn != "n"))//loop to make sure the user only enters y or n
	{
		cout << "Please enter either y or n \n";
		getline(cin, asn);
	}

	while (asn == "y"){

		DFA();// function call to where the DFA is to be executed

		cout << "Do you want to enter a string?\n y for yes, or n for no \n";
		getline(cin, asn);

		while ((asn != "y") && (asn != "n"))
		{
			cout << "Please enter either y or n \n";
			getline(cin, asn);
		}
	};

	return 0;
}


/***************************************************************************
This is the function where the DFA will be executed to do this I used a 
switch statement to determine what action the DFA will use depending on
the character that the automata is working on. Each different state compares
the current character of the string with the options available to said state
and then goes sends the next character to the corresponding state.
***************************************************************************/
void DFA(){

	string str;
	int state = 0;// initializing the state to the initial state q0
	ofstream output;
	output.open("output.txt", ios::out | ios::app | ios::ate);//opening the file where we will write the output of the machine
															  //the file will append the output to the back of the file
	cout << "Please enter a string \n";
	getline(cin, str);//getting the string that the DFA will work on from the user

	//Couple of messages telling the user the string that the program is working on and the initial state of the machine
	cout << "The string to be worked on is \n" << str << endl;
	output << "The string to be worked on is \n" << str << endl;
	cout << "The current state is q" << state << endl;
	output << "The current state is q" << state << endl;


	//loop that will go through each individual character of the string and work on evry one of them there is a switch
	//statement that will be used as the DFA if the string contains any characters that are not in the language or that don't
	//follow the rules of the DFA the switch will default to the trap state(state 17)
	for (int i = 0; i < str.length(); i++)
	{
		switch (state) {
		case 0:
			if ('a' <= str[i] && 'z' >= str[i])
			{
				if (str[i] == 'w')
					state = 1;
				else
					state = 5;
			}
			else
				state = 17;
			break;
		case 1:
			if ('a' <= str[i] && 'z' >= str[i])
			{
				if (str[i] == 'w')
					state = 2;
				else
					state = 5;
			}
			else if (str[i] == '.')
				state = 9;
			else
				state = 17;
			break;
		case 2:
			if ('a' <= str[i] && 'z' >= str[i])
			{
				if (str[i] == 'w')
					state = 3;
				else
					state = 5;
			}
			else if (str[i] == '.')
				state = 9;
			else
				state = 17;
			break;
		case 3:
			if ('a' <= str[i] && 'z' >= str[i])
				state = 5;
			else if (str[i] == '.')
				state = 4;
			else
				state = 17;
			break;
		case 4:
			if ('a' <= str[i] && 'z' >= str[i])
			{
				if (str[i] == 'c')
					state = 6;
				else
					state = 5;
			}
			else
				state = 17;
			break;
		case 5:
			if ('a' <= str[i] && 'z' >= str[i])
				state = 5;
			else if (str[i] == '.')
				state = 9;
			else
				state = 17;
			break;
		case 6:
			if ('a' <= str[i] && 'z' >= str[i])
			{
				if (str[i] == 'o')
					state = 7;
				else
					state = 5;
			}
			else if (str[i] == '.')
				state = 9;
			else
				state = 17;
			break;
		case 7:
			if ('a' <= str[i] && 'z' >= str[i])
			{
				if (str[i] == 'm')
					state = 8;
				else
					state = 5;
			}
			else if (str[i] == '.')
				state = 10;
			else
				state = 17;
			break;
		case 8:
			if ('a' <= str[i] && 'z' >= str[i])
				state = 5;
			else if (str[i] == '.')
				state = 9;
			else
				state = 17;
			break;
		case 9:
			if (str[i] == 'c')
				state = 11;
			else
				state = 17;
			break;
		case 10:
			if (str[i] == 'c')
				state = 11;
			else if (str[i] == 'j')
				state = 15;
			else
				state = 17;
			break;
		case 11:
			if (str[i] == 'o')
				state = 12;
			else
				state = 17;
			break;
		case 12:
			if (str[i] == 'm')
				state = 13;
			else if (str[i] == '.')
				state = 14;
			else
				state = 17;
			break;
		case 13:
			state = 17;
			break;
		case 14:
			if (str[i] == 'j')
				state = 15;
			else
				state = 17;
			break;
		case 15:
			if (str[i] == 'p')
				state = 16;
			else
				state = 17;
			break;
		case 16:
			state = 17;
			break;
		default:
			state = 17;
		}

		//Here we are telling the user the current character being worked on and the current state on the machine
		//We are also saving this to an output file
		cout << "The character that was just processed was " << str[i] << endl;
		output << "The character that was just processed was " << str[i] << endl;
		cout << "The current state is q" << state << endl << endl;
		output << "The current state is q" << state << endl << endl;
	}

	//this if else statement checks if the string that the user entered ended on one of the final/acceptance states of the
	//DFA, then proceeds to inform the user if the string was accepted and writes the output to a file
	if (state == 8 || state == 13 || state == 16){
		cout << "The string " << str << " is accepted in the language \n \n";
		output << "The string " << str << " is accepted in the language \n \n";
	}
	else{
		cout << "The string " << str << " is not accepted in the language \n \n";
		output << "The string " << str << " is not accepted in the language \n \n";
	}

	output.close();

}

