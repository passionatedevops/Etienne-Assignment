#include <iostream>
#include <fstream>         // Combination of creates, reads and writes to files
#include <string>
#include <vector>

using namespace std;

struct Word  //Struct that hold each word
{
	string name;  // Word in dictionary
	string type; // Word type eg. Noun etc
	string definition; // Output the string of the defintion of the name (copy definition in the file (dictionary) and put it in string definition

};



int menuSelect()
{
	int mItem;
	cout << "Press (1) to define a word and display the word type \n Press (2) to find words that contain a given character \n Press (3) to list all words in the dictionary that have a 'q' with no 'u' after \n";
	cin >> mItem;

	while (!(mItem > 3) || (mItem < 1))
	{
		cout << "Incorrect selection.... Try Again \n";
		cin >> mItem;

	}
	return mItem;
}


string DefineWord(string filename, vector<Word> Dictionary)                 // task 1
{

	string defineWordvar;
	string typevar;

	cout << "Enter a word: ";      // input of word
	getline(cin, defineWordvar);



	// copying string into struct defineWord.name

	ifstream myfile(filename);

	if (myfile.is_open())
	{
		Word defineWord;
		while (!myfile.eof())
		{
			getline(myfile, defineWordvar);
			defineWord.name = defineWordvar;
			Dictionary.push_back(defineWord);

			getline(myfile, typevar, '')
				for (int i = )
		}
	}
	myfile.close();

	cout << " " <<





}

GivenCharacters()    // task 2  function
ListAllWords()       // task 3 function





int main()                // put a loop onto all functions to allow continous asking of name of definitions unless you press 2(quit)
{
	string filename = "dictionary2022_S1.txt";
	int menuItem;
	string line;
	menuItem = menuSelect();

	if (menuItem == 1)
	{
		DefineWord();
	}

	if (menuItem == 2)
	{
		GivenCharacters();
	}

	if (menuItem == 3)
	{
		ListAllWords();
	}


	vector<Word> Dictionary;

}
