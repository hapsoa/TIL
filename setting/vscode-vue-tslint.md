# vs code 에서 vue 환경에 tslint 자동 저장 => 자동 formatting하기

npm i --save tslint-config-prettier

.vscode/settings.json 에 들어가서

```json
"editor.formatOnSave": true,
"prettier.tslintIntegration": true
```

<br>

tslint.json에 들어가서

```json
{
   ...
   // 덮어써도 됨
   "extends": ["tslint:recommended", "tslint-config-prettier"],

   // 추가하기
   "rules": {
      "no-console": [false, "log", "error"]
   }
   ...
}
```
