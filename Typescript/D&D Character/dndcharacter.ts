export class DnDCharacter {
  constructor() {
    this.strength = DnDCharacter.generateAbilityScore();
    this.dexterity = DnDCharacter.generateAbilityScore();
    this.constitution = DnDCharacter.generateAbilityScore();
    this.intelligence = DnDCharacter.generateAbilityScore();
    this.wisdom = DnDCharacter.generateAbilityScore();
    this.charisma = DnDCharacter.generateAbilityScore();

    this.hitpoints = 10 + DnDCharacter.getModifierFor(this.constitution);
  }

  public static generateAbilityScore(): number {
    var total:number = 0;
  
    var lowest:number = 0; // first num will always be lower
    
    for (var i:number = 0; i < 4; ++i) {
      //generate random number 1-6
      var roll:number = Math.floor(Math.random() * 6) + 1; // random() will generate 0 - 5, add 1 to get 1-6
  
      // if roll is less than the current lowest
      if (lowest == 0 || roll < lowest) {
        // add lowest to the total
        total += lowest;
        // set new lowest
        lowest = roll;
      } else { // if roll is >= lowest, add to total
        total += roll;
      }
    }
  
    return total;
  }

  public static getModifierFor(abilityValue: number): number {
    // subtract 10 from ability score, divide by 2 and round down
    return Math.floor((abilityValue - 10) / 2);
  }

  hitpoints:number;
  strength:number;
  dexterity:number;
  constitution:number;
  intelligence:number;
  wisdom:number;
  charisma:number;
}