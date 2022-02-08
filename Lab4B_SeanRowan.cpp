///////////////////////////////////////////////////////////////////////////////////////////////
//
// Filename: Lab4B_SeanRowan.cpp
// date: 3/6/21
// programmer: Sean Rowan
//
// description:
// Asks user to input a word. Th eprogram will search a file for the amount of times it appears.
// The program will also count all of the punctuation marks in the file. Finally, it will display the results.
//
////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//function prototypes
void processFile(ifstream& inFile, string wordSearch, int& wordCount, int& grammaticalCount);
void displayResult(string word, int wordCount, int grammaticalCount);

int main()
{
	ifstream inFile;
	string wordSearch, word;
	int wordCount=0, grammaticalCount=0;


	processFile(inFile, wordSearch, wordCount, grammaticalCount);

	displayResult(word, wordCount, grammaticalCount);
	

	return 0;
}


//function definitions
void processFile(ifstream& inFile, string wordSearch, int& wordCount, int& grammaticalCount)
{	
	inFile.open("paragraph.dat");
	
	if (inFile.is_open())
	{
		//Get user-specified word
		cout << "Enter the word you would like to search: ";
		cin >> wordSearch;


		while (!inFile.eof())
		{
			string str;
			inFile >> str;

			//Count word in file
			if (wordSearch.compare(str) == 0)
				wordCount++;

			//search for punctuation marks - defined by WMU
			for (int i = 0; i < str.length(); ++i)
			{
				if (str[i] == '!' || str[i] == '.' || str[i] == '?' ||
					str[i] == ',' || str[i] == ':' || str[i] == ';' ||
					str[i] == '(' || str[i] == ')' || str[i] == '[' ||
					str[i] == ']' || str[i] == '"' || str[i] == '-' ||
					str[i] == '--'|| str[i] == '/' || str[i] == '\'')
					grammaticalCount++;
			}
		}
	}
	else
		cout << "Cannot open file." << endl;
	

}

void displayResult(string word, int wordCount, int grammaticalCount)
{
	
	cout << "The word " << word << " appears " << wordCount << " times in the file." << endl;

	cout << "There are " << grammaticalCount << " punctuation marks in the file" << endl;
}