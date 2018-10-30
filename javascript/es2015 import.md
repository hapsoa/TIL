# es2015 import

```javascript
import name from "module-name";
import * as name from "module-name";
import { member } from "module-name";
import { member as alias } from "module-name";
import { member1 , member2 } from "module-name";
import { member1 , member2 as alias2 , [...] } from "module-name";
import defaultMember, { member [ , [...] ] } from "module-name";
import defaultMember, * as alias from "module-name";
import defaultMember from "module-name";
import "module-name";
```

<br>

모듈 전체를 가져옵니다. export 한 모든 것들을 현재 범위(스크립트 파일 하나로 구분되는 모듈 범위) 내에 myModule 로 바인딩되어 들어갑니다.

```javascript
import * as myModule from "my-module.js";
```

<br>

모듈에서 여러 멤버들을 가져옵니다. 현재 범위 내에 foo 와 bar 이 들어갑니다.

```javascript
import {foo, bar} from "my-module.js";
```

<br>

모듈에서 여러 멤버들을 편리한 별명을 지정하며 가져옵니다.

```javascript
import {reallyReallyLongModuleMemberName as shortName, anotherLongModuleName as short} from "my-module.js";
```

<br>

어떠한 바인딩 없이 모듈 전체의 사이드 이펙트만 가져옵니다.

```javascript
import "my-module.js";
```