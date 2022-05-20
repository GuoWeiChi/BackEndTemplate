<template>
  <div id="app">
    <img alt="Vue logo" src="./assets/logo.png">
<!--    <ClassStyle/>-->
<!--    <ClacDemo/>-->
<!--    <FormDemo/>-->
<!--    基本数据-->
<!--    <vueTemplate mytitle="123"/>-->
<!--    复杂数据,数据可以是动态的-->
<!--    <vueTemplate :mytitle="mytitle"/>-->
<!--    {{msgOfSon}}-->
<!--    接收子组件的信号,将子组件发出的信号getMsg与父组件的函数getSonMsg绑定-->
<!--    <vueTemplate @getMsg="getSonMsg" :mytitle="mytitle"/>-->

<!--    keep-alive保证组件不重复渲染-->
    <keep-alive>
      <component v-bind:is="mycomponent"/>
    </keep-alive>

    <button @click = "changeComponent" type="button" name="button">改变组件</button>

  </div>
</template>

<script>
// import HelloWorld from './components/HelloWorld.vue'
// import Demo002_ClacDemo from "./components/Demo002_ClacDemo";
// import Demo003_Class与style绑定 from "./components/Demo003_Class与style绑定"
import Demo004_表单与侦听器 from "./components/Demo004_表单与侦听器"
import Demo005_基本组件创建 from "./components/Demo005_基本组件创建";
import Demo006_A from "./components/Demo006_A";
import Demo006_B from "./components/Demo006_B";

export default {
  name: 'App',
  components: {
    // ClassStyle:Demo003_Class与style绑定,
    // HelloWorld,
    // ClacDemo:Demo002_ClacDemo
    // FormDemo:Demo004_表单与侦听器
    // vueTemplate:Demo005_基本组件创建
    // componentA:Demo006_A,
    // componentB:Demo006_B,
  },
  methods:{
    getSonMsg(msg){
      console.log("=======")
      this.msgOfSon = msg;
    },
    changeComponent(){
      if(this.mycomponent == Demo006_A){
        this.mycomponent = Demo006_B
      }else{
        this.mycomponent = Demo006_A
      }
    }
  },
  data(){
    //注意:使用v-bind:is,组件应该放在data中
    return{
      //mycomponent,默认为Demo006_A
      mycomponent:Demo006_A,
      msgOfSon:"",
      mytitle:{name:"父组件名称"}
    }

  }
}
</script>

<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
</style>
