
// set of 4 is best deal per book

const BOOK_COST = 800;

const DISCOUNT = [0,1,.95,.9,.8,.75]; // amount to multiply total price by based on set size

function calculateSets(counts,totalBooks,maxSize) {

  var total = 0;
  var booksCounted = 0;
  var curCounts = new Array(...counts);

  do { // start of a new set

    var curSet = 0; // number of books in the current set

    // sort books by most copies to least each loop
    curCounts.sort((a,b) => b-a);

    console.log(curCounts);

    for (var i=0;i<maxSize;i++) {

      // if there is a copy of one of the books, and max set size is not reached, add book to set
      if (curCounts[i] > 0) {
        curSet++;
        curCounts[i]--;
      } else break; // if 0 of a book is found, done making sets
    }

    console.log(curCounts);

    if (curSet == 4 && curCounts[4] == 1 && totalBooks - booksCounted == 5) {
      // final set is a set of 4, with 1 more copy of the last book remaining, make a set of 5
      curSet++;
      curCounts[4]--;
    }

    if (curSet > 0) { // if a set was made, calculate discounted cost and add to total
      console.log(`made a set of ${curSet}`);
      total += curSet * BOOK_COST * DISCOUNT[curSet];
      booksCounted+=curSet;
    }

  } while(curSet > 0);

  return total;
}

export const cost = (books) => {
  if (books.length === 0) {
    return 0;
  }

  // create an array of counts for each volume
  // doesn't matter which volume is which
  var counts = [0,0,0,0,0];
  books.forEach((book) => {counts[book-1]++});

  // because discout for set of 4 is most efficient, 2 sets of 4 is better than 1 set of 5 and 1 set of 3
  // still need to calculate if a set of 5 is possible
  
  // try to make groups of 5 first
  var setOfFiveTotal = calculateSets(counts,books.length,5);
  console.log(`set of 5 total: ${setOfFiveTotal}`);

  // try to make groups of 4 first
  var setOfFourTotal = calculateSets(counts,books.length,4);
  console.log(`set of 4 total: ${setOfFourTotal}`);

  // return lower of 2 totals
  return (setOfFiveTotal < setOfFourTotal) ? setOfFiveTotal : setOfFourTotal;
};