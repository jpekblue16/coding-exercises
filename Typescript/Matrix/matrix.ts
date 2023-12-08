export class Matrix {
  
  constructor(input:string) {

    var rowStrings:string[] = input.split('\n');
    console.log(rowStrings);

    this.rows = [];
    this.columns = [];

    for (var i:number=0;i<rowStrings.length;++i) { // i is row number
      var row:string[] = rowStrings[i].split(' '); // split the string into individual elements
      this.rows.push([]); // push an empty array to the row member variable

      // loop over the current row, create a new column if this is the first row
      for (var j:number = 0; j < row.length; ++j) {
        if(i == 0) {
          this.columns.push([+row[j]]); // need + to convert string element to number
        } else {
          this.columns[j].push(+row[j]); // column already exists, can push onto the existing array
        }
        this.rows[i].push(+row[j]); // row array is already added to the member variable so push onto it
      }
    }
      
  }

  rows:number[][];
  columns:number[][];
}