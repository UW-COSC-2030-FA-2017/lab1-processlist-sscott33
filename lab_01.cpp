// lab_01.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

//#include <cstring>;
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void skipWhitespace(ifstream &inputFile);
		// function to skip whitespaces in an attempt to fix errors with whitespaces at the end of a file


int main()
{
	char yesno = 'n';
	do {
		// ask the user for the file name
		cout << "Please enter the name of the file: ";

		// store the filename in a variable
		string filename;
		cin >> filename;


		// find the file and gather stats
		// report error if the file cannot be accessed/located

		// create an object to read text from the file
		ifstream inputFile;


		// create 2 arrays to store values
		double firstTwo[2], lastTwo[2];

		// open the file
		inputFile.open(filename);

		// if (!inputFile.is_open())
		// 	cout << "\nopen!";
		// boolean flag to check if there are at least four #s in the file
		//bool atLeastFourInts = false;

		// create a counter to determine how many numbers are in the file
		int counter = 0;

		while (!inputFile.eof() && !inputFile.fail()) {
			// step through file and store the numbers accordingly
			// if (inputFile.fail())
			// 	break;

//system("pause");
			if (counter < 2) {
				skipWhitespace(inputFile);
				if (inputFile.eof()) break;
				inputFile >> firstTwo[counter];
				//cout << firstTwo[counter];
			}
			else if (counter == 2) {
				skipWhitespace(inputFile);
				if (inputFile.eof()) break;
				inputFile >> lastTwo[0];
				//cout << lastTwo[0];
			}
			else {
				skipWhitespace(inputFile);
				if (inputFile.eof()) break;
				double temp = lastTwo[0];
				lastTwo[1] = temp;
				inputFile >> lastTwo[0];
				//cout << lastTwo[0];
				//cout << lastTwo[1];
			}

			// the last two #s are stored in the order of second to last: [1] and last: [0]

			counter++;

			// set flag
			//atLeastFourInts = (counter >= 4);

		}

		//system("pause");

		switch (counter)
		{
		case 0:
			cout << "The file is empty";
			break;
		case 1:
			cout << "The file contains only one number: " << firstTwo[0];
			break;
		case 2:
			cout << "The file contains only two numbers (in order of occurence): " << firstTwo[0] << " and " << firstTwo[1];
			break;
		case 3:
			cout << "The file contains only three numbers (in order of occurence): " << firstTwo[0] << ", " << firstTwo[1] << ", and " << lastTwo[0];
			break;
		default:	// four #s or more
			cout << "The first two numbers are (in order of occurence): " << firstTwo[0] << " and " << firstTwo[1] << endl;
			cout << "The last two numbers are (in order of occurence): " << lastTwo[1] << " and " << lastTwo[0];
			break;

		}

		inputFile.close();

		//system("pause");
			// ask the user to reuse the program
			cout << "\n\nWould you like to use this program again? (y/n) ";
			cin >> yesno;
			cout << endl;

	} while (yesno == 'y' || yesno == 'Y');





    return 0;
}

void skipWhitespace(ifstream &inputFile) {
		while (inputFile.peek() == ' ' || inputFile.peek() == '\n') {
				inputFile.get();
		}
}
