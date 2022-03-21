#include <iostream>
#include <fstream>         // Combination of creates, reads and writes to files
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Word  //Struct that hold each word
{
	string name;  // Word in dictionary
	string type; // Word type eg. Noun etc
	string definition; // Output the string of the defintion of the name (copy definition in the file (dictionary) and put it in string definition

};


int menuSelect()
{

	cout << "============================================" << endl;
	cout<< "USER MENU" << endl;
	cout << "============================================" << endl;

	int mItem;
	cout << "Press (1) to define a word and display the word type \nPress (2) to find words that contain a given character \nPress (3) to list all words in the dictionary that have a 'q' with no 'u' after" << endl;;
	cout << "Enter your choice(1-3):";
	cin >> mItem;

	return mItem;


}

/// <summary>
/// 1.	Prompt the user to enter a word. If that exact word is in the dictionary, 
/// print the word’s name, followed directly on the same line by the word type using the scheme in Table 1, and the word’s definition.
/// </summary>
/// <param name="Dictionary"></param>
/// <returns></returns>

void DefineWord(vector<Word> Dictionary)                 
{
	string userInput;

	cout << "Enter a word : " ;
	cin >> userInput;

	for (int i = 0; i < Dictionary.size(); i++) {

		if (Dictionary[i].name.compare(userInput) == 0)
		{
			cout << "name : "  << Dictionary[i].name << "\ntype: " << Dictionary[i].type << "\ndefinition: " << Dictionary[i].definition << endl;
			return;
		}
		
	}


	cout << "exact word not found" << endl;

	
}

/// <summary>
/// word(s) that contain a given character a given number of times or more. The user should be prompted for the character 
/// they wish to find, then prompted for the minimum number of occurrences of that character. This should be follows by the program printing out 
/// all the words that include that character the given number of times or greater (just print the name of the word, not the type or definition).
/// </summary>
/// <param name=""></param>
void GivenCharacters(vector<Word> Dictionary)
{
	string userInputChar;
	int minOccurance;
	int actualOccurance = 0;

	cout << "Enter a character : ";
	cin >> userInputChar;


	cout << "Enter minimum number of occurrences of that character : ";
	cin >> minOccurance;

	for (int i = 0; i < Dictionary.size(); i++) {

		// check string contains user input char
		if (Dictionary[i].name.find(userInputChar) != string::npos) {
			
			actualOccurance = 0;
			for(int j = 0; (j = Dictionary[i].name.find(userInputChar, j)) != std::string::npos; j++) {
				actualOccurance++;
			}

			if (actualOccurance >= minOccurance)
			{
				cout << Dictionary[i].name << endl;
			}
		}

	}

}

/// <summary>
/// List all the words in the dictionary that have a 'q' without a following 'u' eg 'Iraqi'
/// </summary>
/// <param name="Dictionary"></param>
/// <returns></returns>
/// 
void ListAllWords(vector<Word> Dictionary)       // task 3 function
{
	for (int i = 0; i < Dictionary.size(); i++) {

		// check string contains 'q'
		if (Dictionary[i].name.find('q') != string::npos) {
			if (Dictionary[i].name.find('qu') != string::npos) {
				// found
			}
			else {// words in the dictionary that have a 'q' without a following 'u'
				cout << Dictionary[i].name << endl;

			}


		}
	
	}

}





int main()                // put a loop onto all functions to allow continous asking of name of definitions unless you press 2(quit)
{
	string filename = "dictionary2022_S1.txt";
	string name, type, definition, star;


	struct Word w;
	//declare an STL Vector of Word instances
	vector<Word> Dictionary;

	cout << "Loading application ... Please wait .. " << endl;


	//read file and store into structure 

	ifstream  ifs(filename);

	if (ifs.fail()) {
		cout << "Error opening  file (dictionary2022_S1.txt)" << endl;
		exit(1);
	}

	string line;
	int linenumber = 1;
	while (getline(ifs, line))
	{
		if (linenumber == 2)
		{
			w.name = line;
			//cout << w.name << endl;
		}
		else if (linenumber == 1)
		{
			w.type = line;
			//cout << w.type << endl;
		}
		else if (linenumber == 3)
		{
			w.definition = line;
			//cout << w.definition << endl;
		}
		else {
			star = line;

			Dictionary.push_back(w);

			linenumber = 0;

		}

		linenumber++;

	}


	//check all texts store in the vector of structs 
	/*for (int i = 0; i < Dictionary.size(); i++) {
		cout << Dictionary[i].name << " " << Dictionary[i].type << " " << Dictionary[i].definition << endl;
	}*/


	//show user menu items 
	int menuItem;
	string confirm;
	do
	{
		
		menuItem = menuSelect();
		switch (menuItem)
		{
			case 1: DefineWord(Dictionary); break;
			case 2: GivenCharacters(Dictionary); break;
			case 3: ListAllWords(Dictionary); break;
			default: cout << "invalid" <<endl; break;
		}

		cout << "Press y or Y to continue or  press (any other key & enter) to exit" << endl;
		cin >> confirm;


	} while (confirm == "y" || confirm == "Y");



	return 0;


}
