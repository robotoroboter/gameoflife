/*
        # Conway's Game of Life #

    The universe of the Game of Life is an infinite, two-dimensional
    orthogonal grid of square cells, each of which is in one of two
    possible states, live or dead (or populated and unpopulated, respectively).
    Every cell interacts with its eight neighbours, which are the cells that
    are horizontally, vertically, or diagonally adjacent. At each step in time,
    the following transitions occur: 

    - Any live cell with fewer than two live neighbours dies, as if by underpopulation.
    - Any live cell with two or three live neighbours lives on to the next generation.
    - Any live cell with more than three live neighbours dies, as if by overpopulation.
    - Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
*/

#include <iostream> //for debugging
#include <vector> //for vector/matrix of cells


int matrixHeight = 16;
int matrixWidth = 16;
std::vector<std::vector<int>> matrix(matrixHeight, std::vector<int> (matrixWidth )); //the matrix that the cells will live on

int liveNeighboursNumber(int x, int y){ //check the number of live neighbours (between 0 and 8) for a cell with given coords (x,y)
    int liveNeighbours = 0;
    for (int i=x-1; i<=x+1; i++){
        for (int j=y-1; j<=y+1; j++){
            if ((i>=0 and i<matrixWidth) and (j>=0 and j<matrixHeight))
                if (matrix[j][i]==1 and not(j==y and i==x)){
                    liveNeighbours++;
                }
        }
    }
    return liveNeighbours;
}

int main(){
  
    for (auto &line : matrix){ //fill the whole matrix with zeros (dead cells)
        std::fill(line.begin(), line.end(), 0);
    }


    matrix[7][8] =1;
    matrix[9][8] =1;
    matrix[8][8] =1;
    matrix[8][7] =1;
    matrix[8][9] =1;
    
    while(true){    //game loop
        for (int j = 0; j<matrixHeight ; j++){   //print the matrix
            for (int i = 0; i<matrixWidth; i++){
                std::cout<<matrix[j][i];
            }
            std::cout<<"\t";
            for (int i = 0; i<matrixWidth; i++){ //print the alive neighbours number
                std::cout<<liveNeighboursNumber(i,j);
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;

        auto newMatrix = matrix;   //creating a copy of matrix whill will be the matrix in the next generation

        for (int j = 0; j<matrixHeight ; j++){   //update the cells based on the Conway's Game of Life rules
            for (int i = 0; i<matrixWidth; i++){
                int liveNeighbours= liveNeighboursNumber(i,j);
                if (matrix[j][i]==1){                           //if the cell is live..
                    if (liveNeighbours<2 or liveNeighbours>3)   //if the cell has less than 2 or more than 3 live neighbours...
                        newMatrix[j][i] = 0;                    //it dies in the next generation
                }
                else if (liveNeighbours == 3)   //if the cell is dead but it has exactly 3 live neighbours...
                    newMatrix[j][i] = 1;        //it goes live in the next generation
            }
        }
        matrix = newMatrix; //applying the next generation
        getchar();
    }

    std::cout<<" +-+-+-+-+-+-+-+-+ reached the program's end +-+-+-+-+-+-+-+-+ "<<std::endl;
} 
