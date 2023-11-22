// solution for exercise to create an object containing the list of all students in each grade (grade -> array of names)

export class GradeSchool {
  constructor() {
    this.school = {};
    this.names = {};
  }
  
  roster() {
    return structuredClone(this.school);
  }
  add(name,grade) {
    if(!this.school[grade]) this.school[grade] = [];
    
    // if name already exists
    if (this.names[name]) {
      // remove from current grade
      var curGrade = this.names[name];
      this.school[curGrade] = this.school[curGrade].filter((item) => item != name);
    }
    this.school[grade].push(name);
    this.names[name] = grade;
    this.school[grade].sort();
    console.log(this.school);
    console.log(this.names);
  }
  grade(grade) {
    var result = []
    if (this.school[grade]) {
      result = new Array(...this.school[grade]);
    }
    const returnVal = result;
    return returnVal;
  }
}