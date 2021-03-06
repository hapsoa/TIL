# gaesory.com을 만들면서 셋팅

Cmd+shift+p => setting(json)에

```json
{
  "typescript.locale": "ko",
  "editor.fontSize": 12,
  "terminal.integrated.lineHeight": 1.2,
  "terminal.integrated.letterSpacing": 0.5,
  "terminal.integrated.fontSize": 12,
  "terminal.integrated.fontWeight": "400",
  "terminal.integrated.fontWeightBold": "600",
  "terminal.integrated.fontFamily": "Monaco",
  "editor.tabCompletion": "on",
  "editor.fontFamily": "Monaco, Menlo, monospace",
  "editor.tabSize": 2,
  "editor.insertSpaces": true,
  "editor.detectIndentation": false,

  "eslint.validate": [
    {
      "language": "vue",
      "autoFix": true
    },
    {
      "language": "html",
      "autoFix": true
    },
    {
      "language": "javascript",
      "autoFix": true
    }
  ],
  "markdown.preview.fontSize": 16,

  "prettier.tslintIntegration": true,
  "prettier.stylelintIntegration": true,
  "window.zoomLevel": 1,
  "javascript.preferences.quoteStyle": "single",
  "typescript.preferences.quoteStyle": "single",
  "prettier.singleQuote": true,
  "editor.formatOnPaste": true,
  "prettier.useTabs": false,
  "prettier.tabWidth": 2,
  "files.associations": {
    "*.vue": "vue"
  },
  "html.format.wrapAttributes": "force-aligned",
  "vetur.format.defaultFormatter.js": "vscode-typescript",
  "vetur.format.defaultFormatter.html": "js-beautify-html",
  "vetur.format.defaultFormatterOptions": {
    "js-beautify-html": {
      "wrap_attributes": "force-aligned"
    }
  },
  "javascript.format.insertSpaceBeforeFunctionParenthesis": true,
  "eslint.autoFixOnSave": true,
  "editor.formatOnSave": true,
  "npm-scripts.showStartNotification": false
}
```

vue.config.js 에

```javascript
module.exports = {
  devServer: {
    /**
     * 127.0.0.1 / localhost : 192.168.11.x hotreload 가 안되는 경우가 발생한다. */
    host: '0.0.0.0',
    disableHostCheck: true,
  },
  // baseUrl: '/dynamic-network',
  outputDir: undefined,
  assetsDir: undefined,
  runtimeCompiler: undefined,
  productionSourceMap: undefined,
  parallel: undefined,
  css: undefined,
  configureWebpack: {
    performance: { hints: false },
  },
};
```

<br>

tsconfig.json

```json
{
  "compilerOptions": {
    "target": "esnext",
    "module": "esnext",
    "strict": true,
    "jsx": "preserve",
    "importHelpers": true,
    "moduleResolution": "node",
    "experimentalDecorators": true,
    "esModuleInterop": true,
    "allowSyntheticDefaultImports": true,
    "sourceMap": true,
    "baseUrl": ".",
    "resolveJsonModule": true,
    "types": ["webpack-env"],
    "paths": {
      "@/*": ["src/*"]
    },
    "lib": ["esnext", "dom", "dom.iterable", "scripthost"]
  },
  "include": [
    "src/**/*.ts",
    "src/**/*.tsx",
    "src/**/*.vue",
    "tests/**/*.ts",
    "tests/**/*.tsx"
  ],
  "exclude": ["node_modules"]
}
```

<br>

.prettierrc

```
{
  "singleQuote": true,
  "trailing-comma": false,
  "no-submodule-imports": false,
  "no-console": false,
  "no-implicit-dependencies": false
}
```

<br>

tslint.json 에서

rules 프로퍼티 안의 quotemark 안을 true로 변경한다.

vue 파일에서는 .prettierrc 가 ts를 조정하고
ts 파일에서는 tslint가 적용이 되는듯 하다.
