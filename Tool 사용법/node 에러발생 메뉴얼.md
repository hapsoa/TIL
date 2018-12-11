# node 에러발생 시 메뉴얼

## 맥에서 윈도우 node 바꿀 시

## 윈도우에서 맥으로 node 바꿀 시

에러가 이상하게 나서 잡지를 못했다.

Pre-built binaries not found for grpc@1.13.1 and node@11.3.0 (node-v67 ABI, unknown) (falling back to source compile with node-gyp)

이런식으로 떠서 말이다.

```
npm rebuild node-sass
```

Run  `npm rebuild node-sass`  to build the binding for your current environment.

<br>

## npm install 했을 시 에러가 도통 뭔지 모를 때

package.json 파일을 확인해보고, 따로 설치를 해본다.

node_modules 폴더를 삭제하고 다시 npm install 을 한다.

