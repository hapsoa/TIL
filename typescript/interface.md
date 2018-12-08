# interface

객체로 타입을 한정시킬 때 interface를 사용할 수 있다.

아래 코드에서, 상위 코드를 하위코드로 사용할 수 있다.

```typescript
function hello(person: { name: string; age: number; }): void {
    console.log(`안녕하세요! ${person.name} 입니다.`);
}

const p: { name: string; age: number; } = {
    name: 'Mark',
    age: 35
};

hello(p); // 안녕하세요! Mark 입니다.

///////////////////////////////////////////////////////////////

interface Person {
    name: string;
    age: number;
}

function hello(person: Person): void {
    console.log(`안녕하세요! ${person.name} 입니다.`);
}

const p: Person = {
    name: 'Mark',
    age: 35
};

hello(p); // 안녕하세요! Mark 입니다.
```

<br>

## interface - optional property (1) : '?'

있어도 되고 없어도 되는 속성을 '?' 기호를 통해 표현할 수 있다.

```typescript
interface Person {
    name: string;
    age?: number;
}

function hello(person: Person): void {
    console.log(`안녕하세요! ${person.name} 입니다.`);
}

const p1: Person = {
    name: 'Mark',
    age: 35
};

const p2: Person = {
    name: 'Anna'
};

hello(p1); // 안녕하세요! Mark 입니다.
hello(p2); // 안녕하세요! Anna 입니다.
```

## interface - optional property (2) : 'indexable types'

해당 index의 타입에서는 지정된 타입의 값을 넣을 수 있다.

```typescript
interface Person {
    name: string;
    age?: number;
    [props: string]: any;
}

function hello(person: Person): void {
    console.log(`안녕하세요! ${person.name} 입니다.`);
}

const p1: Person = {
    name: 'Mark',
    age: 35,
};

const p2: Person = {
    name: 'Anna',
    systers: [
        'Sung',
        'Chan'
    ]
};

const p3: Person = {
    name: 'Bokdaengi',
    father: p1,
    mother: p2
};

hello(p1); // 안녕하세요! Mark 입니다.
hello(p2); // 안녕하세요! Anna 입니다.
hello(p3); // 안녕하세요! Bokdaengi 입니다.
```

<br>

## interface - function in interface

interface에 함수도 넣을 수 있다.

```
interface Person {
    name: string;
    age: number;
    hello(): void;
}

const p1: Person = {
    name: 'Mark',
    age: 35,
    hello: function (): void {
        console.log(this);
        console.log(`안녕하세요! ${this.name} 입니다.`);
    }
};

const p2: Person = {
    name: 'Mark',
    age: 35,
    hello(): void {
        console.log(this);
        console.log(`안녕하세요! ${this.name} 입니다.`);
    }
};

const p3: Person = {
    name: 'Mark',
    age: 35,
    hello: (): void => {
        console.log(this);
        console.log(`안녕하세요! ${this.name} 입니다.`);
    }
};

p1.hello(); // 안녕하세요! Mark 입니다.
p2.hello(); // 안녕하세요! Mark 입니다.
p3.hello(); // 안녕하세요! 입니다.
```

<br>

## class implements interface

class는 interface를 implements 할 수 있다.

```typescript
interface IPerson {
    name: string;
    age?: number;
    hello(): void;
}

class Person implements IPerson {
    name: string;

    constructor(name: string) {
        this.name = name;
    }

    hello(): void {
        console.log(`안녕하세요! ${this.name} 입니다.`);
    }
}

const person = new Person('Mark');
person.hello(); // 안녕하세요! Mark 입니다.
```

<br>

** 만약 아래 코드로 변수 타입을 interface로 지정하면,

interface 에 있는 변수와 함수만 person 변수가 활용할 수 있다.

```typescript
const person: IPerson = new Person('Mark');
```

<br>

## interface extends interface

interface 는 interface를 상속받을 수 있다.

```typescript
interface Person {
    name: string;
    age?: number;
}

interface Korean extends Person {
    city: string;
}

const k: Korean = {
    name: '이웅재',
    city: '서울'
};
```

<br>

## function interface

함수를 통채로 interface로 활용할 수 있는데, 함수 선언시 바로 에러 체크를 하지 못해 사용하지 않는게 더 나을지도.. 미지수인 문법

```typescript
interface HelloPerson {
    // (name: string, age: number): void;
    (name: string, age?: number): void;
}

let helloPerson: HelloPerson = function (name: string) {
    console.log(`안녕하세요! ${name} 입니다.`);
};

helloPerson('Mark'); // 안녕하세요! Mark 입니다.

/*

함수의 타입 체크는 할당할때가 아니라 사용할때 한다는 점을 명심

*/
```

<br>

## Indexable Types

#### string OR number 만 index 한정 지정가능

string : dictionary 처럼 활용

number : array 같음

```typescript
interface StringArray {
    [index: number]: string;
}

const sa: StringArray = {}; // 옵셔널하다
sa[100] = '백';

interface StringDictionary {
    [index: string]: string;
}

const sd: StringDictionary = {}; // 옵셔널하다
sd.hundred = '백';

interface StringArrayDictionary {
    [index: number]: string;
    [index: string]: string;
}

const sad: StringArrayDictionary = {};
// 당연히 옵셔널하다.
sad[100] = '백';
sad.hundred = '백';
```

<br>

```typescript
interface StringDictionary {
    [index: string]: string;
    name: string;
}

const sd: StringDictionary = {
    name: '이름' // 필수
};

sd.any = 'any'; // 어떤 프로퍼티도 가능

////////////////////////////////////////////////

interface StringDictionaryNo {
    [index: string]: string;
    // name: number; // (X) 인덱서블 타입이 string 값을 가지기 때문에 number 를 필수로 끌어오면 에러
}
```