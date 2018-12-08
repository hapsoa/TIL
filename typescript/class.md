# Class

## 클래스 만들기

```typescript
class Person {
    name: string;
    age: number;
}

const person: Person = new Person();
console.log(person); // Person {}
person.age = 35;
console.log(person.name); // undefined

/*
1. 생성자 함수가 없으면, 디폴트 생성자가 불린다.

2. 클래스의 프로퍼티 혹은 멤버 변수가 정의되어 있지만, 값을 대입하지 않으면 undefined 이다.
=> 오브젝트에 프로퍼티가 아예 존재하지 않는다.

3. 접근제어자 (Access Modifier) 는 public 이 디폴트 이다.
*/
```

<br>

## 클래스와 프로퍼티 (1)

```typescript
class Person {
    name: string;
    age: number;

    constructor() {
        console.log(this.name === null); // false
        console.log(this.name === undefined); // true
    }
}

const person: Person = new Person();
person.name = 'Mark';
person.age = 35;
console.log(person); // Person {name: 'mark', age: 35}
```

## 클래스와 프로퍼티 (2)

```typescript
class Person {
    name: string = 'Mark';
    age: number = 35;

    constructor() {
        console.log(this.name); // 'mark'
    }
}

const person: Person = new Person();
console.log(person); // Person {name: 'Mark', age: 35}

/*
1. 클래스의 프로퍼티를 선언과 동시에 값을 할당하는 방법도 있다.

2. 생성자가 불리기 전에 이미 프로퍼티의 값이 저장되어 있음을 알 수 있다.
*/
```

<br>

## 클래스와 프로퍼티의 접근 제어자 (1)

```typescript
class Person {
    public name: string;
    private _age: number;

    constructor(age: number) {
        this._age = age;
    }
}

const person: Person = new Person(35);
person.name = 'Mark';
// person._age (X)
console.log(person); // Person {name: 'Mark', _age: 35}

/*
1. private 으로 설정된 프로퍼티는 dot 으로 접근할 수 없다.

2. 클래스 내부에서는 private 프로퍼티를 사용할 수 있다.

3. private 이 붙은 변수나 함수는 _ 를 이름앞에 붙이는데,
이는 문법이 아니라 널리 쓰이는 코딩 컨벤션이다.
*/
```

## 클래스와 프로퍼티의 접근 제어자 (2)

```typescript
class Parent {
    private privateProp: string;
    protected protectedProp: string;

    constructor() {

    }
}

class Child extends Parent {
    constructor() {
        super();

        this.protectedProp = 'protected';
        // this.privateProp = 'private'; // (X)
    }
}

/*
1. 부모에서 private 으로 설정된 프로퍼티는 상속을 받은 자식에서도 접근할 수 없다.

2. 부모에서 protected 로 설정된 프로퍼티는 상속을 받은 자식에서 접근이 가능하다.

3. 상속을 받은 자식 클래스에서 부모 클래스에 this 를 통해 접근하려면, 생성자에서 super(); 를 통해 초기화 해야한다.
*/
```

<br>

## 클래스와 디폴트 생성자

```typescript
class Person {
    public name: string;
    private _age: number;

    constructor(age: number) {
        this._age = age;
    }
}

const person: Person = new Person();

/*
1. 디폴트 생성자는 프로그래머가 만든 생성자가 없을 때 사용할 수 있다.
=> 사용자가 만든 생성자가 하나라도 있으면, 디폴트 생성자는 사라진다.
*/
```

<br>

## 클래스와 메서드

```typescript
class Person {
    constructor(private _name: string, private _age: number) { }

    print(): void {
        console.log(`이름은 ${this._name} 이고, 나이는 ${this._age} 살 입니다.`);
    }

    printName = (): void => {
        console.log(`이름은 ${this._name} 입니다.`);
    }

    private printAge(): void  {
        console.log(`나이는 ${this._age} 살 입니다.`);
    }
}

const person: Person = new Person('Mark', 35);
person.print(); // 이름은 Mark 이고, 나이는 35 살 입니다.
person.printName(); // 이름은 Mark 입니다.
// person.printAge(); // (X)

/*
1. 클래스 내부에 작성된 메서드는 public 이 디폴트
2. arrow function 으로 작성 가능
3. private 을 이용하면 클래스 외부애서 접근 불가
*/
```

<br>

## 클래스와 상속 (1)

```typescript
class Parent {
    constructor(protected _name: string, protected _age: number) { }

    print(): void {
        console.log(`이름은 ${this._name} 이고, 나이는 ${this._age} 살 입니다.`);
    }

    printName = (): void => {
        console.log(`이름은 ${this._name} 입니다.`);
    }

    private printAge(): void  {
        console.log(`나이는 ${this._age} 살 입니다.`);
    }
}

class Child extends Parent {
    _name = 'Mark Jr.';
}

// const p: Child = new Child(); // (X)
const p: Child = new Child('', 5);
p.print(); // 이름은 Son 이고, 나이는 5 살 입니다.

/*
1. 상속은 extends 키워드를 이용한다.
2. 자식 클래스에서 디폴트 생성자는 부모의 생성자와 입력 형태가 같다.
*/
```

## 클래스와 상속 (2)

```typescript
class Parent {
    constructor(protected _name: string, private _age: number) { }

    print(): void {
        console.log(`이름은 ${this._name} 이고, 나이는 ${this._age} 살 입니다.`);
    }

    protected printName = (): void => {
        console.log(`이름은 ${this._name} 입니다.`);
    }

    protected printAge(): void  {
        console.log(`나이는 ${this._age} 살 입니다.`);
    }
}

class Child extends Parent {
    constructor(age: number) {
        super('Mark Jr.', age);

        this.printName();
        this.printAge();
    }
}

const p: Child = new Child(1);
// 이름은 Son 입니다.
// 나이는 1 살 입니다.

/*
1. 생성자를 정의하고, this 를 사용하려면, super 를 통해 부모의 생성자를 호출해줘야 한다.
2. super 를 호출할때는 부모 생성자의 입력 타입이 같아야 한다.
3. super 를 호출하는 것은 클래스 외부에서 호출하는 것과 같다.
4. protected 함수를 호출해서 그 안의 private 을 출력하는 것에 주의한다.
*/
```

<br>

## 클래스와 getter, setter

```typescript
class Person {
    private _name: string;
    private _age: number;
    
    constructor(name: string, age: number) {
        this._name = name;
        this._age = age;
     }

    get name() {
        return this._name;
    }

    set name(name: string) {
        // 작업
        this._name = `${name} Lee`;
    }
}

const person: Person = new Person('Mark', 35);

console.log(person.name);
person.name = 'Woongjae';
console.log(person.name);

/*
1. _ 를 변수명 앞에 붙이고, 내부에서만 사용한다.
2. getter 를 함수처럼 설정하면, 프로퍼티처럼 꺼내쓸수있다.
3. 마찬가지로 setter 를 함수처럼 설정하면, 추가 작업을 하고 셋팅할 수 있다.
*/
```