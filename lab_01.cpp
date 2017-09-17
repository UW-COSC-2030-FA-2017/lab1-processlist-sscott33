// lab_01.cpp : Defines the entry point for the console application.
//



#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void skipWhitespace(ifstream &inputFile);
		// function to skip whitespaces
		// prevents the nested loop (below) from attempting to read in whitespace at the end of a file
		// (w/o this the program could duplicate the last number in the file)


int main()
{
	char yesno = 'n';

	// the following loop serves to prevent the immediate closure of the program upon completion
	// it also allows for the reuse of the program
	do {
		// ask the user for the file name
		cout << "Please enter the name of the file: ";

		// store the filename in a variable
		string filename;
		cin >> filename;


		// find the file and gather stats

		// create an object to read text from the file
		ifstream inputFile;

		// open the file
		inputFile.open(filename);

		// create 2 arrays to store the first and last two values
		double firstTwo[2], lastTwo[2];


		// create a counter to determine how many numbers are in the file
		// (controls the format of the output)
		int counter = 0;

		while (!inputFile.eof() && !inputFile.fail()) {
			// step through file and store the numbers accordingly

			if (counter < 2) {
				skipWhitespace(inputFile);
				if (inputFile.eof()) break;
				inputFile >> firstTwo[counter];
			}
			else if (counter == 2) {
				skipWhitespace(inputFile);
				if (inputFile.eof()) break;
				inputFile >> lastTwo[0];
			}
			else {
				skipWhitespace(inputFile);
				if (inputFile.eof()) break;
				double temp = lastTwo[0];
				lastTwo[1] = temp;
				inputFile >> lastTwo[0];
			}

			/// the last two #s are stored in the order of second to last (index of [1]) and then last (index of [0])

			// increment counter after each number has been read
			counter++;

		}

		// format output based on the quantity of numbers in the file (passed via counter)

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

		// close the file stream
		inputFile.close();

			// ask the user to reuse the program
			cout << "\n\nWould you like to use this program again? (y/n) ";
			cin >> yesno;
			cout << endl;		// add some space to increase readability if reused

	} while (yesno == 'y' || yesno == 'Y');

    return 0;
}

void skipWhitespace(ifstream &inputFile) {
		while (inputFile.peek() == ' ' || inputFile.peek() == '\n') {
				// loop through whitespaces in the file until there are no more of them
				inputFile.get();
		}
}
