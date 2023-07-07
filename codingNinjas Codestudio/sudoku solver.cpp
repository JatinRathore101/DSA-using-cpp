#include<bits/stdc++.h>
using namespace std;

void disp(vector<vector<int>>& sudoku)
{
    for(auto it:sudoku)
    {
        for(auto gt:it)
        {
            cout<<gt<<"  ";
        }
        cout<<endl;
    }cout<<endl<<endl;
}

/* // TLE
unordered_set<int> allowed_digits(vector<vector<int>>& sudoku,int i,int j)
{
    unordered_set<int> digits={1,2,3,4,5,6,7,8,9};

    for(int k=0;k<9;k++)
    {
        digits.erase(sudoku[i][k]);
        digits.erase(sudoku[k][j]);
        digits.erase(sudoku[3*(i/3)+k/3][3*(j/3)+k%3]);
    }

    return digits;
}

bool solveSudokuUtil(vector<vector<int>>& sudoku)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(sudoku[i][j]==0)
            {
                unordered_set<int> digits=allowed_digits(sudoku,i,j);

                for(auto it:digits)
                {
                    sudoku[i][j]=it;
                    if(solveSudokuUtil(sudoku)){return true;}
                    else{sudoku[i][j]=0;}
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku)
{
    solveSudokuUtil(sudoku);
}
*/

bool isSafe(vector<vector<int>>& sudoku,int i,int j,int k)
{
    for(int l=0;l<9;l++)
    {
        if(sudoku[i][l]==k){return false;}
        if(sudoku[l][j]==k){return false;}
        if(sudoku[3*(i/3)+l/3][3*(j/3)+l%3]==k){return false;}
    }

    return true;
}

bool solveSudokuUtil(vector<vector<int>>& sudoku)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(sudoku[i][j]==0)
            {
                for(int k=1;k<=9;k++)
                {
                    if(isSafe(sudoku,i,j,k))
                    {
                        sudoku[i][j]=k;
                        if(solveSudokuUtil(sudoku)){return true;}
                        else{sudoku[i][j]=0;}
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku)
{
    solveSudokuUtil(sudoku);
}

int main()
{
    vector<vector<int>> sudoku={{3,0,6,5,0,8,4,0,0},{5,2,0,0,0,0,0,0,0},{0,8,7,0,0,0,0,3,1},{0,0,3,0,1,0,0,8,0},{9,0,0,8,6,3,0,0,5},{0,5,0,0,9,0,6,0,0},{1,3,0,0,0,0,2,5,0},{0,0,0,0,0,0,0,7,4},{0,0,5,2,0,6,3,0,0}};
    disp(sudoku);
    solveSudoku(sudoku);
    disp(sudoku);

    return 0;
}


