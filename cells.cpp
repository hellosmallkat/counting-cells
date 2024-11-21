#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class Cellgrid {
    private:

        int rows, cols;

        bool *grid;

    public:

        int countCells4(int row, int col, int& counter); // counts cells in 4 directions
        int countCells8(int row, int col, int &counter); // counts cells in 8 directions
        int CountCells(int startRow, int startCol, int conn); // calls 4 or 8 direction count
        Cellgrid(const char *fname, int m, int n); // constructor

        ~Cellgrid();// destructor

        void print(); // print function
};
Cellgrid::Cellgrid(const char *fname, int m, int n) {

    rows = m; // number of rows
    cols = n; // number of columns


    grid = new bool[rows*cols];// grid of cells

    ifstream infile; // input file


    infile.open(fname); // open file


    for(int i = 0; i < rows; i++) { // read in grid

        int base = i * cols; // collect base of grid and allows cols to be read in
        for(int offset = 0; offset < cols; offset++) {// read in grid

            infile >> grid[base + offset]; // file into grid
        }
    }


    infile.close(); // close file
}

// destruct object where not implicit to the program
Cellgrid::~Cellgrid() 
{

    delete[] grid; // delete grid
}
int Cellgrid::CountCells(int startRow, int startCol, int conn)
{
    int counter = 0; // counter for cells
    if (conn == 4)
    {
        Cellgrid::countCells4( startRow,  startCol , counter); //4 direction count

    }
    else
    {
        Cellgrid::countCells8(startRow,  startCol , counter); // 8 direction count
    }
    return counter; // return counter
}

int Cellgrid::countCells4(int row, int col, int& counter)
{
    if((grid[row * rows + col] != 1) || row < 0 || col < 0 || row >= rows || col >= cols) // boreder checking and and cell isnt part of the cell
    {
        return 0;
    }
    //std::cout << row << " " << col << "\n";
    //std::cout << grid[row * rows + col];
    counter += 1; // counter plus one
       // std::cout << counter << " " ;
     //std::cout << grid[row * rows + col] << " " << row << " " << col  << "\n";
        grid[row * rows + col] = 0; // set the cell to "visted"

        return 0 + countCells4(row + 1, col,counter) + countCells4(row - 1, col ,counter) + countCells4(row, col + 1,counter ) + countCells4(row, col - 1,counter);// recursive call to check all 4 directions


}
int Cellgrid::countCells8(int row, int col, int& counter) // checks nsew and diagonals
{

    if(row < 0 || col < 0 || row >= rows || col >= cols || grid[row * cols + col] != 1) // border checking and cell cant be visted
    {
        return 0;
    }


        grid[row * cols + col] = 0; // cell marked as visted
        counter ++;

        return 0 + countCells8(row + 1, col,counter) + countCells8(row - 1, col,counter) + countCells8(row, col + 1,counter) + countCells8(row, col - 1,counter) +  countCells8(row + 1, col + 1,counter) + countCells8(row + 1, col - 1,counter) + countCells8(row - 1, col + 1,counter) + countCells8(row - 1, col - 1,counter);// recursive call to check all 8 directions


}


void Cellgrid::print() { // print function
    for(int i = 0; i < rows; i++) {
        int base = i * cols;
        std::cout << grid[base];
        for(int offset = 1; offset < cols; offset++) {
            std::cout << ' ' << grid[base + offset];
        }
        std::cout << std::endl;
    }
}

int main(int argc, char *argv[]) {

    int rows,cols,startRow, startCol, conn;


    char *fname = argv[1];


    rows = atoi(argv[2]); // number of rows in grid
    cols = atoi(argv[3]); // number of cols in grid
    startRow = atoi(argv[4]); // row of starting cell
    startCol = atoi(argv[5]); // col of starting cell
    conn = atoi(argv[6]); // connection type

    startRow = startRow - 1;
      startCol = startCol - 1;
      int conunter = 0;

    Cellgrid myGrid(fname, rows, cols);
    //myGrid.print();
   std::cout << myGrid.CountCells( startRow, startCol,  conn)<< "\n";
  //  myGrid.print();
}


/*<fname> File name for the grid of cells
<M>     Number of rows in the grid
<N>     Number of columns in the grid
<X>     Row of the starting cell
<Y>     Column of the starting cell
<CONN>  Connection type. Can be either `4` or `8`*/
