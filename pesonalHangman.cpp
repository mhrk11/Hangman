#include<iostream>
#include<string>
#include<iomanip>
#include<cctype>
#include<ctime>
#include<cstdlib>

using namespace std;

const int MAX_TRIES = 5;


int foundLetter(char, string, string&);
void displayLine(int, char);
void createmenu();
void space();
void howtoplay();
void gap();
void randomGuess(string, string&);

int main()
{
    srand(time(0));

    createmenu();
    howtoplay();
    createmenu();
//variables
    char letter;
    char ch;
    string word;
    int guesses=0;
    string words[]=
    {
        "nepal",
        "america",
        "japan",
        "india",
        "vietname",
        "china",
    };

//random word assign
   int totalwords=sizeof(words)/sizeof(words[0]);
   space();
   word=words[rand()%totalwords];
   space();

   string unknown(word.length(), '*');

//Guessing starts from here
   randomGuess(word, unknown);
do
{

gap();

    cout<<"Word: "<<unknown<<endl;
gap();

    cout<<"Number of Lives left: "<<MAX_TRIES-guesses<<endl;
gap();


   cout<<"Guess a letter: "; cin >> letter;

   if (foundLetter(letter, word, unknown)==0)
   {
        guesses++;
        space();
        gap();
        cout<<"Try Again."<<endl;

   }
   else
   {
    space();
    gap();

    cout<<"Found a letter.";
   }
   space();


   if (unknown==word)
    {space();
        gap();


    cout<<"YOU WON.";
        break;
    }

    cin.get(ch);
    cin.ignore();
    createmenu();
    space();
    space();


} while(guesses < MAX_TRIES);

if (guesses==5)
{
    space();
    gap();
    cout<<"You went out of lives..."<<endl;
    space();
    gap();

    cout<<"The Word was: "<<word;

    space();

}


}




int foundLetter(char guess, string word, string &guessword)
{

    int matches=0;
    int len=word.length();

    for(int i=0; i<len; i++)
    {
        if (guess==guessword[i])
        {
            space();
            gap();

            cout<<"The letter already exists ";
            return 0;
        }
        if(guess==word[i])
        {
            guessword[i]=guess;
            matches++;
        }
    }
return matches++;
}
void space()
{
    cout<<"\n\n";
}

void displayLine(int n, char symbol)
{
    cout<<"\t\t";
    for(int i=0; i<n; i++)
        cout<<symbol;
    cout<<endl;

}

void gap()
{

    cout<<"\t\t\t";
}

void createmenu()
{
    system("CLS");
    displayLine(80, '_');
    space();
    cout<<"\t\t\t\t\t\tWelcome To Hangman\t\t\t";
    space();
    displayLine(80, '_');


}

void howtoplay()
{
    char ch;

    space();
    space();
    gap();
    cout<<"How to Play";
    space();
    gap();
    cout<<"1.Guess a letter of the country that is presented.\n";
    gap();
    cout<<"2.You have five tries; with every wrong guess you lose a life. \n";
    space();

    cout<<"Press any Key to Continue...";
    cin.get(ch);

}


void randomGuess(string word, string& unknownWord)
{
    int letter = rand()%(word.length());
    unknownWord[letter]=word[letter];

}
