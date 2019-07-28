## 따라 설치하기 좋은 링크(brew, git, iTerm2 셋팅 등등)

https://subicura.com/2017/11/22/mac-os-development-environment-setup.html

## 위 링크가 우선.

brew 를 설치한다.

운영체제마다 설치관리자가 있다.
Mac : brew
Ubuntu : apt
CentOS : curl
RedHat : yum

1.맥을 포맷한다. (한영 처리, spotlight 처리, chrome 설치 등 잡다한 것)

2.brew(package manager)를 설치한다.

(homeBrew) 홈페이지에 들어가면 터미널 명령어가 있다.

```
brew update
```

3.Node를 설치한다.

```
brew install node
```

npm i -g npx 을 한다.

npm i -g babel-cli X
npm i -g web pack X

Global로 설치가 되기 때문에 버전관리에 취약하다.

각 프로젝트 별 환경설정을 전역이 아닌 각각 구성한다.

ngrok, http-server
프로젝트 내부에 포함되는 모듈이 아니다. 프로젝트 외부에서 실행하거나 독립적으로 실행하는 모듈

npm i -g grok
npm i -g http-server

# visual studio code

command p(ctrl + p) : 현재 폴더에서 명령어
command shift p : ide 자체의 명령어

command shift p 후 shell 에서 제일 위에서 엔터를 하면 vscode를 터미널에서 실행할수 있게함. ("code ." 치면 열린다)

extension

vue.js extension pack
(gitLens, Vue vsCode Snippets)

# 생짜로 처음으로 프로젝트 시작할 때

npm init

(license ISC or MIT)

모든 node의 프로젝트는 package.json 으로 돌아간다.

src, dist 폴더를 만든다.

npm install typescript

npx tsc
(node_modules 안의 tsc를 터미널에서 명령어로 사용할 수 있게 한다)

tsconfig.json 파일을 루트에 만든다.

```
{
    "compilerOptions": {
        "target": "es6",
        "module": "commonjs",    // require 쓰는 녀석
        "outDir": "dist",
        "sourceMap": true
    },
    "include": [
        "src/**/*.ts"
    ],
    "exclude": [
        "node_modues"
    ]
}
```

command + , : setting 창

```
npm install @vue/cli -g
```

```


npx tsc --init
```

후에

```
npx tsc
```

를 하면 실행이 된다.

jsdoc comments 설치

게시글이라는 클래스가 있음
내부의 자료구조와 함수 설계

head,
body,
date,
recommand,

increaseRecommand ...
decreaseRecommand ...

util
formatter
number
string
time
setDefaultFormat(format: string),
get(time or date)
getTimeByFormat(format, time or date)

YYYY-MM-DD hh:mm:ss

const formatter = {
get(time: number | string | Date | undefined): string {
return "1997-06-12"
}
}

AMD import... export default or {} -클라이언트에서 돌아가고
CommonJs require... module.exports -node에서 돌아가고 , 클라이언트도 되고
