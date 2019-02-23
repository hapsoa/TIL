# $refs

```
```

# vue component class를 활용시 

```typescript
// @ts-ignore-nextline
public $refs: Vue['$refs'] & {
    editor: Editor;
};
```
editor 는 ref='editor'로 설정했고, 
Editor는 Editor.vue파일의 Editor.ts파일을 import한 것이다.