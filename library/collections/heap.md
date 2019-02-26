# heap

binary heap이 구현이 되었다.

```typescript
const Heap = require('collections/heap');

interface Test {
  id: string;
  recommendCount: number;
}

const testA: Test = { id: 'a', recommendCount: 5 };
const testB: Test = { id: 'b', recommendCount: 3 };
const testC: Test = { id: 'c', recommendCount: 6 };
const testD: Test = { id: 'd', recommendCount: 5 };

const heap = new Heap(
  [testA, testB, testC, testD],
  null,
  (a: Test, b: Test) => {
    return a.recommendCount - b.recommendCount;
  },
);

console.log('first', heap.pop()); // testC
console.log('second', heap.pop()); // testD
console.log('third', heap.pop()); // testA
console.log('fourth', heap.pop()); // testB
```
