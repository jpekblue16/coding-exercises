export function isPangram(sentence:string): boolean {
  var alphabet:string = 'abcdefghijklmnopqrstuvwxyz';

  var lowercase:string = sentence.toLowerCase();

  for (var c of alphabet) {
    if (!lowercase.includes(c)) {
      return false;
    }
  }

  return true;
}