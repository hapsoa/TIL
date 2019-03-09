# vue를 class로 component를 만들 수 있다. (vue-component-class)

```typescript
import Vue from 'vue';
import { Component, Watch } from 'vue-property-decorator';

@Component({
  props: {
    comment: {
      type: Object as () => Comment,
      required: true,
    },
  },
  components: {
    ReCommentComponent,
    EditorComponent,
  },
})
export default class Editor extends Vue {
  // @ts-ignore-nextline
  public $refs: Vue['$refs'] & {
    editor: Editor;
    // editor 는 ref='editor'로 설정했고,
    // Editor는 Editor.vue파일의 Editor.ts파일을 import한 것이다.
    loadDialog;
  };

  private created() {
    this.$props.comment; // props 접근할 때
  }

  // watch
  @Watch('pagination.page', { deep: true })
  public onPageChanged(value: number, oldValue: number) {
    console.log('page', value);
    this.setCommentList(value);
  }

  // computed
  get isNonMember(): boolean {
    if (!_.isNil(this.boardInstance)) {
      return _.isNil(this.boardInstance.uid);
    }
    return false;
  }
}
```

<br>

# mixin (vue-component-class 에서)

```javascript
import { mixins } from 'vue-class-component';
import EditorMixin from './editor-mixin';

export default class BoardEditing extends mixins(EditorMixin) {
  
}
```
