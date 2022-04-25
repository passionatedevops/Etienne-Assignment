#pragma once

#include <iostream>   
#include <string>

using namespace std;


class Word {
private:
	string name;  // Word in dictionary
	string type; // Word type eg. Noun etc
	string definition; // Output the string of the defintion of the name (copy definition in the file (dictionary) and put it in string definition

public:

	//default constrcutor 
	Word() {

	}

	//constructor to initialize variable
	Word(string _name, string _type, string _definition) {
		name = _name;
		type = _type;
		definition = _definition;
	}

	// Setter function for name
	void setName(string _name) {
		name = _name;
	}

	// Setter function for type
	void setType(string _type) {
		type = _type;
	}

	// Setter function for definition
	void setdefinition(string _definition) {
		definition = _definition;
	}



	// Getter function for name
	string getName() {
		return name;
	}

	// Getter function for type
	string getType() {
		return type;
	}

	// Getter function for definition
	string getDefinition() {
		return definition;
	}

	void printDefinition() {

		cout << "name : " << getName() << "\ntype: " << getType() << "\ndefinition: " << getDefinition() << endl;

	}

};
