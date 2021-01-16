#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <unordered_map>

using namespace std;

class Game
{
    private:
        int userScore, compScore, counter;
        vector<vector<int>> moveMap;//Stores the user*computer tabulation of rock papaer scissor
        unordered_map<int, string> moveName; //To store the moves name {rock,paper,scissor}
        unordered_map<int, string>::iterator itr;

        void winCheck()
        {
            if (counter==3)//when 3 rounds have occured
            {
                if (userScore>compScore)
                {
                    cout<<"Winner is User\n";
                }
                else if (compScore>userScore)
                {
                    cout<<"Winner is Computer\n";
                }
                else
                {
                    cout<<"It's a draw\n";
                }

                cout<<"\n!!!!! SCORE BOARD !!!!!\n";
                cout<<"User = "<<userScore<<"\n";
                cout<<"Computer = "<<compScore<<"\n";
                cout<<"!!!!!!!!!!!!!!\n";

                cout<<"\n*******\n";
                cout<<"Now please either restart or quit game\n";
                cout<<"*******\n";

            }

        }

public:
    Game()
    {
        userScore = 0;
        compScore = 0;
        counter = 0;
        moveMap = vector<vector<int>>(3);
        for (int i = 0; i < 3; i++)
        {
            moveMap[i] = vector<int>(3, 0);
        }
        moveMap[0][2] = 1; //for move rock(user) and scissors(comp)
        moveMap[1][0] = 1; //for move paper(user) and rock(comp)
        moveMap[2][1] = 1; //for move scissor(user) and paper(comp)
        moveName.insert(pair<int, string>(0, "Rock"));
        moveName.insert(pair<int, string>(1, "Paper"));
        moveName.insert(pair<int, string>(2, "Scissor"));
    }

    void move(int user)
    {
        if (counter < 3)
        {
            srand(time(NULL));
            int comp = (rand() % 3);
            cout << "--------\n";
            cout << "User -> " << moveName.find(user)->second << " \n";
            cout << "Computer -> " << moveName.find(comp)->second << " \n";
            cout << "--------\n";
            // cout<<comp<<" "<<user<<'\n';
            if (moveMap[user][comp])
            {
                cout << "User got a point\n";
                userScore++;
                counter++;
            }
            else if (user == comp)
            {
                cout << "No point as same move by both\n";
                counter++;
            }
            else
            {
                cout << "Computer got a point\n";
                compScore++;
                counter++;
            }


        }
        else
        {
            cout<<"*******\n";
            cout<<"Please either restart or quit game\n";
            cout<<"*******\n";
        
        }
    }

    void checkWinner()
    {
        winCheck();
    }
};

int main()
{
    Game *RPS = new Game();
    bool stop = false;
    int input;
    
    while (!stop)
    {
        cout << "Choose your move\n";

        cout << "1. Rock\n2. Paper\n3. Scissor\n4. Restart\n5. Quit\n";
        cin >> input;
        switch (input)
        {
        case 1:
            system("CLS");
            RPS->move(input - 1);
            
            break;
        case 2:
            system("CLS");
            RPS->move(input - 1);
            
            break;
        case 3:
            system("CLS");
            RPS->move(input - 1);
            
            break;
        case 4:
            system("CLS");
            RPS = new Game();
            
            break;
        case 5:
            system("CLS");
            stop = true;
            break;
        default:
            system("CLS");
            cout << "Invalid move\n";
            break;
        }
        RPS->checkWinner();
        if (stop)
        {
            system("CLS");
            
        }
        
        // system("CLS");

    }
}