<template>
<div>
<!--  <slot></slot>-->
<!--  具名插槽-->
  <slot name="slot1"></slot>

  <slot name="slot2" >
    没有传递slot2,显示默认值
  </slot>

<!--  传递数据给父组件,这样做的好处是显示的效果可以由父组件决定-->
  <slot ct="来自子组件的数据"></slot>
</div>
</template>

<script>
export default {
  name: "slotDemo"
}
</script>

<style scoped>

</style>