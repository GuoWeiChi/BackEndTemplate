<template>
 <div>
   {{ money | rmb | author}}
 </div>
</template>

<script>
export default {
  name: "filterDemo",
  data(){
    return{
      money:100
    }
  },
  filters:{
    rmb:function (value){
      if(!value) return;
      value = value.toString()
      return "￥" + value;
    },
    author:function (value){
      if(!value) return;
      return  value+"----------来自author";
    }
  }
}
</script>

<style scoped>

</style>