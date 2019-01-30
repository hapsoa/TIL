# firestore


object는 firestore에서는 map 형식으로 들어간다.


map 형식을 쿼리로 찾을 때,
```javascript
 // Find all documents in the 'posts' collection that are
// in the 'cats' category.
db.collection('posts')
    .where('categories.cats', '==', true)
    .get()
    .then(() => {
        // ...
    });)
```

map 형식으로 찾을 때마다 복합 색인 설정하라고 할 수 있으니
array로 구조를 맞춘다음에 쿼리를 날릴 수 있다.


