#include<iostream>
#include<string>
#include<iomanip>
#include<cctype>
#include<ctime>
#include<cstdlib>

using namespace std;

int foundLetter(char, string, string&);
void displayLine(int, char);
void createmenu();
void space();
void howtoplay();
void gap();



int main()
{
    srand(time(0));

    createmenu();
    howtoplay();
    createmenu();

    string word;
    string words[]=
    {
        "nepal",
        "america",
        "japan",
        "india",
        "vietname",
        "china",
    };

   int totalwords=sizeof(words)/sizeof(words[0]);
   cout<<totalwords;




}




int foundLetter(char guess, string word, string &guessword)
{

    int matches=0;
    int len=word.length();

    for(int i=0; i<len; i++)
    {
        if (guess==guessword[i])
        {
            cout<<"\n The letter already exists \n";
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

