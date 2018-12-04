# StyleGuide and Coding Conventions

## Variable and Function
camelCase 로 써라

Bad
```typescript
var FooVar;
function BarFunc() { }
```

Good
```typescript
var fooVar;
function barFunc() { }
```

## Class

클래스 이름에 PascalCase 를 쓰라

Bad
```typescript
class foo { }
```

Good
```typescript
class Foo { }
```

#### 클래스의 members and methods
camelCase를 써라

Bad
```
class Foo {
    Bar: number;
    Baz() { }
}
```

Good
```typescript
class Foo {
    bar: number;
    baz() { }
}
```

<br>

## Interface

name 에는 PascalCase

members 에는 camelCase

I 접두어를 사용하지 마라

Bad
```
interface IFoo {
}
```

```typescript
Good

interface Foo {
}
```

<br>

## Type
name 에는 PascalCase

members 에는 camelCase


