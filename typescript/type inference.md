# Type Inference

## 타입 추론

기본적으로 타입을 명시적으로 쓰지 않을 때 추론하는 방법에 대한 규칙
- 명시적으로 쓰는 것은 타입 추론이 아니라 코드를 읽기 좋게 하는 지름길

let 은 기본적으로 우리가 아는 기본 자료형으로 추론

const 는 리터럴 타입으로 추론
- 오브젝트 타입을 타입을 쓰지 않으면, 프로퍼티는 let 처럼 추론
- const person = {name: 'Mark', age: 35}; 면
- person => {name: string; age: number;} 로 추론

대부분은 추론이 쉽다.
- 단순 변수
- structuring, destructuring

array, 함수의 리턴에서는 원하는데로 얻기가 힘들다.

<br>

## 배열 타입 추론

union 처럼 string | number | boolean 이런 식으로 추론된다.

```typescript
const array1 = [];
const array2 = ['a', 'b', 'c'];
const array3 = ['a', 1, false]; // string | number | boolean

class Animal {
    name: string;
}

class Dog extends Animal { 
    dog: string;
}

class Cat extends Animal {
    cat: string;
}

const array4 = [new Dog(), new Cat()];
```

## 리턴 타입 추론

'world' | 0

```typescript
function hello(message: string | number) {
    if (message === 'world') {
        return 'world';
    } else {
        return 0;
    }
}
```

<br>

## 유니온 타입과 타입 가드

아래 코드의 'is Person'가 타입 가드이다.

타입가드가 통과된 객체에 '.' 찍으면 해당 객체의 메소드가 추론돼서 뜬다.

```typescript
interface Person {
    name: string;
    age: number;
}

interface Car {
    brand: string;
    wheel: number;
}

function isPerson(arg: any): arg is Person {
    return arg.name !== undefined;
}

function hello(arg: Person | Car) {
    if (isPerson(arg)) {
        console.log(arg.name);
        // console.log(arg.brand);
    } else {
        // console.log(arg.name);
        console.log(arg.brand);
    }
}
```