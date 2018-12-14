# Compiler Options

공식 문서
```
http://json.schemastore.org/tsconfig
```

<br>

최상위 프로퍼티
```
compileOnSave
extends
compileOptions
files
include
exclude
typeAcquisition (잘 안씀)
```

## compileOnSave

true / false (default false)

최상단에 설정해야 한다 ?

누가 ?? 아래 두개의 환경에서만

Visual Studio 2015 with TypeScript 1.8.4 이상

atom-typescript 플러그인 

<br>

## extends

파일 (상대) 경로명: string

TypeScript 2.1 New Spec

```typescript
// in config/base.json
{
  "compilerOptions": {
    "noImplicitAny": true,
    "strictNullChecks": true
  }
}


// in tsconfig.json
{
  "extends": "./configs/base",
  "files": [
    "main.ts",
    "supplemental.ts"
  ]
}
```

<br>

## files, include, exclude

셋다 설정이 없으면, 전부다 컴파일

```
files
    상대 혹은 절대 경로의 리스트 배열입니다.
    exclude 보다 쎕니다.
```
```
include, exclude
- glob 패턴 (마치 .gitignore)
- include
    exclude 보다 약합니다.
    * 같은걸 사용하면, .ts / .tsx / .d.ts 만 include (allowJS)
- exclude
    설정 안하면 4가지(node_modules, bower_components, jspm_packages, <outDir>)를 default 로 제외합니다. (아하!)

    <outDir> 은 항상 제외합니다. (include 에 있어도)
```

<br>

## compileOptions

## compileOptions : type

```json
{
    "type": "object",
    "description": "Instructs the TypeScript compiler how to compile .ts files.",
    "properties": {
        "typeRoots": {
            "description": "Specify list of directories for type definition files to be included. Requires TypeScript version 2.0 or later.",
            "type": "array",
            "items": {
                "type": "string"
            }
        },
        "types": {
            "description": "Type declaration files to be included in compilation. Requires TypeScript version 2.0 or later.",
            "type": "array",
            "items": {
                "type": "string"
            }
        }
    }
}
```
```
TypeScript 2.0 부터 사용 가능해진 내장 type definition 시스템

아무 설정을 안하면 ?
- node_modules/@types 라는 모든 경로를 찾아서 사용

typeRoots 를 사용하면 ?
- 배열 안에 들어있는 경로들 아래서만 가져옵니다.

types 를 사용하면 ?
- 배열 안의 모듈 혹은 ./node_modules/@types/ 안의 모듈 이름에서 찾아옵니다.
- [] 빈 배열을 넣는다는건 이 시스템을 이용하지 않겠다는 것입니다.

typeRoots 와 types 를 같이 사용하지 않습니다.
```

<br>

## compileOptions : target 과 lib

```json
{
    "type": "object",
    "description": "Instructs the TypeScript compiler how to compile .ts files.",
    "properties": {
        "target": {
            "description": "Specify ECMAScript target version. Permitted values are 'es3', 'es5', 'es2015', 'es2016', 'es2017' or 'esnext'.",
            "type": "string",
            "default": "es3",
            "anyOf": [
                {
                    "enum": [
                        "es3",
                        "es5",
                        "es2015",
                        "es2016",
                        "es2017",
                        "esnext"
                      ]
                }, {
                      "pattern": "^([eE][sS]([356]|(201[567])|[nN][eE][xX][tT]))$"
                }
            ]
        },
        "lib": {
            "description": "Specify library file to be included in the compilation. Requires TypeScript version 2.0 or later.",
            "type": "array",
            "items": {
                "type": "string",
                "enum": [ "es5", "es6", "es2015", "es7", "es2016", "es2017", "esnext", "dom", "dom.iterable", "webworker", "scripthost", "es2015.core", "es2015.collection", "es2015.generator", "es2015.iterable", "es2015.promise", "es2015.proxy", "es2015.reflect", "es2015.symbol", "es2015.symbol.wellknown", "es2016.array.include", "es2017.object", "es2017.sharedmemory", "esnext.asynciterable"
                ]
            }
        },
        "noLib": {
            "description": "Do not include the default library file (lib.d.ts).",
            "type": "boolean"
        }
    }
}
```

```
target
- 빌드의 결과물을 어떤 버전으로 할 것이냐
- 지정을 안하면 es3 입니다.

lib
- 기본 type definition 라이브러리를 어떤 것을 사용할 것이냐

- lib 를 지정하지 않을 때,
    target 이 'es3' 이고, 디폴트로 lib.d.ts 를 사용합니다.
    target 이 'es5' 이면, 디폴트로 dom, es5, scripthost 를 사용합니다.
    target 이 'es6' 이면, 디폴트로 dom, es6, dom.iterable, scripthost 를 사용합니다.

- ​lib 를 지정하면 그 lib 배열로만 라이브러리를 사용하니다.
    ​빈 [] => 'no definition found 어쩌구'
```

<br>

## compileOptions : outDir, outFile 

```json
{
    "type": "object",
    "description": "Instructs the TypeScript compiler how to compile .ts files.",
    "properties": {
        "outFile": {
            "description": "Concatenate and emit output to single file.",
            "type": "string"
        },
        "outDir": {
            "description": "Redirect output structure to the directory.",
            "type": "string"
        },
        "rootDir": {
            "description": "Specifies the root directory of input files. Use to control the output directory structure with --outDir.",
            "type": "string"
        }
    }
}
```

<br>

## compileOptions : module

```json
{
    "type": "object",
    "description": "Instructs the TypeScript compiler how to compile .ts files.",
    "properties": {
        "module": {
            "description": "Specify module code generation: 'none', 'CommonJS', 'Amd', 'System', 'UMD', or 'es2015'.",
            "enum": [ "commonjs", "amd", "umd", "system", "es6", "es2015", "none" ]
        },
        "moduleResolution": {
            "description": "Specifies module resolution strategy: 'node' (Node) or 'classic' (TypeScript pre 1.6) .",
            "type": "string",
            "pattern": "^(([Nn]ode)|([Cc]lassic))$",
            "default": "classic"
        },
        "baseUrl": {
            "description": "Base directory to resolve non-relative module names.",
            "type": "string"
        },
        "paths": {
            "description": "Specify path mapping to be computed relative to baseUrl option.",
            "type": "object"
        },
        "rootDirs": {
            "description": "Specify list of root directories to be used when resolving modules.",
            "type": "array",
            "items": {
                "type": "string"
            }
        }
    }
}
```
```
module
- 컴파일 된 모듈의 결과물을 어떤 모듈 시스템으로 할지를 결정
- target 이 'es6' 이면 es6 가 디폴트이고,
- target 이 'es6' 가 아니면 commonjs 가 디폴트 입니다.
- AMD 나 System 와 사용하려면, outFile 이 지정되어야 합니다.
- ES6 나 ES2015 를 사용하려면, target 이 es5 이하여야 합니다.

moduleResolution
- ts 소스에서 모듈을 사용하는 방식을 지정해야 합니다.
- Classic 아니면 Node 입니다.
- CommonJS 일때만 Node 라고 생각하시면 됩니다.

paths 와 baseUrl
- 상대경로 방식이 아닌 baseUrl 로 꼭지점과 paths 안의 키/밸류로 모듈을 가져가는 방식입니다.

rootDirs : 배열 안에서 상대 경로를 찾는 방식입니다.
```