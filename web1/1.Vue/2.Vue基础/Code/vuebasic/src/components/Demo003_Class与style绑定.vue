<template>
  <div>
    <!--  hot-fix-Test-->
    <!--  直接使用-->
<!--      <div :class="classDemo">-->
    <!--  判断是否使用  动态绑定的属性和本身的属性不冲突-->
    <!--  <div :class="{'active':classFlag,'txt':classFlag}">-->
    <!--  根据条件切换-->
<!--    <div :class="[classFlag?activeClass : '','txt']">-->
<!--      css-->
<!--    </div>-->
<!--    绑定计算属性-->
    <div :class="cssObj">
      css2
    </div>
    <button type="button" @click="changeCss">改变css2样式</button>

<!--    应用中常用的样式格式-->
<!--    注意:对象中的键只能接受字符串,在数组中可以接收对象-->
    <div class="old" :class="[classFlag ? classDemo : 'notactive',{'active':activeFlag}]">
      应用中常用样式
    </div>


<!--    内联样式-->
<!--    固定值-->
<!--    <div :style="{color:'red',font}">-->
<!--    动态绑定-->
    <div :style="{color:this.color,font}">
      内联样式
    </div>
  </div>
</template>

<script>
export default {
  name: "ClassStyle",
  data(){
    return{
      color:'green',
      classDemo:"txt",
      activeFlag:true,
      classFlag:true,
      c1:true,
      c2:false,
    }
  },
  computed:{
    cssObj(){
      return {'c1':this.c1, 'c2':this.c2}
    }
  },
  methods:{
    changeCss(){
      this.c1 = !this.c1
      this.c2 = !this.c2
    }
  }
}
</script>

<style scoped>

.active{
  color: red;
}

.txt{
  font-size: 30px;
}

.c1{
  color: red;
}

.c2{
  font-size: 30px;
}
</style>