# Counting cells

 This code takes in a matrix filled with ones and zeros and counts the number of 1s in the matrix.

 The code runs off of
 <fname> File name for the grid of cells
<M>     Number of rows in the grid
<N>     Number of columns in the grid
<X>     Row of the starting cell
<Y>     Column of the starting cell
<CONN>  Connection type. Can be either `4` or `8`

Example input: ./cells grid.txt 8 8 3 4 4
9

0 0 0 1 1 1 0 0

0 0 0 1 1 1 0 0

0 0 0 1 1 1 0 0

1 1 1 0 0 0 0 0

1 1 1 0 0 0 0 0

0 0 0 1 1 1 0 0

1 1 0 1 1 1 0 0

1 1 0 1 1 1 0 0


The matrix would be inputted as a file instead of through the terminal.
