#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

//Global Variables
vector<map<string, string>> Dictionary;
vector<string> englishWords;
vector<string> translatedWords;
string fileName = "grace";

// Load words dictionary
bool LoadDictionary()
{
	string line;
	string user = "Dictionary.txt";
	ifstream myfile(user);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			string word = "";
			string eword = "";
			string cword = "";

			int Counter = 0;

			// Iterate through a line to get all the words
			for (auto x : line)
			{
				if (x == ',')
				{
					//Add the english word to dictionary
					if (Counter == 0)
					{
						eword = word;

						//Move counter to next word
						Counter++;
					}
					//Add the cat word
					else
					{
						cword = word;

						//Update dictionary
						map<string, string>word_pair;
						word_pair.insert(make_pair(eword, cword));
						Dictionary.push_back(word_pair);

						//Reset counter
						Counter = 0;
					}
					word = "";
				}
				else {
					word = word + x;
				}
			}
		}
		myfile.close();
	}

	else cout << "Unable to open dictionary file";

	return true;
}

// Read from txt file
bool ReadInput_TXT_File()
{
	string user = fileName + ".txt";
	ifstream myfile(user);
	if (myfile.is_open())
	{
		string line;
		while (getline(myfile, line))
		{
			string word = "";
			for (auto x : line)
			{
				if (x == ' ')
				{
					englishWords.push_back(word);
					word = "";
				}
				else {
					word = word + x;
				}
			}
		}
		myfile.close();
	}

	else cout << "Unable to open input file";

	return true;
}

// Translate input
bool TranslateWords(string Word)
{
	for (int dictionary = 0; dictionary < Dictionary.size(); dictionary++)
	{
		if (Word == Dictionary[dictionary].begin()->first)
		{
			cout << Dictionary[dictionary].begin()->second << endl;
			translatedWords.push_back(Dictionary[dictionary].begin()->second);
		}
	}

	return true;
}

// Write to txt file
bool WriteOutput_TXT_File()
{
	string user = fileName + "_lolcat.txt";
	ofstream myfile(user);
	if (myfile.is_open())
	{
		int Count = 0;
		for (int translated = 0; translated < translatedWords.size(); translated++)
		{
			if (Count > 10)
			{
				myfile << "\n";
				Count = 0; //Reset the word count
			}
			myfile << translatedWords[translated] + " ";
			Count++;
		}
		myfile.close();
	}
	else
	{
		cout << "Unable to open output lolcat file";
	}

	return true;
}

//The program begins here
int main()
{
	//Load dictionary
	LoadDictionary();
	// Read from txt input file
	ReadInput_TXT_File();
	// Translate input
	for (int i = 0; i < englishWords.size(); i++)
	{
		TranslateWords(englishWords[i]);
	}
	// Write to txt file
	WriteOutput_TXT_File();


	// ToDo
	// You can add user interractions here
	
	//example:
	string word;
	cout<<"Input  Word to translate"<<endl;
	cin>>word;
	string transWord="";
		for (int dictionary = 0; dictionary < Dictionary.size(); dictionary++)
	{
		if (word == Dictionary[dictionary].begin()->first)
		{
			transWord=Dictionary[dictionary].begin()->second;
		}
	}

	cout<<"Translation :"<<transWord<<endl;
	
	system("pause");
	return 0;
}