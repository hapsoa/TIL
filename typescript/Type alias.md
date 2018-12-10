# Type alias(가명)

인터페이스랑 비슷해 보입니다.

Primitive, Union Type, Tuple

기타 직접 작성해야하는 타입을 다른 이름을 지정할 수 있습니다.

만들어진 타입의 refer 로 사용하는 것이지 타입을 만드는것은 아닙니다.

<br>

## Aliasing Primitive

```typescript
type MyStringType = string;

const str = 'world';

let myStr: MyStringType = 'hello';
myStr = str;

/*
별 의미가 없다..
*/
```

<br>

## Aliasing Union Type

```typescript
let person: string | number = 0;
person = 'Mark';

type StringOrNumber = string | number;

let another: StringOrNumber = 0;
another = 'Anna';

/*
1. 유니온 타입은 A 도 가능하고 B 도 가능한 타입
2. 길게 쓰는걸 짧게
*/
```

<br>

## Aliasing Tuple

```typescript
let person: [string, number] = ['Mark', 35];

type PersonTuple = [string, number];

let another: PersonTuple = ['Anna', 24];

/*
1. 튜플 타입에 별칭을 줘서 여러군데서 사용할 수 있게 한다.
*/
```

<br>

## Interface 와의 차이점

```typescript
type Alias = { num: number }

interface Interface {
    num: number;
}

declare function aliased(arg: Alias): Alias;
declare function interfaced(arg: Interface): Interface;

/*
1. type alias 는 object literal type 로
2. interface 는 interface 로
*/
```

```typescript
type PersonAlias = {
    name: string;
    age: number;
};

interface IPerson extends PersonAlias {

}

let ip: IPerson = {
    name: 'Mark',
    age: 35
};

class PersonImpl implements PersonAlias {
    name: string;
    age: number;

    hello() {
        console.log('안녕하세요');
    }
}

let pi: PersonImpl = new PersonImpl();
pi.hello();

class PersonChild extends PersonAlias {

}
```
