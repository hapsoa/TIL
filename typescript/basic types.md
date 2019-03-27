# basic types

TypeScript 에서 프로그램 작성을 위해 기본 제공하는 데이터 타입

사용자가 만든 타입은 결국은 이 기본 자료형들로 쪼개집니다.

JavaScript 기본 자료형을 포함 (superset)

ECMAScript 표준에 따른 기본 자료형은 6가지

```
Boolean
Number
String
Null
Undefined
Symbol (ECMAScript 6 에 추가)
Array : object 형
```

프로그래밍을 도울 몇가지 타입이 더 제공된다.

```
Any
Void (return 값으로 이용됨)
Never (return 값으로 이용됨)
Enum
Tuple : object 형
```

## Primitive Type

javascript에서 primitive 형을 객체화 시켜 내장함수를 호출한 다음에

다시 primitive type으로 되돌려 놓는 방식을 쓰는 듯 하다.

```typescript
let name = 'mark';

name.toString();
```

## literal

값자체가 변하지 않는 값을 의미합니다.

상수와 다른 것은 '상수'는 가리키는 포인터가 고정이라는 것이고, '리터럴'은 그 자체가 값이자 그릇입니다.

```typescript
35; // number 리터럴
'mark' // string 리터럴
true // boolean 리터럴

// object 리터럴
{
    name: 'mark',
    age: 35
}
```

#### (리터럴 상수)

"리터럴 상수는 5, 1.23 과 같은 숫자나, 과 같은 문자열 등을 말합니다.

'This is a string' 혹은 "It’s a string!"이것들이 리터럴 상수라고 불리우는 이유는

이것들이 프로그램 내에 직접 문자 형태로(literally)지정되는 값들이기 때문입니다.

이러한 값들은 한번 지정되면 변하지 않습니다.

예를 들면 숫자2 는 언제나 자기 자신이 2라는 숫자임을 나타내며 어떤 다른 의미도 갖지 않습니다.

이들은 한번 지정되면 그 값을 변경할 수 없기 때문에 *상수*입니다.

그 중에서도 특별히 이러한 값들을 리터럴 상수라고 부릅니다."

## Boolean / boolean

가장 기본적인 데이터 타입

단순한 true 혹은 false 값 입니다.

JavaScript / TypeScript 에서 'boolean' 이라고 부른다.

```typescript
let isDone: boolean = false;

typeof isDone === 'boolean'; // true

// Type 'boolean' is assignable to type 'Boolean'.
let isOk: Boolean = true;

// Type 'Boolean' is not assignable to type 'boolean'.
// 'boolean' is a primitive, but 'Boolean' is a wrapper object.
// Prefer using 'boolean' when possible.
let isNotOk: boolean = new Boolean(true);
```

## Number / number

JavaScript 와 같이, TypeScript 의 모든 숫자는 부동 소수점 값 입니다.

TypeScript는 16진수 및 10진수 리터럴 외에도, ECMAScript 2015에 도입된 2진수 및 8진수를 지원합니다.

```typescript
let decimal: number = 6; // 10진수 리터럴

let hex: number = 0xf00d; // 16진수 리터럴

let binary: number = 0b1010; // 2진수 리터럴

let octal: number = 0o744; // 8진수 리터럴
```

## String / string

다른 언어에서와 마찬가지로이 텍스트 형식을 참조하기 위해 `string` 형식을 사용합니다.

