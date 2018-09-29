# svg를 웹폰트로 만드는 법

npm install webfonts-generator --save

src 폴더에
test-input-icons(svg파일을 다운받아 넣는 곳)를 만든다.
icon-font-dest(svg파일이 웹폰트로 변환되는 곳)도 만든다.

build 폴더에
webfont.generator.js 파일을 만들고

```javascript
const webfontsGenerator = require('webfonts-generator');

const fs = require('fs');
const _ = require('lodash');
const iconPath = 'src/test-input-icons';

const files = _.chain(fs.readdirSync(iconPath))
  .filter(f => f.endsWith('.svg'))
  .map(f => `${iconPath}/${f}`)
  .value();

console.log(files);

webfontsGenerator({
  files,
  dest: 'src/icon-font-dest/',
  html: true, // true이면 html 미리보기를 생성해줍니다.
  templateOptions: {
    baseSelector: '.icon-font', // 기본으로 추가될 클래스 이름
    classPrefix: 'icon-font-' // 위 벡터 이미지 이름과 조합하여 추가될 클래스 이름(예: y-icon-download)
  }
}, function(error) {
  if (error) {
    console.log('Fail!', error);
  } else {
    console.log('Done!');
  }
});
```

를 작성한다

package.json 의 scripts 에

"build-icons": "node ./build/webfont.generator.js",

를 입력하고 npm run build-icons를 실행한다.

그렇게 하면, icon-font-dest 폴더에 파일들이 생성이 되고,
iconfont.css 파일 안의 클래스로 사용하면 된다.

ex)
```pug
.icon-font.icon-font-baseline-autorenew-24px
```
