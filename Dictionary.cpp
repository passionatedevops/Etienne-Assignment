

#include "Dictionary.h"

/// <summary>
/// Read from the files and store in the vector ( type Word ) ,  vector name : dictionary 
/// </summary>
/// <param name="filename"></param>

void Dictionary::loadFile(string filename) {

	//read file 
	ifstream  ifs(filename);
	Word w;
	string line, star;
	int linenumber = 1;
	
	cout << "Please wait to load file.... " << endl;

	//exit application if not able to access the file 
	if (ifs.fail()) {
		cout << "Error opening  file " << endl;
		exit(1);
	}

	//read each line of the file and store into the structure variable 
	while (getline(ifs, line))
	{
		if (linenumber == 2)
		{
			w.setName(line);
		}
		else if (linenumber == 1)
		{
			w.setType(line);

		}
		else if (linenumber == 3)
		{
			w.setdefinition(line);

		}
		else {
			star = line;

			//store the structure in the Dictionary vector
			setDictionary(w);

			linenumber = 0;

		}

		linenumber++;

	}



}



/// <summary>
/// 1.	Prompt the user to enter a word. If that exact word is in the dictionary, 
/// print the word’s name, followed directly on the same line by the word type using the scheme in Table 1, and the word’s definition.
/// </summary>
/// <param name="Dictionary"></param>
/// <returns></returns>

void Dictionary::defineWord(vector<Word> dictionary)
{
	string userInput;

	cout << "Enter a word : ";
	cin >> userInput;



	//loop though vector
	for (int i = 0; i < dictionary.size(); i++) {

		//print name, type, define if userInput matches
		if (dictionary[i].getName().compare(userInput) == 0)
		{
			//create object of Word class 
			Word word(dictionary[i].getName(), dictionary[i].getType(), dictionary[i].getDefinition());

			word.printDefinition();
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
void Dictionary::givenCharacters(vector<Word> dictionary)
{
	string userInputChar;
	int minOccurance;
	int actualOccurance = 0;

	cout << "Enter a character : ";
	cin >> userInputChar;


	cout << "Enter minimum number of occurrences of that character : ";
	cin >> minOccurance;

	//loop though vector
	for (int i = 0; i < dictionary.size(); i++) {

		//check string contains user input char
		if (dictionary[i].getName().find(userInputChar) != string::npos) {

			actualOccurance = 0;
			//count occurrences of that character in  word 
			for (int j = 0; (j = dictionary[i].getName().find(userInputChar, j)) != std::string::npos; j++) {
				actualOccurance++;
			}

			//printing out the words that include that character the given number of times or greater
			if (actualOccurance >= minOccurance)
			{
				cout << dictionary[i].getName() << endl;
			}
		}

	}

}

/// <summary>
/// List all the words in the dictionary that have a 'q' without a following 'u' eg 'Iraqi'
/// </summary>
/// <param name="Dictionary"></param>
/// 
void Dictionary::listAllWords(vector<Word> dictionary)       // task 3 function
{
	for (int i = 0; i < dictionary.size(); i++) {

		// check string contains 'q'
		if (dictionary[i].getName().find('q') != string::npos) {
			if (dictionary[i].getName().find('qu') != string::npos) {
				// found
			}
			else {// words in the dictionary that have a 'q' without a following 'u'
				cout << dictionary[i].getName() << endl;

			}


		}

	}

}


