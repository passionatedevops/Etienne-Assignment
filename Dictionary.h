#pragma once

#include <iostream>
#include <fstream>         
#include <string>
#include <vector>
#include "Word.h"

using namespace std;

class Dictionary
{
private:
	//declare an STL Vector of Word instances
	 vector <Word> dictionary;

public:
	// Setter function 
	void setDictionary(Word w) {
		dictionary.push_back(w);
	}

	
	// Getter function 
	vector <Word> getDictionary() {
		return dictionary;
	}

	

	void loadFile(string filename);
	void defineWord(vector<Word> dictionary);
	void givenCharacters(vector<Word> dictionary);
	void listAllWords(vector<Word> dictionary);



};
