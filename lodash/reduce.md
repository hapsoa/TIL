# reduce

해당 객체의 값들을 계산해 하나의 결과값으로 만들어 준다.

1번째 파라미터 : 해당 객체

2번째 파라미터 : 처리 함수

3번째 파라미터 : 초기값

```javascript
_.reduce([1, 2], function(sum, n) {
  return sum + n;
}, 0);
// => 3
 
_.reduce({ 'a': 1, 'b': 2, 'c': 1 }, function(result, value, key) {
  (result[value] || (result[value] = [])).push(key);
  return result;
}, {});
// => { '1': ['a', 'c'], '2': ['b'] } (iteration order is not guaranteed)
```