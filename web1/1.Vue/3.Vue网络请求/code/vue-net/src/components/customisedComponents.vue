<template>
<div>
  <input type="text" v-focus name="" value=""/>
<!--  大写字母要用-加小写字母代替-->
  <input type="text" v-model = "inputData" v-my-style name="" value=""/>
  <br>
  {{inputData}}
</div>
</template>

<script>
import Vue from "vue";

export default {
  name: "customised-components",
  data(){
    return{
      inputData:""
    }
  },
  //局部指令
  directives: {
    "focus": {
      //当前指令的生命周期,el:HtmlElement
      bind: function (el, binding) {
        console.log("初始化...")
        console.log(binding)
      },
      inserted: function (el) {
        console.log("插入父节点调用...")
        el.focus();
      },
      update: function (el) {
        console.log("更新时调用...")
        el.focus();
      }
    },
    myStyle:{
      inserted:function (el){
        el.style.fontSize = "50px";
      }
    }
  }
}
</script>

<style scoped>

</style>