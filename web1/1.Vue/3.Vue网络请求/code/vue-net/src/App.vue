<template>
  <div id="app">
    <img alt="Vue logo" src="./assets/logo.png">
<!--    <animDemo/>-->
    <axios-demo/>
  </div>
</template>

<script>
import HelloWorld from './components/HelloWorld.vue'
import child from "./components/child";
import parent from "./components/parent";
import slotDemo from "./components/slotDemo";
import animDemo from "./components/animDemo";
import customisedComponents from "./components/customisedComponents"
import filterDemo from "./components/filterDemo";
import AxiosDemo from "./components/AxiosDemo";

export default {
  name: 'App',
  components: {
    AxiosDemo
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
