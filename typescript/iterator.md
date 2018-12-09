# iterator

## for..of

es3
- for (var i = 0; i < array.length; i++)

es5
- array.forEach
- return 으로 순회를 탈출할 수 없다.

es6
- for (const item of array)
- 배열에서만 사용이 가능

## for..in
배열을 순회할 때는 사용하지 않을 것
- index 가 number 가 아니라 string 으로 나온다.
- 배열의 프로퍼티를 순회할 수도 있다.
- prototype 체인의 프로퍼티를 순회할 수도 있다.
- 루프가 무작위로 순회할 수도 있다.
- for..of 를 쓸 것

객체를 순회할 때
- for (const prop of Object.keys(obj)) 도 사용할 수 있다.

<br>

for in 보다 for of를 쓰자고 하는데, lodash 라이브러리 쓰는게 더 편리하지 않나

## Example

```typescript
const array = ['first', 'second'];
const obj = {
    name: 'Mark',
    age: 35
};

// 배열에 for..of 이용
for (const item of array) {
    console.log(typeof item + ', ' + item);
}

// 배열에 for..in 이용
// item 이 string 타입의 숫자
for (const item in array) {
    console.log(typeof item + ', ' + item);
}


// 객체에 for..of 이용 => 오류
/*
for (const item of obj) {
    console.log(typeof item + ', ' + item);
}
*/

// 객체에 for..in 이용
for (const item in obj) {
    console.log(typeof item + ', ' + item);
}

// 객체의 keys 들에 for..of 이용
for (const item of Object.keys(obj)) {
    console.log(typeof item + ', ' + item);
}
```

<br>

## target es3 forEach

es3가 중심인 라이브러리가 없기 때문에 이런식으로 처리 한다는 것 정도만 알면되지 않을까

```typescript
const array = ['first', 'second'];

// ts
array.forEach((item) => {
    console.log(item);
});

// js
array.forEach(function (item) {
    console.log(item);
});

/*
target 이 es3 인데도 forEach 는 트랜스파일이 되지 않았음.
https://github.com/Microsoft/TypeScript/issues/2410
*/
```

<br>

## Symbol.iterator
- 프로퍼티이며, 함수가 구현되어있으면, iterable 이라고 한다.
- Array, Map, Set, String, Int32Array, Uint32Array, etc. 에는 내장된 구현체가 있으므로 이터러블 하다.
- 그냥 객체는 이터러블하지 않다.
- 이터레이터를 통해 이터러블한 객체의 Symbol.iterator 함수를 호출한다.

## Symbol.iterator
target : es3 or es5
- Array 에만 for..of 사용 가능
- 일반 객체에 사용하면 오류

target : es6
- Symbol.iterator 함수를 구현하면 어떤 객체에도 for..of 사용 가능

<br>

## lib.es6.d.ts (definition file)

```typescript
interface IteratorResult<T> {
    done: boolean;
    value: T;
}

interface Iterator<T> {
    next(value?: any): IteratorResult<T>;
    return?(value?: any): IteratorResult<T>;
    throw?(e?: any): IteratorResult<T>;
}

interface Iterable<T> {
    [Symbol.iterator](): Iterator<T>;
}

interface IterableIterator<T> extends Iterator<T> {
    [Symbol.iterator](): IterableIterator<T>;
}
```

<br>

## Custom Iterable

```typescript
class CustomIterable implements Iterable<string> {
    private _array: Array<string> = ['first', 'second'];

    [Symbol.iterator]() {
        var nextIndex = 0;

        return {
            next: () => {
                return {
                    value: this._array[nextIndex++],
                    done: nextIndex > this._array.length
                }
            }
        }
    }
}

const cIterable = new CustomIterable();

for (const item of cIterable) {
    console.log(item);
}
```