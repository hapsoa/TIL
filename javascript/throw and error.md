# throw and error

javascript에서 throw and error 활용하기

```typescript
const function1 = (): void => {
    try {
        throw 'oing';
    } catch(error) {
        console.error(error);
        throw new Error('yap');
    }
};

const function2 = (): void => {
    let num: number = 1;
    try {
        function1();
        num++;
    } catch(error) {
        console.error(error);
    }
    
    console.log(num);
}

function2();
```

```
--결과값==
oing
Error: yap
1
```
에러가 발생되면 try 안의 아래 코드는 작동되지 않고 catch 구문만 실행된다.