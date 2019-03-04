# typescript decorator

동적으로 책임 추가가 필요할 때 데코레이터 패턴을 사용할 수 있다.

## Decorator 종류
- Class Decorator
- Method Decorator
- Property Decorator
- Parameter Decorator

## Decorator 코드 작성 준비
step1. 프로젝트 생성
- mkdir ts-decorator
- cd ts-decorator
- yarn init -y

step2. typescript 설치
- yarn add typescript -D

step3. tsconfig 설정
- node_modules/.bin/tsc --init
- experimentalDecorators 추가

​step4. vscode 컴파일 설정
- ${workspaceRoot}/node_modules/.bin/tsc
- command + shift + <B>

<br>

## Class Decorator Basic

```typescript
// parameter에 들어가는 것이 미리 정해져 있는 것을 signature 라고 부르는 듯하다.
function hello(constructorFn: Function) {
    console.log(constructorFn);
}

function helloFactory(show: boolean) {
    if (show) {
        return hello;
    } else {
        return null;
    }
}

// @hello
@helloFactory(true)
class Person {
    constructor() {
        console.log('new Person()');
    }
}

new Person();

/*
helloFactory 는 팩토리 스타일
*/
```

## Class Decorator Advanced
```typescript
function addHello(constructorFn: Function) {
    constructorFn.prototype.hello = function() {
        console.log('hello');
    }
}

@addHello
class Person {
    constructor() {
        console.log('new Person()');
    }
}

const person = new Person();
(<any>person).hello();
```

<br>

## Method Decorator

각 decorator의 약속된 signature 가 다르기 때문에 조금씩 다른 방식으로 코딩이 된다.

```typescript
function editable(canBeEdit: boolean) {

    return function(target: any, propName: string, description: PropertyDescriptor) {
        console.log(canBeEdit);
        console.log(target);
        console.log(propName);
        console.log(description);
        description.writable = canBeEdit;
    }
}

class Person {
    constructor() {
        console.log('new Person()');
    }

    @editable(true)
    hello() {
        console.log('hello');
    }
}

const person = new Person();
person.hello();
person.hello = function() {
    console.log('world');
}
person.hello();
```

<br>

## Property Decorator

```typescript
function writable(canBeWrite: boolean) {
    return function(target: any, propName: string): any {
        console.log(canBeWrite);
        console.log(target);
        console.log(propName);
        return {
            writable: canBeWrite
        }
    }
}

class Person {
    @writable(false)
    name: string = 'Mark';

    constructor() {
        console.log('new Person()');
    }
}

const person = new Person();
console.log(person.name);

/*
undefined
*/
```

<br>

## Parameter Decorator

```typescript
function printInfo(target: any, methodName: string, paramIndex: number) {
    console.log(target);
    console.log(methodName);
    console.log(paramIndex);
}

class Person {
    private _name: string;
    private _age: number;

    constructor(name: string, @printInfo age: number) {
        this._name = name;
        this._age = age;
    }

    hello(@printInfo message: string) {
        console.log(message);
    }
}

/*

Person { hello: [Function] }
hello
0
[Function: Person]
undefined
1

*/
```

