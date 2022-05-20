<template>
  <div class="myinput">
<!--    单行文本输入框-->
<!--    <input v-model="inputmsg" type="text" name="" value="">-->
<!--    lazy模式,转为change事件之后才会响应-->
<!--    <input v-model.lazy="inputmsg" type="text" name="" value="">-->
<!--    <p>{{inputmsg}}</p>-->
<!--    .number:自动转化为数值类型-->
<!--    <input v-model.number="number" type="text" name="" value="">-->
<!--    <p>{{number}}</p>-->
<!--    .trim:自动过滤用户输入的首尾空白字符-->
<!--        <input v-model.trim="inputmsg" type="text" name="" value="">-->
<!--        <p>{{inputmsg}}</p>-->

<!--    多行文本-->
<!--    <textarea v-model="message" placeholder="add multiple lines"></textarea>-->
<!--    <p style="white-space: pre-line;">多行文本是:{{ message }}</p>-->

<!--    复选框-->
<!--    单个复选框-->
<!--    <input type="checkbox" id="checkbox" v-model="checked">-->
<!--    <p>{{checked}}</p>-->
<!--    多个复选框绑定到同一个数组-->
<!--    <input type="checkbox" id="item1" value="itme1" v-model="checkedNames">-->
<!--    <label for="item1">itme1</label>-->
<!--    <input type="checkbox" id="item2" value="item2" v-model="checkedNames">-->
<!--    <label for="item2">item2</label>-->
<!--    <input type="checkbox" id="item3" value="item3" v-model="checkedNames">-->
<!--    <label for="item3">item3</label>-->
<!--    <br>-->
<!--    <span>Checked names: {{ checkedNames }}</span>-->
<!--    单选框-->
<!--      <input type="radio" id="one" value="One" v-model="picked">-->
<!--      <label for="one">One</label>-->
<!--      <br>-->
<!--      <input type="radio" id="two" value="Two" v-model="picked">-->
<!--      <label for="two">Two</label>-->
<!--      <br>-->
<!--      <span>Picked: {{ picked }}</span>-->
<!--    选择框-->
<!--    <select v-model="selected">-->
<!--      <option disabled value="">请选择</option>-->
<!--      <option>A</option>-->
<!--      <option>B</option>-->
<!--      <option>C</option>-->
<!--    </select>-->
<!--    <span>Selected: {{ selected }}</span>-->
<!--    如果 v-model 表达式的初始值未能匹配任何选项，<select> 元素将被渲染为“未选中”状态。在 iOS 中，这会使用户无法选择第一个选项。因为这样的情况下，iOS 不会触发 change 事件。因此，更推荐像上面这样提供一个值为空的禁用选项。-->

<!--    选择框多选-->
<!--    <select v-model="selects" multiple style="width: 50px;">-->
<!--      <option>A</option>-->
<!--      <option>B</option>-->
<!--      <option>C</option>-->
<!--    </select>-->
<!--    <br>-->
<!--    <span>Selects: {{ selects }}</span>-->

<!--    动态渲染选择框-->
    <select v-model="selected">
      <option v-for="option in options" :key="option" :value="option.value" >
        {{ option.text }}
      </option>
    </select>
    <span>Selected: {{ selected }}</span>

<!--    单选框值绑定-->
<!--    指定选中后picked的值 当值不一样时可以单选,当值一样时一样的名字的会全选-->
    <!-- 当选中时，`picked` 为字符串 "one" -->
    <input type="radio" v-model="picked" :value="radioCheckedValue" id="radio2">
    <!-- 当选中时，`picked` 为字符串 "two" -->
    <input type="radio" v-model="picked"  value="two" id="radio3">
<!--    <input type="radio" v-model="picked" :value="yes" id="radio2">-->
<!--    for的作用是使标签和radio绑定,点击文字相当于点击radio-->
<!--    <label for="radio2">forA</label>-->

    <p>{{picked}}</p>
    <button type="button" @click="showValue">获取value</button>
    <br>
    <!-- 复选框不绑定到数组类型,而是绑定到单值类型,例如true或false,则选中为true,没有选中为false,如果是数组类型,数组中的元素对应选择的checkbox的value-->
<!--    <input type="checkbox"  v-model="toggle">-->
<!--    <p>{{toggle}}</p>-->

<!--    指定选中与没有选中toggle的值-->
<!--    <input type="checkbox"  v-model="toggle" true-value="yes" false-value="no">-->
<!--    值可以是对象-->
    <input type="checkbox"  v-model="toggle" true-value="{number:123}" false-value="no">
    <p>{{toggle}}</p>

    <!-- 单值类型,单选按钮,当选中第一个选项时，`selected`为value属性"abc",没有value属性则对应标签名ABC -->
    <select v-model="selected">
      <option value="abc">ABC</option>
    </select>
    <p>{{selected}}</p>


    <select v-model="selected">
      <option disabled value="">请选择</option>
      <option value='a'>A</option>
      <option>B</option>
      <option>C</option>
    </select>

    {{selected}}




<!--    watch:监听事件:实时监听数据变化,watch的函数名必须为要监听的变量的名字,但是能用computed属性就用computed-->

      </div>
</template>

<script>
export default {
  name: "表单与侦听器",
  methods:{
    showValue(){
      let value = document.getElementById("radio2").value
      console.log(value)
    }
  },
  data(){
    return{
      radioCheckedValue:'checked',
      number:10,
      inputmsg:"",
      checked:true,
      message:``,
      checkedNames: [],
      picked:'',
      selected:'',
      selects:[],
      options:[
        { text: 'One', value: 'A' },
        { text: 'Two', value: 'B' },
        { text: 'Three', value: 'C' }
      ],
      toggle:true
    }
  }
}
</script>

<!--scopped属性使组件中的样式只在当前组件中生效-->
<!--<style scoped>-->
<style>
.container{
  background: aqua;
}
</style>