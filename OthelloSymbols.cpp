#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Grid8x8Symbols.hpp" //File that contains class Grid8x8
using namespace std; 

void game();
void rules();
void mainMenu();
void author();

int main()
{  
    //Starting the game
    mainMenu();
}

void mainMenu ()
{
    char input;
    //Main menu options
    cout<<"\n\t Othello by Dieto"<<endl;
    cout<<"P. Play"<<endl;
    cout<<"R. Rules"<<endl;
    cout<<"A. Author"<<endl;
    cout<<"Q. Quit"<<endl;
    
    //Main menu loop that allows to make a choice
    while(true)
    {
        cout<<"Make your choice: ";
        cin >> input;
        switch(input)
        {
            case 'P':
                game();
                break;
            case 'R':
                rules();
                break;
            case 'A':
                author();
                break;
            case 'Q':
                exit(0);
                break;
            default: 
                cout<<"Wrong input!"<<endl;
        }
    }
}

void game()
{
    string input = "";
    int TotalRows = 8;
    int TotalColumns = 8;
    int RowNumber {};
    int ColumnNumber {};
    Grid8x8 grid;
    //New Game/Continue menu
    
    while(true)
    {
        cout<<"\tOthello by Dieto\n"<<endl;
        cout<<"N. New Game"<<endl;
        cout<<"C. Continue"<<endl;
        cout<<"Make your choice: ";
        cin >> input;
        if (input == "N")
        {
            grid.Render();
            break;
        }
        else if (input == "C")
        {
            grid.load();
            grid.Render();
            break;
        }
        else
        {
            cout<<"Wrong input!"<<endl;
        }
    }
    
    // Game Loop
    while(true)
    {
        
        //While loop that validates coordinates input
        //and saves it in case it's valid
        while(true)
        {
            //if statement that skips turn if there are any legal moves avaible
            if (grid.CheckMoveBlack() == false)
            {
                cout<<"Black has no legal moves. Turn skipped."<<endl;
                break;
            }
            bool InputValid = false;
            cout<<"(Enter M to go back to the main menu)"<<endl;
            cout<<"Enter the row coordinate (Black): ";
            cin >> input;
            if (input == "M")
            {
                grid.save();
                mainMenu();
            }
            for (int i = 0; i < TotalRows; i++)
            {
                if(input == to_string(i))
                {
                    InputValid = true;
                }
            }
            if (InputValid == false)
            {
                cout<<"Input is invalid!"<<endl;
                continue;
            }
            else 
            {
                RowNumber = stoi(input);
            }
            InputValid = false;
            cout<<"(Enter M to go back to the main menu)"<<endl;
            cout<<"Enter the column coordinate (Black): ";
            cin >> input; 
            if (input == "M")
            {
                grid.save();
                mainMenu();
            }
            for (int i = 0; i < TotalColumns; i++)
            {
                if(input == to_string(i))
                {
                    InputValid = true;
                }
            }
            if (InputValid == false)
            {
                cout<<"Input is invalid!"<<endl;
                continue;
            }
            else 
            {
                ColumnNumber= stoi(input);
                
            }
            /*BlackTurn tries to execute the move
            and returns true if it succeds
            (returns false if e.g. the move didn't outflank the opponent)*/
            if(grid.BlackTurn(RowNumber, ColumnNumber,true) == true) //Black's turn happens 
            {
                break;
            }
        }
        grid.Render(); //printing the board
        grid.CheckWinner();//checking if the game is over
        //Below same logic but for white player
        while(true)
        {
            if (grid.CheckMoveWhite() == false)
            {
                cout<<"White has no legal moves. Turn skipped."<<endl;
                break;
            }
            bool InputValid = false;
            cout<<"(Enter M to go back to the main menu)"<<endl;
            cout<<"Enter the row coordinate (White): ";
            cin >> input;
            if (input == "M")
            {
                mainMenu();
            }
            for (int i = 0; i < TotalRows; i++)
            {
                if(input == to_string(i))
                {
                    InputValid = true;
                }
            }
            if (InputValid == false)
            {
                cout<<"Input is invalid!"<<endl;
                continue;
            }
            else 
            {
                RowNumber = stoi(input);
            }
            InputValid = false;
            cout<<"(Enter M to go back to the main menu)"<<endl;
            cout<<"Enter the column coordinate (White): ";
            cin >> input;
            if (input == "M")
            {
                mainMenu();
            } 
            for (int i = 0; i < TotalColumns; i++)
            {
                if(input == to_string(i))
                {
                    InputValid = true;
                }
            }
            if (InputValid == false)
            {
                cout<<"Input is invalid!"<<endl;
                continue;
            }
            else 
            {
                ColumnNumber= stoi(input);
                
            }
            if(grid.WhiteTurn(RowNumber, ColumnNumber,true) == true) 
            {
                break;
            }
        }
        grid.Render(); //printing the board
        grid.CheckWinner();//checking if the game is over
    }
}
//rules submenu function
void rules() 
{
    fstream rules;
    char input;
    string line;
    cout<<"\n\t Othello by Dieto"<<endl;
    cout<<endl;
    //Printing rules
    rules.open("rules.txt",ios::in);
    while(getline(rules,line))
    {
        cout<<line<<endl;
    }
    rules.close();
    cout<<"\nM. Main menu"<<endl;
    cout<<"Make your choice: ";
    cin >> input;
    //loop that gives choice to go back to the main menu
    while(true)
    {
        switch(input)
        {
            case 'M':
                mainMenu();
                break;
            default :
                cout<<"Wrong input!"<<endl;
        }
    }
}
//author submenu function
void author() 
{
    char input;
    cout<<"\n\t Othello by Dieto"<<endl;
    cout<<"\nGame made by AGH junior year student Paweł Urban."<<endl;
    cout<<"It's my biggest project so far, hope you enjoy playing."<<endl;
    cout<<"M. Main Menu"<<endl;
    while(true)
    {
        cout<<"\nMake your choice: ";
        cin >> input;
        switch(input)
        {
            case 'M':
                mainMenu();
                break;
            default: 
                cout<<"Wrong input!"<<endl;
        }
    }
}
