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

	//loop though vector
	for (int i = 0; i < Dictionary.size(); i++) {

		//print name, type, define if userInput matches
		if (Dictionary[i].name.compare(userInput) == 0)
		{
			cout << "name : "  << Dictionary[i].name << "\ntype: " << Dictionary[i].type << "\ndefinition: " << Dictionary[i].definition << endl;
			return;
		}
		
	}

	//print message in case no match found with userInput 
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

	//loop though vector
	for (int i = 0; i < Dictionary.size(); i++) {

		//check string contains user input char
		if (Dictionary[i].name.find(userInputChar) != string::npos) {
			
			actualOccurance = 0;
			//count occurrences of that character in  word 
			for(int j = 0; (j = Dictionary[i].name.find(userInputChar, j)) != std::string::npos; j++) {
				actualOccurance++;
			}

			//printing out the words that include that character the given number of times or greater
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





int main()               
{

	//var declaration 
	string filename = "dictionary2022_S1.txt";
	string name, type, definition, star;
	struct Word w;
	string line;
	int linenumber = 1;
	int menuItem;
	string confirm;


	//declare an STL Vector of Word instances
	vector<Word> Dictionary;

	cout << "Loading application ... Please wait .. " << endl;


	//read file 
	ifstream  ifs(filename);

	//exit application if not able to access the file 
	if (ifs.fail()) {
		cout << "Error opening  file (dictionary2022_S1.txt)" << endl;
		exit(1);
	}

	
	//read each line of the file and store into the structure variable 
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

			//store the structure in the Dictionary vector
			Dictionary.push_back(w);

			linenumber = 0;

		}

		linenumber++;

	}


	//check all texts store in the vector of structs 
	/*for (int i = 0; i < Dictionary.size(); i++) {
		cout << Dictionary[i].name << " " << Dictionary[i].type << " " << Dictionary[i].definition << endl;
	}*/


	
	
	do
	{
		

		//show user menu items 
		menuItem = menuSelect();
		switch (menuItem)
		{
			// call function based on user selection
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
