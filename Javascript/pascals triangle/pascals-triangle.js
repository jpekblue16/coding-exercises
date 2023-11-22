
// create the next row based on the previous
const nextRow = (prevRow) => {
  var newRow = [1];
  for (let i=0;i<prevRow.length-1;i++) {
    newRow.push(prevRow[i]+prevRow[i+1]);
  }
  newRow.push(1);
  return newRow;
}

// create all rows of the triangle up to the given number of rows
export const rows = (numRows) => {

  // trivial case
  if (numRows==0) return [];

  // base row
  var triangle = [[1]];
  for (let i=0; i<numRows-1;i++) {
    triangle.push(nextRow(triangle[i]));
  }
  
  return triangle;
};