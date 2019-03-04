# javascript Date 객체

```javascript
const date = new Date();

console.log(date);
console.log(date.getTime()); // 1544798477771
console.log(new Date(date.getTime())); // 변수 date와 같다
console.log(new Date(1544798477771)); // 변수 date와 같다

console.log(Date.now()); // 현재시간
console.log(date.getFullYear()); //2018
console.log(date.getMonth()) // 11 ('해당 월 - 1' 인듯)
console.log(date.getDate()); // 14(일)
console.log(new Date().getMinutes()); // 해당 시간의 분만 나타냄
console.log(new Date().getMilliseconds()); // 772 초 아래의 단위만 나타내는 듯

console.log(new Date().toLocaleString()); // 2018-12-23 02:40:11
console.log(new Date().toLocaleDateString()); // 2018-12-23
console.log(new Date().toLocaleTimeString()); // 02:39:48
```