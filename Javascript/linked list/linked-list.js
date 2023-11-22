//
// This is only a SKELETON file for the 'Linked List' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

class Node {
  constructor(value=0) {
    this.value = value;
    this.prev = null;
    this.next = null;
  }
}

export class LinkedList {
  constructor() {
    this.nodeCount=0;
    this.first = null;
    this.last = null
  }
  
  // add a new node to the end of the list
  push(value) {
    var newNode = new Node(value);
    if(this.nodeCount == 0) {
      this.first = newNode;
      this.last = newNode;
    } else {
      newNode.prev = this.last;
      this.last.next = newNode;
      this.last = newNode;
    }
    this.nodeCount++;
  }

  // remove and return the last element in the list
  pop() {
    var result = this.last.value;
    if(this.nodeCount == 1) {
      this.first = null;
      this.last = null;
    } else {
      // more than 1 node
      this.last.prev.next = null;
      this.last = this.last.prev;
    }
    
    this.nodeCount--;
    return result;
  }

  // removing and returning the frontmost element and shift all elements one to the front
  shift() {
    var result = this.first.value;
    if (this.nodeCount == 1) {
      this.first = null;
      this.last = null;
    } else {
      this.first.next.prev = null;
      this.first = this.first.next;
    }
    if (this.first) console.log(`new first value: ${this.first.value}`);
    this.nodeCount--;
    return result;
  }

  // move all elements one to the back, adding on the given value to the front
  unshift(value) {
    var newNode = new Node(value);
    if(this.nodeCount == 0) {
      this.first = newNode;
      this.last = newNode;
    } else {
      this.first.prev = newNode;
      newNode.next = this.first;
      this.first = newNode;
    }
    this.nodeCount++;
  }

  // find the given value in the list and remove it if found.
  delete(value) {
    // find value
    var curNode = this.first;
    do {
      // value found, delete
      if (curNode.value == value) {
        if (curNode.next) {
          curNode.next.prev = curNode.prev;
        } else {
          this.last = curNode.prev;
        }

        if (curNode.prev) {
          curNode.prev.next = curNode.next;
        } else {
          this.first = curNode.next;
        }
        
        this.nodeCount--;
        break;
      }
      curNode = curNode.next;
    } while (curNode != null);
  }

  // return size of list
  count() {
    return this.nodeCount;
  }
}