# vue를 class로 component를 만들 수 있다.

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
