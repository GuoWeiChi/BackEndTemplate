import Vue from 'vue'
import App from './App.vue'
import Axios from "axios"


Vue.prototype.$axios = Axios
Vue.config.productionTip = false

// 全局指令
Vue.directive("focus",{
  //当前指令的生命周期,el:HtmlElement
  bind:function(el,binding){
    console.log("初始化...")
    console.log(binding)
  },
  inserted:function(el){
    console.log("插入父节点调用...")
    el.focus();
  },
  update:function(el){
    console.log("更新时调用...")
    el.focus();
  }
})

new Vue({
  render: h => h(App),
  data:{
    //全局都可以访问
    g_data1:"gloable value1"
  }
}).$mount('#app')
