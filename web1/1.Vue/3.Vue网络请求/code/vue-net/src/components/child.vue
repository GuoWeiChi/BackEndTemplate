<template>
  <div class="child">
    子组件:<br/>
    title:{{title}}<br/>
    author:{{author}}<br/>
    price:{{price}}<br/>
    chapters:{{chapers}}<br/>
    <input v-model="childMsg">
    <button @click = "sendMsg" type="button" name="button">子组件发送数据</button>
  </div>
</template>

<script>
export default {
  name: "child",
  //不指定类型
  // props:["title","author"],
  //指定类型,一般都要指定类型
  props:{
    //必选项
    title:{
      type:String,
      required:true
    },
    author:String,
    //设置默认值
    price:{
      type:Number,
      default:100
    },
    //注意,默认值如果是数组或者对象,必须返回一个function
    chapers:{
      type:Array,
      default: function (){
        //如果是对象这返回{}
        return ['1','2']
      }
    }
  },
  methods:{
    sendMsg(){
      this.$emit("msg_sig",this.childMsg);
    }
  },
  data(){
    return{
      childMsg:"来自子组件的数据"
    }
  }
}
</script>

<style scoped>
.child{
  background-color: darkgray;
}
</style>