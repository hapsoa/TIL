# vue를 class로 component를 만들 수 있다. (vue-component-class)

```typescript
import Vue from "vue";
import { Component, Watch, Prop } from "vue-property-decorator";
import ReCommentComponent from "@/components/ReCommentComponent/ReCommnentComponent.vue";

@Component({
  components: {
    ReCommentComponent,
    EditorComponent
  }
})
export default class Editor extends Vue {
  public $refs!: {
    page: HTMLDivElement;
    canvas: HTMLCanvasElement;
    editor: Editor;
    // editor 는 ref='editor'로 설정했고,
    // Editor는 Editor.vue파일의 Editor.ts파일을 import한 것이다.
  };

  // 이게 버그가 없다.
  @Prop({ type: Number, default: 1000 }) public limitLength!: number;
  @Prop({ required: true, type: Object as () => BoardPostType })
  public asdf!: BoardPostType;

  private created() {
    this.$props.comment; // props 접근할 때
    this.$props.limitLength; // props 접근할 때
    this.$refs.editor.addRect(); // ref중 canvas의 addRect() 메소드 호출
  }

  // watch
  // pagination.page가 변경되는 변수이름
  // { deep: true }는 pagination이 object이기 때문에 그 안의 변수를 인식하기 위해서 사용. 그렇지 않다면 안써도 됨.
  // onPageChanged는 pagination.page와 이름만 다르게
  @Watch("pagination.page", { deep: true })
  public onPageChanged(value: number, oldValue: number) {
    console.log("page", value);
    this.setCommentList(value);
  }

  // computed
  get isNonMember(): boolean {
    if (!_.isNil(this.boardInstance)) {
      return _.isNil(this.boardInstance.uid);
    }
    return false;
  }
  // computed setter
  set isNonMember(variable: boolean) {
    // ....
  }
}
```

<br>

# mixin (vue-component-class 에서)

mixin

```javascript
export default class EditorMixin extends Vue {}
```

<br>

extends 받는 것

```javascript
import { mixins } from "vue-class-component";
import EditorMixin from "./editor-mixin";

export default class BoardEditing extends mixins(EditorMixin) {}
```
