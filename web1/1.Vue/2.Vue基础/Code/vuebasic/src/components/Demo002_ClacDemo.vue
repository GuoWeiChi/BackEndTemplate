<template>
  <div>
    {{getMsg}}
    {{getMsg}}
    {{getMsg}}
    <input type="button" value="testNum加1" name="button" @click="clickHandler">
  </div>
</template>

<script>
export default {
  name: "ClacDemo",
  //计算属性
  computed:{
    getMsg(){
      console.log('-------')
      console.log(this.testNum)
      return this.msg.split('').reverse().join('')
    }
  },
  methods:{
    clickHandler() {
      this.testNum += 1
    }
  },
  data(){
    return{
      msg:"hello",
      testNum:1
    }
  }
}
</script>

<style scoped>

</style>