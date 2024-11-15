#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std; 
// Class Grid8x8 that is the backbone of the whole game
class Grid8x8 
{   private: 
    //Vector grid that will remember the state of the game board
    vector<vector<string>> grid;
    int TotalRows {8};
    int TotalColumns {8};
    public:
    //Constructor, it fills in grid with a starting position
    Grid8x8()
    {
        //Creating vector row containing 8 "□" symbols
        vector<string> row;
        for(int j = 0; j< TotalColumns; j++)
        {
            row.push_back("□");  // ○ □ ● - symbols used in the game
        }
        //Inserting vector row to the grid 8 times 
        for(int i = 0; i < TotalRows; i++)
        {
            grid.push_back(row);
        }
        //Setting starting pattern in the middle of the board
         grid[3][3] = "●";
         grid[3][4] = "○";
         grid[4][3] = "○";
         grid[4][4] = "●";
        
    }
    // Method Render() which when called, updates the game board
    void Render()
    {   
        cout<<"\n\t Othello by Dieto \n\n";
       for (int row = 0; row < TotalRows; row++)
       {
            //Printing row number at the start of the row
            cout<<row<<" ";
            //Printing the row
            for (int column = 0; column < TotalColumns; column++)
            {
                cout<<grid[row][column]<<" ";
            }
            cout<<endl;
       }
       //Printing column numbers at the bottom of the grid
       cout<<"  ";
       for (int column= 0; column < TotalColumns; column++)
       {
            cout<<column<<" ";
       }
       cout<<"\n\n";
    }
    //Method WhiteTurn() which places a white circle and also changes the color
    //of already existing black circles according to the rules of Othello 
    bool WhiteTurn (int RowNumber, int ColumnNumber)
    {
        bool outFlanked = false;
        bool squareNotTaken = false;
        //Checking if a square with received coordinates is not already taken
        //and if not, setting squareNotTaken to true
        if (grid[RowNumber][ColumnNumber]  == "□" )
        {
            squareNotTaken = true;
        }
        else 
        {
            //Handling the taken square scenario
            cout <<"This square is already taken!"<<endl;
            return false;
        }
        //Below lies logic responsible for changing black circles to white 
        //when a new white circle is placed
        if(squareNotTaken == true)
        {
        //Loop that checks if there is a line of black circles that 
        //ends with a white circle downwards from the placed white circle
        //if so it changes the color of the black circles in the line to white
        //and changes outFlanked value to true 
            for (int i = ColumnNumber +1; i < TotalColumns; i++)
            {
                if (grid[RowNumber][ColumnNumber +1] == "●")
                {
                    break;
                }
                if (grid[RowNumber][i] == "□") 
                {
                    break;
                }
                if (grid[RowNumber][i] == "●")
                {
                    for (int j = i; j > ColumnNumber;j--)
                    {
                        grid[RowNumber][j] = "●";
                    }
                    outFlanked = true;
                }
            }
            //Same logic as in the previous loop but upwards
            for (int i = ColumnNumber -1; i >= 0; i--)
            {
                if (grid[RowNumber][ColumnNumber -1] == "●")
                {
                    break;
                }
                if (grid[RowNumber][i] == "□") 
                {
                    break;
                }
                if (grid[RowNumber][i] == "●")
                {
                    for (int j = i; j < ColumnNumber;j++)
                    {
                        grid[RowNumber][j] = "●";
                    }
                    outFlanked = true;
                }
            }
            //Leftwards
            for (int i = RowNumber -1; i >= 0; i--)
            {
                if (grid[RowNumber-1][ColumnNumber] == "●")
                {
                    break;
                }
                if (grid[i][ColumnNumber] == "□") 
                {
                    break;
                }
                if (grid[i][ColumnNumber] == "●")
                {
                    for (int j = i; j < RowNumber;j++)
                    {
                        grid[j][ColumnNumber] = "●";
                    }
                    outFlanked = true;
                }
            }
            //Rightwards
            for (int i = RowNumber +1; i < TotalRows; i++)
            {
                if (grid[RowNumber+1][ColumnNumber] == "●")
                {
                    break;
                }
                if (grid[i][ColumnNumber] == "□") 
                {
                    break;
                }
                if (grid[i][ColumnNumber] == "●")
                {
                    for (int j = i; j > RowNumber;j--)
                    {
                        grid[j][ColumnNumber] = "●";
                    }
                    outFlanked = true;
                }
            }
            //diagonally right-down
            for (int i = RowNumber +1,j = ColumnNumber + 1; i < 8 && j < 8; i++,j++)
            {
                if (grid[RowNumber+1][ColumnNumber+1] == "●")
                {
                    break;
                }
                if (grid[i][j] == "□") 
                {
                    break;
                }
                if (grid[i][j] == "●")
                {
                    for (int k = i, l = j; k > RowNumber && l > ColumnNumber ;k--,l--)
                    {
                        grid[k][l] = "●";
                    }
                    outFlanked = true;
                }
            }
            //diagonally left-up
            for (int i = RowNumber -1,j = ColumnNumber - 1; i >= 0 && j >= 0; i--,j--)
            {
                if (grid[RowNumber-1][ColumnNumber-1] == "●")
                {
                    break;
                }
                if (grid[i][j] == "□") 
                {
                    break;
                }
                if (grid[i][j] == "●")
                {
                    for (int k = i, l = j; k < RowNumber && l < ColumnNumber ;k++,l++)
                    {
                        grid[k][l] = "●";
                    }
                    outFlanked = true;
                }
            }
            //diagonally right-up
            for (int i = RowNumber -1,j = ColumnNumber + 1; i >= 0 && j < TotalColumns; i--,j++)
            {
                if (grid[RowNumber-1][ColumnNumber+1] == "●")
                {
                    break;
                }
                if (grid[i][j] == "□") 
                {
                    break;
                }
                if (grid[i][j] == "●")
                {
                    for (int k = i, l = j; k < RowNumber && l > ColumnNumber ;k++,l--)
                    {
                        grid[k][l] = "●";
                    }
                    outFlanked = true;
                }
            }
            //diagonally left-down
            for (int i = RowNumber +1,j = ColumnNumber - 1; i < TotalRows && j >= 0; i++,j--)
            {
                if (grid[RowNumber+1][ColumnNumber-1] == "●")
                {
                    break;
                }
                if (grid[i][j] == "□") 
                {
                    break;
                }
                if (grid[i][j] == "●")
                {
                    for (int k = i, l = j; k > RowNumber && l < ColumnNumber ;k--,l++)
                    {
                        grid[k][l] = "●";
                    }
                    outFlanked = true;
                }
            }
        }
        //if all conditions were met the white circle is placed
        if(outFlanked == true && squareNotTaken == true)
        {
            grid[RowNumber][ColumnNumber]  = "●";
            return true;
        }
        //if not it returns false
        cout <<"You must outflank your opponent!"<<endl;
        return false;  
    }   
    //Essentialy the same logic that White uses
    //but for black circles
    bool BlackTurn (int RowNumber, int ColumnNumber)
    {
        bool outFlanked = false;
        bool squareNotTaken = false;
        if (grid[RowNumber][ColumnNumber]  =="□")
        {
            squareNotTaken = true;
        }
        else 
        {
            cout <<"This square is already taken!"<<endl;
            return false;
        }
        if (squareNotTaken == true)
        {
            for (int i = ColumnNumber +1; i < TotalColumns; i++)
            {
                if (grid[RowNumber][ColumnNumber +1] == "○")
                {
                    break;
                }
                if (grid[RowNumber][i] == "□") 
                {
                    break;
                }
                if (grid[RowNumber][i] == "○")
                {
                    for (int j = i; j > ColumnNumber;j--)
                    {
                        grid[RowNumber][j] = "○";
                    }
                    outFlanked = true;
                }
            }
            for (int i = ColumnNumber -1; i >= 0; i--)
            {
                if (grid[RowNumber][ColumnNumber -1] == "○")
                {
                    break;
                }
                if (grid[RowNumber][i] == "□") 
                {
                    break;
                }
                if (grid[RowNumber][i] == "○")
                {
                    for (int j = i; j < ColumnNumber;j++)
                    {
                        grid[RowNumber][j] = "○";
                    }
                    outFlanked = true;
                }
            }
            for (int i = RowNumber -1; i >= 0; i--)
            {
                if (grid[RowNumber-1][ColumnNumber] == "○")
                {
                    break;
                }
                if (grid[i][ColumnNumber] == "□") 
                {
                    break;
                }
                if (grid[i][ColumnNumber] == "○")
                {
                    for (int j = i; j < RowNumber;j++)
                    {
                        grid[j][ColumnNumber] = "○";
                    }
                    outFlanked = true;
                }
            }
            for (int i = RowNumber +1; i < TotalRows; i++)
            {
                if (grid[RowNumber+1][ColumnNumber] == "○")
                {
                    break;
                }
                if (grid[i][ColumnNumber] == "□") 
                {
                    break;
                }
                if (grid[i][ColumnNumber] == "○")
                {
                    for (int j = i; j > RowNumber;j--)
                    {
                        grid[j][ColumnNumber] = "○";
                    }
                    outFlanked = true;
                }
            }
            for (int i = RowNumber +1,j = ColumnNumber + 1; i < TotalRows && j < 8; i++,j++)
            {
                if (grid[RowNumber+1][ColumnNumber+1] == "○")
                {
                    break;
                }
                if (grid[i][j] == "□") 
                {
                    break;
                }
                if (grid[i][j] == "○")
                {
                    
                    for (int k = i, l = j; k > RowNumber && l > ColumnNumber ;k--,l--)
                    {
                        grid[k][l] = "○";
                    }
                    outFlanked = true;
                }
            }
            for (int i = RowNumber -1,j = ColumnNumber - 1; i >= 0 && j >= 0; i--,j--)
            {
                if (grid[RowNumber-1][ColumnNumber-1] == "○")
                {
                    break;
                }
                if (grid[i][j] == "□") 
                {
                    break;
                }
                if (grid[i][j] == "○")
                {
                    
                    for (int k = i, l = j; k < RowNumber && l < ColumnNumber ;k++,l++)
                    {
                        grid[k][l] = "○";
                    }
                    outFlanked = true;
                }
            }
            for (int i = RowNumber -1,j = ColumnNumber + 1; i >= 0 && j < TotalColumns; i--,j++)
            {
                if (grid[RowNumber-1][ColumnNumber+1] == "○")
                {
                    break;
                }
                if (grid[i][j] == "□") 
                {
                    break;
                }
                if (grid[i][j] == "○")
                {
                    
                    for (int k = i, l = j; k < RowNumber && l > ColumnNumber ;k++,l--)
                    {
                        grid[k][l] = "○";
                    }
                    outFlanked = true;
                }
            }
            for (int i = RowNumber +1,j = ColumnNumber - 1; i < 8 && j >= 0; i++,j--)
            {
                if (grid[RowNumber+1][ColumnNumber-1] == "○")
                {
                    break;
                }
                if (grid[i][j] == "□") 
                {
                    break;
                }
                if (grid[i][j] == "○")
                {
                    
                    for (int k = i, l = j; k > RowNumber && l < ColumnNumber ;k--,l++)
                    {
                        grid[k][l] = "○";
                    }
                    outFlanked = true;
                }
            }
        }
        if(outFlanked == true && squareNotTaken == true)
        {
            grid[RowNumber][ColumnNumber] = "○";
            return true;
        }
        cout<<"You must outflank your opponent!"<<endl;
        return false;
    }
    //Method that checks if the board is completely filled and if so
    //announces the winner
    void CheckWinner()
    {
        int whiteCounter = 0;
        int blackCounter = 0;
        bool gameFinished = true;
        for (int row = 0; row < TotalRows;row++)
        {
            for(int column = 0; column < TotalColumns; column++)
            {
                if(grid[row][column] == "□")
                {
                    gameFinished = false;
                    break;
                }
                else if (grid[row][column] == "○")
                {
                    blackCounter++;
                }
                else
                {
                    whiteCounter++; 
                }
            }
            if (gameFinished == false)
            {
                break;   
            }
        }
        if(gameFinished == true)
        {
            cout<<"\t The game is over"<<endl;
            cout<<"White: "<<whiteCounter<<"\tBlack: "<<blackCounter<<endl;
            if (blackCounter>whiteCounter)
            {
                cout<<"\n\t Black won!\n"<<endl;
                exit(0);
            }
            else if (whiteCounter>blackCounter)
            {
                cout<<"\n\t White won!"<<endl;
                exit(0);
            }
            else
            {
                cout<<"Tie!"<<endl;
                exit(0);
            }
        }
    }
    void save()
    {
        string line;
        fstream saveFile;
        saveFile.open("saveFile.txt",ios::out);
        for (int i = 0; i < TotalColumns; i++)
        {
            for (int j = 0; j < TotalColumns; j++)
            {
                line += grid[i][j];
                line += " ";
            }
            saveFile << line << endl;
            line = "";
        }
        saveFile.close();
    }
    void load()
    {
        fstream loadFile;
        if (loadFile.good() == false)
        {
            cout<<"SaveFile doesn't exist!";
            exit(0);
        }
        loadFile.open("saveFile.txt",ios::in);
        for (int i = 0; i < TotalColumns; i++)
        {
            for (int j = 0; j < TotalColumns; j++)
            {
                loadFile >> grid[i][j];
            }
        }
        loadFile.close();
    }
};