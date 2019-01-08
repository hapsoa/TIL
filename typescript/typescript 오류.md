# typescript 오류

import 할 때 에러나는 것은

tsconfig.json 의 compilerOptions의 types에 모듈이름을 입력하면 된다.
(ex. lodash, vuetify)

or
"compilerOptions" 안에
```
Edit your tsconfig.json

"noImplicitAny": false
```
을 한다.