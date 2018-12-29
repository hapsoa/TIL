# Type assersions

적당한 번역을 찾을 수가 없다.

Type assertions(주장)

형변환과는 다릅니다.

형변환은 실제 데이터 구조를 바꿔줍니다.

'타입이 이것이다' 라고 컴파일러에게 알려주는 것을 의미합니다.

그래서 행동에 대해서 작성자가 100% 신뢰하는 것이 중요합니다.

문법적으로는 두가지 방법이 있습니다.

```
변수 as 강제할타입
<강제할타입>변수
```

```typescript
let someValue: any = "this is a string";

let strLength: number = (<string>someValue).length;
let strLength: number = (someValue as string).length;

/*
1. 주로 넓은 타입에서 좁은 타입으로 강제하는 경우가 많다.
2. jsx 에서는 as 를 쓴다. (react에서 쓰는 뭔가인듯)
*/
```
<br>

ex)2
```tyescript
class Character {
  hp: number;
  runAway() {
    /* ... */
  }
  isWizard() {
    /* ... */
  }
  isWarrior() {
    /* ... */
  }
}

class Wizard extends Character {
  fireBall() {
    /* ... */
  }
}

class Warrior extends Character {
  attack() {
    /* ... */
  }
}

function battle(character: Character) {
  if (character.isWizard()) {
    character.fireBall(); // Property 'fireBall' does not exist on type 'Character'.
  } else if (character.isWarrior()) {
    character.attack(); // Property 'attack' does not exist on type 'Character'.
  } else {
    character.runAway();
  }
}
```
```typescript
function battle(character: Character) {
  if (character.isWizard()) {
    (character as Wizard).fireBall(); // Pass
  } else if (character.isWarrior()) {
    (character as Warrior).attack(); // Pass
  } else {
    character.runAway();
  }
}
```
