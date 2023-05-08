// Author: Ahmed Gamal

// for this problem we will just implement what the problem says
// how to know that the current element is on the main diagonal or the secondary diagonal
// we will use the index of the element
// if the index of the element is equal to the index of the row then it is on the main diagonal
// if the index of the element is equal to the length of the matrix minus the index of the row then it is on the secondary diagonal
// we will use reduce function to sum the elements of the matrix this way

/**
 * @param {number[][]} mat
 * @return {number}
 */
var diagonalSum = function(mat) {
    // n: the length of the matrix
    const n = mat.length;

    // we will use reduce function to sum the elements of the matrix
    // r: the sum of the elements of the matrix (matrix accumulator)
    // row: the current row of the matrix
    // i: the index of the current row
    return mat.reduce((r, row, i) => {
        // we will use reduce function to sum the elements of the current row
        // c: the sum of the elements of the current row (row accumulator)
        // x: the current element of the current row
        // j: the index of the current element

        return r + row.reduce((c, x, j) => {
            // we will sum the current element with the sum of the current row if the current element is on the main diagonal or the secondary diagonal
            return c + x * (i === j || i + j == n - 1 ? 1 : 0);
        }, 0);
    }, 0);
};