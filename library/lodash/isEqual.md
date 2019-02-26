# isEqual

두 값이 같은지 깊게 비교를 수행합니다.

```javascript
var object = { 'a': 1 };
var other = { 'a': 1 };
 
_.isEqual(object, other);
// => true
 
object === other;
// => false
```