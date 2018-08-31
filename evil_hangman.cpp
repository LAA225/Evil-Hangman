#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

//Reads the dictionary and stores the words in an array of strings
void ReadFile(string dict[], string filename, int num_words)
{
    	string word;
    	ifstream words;
    	words.open(filename);
    	if(words.fail())
    		{
    			cout << "error opening file"<< endl;
    			exit (1);
    		}

    	for(int i=0; i<num_words; i++)
    	{
    		if(words.fail())break;
    		words >> word;
    		dict[i]=word;
    		//cout << word<< " ";
    	}
    	words.close();
    	
}

//displays the dictionary
void displayarr(string array[], int size_of_array)
{
	for(int i=0; i<size_of_array; i++)
	{
		if(array[i]=="")continue;
		cout << array[i]<<endl;
	}
}

//takes guess of user for letter and checks if only one letter is entered
char takeinput()
{
	string letter;
	cout << "enter your guess: "; cin>>letter;
	while(letter.length()!=1)
	{
		cout << "You entered more than one characters, please try again"<< endl;
		cout << "enter your guess: "; cin>> letter;
	}
	const char* word=letter.c_str();
	return word[0];
}

//removes all words with the guessed letter from the dictionary
void RemoveWords(string dict[], char input, int num_words)
{
	for(int i=0; i<num_words; i++)
	{
		for(int j=0; j<dict[i].length() ;j++)
		{
			if(dict[i][j]==input)
			{
				dict[i]="";
				break;
			}
		}
	}

}
int random3_7()
{
	int x;
	srand(time(NULL));
	x=(rand()%5)+3;
	return x;
}



int main(int argc, char const *argv[])
{
	if(argc!=4)
	{
		cout << "there was insufficient input "<<endl
		     << "enter in the format "<<endl
		     << "filename dictionary_to_be_used number_of_words codenum";

		return 0;  
	}
	else
	{
		string dictionary;
		int number_of_words, code;

		dictionary= argv[1];
		number_of_words=atoi(argv[2]);
		code =atoi(argv[3]);

		string dict[number_of_words];

		string chosen_word;
		int index;
		int size_of_chosenword;
		char letter;

		int tries=5;


		switch(code)
		{
			case 1: //file given is read
			
			ReadFile(dict,dictionary,number_of_words);
			displayarr(dict, number_of_words);
			break;

			case 2: //user is prompted for a guess and all words with that letter are removed.
			        //can choose not to display edited dictionary by commenting out displayarr
			
			ReadFile(dict, dictionary, number_of_words);
			
			size_of_chosenword=random3_7();
		    cout << "Word lenght: "<<size_of_chosenword<< endl;
			letter=takeinput();
		     
			RemoveWords(dict, letter, number_of_words);
			displayarr(dict, number_of_words);
		
			cout << "nope wrong guess."<<endl;
		
            break;

			case 3: //user is prompted for a guess according to number of tries. in this case 5.
			        //the words with that letter are removed.
			        //at the end of the tries, a word that fulfills the word lenght is displayed as the word
			
			ReadFile(dict,dictionary,number_of_words);
			
			size_of_chosenword=random3_7();
			cout << "Word lenght: "<< size_of_chosenword << endl;

			while(tries>0)
			{
				letter=takeinput();
				for(int i=0; i<number_of_words; i++)
				{
					for(int j=0; j<dict[i].length(); j++)
					{
						if(dict[i][j]==letter)
						{
							dict[i]="";
						}
					}
				}
				displayarr(dict,number_of_words);
				cout << "nope wrong input"<<endl;
				tries--;

			}
			for(int i=0; i<number_of_words; i++)
			{
				if(dict[i].length()==size_of_chosenword)
				{
					cout <<"you have lost the game, following was the word: " <<dict[i]<<endl;
					break;
				}
			}
			break;

			default:
			cout << "wrong code entered"<< endl;
			break;
		}

	}
	return 0;
}