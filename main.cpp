#include <iostream>
#include <fstream>         // Combination of creates, reads and writes to files
#include <string>
#include <vector>

// include header files 
#include "Word.h"
#include "Dictionary.h"
#include "extendedDictionary.h"


using namespace std;




int menuSelect()
{

	cout << "============================================" << endl;
	cout<< "USER MENU" << endl;
	cout << "============================================" << endl;

	int mItem;
	cout << "Press (1) to define a word and display the word type \n"
		    "Press (2) to find words that contain a given character \n"
		    "Press (3) to list all words in the dictionary that have a 'q' with no 'u' after \n" 
			"Press (4) to list all words in the dictionary that are palindromes. e.g .'civic' \n"
			"Press (5) to prompt the user for a word, and report all words that are anagrams of the word  \n"
			"Press (6) to play guessing game \n"
		   << endl;;
	cout << "Enter your choice(1-6):";
	cin >> mItem;

	return mItem;


}



int main()               
{
	//var declaration 
	Dictionary dict;
	extendedDictionary exdict;

	Word w;
	string filename = "dictionary2022_S1.txt";
	
	dict.loadFile(filename);


	int menuItem;
	string confirm;
	
	
	do
	{
		//show user menu items 
		menuItem = menuSelect();
		switch (menuItem)
		{
			// call function based on user selection

			case 1: dict.defineWord(dict.getDictionary()); break;
			case 2: dict.givenCharacters(dict.getDictionary()); break;
			case 3: dict.listAllWords(dict.getDictionary()); break;
			//Basic tasks
			case 4: exdict.listPalindromes(dict.getDictionary()); break;
			case 5: exdict.listAnagrams(dict.getDictionary()); break;
			
			//intermediate task
			case 6: exdict.guessingGame(dict.getDictionary()); break;


			default: cout << "invalid" <<endl; break;
		}

		cout << "Press y or Y to continue or  press (any other key & enter) to exit" << endl;
		cin >> confirm;


	} while (confirm == "y" || confirm == "Y");



	return 0;


}
