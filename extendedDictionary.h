#pragma once
#include <iostream>
#include "Dictionary.h"

class extendedDictionary : public Dictionary
{

public:
	void listPalindromes(vector<Word> dictionary);
	void listAnagrams(vector<Word> dictionary);
	void guessingGame(vector<Word> dictionary);
};

