#include <iostream>
#include<string>
using namespace std;

class Hangman{
    private:
    string word;
    //int numberOfGuesses=6;
    int hits=0;
    string boards = "";
    
public:
    Hangman(string w){
        word = w;
        for(int i=0;i<word.size();i++)
        {
            boards=boards+"_";
        }
        cout << boards << endl;
    }    

    
    void checkInput(char p)
    {
        bool takeHit = true;
        for(int i=0;i<word.size();i++)
        {
            if(word[i]==p)
            {
            boards[i]=p;
            takeHit = false;
            }
        }
        if (takeHit){
            hits ++;
        }
    }

    bool gameOverCheck()
    {
        if(word == boards) { cout << "CONGRATS YOU HAVE WON THE GAMEE" << endl; return true;}
        return (hits >= 7) ? true : false;
    }

void displayBoard()
{
    string HangManBodyParts = "0|/\\";
    
    for(int i=0;i<hits;i++)
    {
        if(i>=2)
          {
              cout<<"<";
              cout << HangManBodyParts[i-1];
              i++;
          }
          else{
            cout<<HangManBodyParts[i];
          } 
          
        if(i>=2)
        {
            cout<<">";
            i=i+1;
        }
        else cout << endl;
        
    }
    cout << endl << endl;
    cout<<boards<<endl << endl;
}
    
};

int main() {
    bool gameOver = false;
    string word;
    cout<<"Enter the word to be guessed."<<endl;
    cin >> word;
    cout<<"**********************************"<<endl;
    cout<<"********WELCOME TO HANGMAN********"<<endl;
    cout<<"**********************************"<<endl;
    cout<<"Let's start......";
    Hangman hangman(word);
    char p1_guess;
    while (!gameOver){
        cout << "Enter the letter: ";
        cin >> p1_guess;
        hangman.checkInput(p1_guess);
        gameOver = hangman.gameOverCheck();
        hangman.displayBoard();
    }
        cout << gameOver;
    return 0;
}
