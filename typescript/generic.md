# Generic

## any(적폐) => generic 으로

타입만 다른 반복되는 함수를 하나의 함수로 만들 수 있다.

타입 추론이 가능해져, 미리 타입오류를 잡아낼 수 있다.

```typescript
function helloString(message: string): string {
    return message;
}

function helloNumber(message: number): number {
    return message;
}

// 더 많은 반복된 함수들 ...

function hello(message: any): any {
    return message;
}

function helloGeneric<T>(message: T): T {
    return message;
}

console.log(hello('Mark').length);
console.log(hello(35).length);

console.log(helloGeneric(35).toString()); // console.log(helloGeneric<number>(35).toString());

// hello 의 리턴이 any 이기 때문에 타입 헬퍼가 제대로 되지 않음
// helloGeneric 을 사용하면 정상적으로 사용가능
```

<br>

## basic generic

```typescript
function helloGeneric<T>(message: T): T {
    return message;
}

function hello<T>(message: T): T {
    return message;
}

console.log(hello<string>('Hello'));
let age = hello(35);
hello<number>('35');

/*
1. Generic 타입을 쓰지 않으면, T 로 추론
2. Generic 타입을 쓰면, T 를 확인
*/
```

<br>

## Generic Array

T[] 사용가능

```typescript
function hello<T>(messages: T[]): T {
    return messages[0];
}

console.log(hello<string>(['Hello', 'World']));

/*
hello 함수의 제네릭 타입을 [] 를 이용하여 배열로 사용할 수 있음
*/
```

<br>

## Generic Types

type alias에 generic 사용 가능

```typescript
type HelloGeneric = <T>(message: T) => T;

const hello: HelloGeneric = <T>(message: T): T => {
    return message;
}

console.log(hello<string>('Hello').length);

/*
구현체에 return T 를 설정하지 않아도,
return false 시 오류가 나지 않는다?

함수 제네릭 타입은 오류를 미리 잡아주지 않네..
*/
```

<br>

## Generic Class

class에 generic 사용가능

```typescript
class Person<T> {
    private _name: T;
    private _age: number;

    constructor(name: T) {
        this._name = name;
    }
}

new Person('Mark');
// new Person<string>(35);

/*
명시적으로 제네릭 타입을 설정하면 오류
*/
```

<br>

## Generic with extends

상속 받은 type만 T의 type으로 사용 가능하다.

```typescript
class Person<T extends string | number> {
    private _name: T;
    private _age: T;

    constructor(name: T) {
        this._name = name;
    }
}

new Person('Mark');
new Person(35);
// new Person(true);

/*
T 가 string 또는 number 를 상속받기 때문에 boolean 은 안된다.
*/
```

<br>

## Generic with multiple types

T, K 여러개의 generic을 둘 수 있다.

```typescript
class Person<T, K> {
    private _name: T;
    private _age: K;

    constructor(name: T, age: K) {
        this._name = name;
        this._age = age;
    }
}

new Person('Mark', 35);
```

<br>

## type lookup system

type을 추론할 수 있다. (keyof도 활용)

```typescript
interface Person {
    name: string;
    age: number;
}

const person: Person = {
    name: 'Mark',
    age: 35
};

function getProperty<T, K extends keyof T>(obj: T, key: K): T[K] {
    return obj[key];
}

function setProperty<T, K extends keyof T>(obj: T, key: K, value: T[K]): void {
    obj[key] = value;
}

console.log(getProperty(person, 'name'));
// console.log(getProperty(person, fullname));
setProperty(person, 'name', 'Anna');
console.log(getProperty(person, 'name'));
// setProperty(person, 'name', 24);
```

```typescript
interface Person {
    name: string;
    age: number;
}

type asdf = keyof Person; // 'name' | 'age' (리터럴 타입)

const a: asdf = 'name';
// const b: asdf = 'name1'; // 안됨
```