JavaScript 와 마찬가지로, TypeScript는 문자열 데이터를 둘러싸기 위해 큰 따옴표 ( " ) 나, 작은 따옴표 ( ' ) 를 사용합니다.

```typescript
let name: string = 'mark';

name = 'anna';
```

## Template String

행에 걸쳐 있거나, 표현식을 넣을 수 있는 문자열

이 문자열은 backtick (= backquote) 기호에 둘러쌓여 있습니다.

포함된 표현식은 `${ expr }` 와 같은 형태로 사용합니다.

```typescript
let fullName: string = `Bob Bobbington`;
let age: number = 37;

let sentence: string = `Hello, my name is ${fullName}.

I'll be ${age + 1} years old next month.`;

// template string 을 사용하지 않을 경우
let sentence: string =
  'Hello, my name is ' +
  fullName +
  '.\n\n' +
  "I'll be " +
  (age + 1) +
  ' years old next month.';
```

## Undefined & Null

TypeScript 에서 'undefined' 와 'null' 은 실제로 각각 'undefined' 와 'null' 이라는 고유한 타입을가집니다.

'void' 와 마찬가지로, undefined 와 null 은 그 자체로는 쓸모가 없습니다.

둘다 소문자만 존재합니다.

```typescript
// 이 변수들에 할당할 수 있는 것들은 거의 없다.

let u: undefined = undefined;
let n: null = null;
```

### undefined & null are subtypes of all other types.

기본 설정이 그렇습니다.

number 에 null 또는 undefined 를 할당할 수 있다는 의미입니다.

(하지만, 컴파일 옵션에서 `--strictNullChecks`사용하면, null 과 undefined 는 void 나 자기 자신들에게만 할당할 수 있습니다.

이 경우, null 과 undefined 를 할당할 수 있게 하려면, union type 을 이용해야 합니다.)

```typescript
let name: string = null;
let age: number = undefined;

// (
// strictNullChecks => true
// Type 'null' is not assignable to type 'string'.
let name: string = null;
X;

// null => null || void, undefined => undefined || void
// Type 'null' is not assignable to type 'undefined'.
let u: undefined = null; // (X)

let v: void = undefined; // (O)

let union: string | null | undefined = 'str';
// )
```

## null in JavaScript

null 이라는 값으로 할당된 것을 null 이라고 합니다.

무언가가 있는데, 사용할 준비가 덜 된 상태.

null 이라는 타입은 null 이라는 값만 가질 수 있습니다.

런타임에서 typeof 연산자를 이용해서 알아내면, object 입니다.

```typescript
let n: null = null;

console.log(n); // null
console.log(typeof n); // object
```

## undefined in JavaScript

값을 할당하지 않은 변수는 undefined 라는 값을 가집니다.

무언가가 아예 준비가 안된 상태

object 의 property 가 없을 때도 undefined 입니다.

런타임에서 typeof 연산자를 이용해서 알아내면, undefined 입니다.

```typescript
let u: undefined = undefined;

console.log(u); // undefined
console.log(typeof u); // undefined
```

## void

타입이 없는 상태입니다.

`any` 와 반대의 의미를 가집니다.

Void 는 없습니다. 소문자입니다.

주로 함수의 리턴이 없을 때 사용합니다. 그 외에는 사용할 일이 거의 없습니다.

```typescript
function returnVoid(message: string): void {
  console.log(message);
}

returnVoid('리턴이 없다');
```

## Any

어떤 타입이어도 상관없는 타입입니다.

이걸 최대한 쓰지 않는게 핵심입니다. (적폐)

왜냐면 컴파일 타임에 타입 체크가 정상적으로 이뤄지지 않기 때문입니다.

그래서 컴파일 옵션 중에는 any 를 쓰면 오류를 뱉도록 하는 옵션도 있습니다.

noImplicitAny

```typescript
function returnAny(message: string): any {
  console.log(message);
}

returnVoid('리턴은 아무거나');
```

## Never

리턴에 주로 사용됩니다. 별 쓸모 없는듯

아래 3가지 정도의 경우가 대부분입니다.

```typescript
// Function returning never must have unreachable end point
function error(message: string): never {
  throw new Error(message);
}

// Inferred return type is never
function fail() {
  return error('Something failed');
}

// Function returning never must have unreachable end point
function infiniteLoop(): never {
  while (true) {}
}
```

## Array

원래 자바스크립트에서 array 는 객체입니다.

사용방법

Array<타입>

타입[]

```typescript
let list: number[] = [1, 2, 3];

let list: Array<number> = [1, 2, 3];
```

## Tuple

배열인데 타입이 한가지가 아닌 경우

마찬가지로 객체입니다.

꺼내 사용할때 주의가 필요합니다. 무슨 타입인지 인식이 잘 안돼서 사용을 잘 안하는 듯

배열을 Destructuting 하면 타입이 제대로 얻어집니다.

```typescript
// Declare a tuple type
let x: [string, number];
// Initialize it
x = ['hello', 10]; // OK
// Initialize it incorrectly
x = [10, 'hello']; // Error

x[3] = 'world'; // OK, 'string' can be assigned to 'string | number'

console.log(x[5].toString()); // OK, 'string' and 'number' both have 'toString'

x[6] = true; // Error, 'boolean' isn't 'string | number'

const person: [string, number] = ['mark', 35];

const [name, age] = person;
```

## Enum

C 에서 보던것과 같습니다.

아래 예제만 이해하면 사용 준비 끝

```typescript
enum Color {
  Red,
  Green,
  Blue,
}
let c: Color = Color.Green; // c의 값 : 1

enum Color {
  Red = 1,
  Green,
  Blue,
}
let c: Color = Color.Green; // c의 값 : 2

enum Color {
  Red = 1,
  Green = 2,
  Blue = 4,
}
let c: Color = Color.Green; // c의 값 : 2

enum Color {
  Red = 1,
  Green,
  Blue,
}
let colorName: string = Color[2]; // colorName의 값 : "Green"
```

## Symbol

ECMAScript 2015 의 Symbol 입니다.

프리미티브 타입의 값을 담아서 사용합니다.

고유하고 수정불가능한 값으로 만들어줍니다.

그래서 주로 접근을 제어하는데 쓰는 경우가 많았습니다.

```typescript
let sym = Symbol();

let obj = {
  [sym]: 'value',
};

console.log(obj[sym]); // "value"
```
