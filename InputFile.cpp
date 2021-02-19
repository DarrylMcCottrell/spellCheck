#include "InputFile.h"

#include <iostream>
#include <fstream>

using namespace std;

InputFile::InputFile(const string& f)
{
	//store the path to the dictionary file
	setInputFilename(f);
    
	//call helper to load with default string
    loadFileContents();
}
//*********************************************
void InputFile::loadFileContents()
{
    //name of file that holds the file contents
    ifstream infile(getInputFilename().c_str());

    //if opened ok, then load
    if(infile)
    {
        string* temp = new string; //hold words from file
        infile>>*temp; //get first word

        while(infile) //while there are more words to get
        {
            //push the word on the vector
            fileContents.push_back(*temp);
            
            //get the next word
            infile>>*temp;
        }
    }
    else //print error message
    {
        cout<<"Error opening "<<getInputFilename()<<endl;
		exit(0);
    }
}
//*********************************
void InputFile::printFileContents()
{
	for(int i = 0;i < fileContents.size();i++)
	{
		cout<<fileContents[i]<<endl;
	}
}
//**********************************
void InputFile::removeAllPunctuation()
{
	string puncMarks[] = {".", ",", "!", "\"", "\'", ";", 
						  "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
	
	for(int i = 0;i < 15;i++)
	{
		removePunctuation(puncMarks[i]);
	}
}
//**********************************
void InputFile::removePunctuation(string& p)
{
	for(int i = 0;i < fileContents.size();i++)
	{
		int pos = fileContents[i].find(p);
		if(pos != string::npos)
		{
			fileContents[i].replace(pos + 1, 1, "");
		}

		if(fileContents[i] == "")
		{
			fileContents.erase(fileContents.begin() + i);
		}
	}
}
void InputFile::makeLowerCase()
{
	for(int i = 0;i < fileContents.size();i++)
	{
		int stringSize = fileContents[i].size();
		for(int j = 0;j < stringSize;j++)
		{
			fileContents[i].at(j) = tolower(fileContents[j].at(j));
		}
	}
}


//COMMENTS: The inputfile comment on line 10 is being referred to as a dictionary
//Line 23-36, couldn't you just put the complete infile in the while loop?
//Line 25-26, Memory leak is possible because temp isn't being deleted.
//More preference based but couldn't you just make removing a punctuation one whole function instead of 2 complete different ones
//for loop in line 57 is off it's not matching the size of the string punchMarks[]
