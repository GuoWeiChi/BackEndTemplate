<template>
<!--只能存在一个根容器-->
  <div class="container">
    组件名:{{mytitle}}
<!--    vmodel动态传递数据-->
    <input v-model="searchText">
    <button @click = "sendMsg" type="button" name="button">给父组件传递数据</button>
  </div>
</template>

<script>
export default {
  name: "Demo005_基本组件创建",
  //props中的双引号不能少
  props:["mytitle"],
//  所有的初始化状态全部放入data中,data必须是一个函数
  data(){
    return{
      searchText:""
    }
  },
  methods:{
    sendMsg(){
      //第一个参数相当于信号名,第二个参数是发送的参数
      // this.$emit("getMsg","来自子组件的数据")
      //传递动态数据
      this.$emit("getMsg",this.searchText)
    }
  }
}
</script>

<!--样式-->
<!--scopped属性使组件中的样式只在当前组件中生效-->
<!--<style scoped>-->
<style>
.container{
  background: aqua;
}
</style>