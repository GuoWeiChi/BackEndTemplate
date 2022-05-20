<template>
  <div class="parent">
    父组件
<!--    <child title="来自父组件数据" @msg_sig = "getChildMsg"/>-->
<!--    传递两个数据-->
<!--    <child title="来自父组件数据title" author="来自父组件数据author" @msg_sig = "getChildMsg"/>-->
<!--    指定类型-->
<!--    输入与number类型绑定-->
    <input type="number" v-model.number="price"/>
    <!--    没有冒号:,传入的数据都是字符串类型-->
<!--    <child title="来自父组件数据title" author="来自父组件数据author" :price="price" @msg_sig = "getChildMsg"/>-->
<!--    默认值-->
<!--    <child title="来自父组件数据title" author="来自父组件数据author"  @msg_sig = "getChildMsg"/>-->
<!--    传递数组类型-->
    <child title="来自父组件数据title" author="来自父组件数据author"  :chapers="[1,2,3]" @msg_sig = "getChildMsg"/>
    {{msgFromChild}}

    <br>
    全局变量:{{getGData1}}
    <br>
<!--    通过ref获取原生dom-->
    <p ref="p1">原生p标签</p>

  </div>
</template>

<script>
import child from "./child";

export default {
  name: "parent",
  components: {
    child
  },
  methods:{
    getChildMsg(data){
      this.msgFromChild = data;
    }
  },
  //全局属性访问得从computed计算属性中读取
  computed:{
    getGData1(){
      return this.$root.g_data1
    }
  },
  data(){
    return{
      msgFromChild:"",
      price:0,
    }
  },
  mounted() {
    this.$refs.p1.innerHTML = "改变"
  }

}
</script>

<style scoped>
.parent{
  background-color: aqua;
}
</style>