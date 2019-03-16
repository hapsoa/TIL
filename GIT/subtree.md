# git subtree (+ vue.js)

hapsoa.github.io 에 바로 github page를 만드는게 아니라

hapsoa.github.io/vuetify-practice 처럼 github-page에 subtree를 만드는 것

```
1. vue.config.js의 publicPath 를 프로젝트 이름으로 변경한다. proxy는 지운다.
2. .gitignore 에서 dist 폴더를 지운다.
3. build를 한다.
4. git add .
5. git commit -m “gh-pages first commit”
6. git subtree push --prefix dist origin gh-pages

7.를 한 후 시간이 지나고 ‘hapsoa.github.io/프로젝트이름’으로 들어간다.
```

<br>

vue.config.js

```javascript
module.exports = {
  devServer: {
    host: '0.0.0.0',
    disableHostCheck: true,
  },
  publicPath: '/프로젝트이름',
  outputDir: undefined,
  assetsDir: undefined,
  runtimeCompiler: undefined,
  productionSourceMap: undefined,
  parallel: undefined,
};
```

<br>

# 오류 해결 방법

git subtree push --prefix dist origin gh-pages 가 실패하고, pull 하라고 뜰 때

```
git push origin :gh-pages && git subtree push --prefix dist origin gh-pages
```

'deletes the branch and re-pushes. Avoids all that remote branch being ahead fluff that others are mentioning ' 라고 함.
