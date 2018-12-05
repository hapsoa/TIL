# var, let, const

var VS let, const

```
var

ES5
변수의 유효 범위 : 함수 스코프
호이스팅 (O)
재선언 가능
```
```
let, const
ES6

변수의 유효 범위 : 블록 스코프 (친숙)
호이스팅 (X)
재선언 불가
var 말고 let, const
```

## Hoisting

```typescript
console.log(hoisted_var);

var hoisted_var = '변수를 아래서 선언했는데 사용이 위에서 가능';

////////////////////////////////////////

console.log(hoisted_let);

let hoisted_let = '변수를 아래서 선언했는데 사용이 위에서 불가';
```

## 재선언 redeclare

```typescript
var redeclare_var: string = '한번 선언 했는데';
var redeclare_var: string = '또 선언이 가능';
// var redeclare_var: number = 0; (X)

////////////////////////////////////////

let redeclare_let = '한번 선언 했기 때문에';
let redeclare_let = '또 선언이 불가';

/*

그렇지만 var 에서 재선언 하더라도 같은 타입이어야 함.

*/
```

## let 과 const 의 타입 추론

```typescript
let a: string = '에이';
let b = '비이';

const c: string = '씨이';
const d = '디이';

/*
1. a 는 명시적으로 지정된 타입인 string
2. b 는 타입추론에 의한 타입인 string
3. c 는 명시적으로 지정된 타입인 string
4. d 는 타입추론에 의한 타입인 리터럴타입 "디이"
*/
```



