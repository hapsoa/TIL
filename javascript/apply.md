# apply

문맥을 넘어서서 this를 연결하려면 bind, apply, call 등의 함수 수준의 메서드를 이용해야 합니다.

```javascript
function Person(name, yearCount) {
    this.name = name;
    this.age = 0;
    var incrAge = function () {
        this.age++;
    }
    for (var i=1; i <= yearCount; i++) {
        incrAge.apply(this);
    }
}
var p1 = new Person("홍길동",20);

//--this.age는 20이 출력됨.
console.log(p1.name + "님의 나이 : " + p1.age);
```