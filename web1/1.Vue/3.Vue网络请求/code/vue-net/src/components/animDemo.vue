<template>
  <div class="anim">
    <button v-on:click="show = !show">Button</button>
<!--    淡入淡出-->
<!--    <transition name="myFade">-->
<!--      <h1 v-if="show">hello</h1>-->
<!--    </transition>-->
<!--    变大变小-->
<!--    <transition name="trans">-->
<!--      <h1 class="big" v-if="show">hello</h1>-->
<!--    </transition>-->
<!--    动画-->
<!--<! &#45;&#45;    <transition name="myAni">&ndash;&gt;-->
<!--      <h1 class="big" v-if="show">hello</h1>-->
<!--    </transition>-->
<!--    使用第三方动画-->
<!--    <transition-->
<!--      name="custom-classes-transition"-->
<!--      enter-active-class="animated tada"-->
<!--      leave-active-class="animated bounceOutRight"-->
<!--    >-->
    <transition
      name="custom-classes-transition"
      enter-active-class="animated rotateIn"
      leave-active-class="animated zoomOutDown"
    >
      <h1 class="big" v-if="show">hello</h1>
    </transition>
  </div>
</template>

<script>
export default {
  name: "animDemo",
  data(){
    return{
      show:true
    }
  }
}
</script>

<style scoped>

/*淡入淡出效果*/
/*Opacity为0的状态*/
.myFade-enter,.myFade-leave-to{
  opacity: 0;
}

/*Opacity为1的状态*/
.myFade-enter-to,.myFade-leave{
  opacity: 1;
}

/*过渡*/
.myFade-enter-active,.myFade-leave-active{
  transition: opacity 3s;
}

.big{
  width: 100px;
  height: 100px;
  background: aquamarine;
  /*脱离文档流*/
  position:fixed;
}

/*Opacity为0的状态*/
.trans-enter,.trans-leave-to{
  opacity: 0;
  width: 0;
  height: 0;
}

/*Opacity为1的状态*/
.trans-enter-to,.trans-leave{
  opacity: 1;
  width: 100px;
  height: 100px;
}

/*过渡*/
.trans-enter-active,.trans-leave-active{
  transition: all 3s;
}


/*Opacity为0的状态*/
.myAni-enter,.myAni-leave-to{

}

/*Opacity为1的状态*/
.myAni-enter-to,.myAni-leave{

}

/*过渡*/
.myAni-enter-active{
  animation: bounce-in 1s;
}

.myAni-leave-active{
  animation: bounce-out 1s;
}

/*关键帧动画,淡入*/
@keyframes bounce-in {
  0%{
    transform: scale(0);
  }
  50%{
    transform: scale(1.5);
  }
  100%{
    transform: scale(1);
  }
}

/*关键帧动画,淡出*/
@keyframes bounce-out {
  0%{
    transform: scale(1);
  }
  50%{
    transform: scale(1.5);
  }
  100%{
    transform: scale(0);
  }
}

</style>