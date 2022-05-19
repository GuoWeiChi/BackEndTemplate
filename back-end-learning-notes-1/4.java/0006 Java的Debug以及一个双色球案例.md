> <strong>本专栏将从基础开始，循序渐进，由浅入深讲解Java的基本使用，希望大家都能够从中有所收获，也请大家多多支持。</strong>
> <strong>专栏地址:[22天掌握Java编程](https://blog.csdn.net/learning_xzj/category_11806176.html) </strong>
> <strong>相关软件地址:[链接地址](https://pan.baidu.com/s/1bXCZR0yxN2-v6NqDpe4H1g?pwd=1111) </strong>
> <strong>所有代码地址:[链接地址](https://gitee.com/codinginn/java-code) </strong>
> <strong> 如果文章知识点有错误的地方，请指正！大家一起学习，一起进步。</strong>
> <font color="red"><strong> 如果感觉博主的文章还不错的话，还请关注、点赞、收藏三连支持一下博主哦</strong></font>

@[toc]



## 1.进制

### 1.1 常见的进制分类(掌握)

> * 二进制
> * 十进制
> * 八进制
> * 十六进制
>

### 1.2 二进制

> ​	计算机数据在底层存储和运算的时候，都是以二进制的形式操作的，了解不同的进制，便于我们对数据的运算过程理解的更加深刻。
>
> ​	二进制数据是用0和1两个数码来表示。例如：0101000。进位规则是“逢二进一”，借位规则是“借一当二”。
>
> 练习：
>
> ​	思考一下，十进制中的0,1,2,3,4在二进制中如何表示：
>

```java
十进制中的0 --->  二进制中的表现形式 0
十进制中的1 --->  二进制中的表现形式 1
十进制中的2 --->  二进制中的表现形式 10
十进制中的3 --->  二进制中的表现形式 11
十进制中的4 --->  二进制中的表现形式 100
十进制中的5 --->  二进制中的表现形式 101   
```

<font color="red">**扩展1：**</font>

> ​	计算机的底层不管是数字还是图片，还是字母，还是汉字，还是音频，还是视频，都是以二进制的形式来存储的。
>
> 数字：123，直接转成二进制来存储的。
>
> 字母：'a'  会先到ASCII码表中查询对应的数字，再变成二进制进行存储。
>
> 其他的就业班IO流章节会再次学习。
>

<font color="red">**扩展2：**</font>

> ​	存储的单位
>
> ​	在计算机中，存储的时候，都是以二进制的形式来存储的。
>
> ​	其中一个0或者1个1，我们会叫做一个bit位，比特位。
>
> ​	在二进制中，一个0或者一个1，能存储的信息太少了。
>
> ​	所以，我们一般会把8个二进制分为一组，这个单位叫做字节，而**字节也是计算机中最小的存储单元。**
>
> ​	0000 0000  1个字节
>
> ​	1024 字节 = 1KB
>
> ​	1024 KB = 1MB
>
> ​	1024 MB = 1GB
>
> ​	1024 GB = 1TB
>

<font color="red">**扩展3：**</font>

> ​	byte 在底层 占用1个字节（掌握的）
>
> ​	short 在底层 占用2个字节（掌握的）
>
> ​	int  在底层占用 4个字节（掌握的）
>
> ​	long 在底层占用 8 个字节（掌握的）
>
> 隐式转换的底层原理：（了解）
>
> ​		byte b = 10;  在计算机的底层中是这样的： 0000 1010
>
> ​		int i = b; 此时把一个取值范围小的，给取值范围大的，触发隐式转换。（前面补0）
>
> ​		0000 0000 0000 0000 0000 0000  0000 1010
>
> 强制转换的底层原理：（了解）
>
> ​		int i = 10; 在计算机的底层中是这样的：0000 0000 0000 0000 0000 0000  0000 1010		
>
> ​		byte b = (byte)i; 就会把前面不要的0给去掉了，只留下最后8位： 0000 1010
>
> 强制转换有可能导致数据发生错乱：（了解）
>
> ​		int i = 300；在计算机的底层中是这样的：00000000 00000000 00000001 00101100
>
> ​		byte b = (byte)i; 就会把前面三个字节给去掉了，只留下最后8位：00101100
>
> ​		这个时候，再转成十进制就是：44
>

<font color="red">**扩展4：（了解）**</font>

> ​	在二进制中：第一位是符号位，0为正数  1为负数
>
> ​	byte是有取值范围：-128 ~ 127
>
> ​	其实就是因为byte是一个字节的原因：
>
> ​	127：0111 1111 
>
> ​	-128：1000 0000
>
> 以上的这些的内容，都是局限于正数的情况，负数的情况会更加复杂
>
> 如果有兴趣，大家可以学习原码反码补码
>

### 1.3 十进制

> ​	现实生活中是进制。
>
> ​	十进制数据是用0,1,2,3,4,5,6,7,8,9来表示。例如：1234。进位规则是“逢十进一”，借位规则是“借一当十”。
>

### 1.4 八进制

> ​	由于二进制太长了，为了方便使用，所以有了八进制，把二进制中每三个看成一组，就是八进制。
>
> ​	十进制数据是用0,1,2,3,4,5,6,7来表示。例如：1234567。
>

### 1.5 十六进制

> ​	由于二进制太长了，为了方便使用，所以有了十六进制，把二进制中每四个看成一组，就是十六进制。堆内存中的地址值就是以十六进制的形式来体现的。
>
> ​	十六进制数据是用0,1,2,3,4,5,6,7,8,9,a,b,c,d,e,f来表示。例如：12ab。
>
> ​	其中a表示10，b表示11，c表示12，d表示13，e表示14，f表示15
>

### 1.6 代码中不同进制的书写格式（掌握）

```java
十进制：Java中，数值默认都是10进制，不需要加任何修饰。
二进制：数值前面以0b开头，b大小写都可以。
八进制：数值前面以0开头。
十六进制：数值前面以0x开头，x大小写都可以。
```

### 1.7 进制之间的转换

#### 1.7.1 任意进制到十进制的转换

> 公式：系数 * 基数的权次幂 再相加
>
> * 系数：每一【位】上的数
> * 基数：几进制，就是几
> * 权：从数值的右侧，以0开始，逐个+1增加
>

#### 1.7.1 十进制到任意进制的转换

> 公式：除基取余
>
> 使用源数据，不断的除以基数（几进制，基数就是几）得到余数，直到商为0，再将余数倒着拼起来即可。
>

#### 1.7.2 8421快速转换法

> ​	8421码又称BCD码，是BCD代码中最常用的一种
>
> ​	BCD： (Binary-Coded Decimal‎) 二进制码十进制数
>
> ​	在这种编码方式中，每一位二进制值的1都是代表一个固定数值，把每一位的1代表的十进制数加起来得到的结果就是它所代表的十进制数。
>

## 2.Debug模式

### 2.1什么是Debug模式

> 是供程序员使用的程序调试工具，它可以用于查看程序的执行流程，也可以用于追踪程序执行过程来调试程序。
>

### 2.2Debug模式操作流程

- 如何加断点

  - 选择要设置断点的代码行，在行号的区域后面单击鼠标左键即可

  细节：

  ​	在每一个方法的第一行有效语句前面打上断点，而且一个方法，只打一个。

  ![01](imgs.assets/01.png)

- 如何运行加了断点的程序

  - 在代码区域右键Debug执行

  ![02](imgs.assets/02.png)

- 看哪里

  - 看Debugger窗口

  ![03](imgs.assets/03.png)

  - 看Console窗口

  ![04](imgs.assets/04.png)

- 点哪里

  - 点Step Into (F7)这个箭头，也可以直接按F7

  ![05](imgs.assets/05.png)

- 如何删除断点

  - 选择要删除的断点，单击鼠标左键即可

  ![06](imgs.assets/06.png)

  - 如果是多个断点，可以每一个再点击一次。也可以一次性全部删除

  ![07](imgs.assets/07.png)

### 2.3 debugder断点调试的细节

> 1.断点调试可以控制程序一步一步的运行，停在背景色变深的那行代码
>
> 2.断点调试不会回到上一步。
>
> 3.如果在断点调试中涉及打印语句，会把结果输出到控制台上面
>
> 4.如果在断点调试中涉及键盘录入，那么必须要到控制台输入数字，否则断点调试无法向下运行

## 3.基础练习

### 3.1 练习1求和（掌握）

> ​	有这样的一个数组，元素是{68,27,95,88,171,996,51,210}。
>
> 求出该数组中满足要求的元素和，要求是：求和的元素个位和十位都不能是7，并且只能是偶数。
>

代码示例：

```java
//1.定义数组
int[] arr = {68,27,95,88,171,996,51,210};
//定义求和变量
int sum = 0;
//2.遍历数组得到每一个元素
for (int i = 0; i < arr.length; i++) {
    //条件一：个位不能是7
    //条件二：十位不能是7
    //条件三：只能是偶数
    //先获得个位
    int ge = arr[i] % 10;
    //再获得十位
    int shi = arr[i] / 10 % 10;
    if(ge != 7 &&  shi != 7 && arr[i] % 2 ==0){
        sum = sum + arr[i]; //+=
    }
}
//3.打印输出
System.out.println(sum);
```

### 3.2 练习2 定义数组添加元素（掌握）

> 将10 – 20 之间能被5整除的数存入到数组当中，并遍历这个数组。
>

代码示例：

```java
//静态 知道所有元素
//动态 不知道所有元素，但是知道要存几个

//如果上面的两种方式我都不知道
//思想：先确定长度，再创建数组

//1.先确定数组的长度
int count = 0;
for (int i = 10; i <= 20; i++) {
    if(i % 5 == 0){
        count++;
    }
}
//当循环结束之后，数组的长度就可以确定了
//2.创建数组
int[] arr = new int[count];
//3.把符合要求的元素，添加到数组当中
int index = 0;
for (int i = 10; i <= 20; i++) {
    if(i % 5 == 0){
        //把i存入数组
        arr[index] = i;
        index++;
    }
}
//4.遍历
for (int i = 0; i < arr.length; i++) {
    System.out.print(arr[i] + " ");
}
```

### 3.3 练习3 判断是否为质数（掌握）

> 判断101~200之间有多少个质数，并打印出所有质数
>

代码示例：

```java
int countA = 0;
for (int number = 101; number <= 200; number++) {
    //统计有多少个数字能被number整除
    int countB = 0;
    for (int i = 2; i < number; i++) {
        //判断i是否可以被number整除
        if(number % i == 0){
            countB++;
            break;
        }
    }
    if(countB == 0){
        System.out.println(number + "是质数");
        countA++;
    }/*else{
                System.out.println(number + "不是质数");
            }*/
}
//此时就表示这个范围里面所有的数字都已经判断完毕
System.out.println(countA);
```

### 3.4 练习4随机点名器（掌握）

> ​	键盘录入班级人数, 根据班级人数录入班级学员姓名
>
> ​	从录入的学员姓名中, 随机取出一个, 并打印在控制台
>

代码示例：

```java
//1.键盘录入班级的人数
Scanner sc = new Scanner(System.in);
System.out.println("请输入班级的人数");
int number = sc.nextInt();
//2.根据人数来创建数组
String[] arr = new String[number];
//3.键盘录入姓名并存入数组
//录入整数：nextInt  录入小数：nextDouble 录入字符串 next
for (int i = 0; i < arr.length; i++) {
    System.out.println("请输入学生的姓名");
    String name = sc.next();
    //把name添加到数组当中
    arr[i] = name;
}
//4.随机抽取
//随机抽取一个索引，再通过索引获取姓名
Random r = new Random();
int index = r.nextInt(arr.length);
//5.根据索引获取姓名
String name = arr[index];
System.out.println("本次的幸运观众为:" + name);
```

### 3.5 练习5 评委打分（掌握）

> 需求：
>
> ​	在唱歌比赛中，有6名评委给选手打分，分数范围是[0 - 100]之间的整数。选手的最后得分为：去掉最高分、最低分后的4个评委的平均分，请完成上述过程并计算出选手的得分。
>

代码示例：

```java
public class Test13 {
    public static void main(String[] args) {
        //1.定义数组存入6个评委的打分
        int[] arr = new int[6];
        //2.生成6个数字，存入数组当中  0~100
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < arr.length; ) {
            System.out.println("请输入第" + (i + 1) + "个评委的打分");
            int score = sc.nextInt();
            if (score >= 0 && score <= 100) {
                //只有当分数在范围之内，才会添加到数组当中
                arr[i] = score;
                //只有添加成功之后，那么索引才会发生变化
                i++;
            } else {
                System.out.println("分数超出范围");
                continue;
            }
        }
        //3.求平均分
        int sum = getSum(arr);
        int max = getMax(arr);
        int min = getMin(arr);
        int avg  = (sum - max - min)/(arr.length - 2);
        System.out.println(avg);
    }

    //1.我要干嘛？ --- 求和
    //2.需要什么？ --- 数组
    //3.调用处是否需要继续使用结果？ 必须返回
    public static int getSum(int[] arr){
        int sum = 0;
        for (int i = 0; i < arr.length; i++) {
            sum = sum + arr[i]; //+=
        }
        return sum;
    }

    public static int getMax(int[] arr){
        int max = arr[0];
        for (int i = 0; i < arr.length; i++) {
            if(arr[i] > max){
                max = arr[i];
            }
        }
        return max;
    }

    public static int getMin(int[] arr){
        int min = arr[0];
        for (int i = 0; i < arr.length; i++) {
            if(arr[i] < min){
                min = arr[i];
            }
        }
        return min;
    }
}
```

### 3.6 练习6 数字加密（掌握）

> **需求：**
>
> 某系统的数字密码，比如1983，采用加密方式进行传输，
>
> 规则如下：
>
> * 先得到每位数，
>
> * 然后每位数都加上5 , 
>
> * 再对10求余，
>
> * 最后将所有数字反转，得到一串新数。
>

代码示例：

```java
public class Test14 {
    public static void main(String[] args) {
        //1.直接把这个数字以数组的形式体现
        int[] arr = {1, 9, 8, 3};
        //2.每一位都+5
        for (int i = 0; i < arr.length; i++) {
            arr[i] = arr[i] + 5;//+=
        }
        //3.对10取余
        for (int i = 0; i < arr.length; i++) {
            arr[i] = arr[i] % 10;
        }
        //4.反转
        for (int left = 0, right = arr.length - 1; left < right; left++, right--) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
        //5.遍历打印
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
        }

    }
}
```

### 3.7 练习7 打印形状（掌握）

> 题目本身没有什么特殊的意义，为了锻炼大家循环嵌套的能力
>
> 思路分析：
>
> ​	对于任意的一种有规则的图形，我们可以把他们拆成矩形，正三角形和倒三角形，然后再组合在一起。
>
> 所以，我们要会先打印基础形状
>

#### 需求1：打印矩形（掌握）

```java
//目的：
//为了锻炼大家循环嵌套的能力而已

//把在一行打印5个*这件事情，重复了5次
//决定了行数
for (int i = 0; i < 5; i++) {
    //目的：在一行打印5个*
    for (int j = 0; j < 5; j++) {
        System.out.print("*");
    }
    //打印完毕之后，进行换行
    System.out.println();
}
```

#### 需求2：打印正三角形（掌握）

```java
/*
        *
        **
        ***
        ****
        *****
*/

//把在一行打印5个*这件事情，重复了5次
//决定了行数
for (int i = 1; i <= 5; i++) {
    //目的：在一行打印5个*
    for (int j = 1; j <= i; j++) {
        System.out.print("*");
    }
    //打印完毕之后，进行换行
    System.out.println();
}

//当i = 1 的时候，打印第一行，内循环范围：1~1
//当i = 2 的时候，打印第二行，内循环范围：1~2
//当i = 3 的时候，打印第三行，内循环范围：1~3
//。。。。
//当i = 5 的时候，打印第五行，内循环范围：1~5
```

#### 需求3：打印倒三角形（了解）

```java
/*
         *****
         ****
         ***
         **
         *
*/

//把在一行打印5个*这件事情，重复了5次
//决定了行数
for (int i = 1; i <= 5; i++) {
    //目的：在一行打印5个*
    for (int j = i; j <= 5; j++) {
        System.out.print("*");
    }
    //打印完毕之后，进行换行
    System.out.println();
}
//当i=1的时候，打印的是第一行，内循环 1~5
//当i=2的时候，打印的是第二行，内循环 2~5
//当i=3的时候，打印的是第三行，内循环 3~5
//。。。。
```

#### 需求4：打印等腰三角形（掌握）

用基础形状再拼成想要的效果

```java
for (int i = 1; i <= 5; i++) {
    //打印空格
    for (int j = i; j <= 5; j++) {
        System.out.print(" ");
    }

    //打印*
    for (int j = 1; j <= i; j++) {
        System.out.print("*");
    }

    //打印*
    for (int j = 1; j <= i - 1; j++) {
        System.out.print("*");
    }

    System.out.println();
}
```

### 3.8 练习8 99乘法表（了解）

> 分析：
>
> ​	先打印形状，再修改内容
>

代码示例：

```java
//先打印一个9行9列的矩形
//负责：打印几行
for (int i = 1; i <= 9; i++) {
    //负责：在一行当中打印多少个*
    for (int j = 1; j <= 9; j++) {
        System.out.print("*");
    }
    System.out.println();
}

--------------------------------------------------------
//再打印一个直角三角形
//第一行：1个
//第二行：2个
//第三行：3个
//...
//负责：打印几行
for (int i = 1; i <= 9; i++) {
    //负责：在一行当中打印多少个*
    for (int j = 1; j <= i; j++) {
        System.out.print("*");
        //默认情况下一个制表符等于4个空格，除此之外还由一个对其的功能
    }
    System.out.println();
}
--------------------------------------------------------
//最后修改内容变成99乘法表
//负责：打印几行
for (int i = 1; i <= 9; i++) {
    //负责：在一行当中打印多少个*
    for (int j = 1; j <= i; j++) {
        System.out.print(j + " * " + i + " = " + (i * j) + "\t");
        //默认情况下一个制表符等于4个空格，除此之外还由一个对其的功能
    }
    System.out.println();
}
```

### 3.9 练习9 抽奖（掌握）

> **需求：**
>
> 一个大V直播抽奖，奖品是现金红包，分别有{2, 588 , 888, 1000, 10000}五个奖金。请使用代码模拟抽奖，打印出每个奖项，奖项的出现顺序要随机且不重复。
>
> 打印效果如下：（随机顺序，不一定是下面的顺序）
>
> 888元的奖金被抽出
> 588元的奖金被抽出
> 10000元的奖金被抽出
> 1000元的奖金被抽出
> 2元的奖金被抽出
>
> 思路分析：
>
> 1. 可以把抽取到的奖项，再存到另一个数组当中newArr
> 2. 假设现在抽取到588，拿着当前抽取到的奖项588，可以到newArr中判断，是否已经存在。
> 3. 如果没有存在，表示当前的奖项是第一次被抽中，添加到newArr当中
> 4. 如果已经存在，表示当前的奖项不是第一次出现，重新抽取
>

代码示例：

```java
//以后随机会有两种思路：
//第一种：一次随一个
//第二种：整体打乱
//1，新建一个数组，存所有的奖项
int[] arr = {2, 588, 888, 1000, 10000};//0~4

//2.打乱数组中所有数据的顺序
Random r = new Random();

for (int i = 0; i < arr.length; i++) {
    //获取一个随机索引index
    //让i跟index进行交换
    int index = r.nextInt(arr.length);

    int temp = arr[i];
    arr[i] = arr[index];
    arr[index] = temp;
}
//遍历数组
for (int i = 0; i < arr.length; i++) {
    System.out.println(arr[i]);
}
```

### 3.10 二维数组

> 分析：
>
> ​	二维数组：数组里面存的还是其他数组。
>

静态初始化：

```java
//首先是一个大数组，在大数组里面存了三个小数组。
//大数组的0索引，是第一个小数组
//大数组的1索引，是第二个小数组
//大数组的2索引，是第三个小数组
int[][] arr = {
	{1,2,3,4},
	{5,6,7,8},
	{9,10,11,12}
};
```

动态初始化：

```java
//第一个方框里面表示大数组的长度
//第二个方框里面表示每一个小数组的长度
int[][] arr = new int[3][5];
```

获取元素：

```java
int num1 = arr[0][1];
System.out.println(num1);
```

修改元素：

```java
需求：把10修改为100
arr[2][1] = 100;
```

遍历二维数组：

```java
//外循环：遍历大数组，得到大数组里面的每一个小数组
for (int i = 0; i < arr.length; i++) {
    //i 表示大数组的索引
    //arr[i] 依次表示每一个小数组
    //内循环：遍历小数组，得到小数组里面的每一个元素
    for (int j = 0; j < arr[i].length; j++) {
        System.out.print(arr[i][j] + " ");
    }
    //表示一个小数组已经遍历完毕，所以换行处理
    System.out.println();
}
```

### 3.11 练习10 商场营业额（了解）

> **需求：**
>
> ​	一家商场每个季度的销售额如下：单位万元。
>
> ​	一季度：20，30，40
>
> ​	二季度：10，35，42
>
> ​	三季度：21，32，49
>
> ​	四季度：51，45，78
>
> 要求：
>
> ​	分别中四个数组将每一个季度的营业额存储，再把4个数组存储到一个大数组中。
>
> 求出全年的总销售额
>

代码示例：

```java
//1,利用静态初始化定义一个二维数组
int[][] arr = {
    {20,30,40},
    {10,35,42},
    {21,32,49},
    {51,45,78}
};

//2.遍历求和
int sum = 0;
//遍历大数组
for (int i = 0; i < arr.length; i++) {
    //i 表示大数组里面的每一个索引
    //arr[i] 大数组里面的每一个小数组
    for (int j = 0; j < arr[i].length; j++) {
        sum = sum + arr[i][j];
    }
}

//3.打印
System.out.println(sum);
```

## 4.彩票双色球系统

> 建议：
>
> ​	把第一个需求，随机生成一组彩票号码能掌握即可。
>
> 分析：
>
> 1，随机生成一组彩票号码
>
> 2，键盘录入自己的彩票号码
>
> 3，比较中了多少红球和篮球

代码示例：

```java
package com.itheima.test;

import java.util.Random;
import java.util.Scanner;

public class Test17 {
    public static void main(String[] args) {
        //1.随机生成一组彩票号码
        //红球： 范围1~33  6个
        //篮球： 范围1~16  1个
        int[] awordNumber = createAwordNumber();
        for (int i = 0; i < awordNumber.length; i++) {
            System.out.print(awordNumber[i] + " ");
        }
        System.out.println();

        //2.键盘录入自己的彩票号码
        int[] userArr = userNumber();
        for (int i = 0; i < userArr.length; i++) {
            System.out.print(userArr[i] + " ");
        }
        System.out.println();


        //3.比较中了多少红球和篮球
        check(awordNumber,userArr);

    }

    //比较中奖号码跟 用户输入的号码。
    //获取中了多少红球和多少篮球
    private static void check(int[] awordNumber, int[] userArr) {
        //定义计数器
        int redCount = 0;
        int blueCount = 0;

        //遍历用户的数组，获取每一个用户的号码(只要比红球)
        for (int i = 0; i < userArr.length - 1; i++) {
            //i 表示索引 userArr[i] 用户彩票号码
            //拿着用户的号码到awordNumber数组中去判断，是否存在
            boolean flag1 = contains(awordNumber, userArr[i]);
            //如果为真，表示当前红球号码已经中奖
            if(flag1){
                redCount++;
            }
        }

        //判断篮球
        boolean flag2 =  userArr[userArr.length - 1] == awordNumber[awordNumber.length - 1];
        if(flag2){
            blueCount++;
        }


        System.out.println("红球中了" + redCount + "个");
        System.out.println("蓝球中了" + blueCount + "个");

        if((redCount == 2 && blueCount ==1) || (redCount == 1 && blueCount == 1) || (redCount == 0 && blueCount == 1)){
            System.out.println("恭喜你，中了六等奖，奖金5元");
        }else if((redCount == 4 && blueCount ==0) || (redCount ==3 && blueCount == 1)){
            System.out.println("恭喜你，中了五等奖，奖金10元");
        }else if((redCount == 5 && blueCount ==0) || (redCount ==4 && blueCount == 1)){
            System.out.println("恭喜你，中了四等奖，奖金200元");
        }else if(redCount == 5 && blueCount ==1){
            System.out.println("恭喜你，中了三等奖，奖金3000元");
        }else if(redCount == 6 && blueCount ==0){
            System.out.println("恭喜你，中了二等奖，奖金500万元");
        }else if(redCount == 6 && blueCount ==1){
            System.out.println("恭喜你，中了一等奖，奖金1000万元");
        }else{
            System.out.println("脸黑，没中~");
        }



    }

    //让用户输入自己购买的彩票号码
    private static int[] userNumber() {
        //1.定义一个数组，存红球号码和蓝球号码 6 + 1 = 7
        int[] arr = new int[7];
        //2.用户键盘输入彩票号码(红球) 1~33
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < arr.length - 1; ) {
            System.out.println("请输入第" + (i + 1) + "个红球号码");
            int redNumber = sc.nextInt();
            boolean flag = contains(arr, redNumber);
            //判断，用户输入的彩票号码是否在1~33的范围，并且在arr中是不存在的
            if(redNumber >= 1 && redNumber <= 33 && !flag){
                arr[i] = redNumber;
                //只有成功存入，才会添加到数组当中
                i++;
            }else{
                System.out.println("您的红球号码有误，请重新输入");
            }
        }

        //当循环结束之后，表示所有的红球号码已经录入完毕
        //接下来录入篮球号码即可
        while (true) {
            System.out.println("请输入蓝球号码 1 ~ 16");
            int blueNumber = sc.nextInt();
            if(blueNumber >= 1 && blueNumber <= 16){
                arr[arr.length - 1] = blueNumber;
                //存入之后，循环结束
                break;
            }else{
                System.out.println("您输入的篮球号码有误，请重新输入");
            }
        }
        //所有的红球和篮球号码已经录入完毕
        return arr;

    }

    //我要干嘛？我要生成一组随机的彩票号码
    //我完成这件事需要什么？ 什么都不需要
    //调用处是否需要继续使用结果? 要，必须返回
    public static int[] createAwordNumber() {
        //1.定义一个数组，存红球号码和蓝球号码 6 + 1 = 7
        int[] arr = new int[7];
        //2.随机生成红球的号码（范围：1~33 不重复）
        Random r = new Random();
        //遍历数组，给数组中添加元素
        //在添加的时候，需要 arr.length - 1
        //因为此时，只添加红球号码
        for (int i = 0; i < arr.length - 1; ) {
            int redNumber = r.nextInt(33) + 1;
            boolean flag = contains(arr, redNumber);
            if (!flag) {
                arr[i] = redNumber;
                i++;
            } else {
                System.out.println("重新生成一个号码");
            }
        }

        //当循环结束之后，表示所有的红球都已经生成并存入数组
        //接下来，生成篮球号码并存入数组
        int blueNumber = r.nextInt(16) + 1;
        arr[arr.length - 1] = blueNumber;

        //把数组返回
        return arr;
    }

    //判断数字在数组中是否存在
    //需要什么？数组 数字
    //调用处是否需要使用结果？要
    public static boolean contains(int[] arr, int number) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == number) {
                //只要有一个一样，那么表示number在arr中是存在的，返回true
                return true;
            }
        }
        //当循环结束之后，表示数组里面所有的元素已经判断完毕，就是不存在，返回false
        return false;
    }
}
```
