<!--基本指令-->
<!--<template>-->
<!--  <div class="HelloWorldStyle">-->
<!--&lt;!&ndash;Mustache: {{变量}} begin    &ndash;&gt;-->
<!--&lt;!&ndash;    字符串&ndash;&gt;-->
<!--    {{"哈哈"}}-->
<!--&lt;!&ndash;    数字&ndash;&gt;-->
<!--    {{1 + 1}}-->
<!--&lt;!&ndash;    三目运算法&ndash;&gt;-->
<!--    {{ 1 + 1 > 2 ? "YES" : "NO"}}-->
<!--&lt;!&ndash;    函数&ndash;&gt;-->
<!--    {{"hello".split('').reverse().join('')}}-->
<!--&lt;!&ndash;    使用变量&ndash;&gt;-->
<!--    {{msg}}-->
<!--&lt;!&ndash;Mustache: {{变量}} end    &ndash;&gt;-->

<!--&lt;!&ndash;v-once begin    &ndash;&gt;-->
<!--&lt;!&ndash;    当msg变化不会被渲染&ndash;&gt;-->
<!--    <p v-once>{{msg}}</p>-->
<!--&lt;!&ndash;    v-once end&ndash;&gt;-->
<!--&lt;!&ndash;    解析html结构 begin&ndash;&gt;-->
<!--    <div v-html = "hello"></div>-->
<!--&lt;!&ndash;    解析html结构 end&ndash;&gt;-->
<!--    &lt;!&ndash;    v-bind begin&ndash;&gt;-->
<!--    <a v-bind:href="url">{{url_name}}</a>-->
<!--    <div v-bind:class="divClass">容器</div>-->
<!--    <div :class="divClass + '-1'">容器1</div>-->
<!--    &lt;!&ndash;    v-bind end&ndash;&gt;-->

<!--    &lt;!&ndash;template begin&ndash;&gt;-->

<!--    &lt;!&ndash;template end&ndash;&gt;-->

<!--    &lt;!&ndash;v-if begin&ndash;&gt;-->
<!--      <div v-if="start_id + 1 === 1">1</div>-->
<!--      <div v-else-if="start_id + 1 === 2">2</div>-->
<!--      <div v-else>3</div>-->
<!--    &lt;!&ndash;v-if end&ndash;&gt;-->


<!--    &lt;!&ndash;flag begin&ndash;&gt;-->
<!--      <div v-show="flag">TRUE</div>-->
<!--    &lt;!&ndash;flag end&ndash;&gt;-->

<!--    &lt;!&ndash;v-for begin&ndash;&gt;-->
<!--    <p>name in names</p>-->
<!--    <ul>-->
<!--&lt;!&ndash;      直接遍历list,list中每一个参数是字符串&ndash;&gt;-->
<!--      <li v-for="name in names" :key="name"> {{name}} </li>-->
<!--    </ul>-->

<!--    <p>(name,index)  in names</p>-->
<!--    <ul>-->
<!--      &lt;!&ndash;遍历list,最后一个参数为索引,list中每一个参数是字符串&ndash;&gt;-->
<!--      <li v-for="(name,index)  in names" :key="index"> {{index + ' ' + name}} </li>-->
<!--    </ul>-->

<!--    <p>item in names2</p>-->
<!--    <ul>-->
<!--      &lt;!&ndash;遍历list,list中每一个参数是一个对象&ndash;&gt;-->
<!--      <li v-for="item in names2" :key="item"> {{item.name + ' ' + item.age}} </li>-->
<!--    </ul>-->

<!--    <p>(item,index)  in names2</p>-->
<!--    <ul>-->
<!--      &lt;!&ndash;遍历list,,最后一个参数为索引,item是list中的对象&ndash;&gt;-->
<!--      <li v-for="(item,index)  in names2" :key="index"> {{index + ' ' + item.name + ' ' + item.age}} </li>-->
<!--    </ul>-->

<!--    <p>item in names2   →   (value,key,index) in item</p>-->
<!--    <ul>-->
<!--      &lt;!&ndash;        取出names2中每一个对象&ndash;&gt;-->
<!--      <li v-for="item in names2" :key="item">-->
<!--        &lt;!&ndash;遍历对象,第一个参数是值,第二个参数是键,第三个参数是索引,只能使用在对象上,不能在list上使用&ndash;&gt;-->
<!--        <div class="liofli" v-for = "(value,key,index) in item" :key="index">{{ index+ '-' + key + '-' + value }}</div>-->
<!--      </li>-->
<!--    </ul>-->
<!--    &lt;!&ndash;v-for end&ndash;&gt;-->
<!--  </div>-->
<!--</template>-->
<!--data(){-->
<!--return{-->
<!--names:["name1","name2","name3"],-->
<!--names2:[-->
<!--{-->
<!--name:"name1",-->
<!--age:20-->
<!--},-->
<!--{-->
<!--name:"name1",-->
<!--age:20-->
<!--}-->
<!--],-->
<!--hello:"<h3>Hello H3</h3>",-->
<!--url_name:"百度",-->
<!--url:"https://www.baidu.com",-->
<!--divClass:'isActive',-->
<!--start_id:1,-->
<!--flag:true,-->

<!--}-->
<!--}-->


<!--事件处理-->
<template>
  <div class="HelloWorldStyle">
    <div v-if="flag">true</div>
    <div v-else>false</div>
    <!--template begin-->
      <button type="button" name="button" v-on:click = "clickHandler('hello1','hello2')">按钮</button>
      <ul>
        <li v-for="item in helloArr" :key="item">{{item}}</li>
      </ul>
      <button @click="addItem" type="button" name="button1">添加</button>
    <!--template end-->
    <!--template begin-->

    <!--template end-->
  </div>
</template>

<script>
export default {
  name: 'HelloWorld',
  props: {
    msg: String
  },
  data(){
    return{
      flag:true,
      helloArr:['h1','h2','h3'],
    }
  },
  methods:{
    clickHandler(data1,data2){
      //改变data中的数据\
      this.flag = !this.flag
      console.log(data1)
      console.log(data2)
    },
    addItem(){
      //改变原数组的方法引起页面更新
      this.helloArr.push('he')
      this.helloArr.unshift('hb')
      //未改变原数组的方法不能引起页面的更新,例如concat,filter返回的是一个新数组
      this.helloArr.concat(['hh'])
    }
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
  .liofli{
    display: inline-block;
    margin: 0 10px;
  }
</style>
