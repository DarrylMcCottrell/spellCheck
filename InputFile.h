#ifndef INPUTFILE_H
#define INPUTFILE_H

#include <string>
#include <vector>

using namespace std;

class InputFile
{
public:
	InputFile(const string& f);
	void setInputFilename(const string& s) {inputFilename = s;}
	string getInputFilename() {return inputFilename;}
	void loadFileContents();
	void printFileContents();
	void removeAllPunctuation();
	void removePunctuation(string& p);
	void makeLowerCase();
	int getNumWords() {return fileContents.size();}
	string getWord(int i) {return fileContents[i];}
private:
	vector < string > fileContents;
	string inputFilename;
};

#endif

//The name of the parameter names are confusing a little should have more meaning, even if the code works fine
//Also use for pragma once is missing for header files
// A little confused on the constant use of #endif in the header files, is it needed?