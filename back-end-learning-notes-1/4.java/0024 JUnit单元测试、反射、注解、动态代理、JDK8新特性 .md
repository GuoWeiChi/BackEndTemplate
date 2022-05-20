> <strong>本专栏将从基础开始，循序渐进，由浅入深讲解Java的基本使用，希望大家都能够从中有所收获，也请大家多多支持。</strong>
> <strong>专栏地址:[26天高效学习Java编程](https://blog.csdn.net/learning_xzj/category_11806176.html) </strong>
> <strong>相关软件地址:[软件地址](https://pan.baidu.com/s/1bXCZR0yxN2-v6NqDpe4H1g?pwd=1111) </strong>
> <strong>所有代码地址:[代码地址](https://gitee.com/codinginn/java-code) </strong>
> <strong> 如果文章知识点有错误的地方，请指正！大家一起学习，一起进步。</strong>
> <font color="red"><strong> 如果感觉博主的文章还不错的话，还请关注、点赞、收藏三连支持一下博主哦</strong></font>

@[toc]



## 本文内容

- JUnit单元测试
- 反射
- 注解
  - 使用注解
- 动态代理
- JDK8新特性
  - 方法引用
  - Base64

# 第一章 Junit单元测试

## 知识点--Junit单元测试

### 目标

- 掌握Junit的使用

### 讲解

#### Junit的概念

- 概述 : Junit是Java语言编写的第三方单元测试框架(工具类)
- 作用 : 用来做“单元测试”——针对某个普通方法，可以像main()方法一样独立运行，它专门用于测试某个方法。

#### Junit的使用步骤

- 1.在模块下创建lib文件夹,把Junit的jar包复制到lib文件夹中

- 2.选中Junit的jar包,右键选中 add as Library,把JUnit4的jar包添加到classPath中

- 3.在测试方法上面写上@Test注解

- 4.执行测试方法 

  ```java
  public class Person {
  
      @Test
      public void test1(){
          System.out.println("Person test1 方法执行了....");
      }
  
      @Test
      public void test2(){
          System.out.println("Person test2 方法执行了....");
      }
  
  }
  
  ```

#### 执行测试方法

- 1.选中方法名--->右键--->选中执行             只执行选中的测试方法
- 2.选中类名----->右键--->选中执行             执行该类中所有的测试方法
- 3.选中模块---- ->右键--->选中all tests 执行   执行该模块中所有的测试方法 

- 如何查看测试结果
  * 绿色：表示测试通过
  * 红色：表示测试失败，有问题

## 知识点--Junit单元测试的注意实现

### 目标

- 测试方法注意事项:

### 讲解

- 1.测试方法的权限修饰符一定是public
- 2.测试方法的返回值类型一定是void
- 3.测试方法一定没有参数
- 4.测试方法 的声明之上一定要使用@Test注解

## 知识点--Junit其他注解

### 目标

- Junit其他注解的使用

### 路径

- Junit其他注解

### 讲解

* @Before：用来修饰方法，该方法会在每一个测试方法执行之前执行一次。
* @After：用来修饰方法，该方法会在每一个测试方法执行之后执行一次。
* @BeforeClass：用来静态修饰方法，该方法会在所有测试方法之前执行一次，而且只执行一次。
* @AfterClass：用来静态修饰方法，该方法会在所有测试方法之后执行一次，而且只执行一次。

```java
public class Student {

    @BeforeClass
    public static void beforeClass1(){
        System.out.println("Student beforeClass1静态方法执行了...");
    }

    @BeforeClass
    public static void beforeClass2(){
        System.out.println("Student beforeClass2静态方法执行了...");
    }


    @Before
    public void b1(){
        System.out.println("Student b1方法执行了...");
    }

    @Before
    public void b2(){
        System.out.println("Student b2方法执行了...");
    }

    @Before
    public void b3(){
        System.out.println("Student b3方法执行了...");
    }


    @Test
    public void test1(){
        System.out.println("Student test1 方法执行了....");
    }

    @Test
    public void test2(){
        System.out.println("Student test2 方法执行了....");
    }

    @After
    public void a1(){
        System.out.println("Student a1方法执行了...");
    }

    @After
    public void a2(){
        System.out.println("Student a2方法执行了...");
    }

    @After
    public void a3(){
        System.out.println("Student a3方法执行了...");
    }

    @AfterClass
    public static void afterClass1(){
        System.out.println("Student afterClass1方法执行了...");
    }

    @AfterClass
    public static void afterClass2(){
        System.out.println("Student afterClass2方法执行了...");
    }

}

```

## 知识点--Junit断言

### 目标

- Junit断言

### 讲解

- 断言：预先判断某个条件一定成立，如果条件不成立，则直接报错。 使用Assert类中的assertEquals()方法
- 案例:

```java
public class Demo02 {
    @Test
    public void addTest(){
        //测试
        int add = add(3, 6);

        //断言判断结果
        //第一个参数表示期望值
        //第二个参数表示实际值
        //如果结果正确的就测试通过,如果结果错误的,就会报错
        Assert.assertEquals(9,add);
    }

    //加法
    //这个代码的语法没问题，也没有异常。他是逻辑错误，系统不知道你要算的是加法
    public int add(int a, int b){
        int sum = a * b;
        return sum;
    }

}
```

# 第二章 反射

## 知识点--类加载器

### 目标

- 理解类在什么时候加载,以及如何获取类加载器

### 路径

- 类的加载
- 类的加载时机
- 类加载器

### 讲解

#### 类的加载

- 当我们的程序在运行后，第一次使用某个类的时候，会将此类的class文件读取到内存，并将此类的所有信息存储到一个Class对象中

![](imgs.assets/03_%E8%AF%BB%E5%8F%96class.png)

#### 类的加载时机

1. 创建类的实例。

2. 类的静态变量，或者为静态变量赋值。

3. 类的静态方法被调用。

4. 使用反射方式来强制创建某个类或接口对应的java.lang.Class对象。

5. 初始化某个类的子类。

6. 直接使用java.exe命令来运行某个主类。

   以上六种情况的任何一种，都可以导致JVM将一个类加载到方法区。

```java
public class Test {
    public static void main(String[] args) throws Exception{
        // 类的加载时机
        //  1. 创建类的实例。
        //  Student stu = new Student();

        // 2. 类的静态变量，或者为静态变量赋值。
        // Person.country = "中国";

        // 3. 类的静态方法被调用。
        // Person.method();

        // 4. 使用反射方式来强制创建某个类或接口对应的java.lang.Class对象。
        // Class<?> c = Class.forName("demo1_类的加载.Student");

        //  5. 初始化某个类的子类。
        // Zi zi = new Zi();

        // 6. 直接使用java.exe命令来运行某个主类。
    }
}

```

#### 类加载器

​	**类加载器：是负责将磁盘上的某个class文件读取到内存并生成Class的对象。**

- Java中有三种类加载器，它们分别用于加载不同种类的class：
  - 启动类加载器(Bootstrap ClassLoader)：用于加载系统类库<JAVA_HOME>\bin目录下的class，例如：rt.jar。
  - 扩展类加载器(Extension ClassLoader)：用于加载扩展类库<JAVA_HOME>\lib\ext目录下的class。
  - 应用程序类加载器(Application ClassLoader)：用于加载我们自定义类的加载器。

~~~java

public class Test {
    public static void main(String[] args) {
        /*
            类加载器:
                概述:是负责将磁盘上的某个class文件读取到内存并生成Class的对象。
                如何获取类加载器:
                    类的字节码对象.getClassLoader()
         */
        // 获取Test类的类加载器
        ClassLoader c1 = Test.class.getClassLoader();
        System.out.println(c1);// AppClassLoader

        // 获取Student类的类加载器
        ClassLoader c2 = Student.class.getClassLoader();
        System.out.println(c2);// AppClassLoader

        // 获取String类的类加载器
        ClassLoader c3 = String.class.getClassLoader();
        System.out.println(c3);// null
        //API中说明：一些实现可能使用null来表示引导类加载器。 如果此类由引导类加载器加载，则此方法将在此类实现中返回null

        System.out.println("====================委派机制=================");
        System.out.println(c1.getParent());// PlatformClassLoader
        System.out.println(c1.getParent().getParent());// null


    }
}

~~~

## 知识点--反射的概述

### 目标

- 理解反射的概念

### 讲解

#### 反射的引入

* 问题：IDEA中的对象是怎么知道类有哪些属性，哪些方法的呢？

```java
 通过反射技术对象类进行了解剖得到了类的所有成员。
```

#### 反射的概念

```java
 反射是一种机制，利用该机制可以在程序运行过程中对类进行解剖并操作类中的所有成员(成员变量，成员方法，构造方法)
```

#### 使用反射操作类成员的前提

```java
要获得该类字节码文件对象，就是Class对象
```

#### 反射在实际开发中的应用

```java
* 开发IDE(集成开发环境)，比如IDEA,Eclipse
* 各种框架的设计和学习 比如Spring，Hibernate，Struct，Mybaits....
```

### 小结

- 通过反射技术去获取一个类的成员变量,成员方法,构造方法...,并可以访问

## 知识点--Class对象的获取方式

### 目标

- 能够获取一个类的Class对象

### 讲解

```java
* 方式1: 通过类名.class获得
* 方式2：通过对象名.getClass()方法获得
* 方式3：通过Class类的静态方法获得： static Class forName("类全名")
    * 每一个类的Class对象都只有一个。
```

- 示例代码

~~~java

public class Student {
    private String name;

    public void method1(){

    }
}

~~~

```java
public class Test {
    public static void main(String[] args) throws Exception{
          /*
            Class对象的获取:
                通过类名.class获得
                通过对象名.getClass()方法获得
                通过Class类的静态方法获得： static Class forName("类全名")
           */
        // 1.方式一:通过类名.class获得
        Class<Student> c1 = Student.class;
        System.out.println(c1);

        // 2.方式二:通过对象名.getClass()方法获得
        Student stu = new Student();
        Class<? extends Student> c2 = stu.getClass();
        System.out.println(c2);

        // 3.方式三:通过Class类的静态方法获得： static Class forName("类全名")
        Class<?> c3 = Class.forName("demo2_Class对象的获取.Student");
        System.out.println(c3);

        // 问题:一个类只有一个字节码对象(Class对象)
        System.out.println(c1 == c2);// true
        System.out.println(c1 == c3);// true
    }
}

```

## 知识点--Class类常用方法

### 目标

- Class类的常用方法

### 路径

- Class类的常用方法

### 讲解

```java
String getSimpleName(); 获得类名字符串：类名
String getName();  获得类全名：包名+类名
T newInstance() ;  创建Class对象关联类的对象
```

- 示例代码

```java
public class ReflectDemo02 {
    public static void main(String[] args) throws Exception {
        // 获得Class对象
        Class c = Student.class;
        // 获得类名字符串：类名
        System.out.println(c.getSimpleName());
        // 获得类全名：包名+类名
        System.out.println(c.getName());
        // 创建对象
        Student stu = (Student) c.newInstance();
        System.out.println(stu);
    }
}
```

## 知识点--反射之操作构造方法

### 目标

- 通过反射获取类的构造方法,并执行构造方法

### 讲解

#### Constructor类概述

```java
反射之操作构造方法的目的
    * 获得Constructor对象来创建类的对象。

Constructor类概述
    * 类中的每一个构造方法都是一个Constructor类的对象
```

#### 通过反射获取类的构造方法

```java
Class类中与Constructor相关的方法 
1. Constructor getConstructor(Class... parameterTypes)
        * 根据参数类型获得对应的Constructor对象。
        * 只能获得public修饰的构造方法
 2. Constructor getDeclaredConstructor(Class... parameterTypes)
        * 根据参数类型获得对应的Constructor对象
    	* 可以是public、protected、(默认)、private修饰符的构造方法。
 3. Constructor[] getConstructors()
        获得类中的所有构造方法对象，只能获得public的
 4. Constructor[] getDeclaredConstructors()
        获得类中的所有构造方法对象
    	可以是public、protected、(默认)、private修饰符的构造方法。
```

#### 通过反射执行构造方法

```java
Constructor对象常用方法
1. T newInstance(Object... initargs)
 	根据指定的参数创建对象
2. void setAccessible(true)
   设置"暴力反射"——是否取消权限检查，true取消权限检查，false表示不取消
```

#### 示例代码

~~~java

public class Student {
    public String name;
    public int age;

    public Student() {
    }

    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public Student(String name) {
        this.name = name;
    }

    private Student(int age) {
        this.age = age;
    }

    @Override
    public String toString() {
        return "Student{" +
                "name='" + name + '\'' +
                ", age=" + age +
                '}';
    }
}

~~~

```java

import java.lang.reflect.Constructor;

public class Test {
    public static void main(String[] args) throws Exception{
        /*
            Constructor类概述
               类中的每一个构造方法都是一个Constructor类的对象

            反射之操作构造方法的目的
                获得Constructor对象来创建类的对象。

            使用:
                1.如何通过反射获取一个类中的构造方法:Class类的方法
                     1. Constructor getConstructor(Class... parameterTypes)
                        * 根据参数类型获得对应的Constructor对象。
                        * 只能获得public修饰的构造方法
                     2. Constructor getDeclaredConstructor(Class... parameterTypes)
                            * 根据参数类型获得对应的Constructor对象
                            * 可以是public、protected、(默认)、private修饰符的构造方法。

                     3. Constructor[] getConstructors()
                            获得类中的所有构造方法对象，只能获得public的
                     4. Constructor[] getDeclaredConstructors()
                            获得类中的所有构造方法对象
                            可以是public、protected、(默认)、private修饰符的构造方法。

                2.如何通过反射执行获取的构造方法:Constructor的方法
                    1. T newInstance(Object... initargs)
                        根据指定的参数创建对象
                    2. void setAccessible(true)
                       设置"暴力反射"——是否取消权限检查，true取消权限检查，false表示不取消

         */
        // 获取Student类的Class对象
        Class<Student> c = Student.class;

        // 获取单个构造方法
        // 获取无参数的构造方法
        Constructor<Student> con1 = c.getDeclaredConstructor();
        System.out.println(con1);

        // 获取满参构造方法
        Constructor<Student> con2 = c.getDeclaredConstructor(String.class, int.class);
        System.out.println(con2);

        // 获取私有构造方法
        Constructor<Student> con3 = c.getDeclaredConstructor(int.class);
        System.out.println(con3);

        System.out.println("================================");
        // 获取所有构造方法
        Constructor<?>[] arr1 = c.getDeclaredConstructors();
        for (Constructor<?> con : arr1) {
            System.out.println(con);
        }

        System.out.println("================================");
        // 通过执行con1表示的构造方法来创建Student对象
        Student stu1 = con1.newInstance();
        System.out.println(stu1);// Student{name='null', age=0}

        // 通过执行con2表示的构造方法来创建Student对象
        Student stu2 = con2.newInstance("张三", 18);
        System.out.println(stu2);// Student{name='张三', age=18}

        // 取消con3表示的构造方法的权限检查
        con3.setAccessible(true);

        // 通过执行con3表示的构造方法来创建Student对象
        Student stu3 = con3.newInstance(19);
        System.out.println(stu3);// Student{name='null', age=19}

    }
}

```

## 知识点--反射之操作成员方法

### 目标

- 通过反射获取类的成员方法,并执行成员方法

### 路径

- Method类概述
- 通过反射获取类的成员方法
- 通过反射执行成员方法

### 讲解

#### Method类概述

```java
反射之操作成员方法的目的
    * 操作Method对象来调用成员方法
Method类概述
    * 每一个成员方法都是一个Method类的对象。
```

#### 通过反射获取类的成员方法

```java
Class类中与Method相关的方法
* Method getMethod(String name,Class...args);
    * 根据方法名和参数类型获得对应的构造方法对象，只能获得public的

* Method getDeclaredMethod(String name,Class...args);
    * 根据方法名和参数类型获得对应的构造方法对象，包括public、protected、(默认)、private的

* Method[] getMethods();
    * 获得类中的所有成员方法对象，返回数组，只能获得public修饰的且包含父类的

* Method[] getDeclaredMethods();
    * 获得类中的所有成员方法对象，返回数组,只获得本类的，包括public、protected、(默认)、private的
```

#### 通过反射执行成员方法

```java
Method对象常用方法
*  Object invoke(Object obj, Object... args)
    * 调用指定对象obj的该方法
    * args：调用方法时传递的参数
*  void setAccessible(true)
    设置"暴力访问"——是否取消权限检查，true取消权限检查，false表示不取消
```

#### 示例代码

~~~java

public class Student {

    public void show1() {
        System.out.println("show1 方法...");
    }

    public void show2(int num) {
        System.out.println("show2 方法...num: " + num);
    }

    private void show3() {
        System.out.println("show3 方法...");
    }

    private void show4(String str) {
        System.out.println("show1 方法...str: " + str);
    }

    public int show5(int num) {
        System.out.println("show5 方法...num: " + num);
        return 100;
    }

}

~~~



```java

import java.lang.reflect.Method;

public class Test {
    public static void main(String[] args) throws Exception {
        /*
            反射之操作成员方法:
                Method类概述
                      每一个成员方法都是一个Method类的对象。
                反射之操作成员方法的目的
                      操作Method对象来调用成员方法
                使用:
                    1.如何通过反射获取类中的成员方法:Class类的方法
                        * Method getMethod(String name,Class... args);
                        * 根据方法名和参数类型获得对应的构造方法对象，只能获得public的

                        * Method getDeclaredMethod(String name,Class...args);
                        * 根据方法名和参数类型获得对应的构造方法对象，包括public、protected、(默认)、private的

                        * Method[] getMethods();
                        * 获得类中的所有成员方法对象，返回数组，只能获得public修饰的且包含父类的

                        * Method[] getDeclaredMethods();
                        * 获得类中的所有成员方法对象，返回数组,只获得本类的，包括public、protected、(默认)、private的

                    2.如何通过反射执行获取类中成员方法: Method类的方法
                        *  Object invoke(Object obj, Object... args)
                            * 参数1:调用方法的对象
                            * 参数2：调用方法时传递的实际参数
                            * 返回值: 执行的方法的返回值

                        *  void setAccessible(true)
                            设置"暴力访问"——是否取消权限检查，true取消权限检查，false表示不取消

         */
        // 获取Student类的Class对象
        Class<Student> c = Student.class;

        // 获取单个方法
        // 通过反射获取show1方法
        Method m1 = c.getDeclaredMethod("show1");
        System.out.println(m1);

        // 通过反射获取show2方法
        Method m2 = c.getDeclaredMethod("show2", int.class);
        System.out.println(m2);

        // 通过反射获取show3方法
        Method m3 = c.getDeclaredMethod("show3");
        System.out.println(m3);

        // 通过反射获取show4方法
        Method m4 = c.getDeclaredMethod("show4", String.class);
        System.out.println(m4);

        // 通过反射获取show5方法
        Method m5 = c.getDeclaredMethod("show5", int.class);
        System.out.println(m5);

        System.out.println("==============================");
        // 获取所有方法
        Method[] arr = c.getDeclaredMethods();
        for (Method m : arr) {
            System.out.println(m);
        }

        System.out.println("==============================");
        // 通过反射创建Student对象
        Student stu = c.newInstance();

        // 通过反射执行m1表示的show1方法
        m1.invoke(stu);

        // 通过反射执行m2表示的show2方法
        m2.invoke(stu,10);

        // 取消m3表示的方法的权限检查
        m3.setAccessible(true);

        // 通过反射执行m3表示的show3方法
        m3.invoke(stu);

        // 取消m4表示的方法的权限检查
        m4.setAccessible(true);

        // 通过反射执行m4表示的show4方法
        m4.invoke(stu,"aaa");

        // 通过反射执行m5表示的show5方法
        Object res = m5.invoke(stu, 20);// int res = stu.show5(20);
        System.out.println(res);// 100

    }
}

```

## 扩展:扩展反射操作成员方法案例

```java

import java.lang.reflect.Constructor;
import java.lang.reflect.Method;

public class Test {
    public static void main(String[] args)throws Exception {
        /*
            Method类:
            public String getName() 获取方法名
         */
        // 需求: 访问Student类中的成员
        // 1.获取该类的字节码对象
        Class<Student> c = Student.class;

        // 2.获取所有构造方法
        Constructor<?>[] cons = c.getDeclaredConstructors();

        // 3.遍历所有的构造方法
        Student stu = null;
        for (Constructor<?> con : cons) {
            stu = (Student) con.newInstance();
        }

        // 4.获取所有的成员方法
        Method[] methods = c.getDeclaredMethods();

        // 5.遍历所有的成员方法
        for (Method m : methods) {
            if (m.getName().equals("show1")){
                m.invoke(stu);
            }

            if (m.getName().equals("show2")){
                m.invoke(stu,10);
            }

            if (m.getName().equals("show5")){
                Object res = m.invoke(stu, 20);
                System.out.println(res);
            }
            // ...
        }
    }
}

```



## 知识点--反射之操作成员变量

### 目标

- 通过反射获取类的成员变量,并访问成员变量

### 讲解

#### Field类概述

```java
反射之操作成员变量的目的
    * 通过Field对象给对应的成员变量赋值和取值

Field类概述
    * 每一个成员变量都是一个Field类的对象。
```

#### 通过反射获取类的成员变量

```java
Class类中与Field相关的方法
* Field getField(String name);
    *  根据成员变量名获得对应Field对象，只能获得public修饰
* Field getDeclaredField(String name);
    *  根据成员变量名获得对应Field对象，包括public、protected、(默认)、private的
* Field[] getFields();
    * 获得所有的成员变量对应的Field对象，只能获得public的
* Field[] getDeclaredFields();
    * 获得所有的成员变量对应的Field对象，包括public、protected、(默认)、private的
```

#### 通过反射访问成员变量

```java
Field对象常用方法
void  set(Object obj, Object value) 
void setInt(Object obj, int i) 	
void setLong(Object obj, long l)
void setBoolean(Object obj, boolean z) 
void setDouble(Object obj, double d) 

Object get(Object obj)  
int	getInt(Object obj) 
long getLong(Object obj) 
boolean getBoolean(Object ob)
double getDouble(Object obj) 

void setAccessible(true);暴力反射，设置为可以直接访问私有类型的属性。
Class getType(); 获取属性的类型，返回Class对象。
```

> setXxx方法都是给对象obj的属性设置使用，针对不同的类型选取不同的方法。
>
> getXxx方法是获取对象obj对应的属性值的，针对不同的类型选取不同的方法。

#### 示例代码

~~~java

public class Student {
    public String name;
    private int age;
}

~~~



```java


import java.lang.reflect.Field;

public class Test {
    public static void main(String[] args) throws Exception{
        /*
            Field类概述
                * 每一个成员变量都是一个Field类的对象。

            反射之操作成员变量的目的
                * 通过Field对象给对应的成员变量赋值和取值

            使用:
                1.如何通过反射获取类的成员变量: Class类的方法
                    * Field getField(String name);
                        *  根据成员变量名获得对应Field对象，只能获得public修饰
                    * Field getDeclaredField(String name);
                        *  根据成员变量名获得对应Field对象，包括public、protected、(默认)、private的

                    * Field[] getFields();
                        * 获得所有的成员变量对应的Field对象，只能获得public的
                    * Field[] getDeclaredFields();
                        * 获得所有的成员变量对应的Field对象，包括public、protected、(默认)、private的

                2.如何通过反射访问获取的类的成员变量: Field类的方法
                    Class getType(); 获取属性的类型，返回Class对象。
                    void  set(Object obj, Object value)
                    Object get(Object obj)
                    void setAccessible(true);暴力反射，设置为可以直接访问私有类型的属性。

         */
        // 获取Student类的Class对象
        Class<Student> c = Student.class;
        Student stu = c.newInstance();

        // 获取单个的成员变量
        // 通过反射获取name成员变量
        Field f1 = c.getDeclaredField("name");
        System.out.println(f1);

        // 通过反射获取age成员变量
        Field f2 = c.getDeclaredField("age");
        System.out.println(f2);

        System.out.println("===============================");
        // 获取所有成员变量
        Field[] arr = c.getDeclaredFields();
        for (Field field : arr) {
            System.out.println(field);
        }

        System.out.println("===============================");
        // 获取f1表示的name属性的类型
        System.out.println(f1.getType());
        // 获取f2表示的age属性的类型
        System.out.println(f2.getType());

        System.out.println("===============================");
        // 通过反射给f1表示的name属性赋值
        f1.set(stu,"张三" );// 相当于stu.name="张三";

        // 取消f2表示的属性的权限检查
        f2.setAccessible(true);

        // 通过反射给f2表示的age属性赋值
        f2.set(stu,18 );

        System.out.println("===============================");
        // 通过反射获取f1表示的name属性的值
        System.out.println(f1.get(stu));// 张三

        // 通过反射获取f2表示的age属性的值
        System.out.println(f2.get(stu));// 18


    }
}

```

# 第三章 注解

## 知识点-注解概述

### 目标

- 掌握什么是注解, 注解的作用

### 路径

- 注解概述
- 注解的作用

### 讲解

#### 注解概述

- 注解(annotation),是一种代码级别的说明,和类 接口平级关系.

  - 注解（Annotation）相当于一种标记，在程序中加入注解就等于为程序打上某种标记，以后，javac编译器、开发工具和其他程序可以通过反射来了解你的类及各种元素上有无标记，看你的程序有什么标记，就去干相应的事

  - 我们之前使用过的注解：

    ​                   1)[.@Override](mailto:.@Override)：子类重写方法时——编译时起作用

    ​                   2)[.@FunctionalInterface](mailto:.@FunctionalInterface)：函数式接口——编译时起作用

    ​                   3)[.@Test：JUnit](mailto:.@Test：JUnit)的测试注解——运行时起作用

#### 注解的作用

- 生成帮助文档**：**@author和@version	

- 执行编译期的检查 例如:@Override   
- 框架的配置(框架=代码+配置)

  - 具体使用请关注框架课程的内容的学习。

### 小结

1. 注解用在“源码中”，作为一个“标记”。给“注解解析器”看的，告诉“注解解析器”怎样编译、运行下面的代码。
2. 开发中,我们一般都是使用注解

## 知识点-JDK提供的三个基本的注解

### 目标

- 掌握JDK中提供的三个基本的注解

### 路径

- 三个基本的注解

### 讲解

​	@Override:描述方法的重写.

​	@SuppressWarnings:忽略警告.

​	@Deprecated:标记过时

```java

@SuppressWarnings("all")
class Fu{
    public void show(){

    }
}
class Zi extends Fu{
    @Override
    public void show(){

    }
}
public class Demo {
    public static void main(String[] args) {
        /*
            JDK提供的三个基本的注解:
                	@Override:描述方法的重写.
                    @SuppressWarnings:压制\忽略警告.
                    @Deprecated:标记过时
         */
        @SuppressWarnings("all")
        int num;
    }

    @Deprecated
    public static void method1(){

    }

    public static void method2(){

    }
}

```



### 小结

1. @Override: 重写父类的方法
2. @SuppressWarnings: 压制警告
3. @Deprecated: 标记方法的过时

## 知识点-自定义注解

### 目标

- 掌握自定义注解和定义注解属性

### 讲解

#### 自定义注解语法

```java
public @interface 注解名{
     属性
}
```

- 示例代码

```java
/**
 * 定义了注解
 *
 */
public @interface Annotation01 {

}
```

#### 注解属性

##### 格式

- `数据类型 属性名();`

##### 属性类型

​	1.基本类型

​	2.String

​	3.Class类型 

​	4.注解类型

​	5. 枚举类型

​	6.以上类型的一维数组类型  

- 示例代码

```java
public @interface Annotation01 {
    // 1.基本数据类型(4类8种)
    int a();
    double b();

    // 2.String类型
    String c();

    // 3.Class类型
    Class d();

    // 4.注解类型
    Annotation02 f();
    
    // 5.枚举类型
    Sex e();
    // 6.以上类型的一维数组类型
    int[] g();
    double[] h();
    String[] i();
    Sex[] j();
    Annotation02[] k();
}
```



## 知识点-- 使用注解并给注解属性赋值

### 目标

- 能够使用注解并给注解属性赋值

### 路径

- 使用注解并给注解属性赋值

### 讲解

```java
 使用注解:
        如果一个注解中有属性,那么使用注解的时候一定要给注解属性赋值
        如果一个注解没用属性,那么就不需要给注解属性赋值,直接使用即可
如何给注解属性赋值:
        @注解名(属性名=值,属性名2=值2) 
```

##### 案例演示

```java

public @interface MyAnnotation1 {
    // 不带属性的注解
}




public @interface MyAnnotation2 {
    // 带属性的注解
    String name();
    int age();
    String[] arr();
}




@MyAnnotation1
@MyAnnotation2(name="张三",age=18,arr={"aaa","bbb"})
public class Test1 {
    @MyAnnotation1
    String str;

    @MyAnnotation1
    @MyAnnotation2(name="张三",age=18,arr={"aaa","bbb"})
    public static void main(String[] args) {
        /*
            注解使用:
                不带属性的注解:@注解名
                带属性的注解: @注解名(属性名=属性值,属性名=属性值,...)
                
            注意:带有属性且没有default的注解在使用的时候一定要给属性赋值
         */
        @MyAnnotation1
        @MyAnnotation2(name="张三",age=18,arr={"aaa","bbb"})
        int num = 10;
    }
}


```

## 知识点--给注解属性赋值的注意事项

### 目标

- 理解给注解属性赋值的注意事项

### 路径

### 讲解

- 一旦注解有属性了,使用注解的时候,属性必须有值
- 若属性类型是一维数组的时候,当数组的值只有一个的时候可以省略{}
- 如果注解中只有一个属性,并且属性名为value,那么使用注解给注解属性赋值的时候,注解属性名value可以省略
- 注解属性可以有默认值  格式:属性类型 属性名() defaul t 默认值;

```java
public @interface MyAnnotation1 {
    int a();
}

public @interface MyAnnotation2 {
    int[] arr();
}

public @interface MyAnnotation3 {
    int value();
}

public @interface MyAnnotation33 {
    String[] value();
}

public @interface MyAnnotation4 {
    int a() default 10;
}

public class Test {
    public static void main(String[] args) {
        /*
            给注解属性赋值的注意事项:
                - 一旦注解有属性了,使用注解的时候,属性必须有值
                - 若属性类型是一维数组的时候,当数组的值只有一个的时候可以省略{}
                - 如果注解中只有一个属性,并且属性名为value,那么使用注解给注解属性赋值的时候,注解属性名value可以省略
                - 注解属性可以有默认值  格式:属性类型 属性名() defaul t 默认值;

         */
    }

    //  注解属性可以有默认值  格式:属性类型 属性名() defaul t 默认值;
    //@MyAnnotation4
    //@MyAnnotation4()
    @MyAnnotation4(a = 100)
    public static void method4(){

    }

    // 若属性类型是一维数组的时候,当数组的值只有一个的时候可以省略{}
    //如果注解中只有一个属性,并且属性名为value,那么使用注解给注解属性赋值的时候,注解属性名value可以省略
    //@MyAnnotation33(value={"aaa","bbb"})
    //@MyAnnotation33(value={"aaa"})
    //@MyAnnotation33(value="aaa")
    @MyAnnotation33("aaa")
    public static void method33(){

    }

    // 如果注解中只有一个属性,并且属性名为value,那么使用注解给注解属性赋值的时候,注解属性名value可以省略
    //@MyAnnotation3(value=10)
    @MyAnnotation3(10)
    public static void method3(){

    }

    // 若属性类型是一维数组的时候,当数组的值只有一个的时候可以省略{}
    // @MyAnnotation2(arr={10,20,30})
    // @MyAnnotation2(arr={10})
    @MyAnnotation2(arr=10)
    public static void method2(){

    }

    // 一旦注解有属性了,使用注解的时候,属性必须有值
    @MyAnnotation1(a = 10)
    public static void method1(){

    }

}

```

## 知识点-元注解

### 目标

- 能够说出常用的元注解及其作用

### 讲解

#### 什么是元注解

​	定义在注解上的注解

#### 常见的元注解

​	@Target:表示该注解作用在什么上面(位置),默认注解可以在任何位置. 值为:ElementType的枚举值

​		METHOD:方法

​		TYPE:类 接口

​		FIELD:字段

​		CONSTRUCTOR:构造方法声明

​	@Retention:定义该注解保留到哪个代码阶段, 值为:RetentionPolicy类型,  `默认只在源码阶段保留`

​		SOURCE:只在源码上保留(默认)

​		CLASS:在源码和字节码上保留

​		RUNTIME:在所有的阶段都保留 

.java (源码阶段) ----编译---> .class(字节码阶段) ----加载内存--> 运行(RUNTIME)

案例:

```java


import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;


@Target({ElementType.METHOD,ElementType.TYPE})
@Retention(RetentionPolicy.RUNTIME)
public @interface MyAnnotation1 {
    // 限制该注解只能在方法上和类上使用
    // 设置注解保留到运行阶段
}


@MyAnnotation1
public class Test {
    //@MyAnnotation1  // 编译报错
    int num;

    @MyAnnotation1
    public static void main(String[] args) {
        //@MyAnnotation1 // 编译报错
        String str;
    }
}

```

## 知识点-注解解析

### 目标

- 理解常见注解解析方法

### 讲解

java.lang.reflect.AnnotatedElement接口: Class、Method、Field、Constructor等实现了AnnotatedElement

- **T getAnnotation(Class<T>annotationType):得到指定类型的注解引用。没有返回null。**

- **boolean isAnnotationPresent(Class<?extends Annotation> annotationType)**：判断指定的注解有没有。


```java
@Target(ElementType.METHOD)
@Retention(RetentionPolicy.RUNTIME)
public @interface MyAnnotation1 {
    String name();

    int age();

}


public class Test {

    @MyAnnotation1(name="张三",age=18)
    public void show1(){
        System.out.println("show1方法执行了....");
    }

    public void show2(){
        System.out.println("show2方法执行了....");
    }

    public static void main(String[] args) throws Exception{
        /*
            java.lang.reflect.AnnotatedElement接口: Class、Method、Field、Constructor等实现了AnnotatedElement
            - T getAnnotation(Class<T> annotationType):得到指定类型的注解引用。没有返回null。
            - boolean isAnnotationPresent(Class<?extends Annotation> annotationType)：判断指定的注解有没有。

         */
        // 需求:1.获取show1方法上面的注解对象
        // 1.1 得到Test类的Class对象
        Class<?> c = Class.forName("demo12_注解解析.Test");

        // 1.2 获得show1方法的Method对象
        Method show1M = c.getDeclaredMethod("show1");

        // 1.3 根据Method对象调用getAnnotation()方法得到注解对象
        MyAnnotation1 a1 = show1M.getAnnotation(MyAnnotation1.class);
        System.out.println(a1.name());
        System.out.println(a1.age());

        System.out.println("======================");

        // 2.需求: 判断某个方法上是否有MyAnnotation1注解
        // 判断show1方法上是否有MyAnnotation1注解
        boolean res1 = show1M.isAnnotationPresent(MyAnnotation1.class);
        System.out.println(res1);// true

        // 判断show2方法上是否有MyAnnotation1注解
        Method show2M = c.getDeclaredMethod("show2");
        boolean res2 = show2M.isAnnotationPresent(MyAnnotation1.class);
        System.out.println(res2);// false

    }
}

```

## 实操--完成注解的MyTest案例 

### 需求

​	在一个类(测试类,TestDemo)中有三个方法,其中两个方法上有@MyTest,另一个没有.还有一个主测试类(MainTest)中有一个main方法.  在main方法中,让TestDemo类中含有@MyTest方法执行.   自定义@MyTest, 模拟单元测试.

### 思路分析

1. 定义两个类和一个注解

2. 在MainTest的main()方法里面:

   ​	//1.获得TestDemo字节码对象
   ​	//2.反射获得TestDemo里面的所有的方法
   ​	//3.遍历方法对象的数组. 判断是否有@MyTest(isAnnotationPresent)
   ​	//4.有就执行(method.invoke())

### 代码实现

- MyTest.java

```java
@Target(ElementType.METHOD)
@Retention(RetentionPolicy.RUNTIME)
public @interface MyTest {

}
```

- TestDemo.java

```java
public class TestDemo {
    @MyTest
    public void show1(){
        System.out.println("show1方法执行了...");
    }

    @MyTest
    public void show2(){
        System.out.println("show2方法执行了...");
    }

    public void show3(){
        System.out.println("show3方法执行了...");
    }

}

```

- MainTest.java

```java
public class MainTest {

    public static void main(String[] args) throws Exception {
        // 让第一个类中含有@MyTest注解的方法执行
        // 1.获取TestDemo类的字节码对象
        Class<TestDemo> clazz = TestDemo.class;

        // 2.使用字节码对象获取该类中所有方法对象
        Method[] methods = clazz.getDeclaredMethods();

        // 3.循环遍历所有方法对象
        for (Method method : methods) {
            // 4.在循环中,判断遍历出来的方法对象是否含有@MyTest注解
            boolean res = method.isAnnotationPresent(MyTest.class);
            if (res) {
                // 5.如果有,就调用该方法执行
                method.invoke(clazz.newInstance());
            }
        }

    }

}
```

# 第四章 动态代理 

### 目标

- 能够使用动态代理生成一个代理对象

### 路径

- 代理模式概念
- 动态代理
- 动态代理相关api介绍
- 案例演示

### 讲解

#### 代理模式概述

为什么要有“代理”？生活中就有很多代理的例子，例如，我现在需要出国，但是我不愿意自己去办签证、预定机票和酒店（觉得麻烦 ，那么就可以找旅行社去帮我办，这时候旅行社就是代理，而我自己就是被代理了。

代理模式的定义：被代理者没有能力或者不愿意去完成某件事情，那么就需要找个人代替自己去完成这件事,这个人就是代理者, 所以代理模式包含了3个角色: 被代理角色     代理角色    抽象角色(协议)

静态代理:

```java
public interface Happy {// 协议,被代理者需要代理的方法,就定义在这里,然后让代理者和被代理者去实现
    // 被代理者实现: 为了确保和代理者实现的方法一致
    // 代理者实现: 为了增强被代理者的这些方法
    public abstract void happy();
}


public class AAA implements Happy {

    public void happy(){
        System.out.println("AAA在happy...");
    }

}


public class BBB implements Happy{
    // 成员变量
    AAA aaa;

    // 构造方法
    public WangPo(AAA aaa) {
        this.aaa = aaa;
    }

    // 成员方法
    @Override
    public void happy() {
        System.out.println("BBB来协作...");
        // AAA在happy
        jl.happy();
        System.out.println("BBB完成清理...");
    }
}


public class CCC {
    public static void main(String[] args) {
        /*
            案例: AAA要找CCC一起happy
            代理模式的定义：被代理者没有能力或者不愿意去完成某件事情，那么就需要找个人代替自己去完成这件事,这个人就是代理者,
            所以代理模式包含了3个角色: 被代理角色     代理角色    抽象角色(协议)

         */
        // 不请代理: AAA直接找CCChappy
        // 创建金莲对象
        AAA aaa = new AAA();
        // happy
        // aaa.happy();

        // 请代理: 静态代理,代理类真实存在
        Happy wp = new BBB(aaa);// wp:代理对象   BBB类: 代理类   Happy接口: 协议  AAA: 被代理类
        wp.happy();
    }
}

```

#### 动态代理介绍

- 概述 : 动态代理就是直接通过反射生成一个代理对象,代理对象所属的类是不需要存在的

- 动态代理的获取:

  ​	jdk提供一个Proxy类可以直接给实现接口类的对象直接生成代理对象 


#### 动态代理相关api介绍

Java.lang.reflect.Proxy类可以直接生成一个代理对象  

- Proxy.newProxyInstance(ClassLoader loader, Class<?>[] interfaces, InvocationHandler h)生成一个代理对象
  - 参数1:ClassLoader loader 被代理对象的类加载器 
  - 参数2:Class<?>[] interfaces 被代理对象的要实现的接口 
  - 参数3:InvocationHandler h (接口)执行处理类
  - 返回值: 代理对象
  - 前2个参数是为了帮助在jvm内部生成被代理对象的代理对象,第3个参数,用来监听代理对象调用方法,帮助我们调用方法
- InvocationHandler中的Object invoke(Object proxy, Method method, Object[] args)方法：调用代理类的任何方法，此方法都会执行
  - 参数1:代理对象(慎用)
  - 参数2:当前执行的方法
  - 参数3:当前执行的方法运行时传递过来的参数
  - 返回值:当前方法执行的返回值			

#### 案例演示

##### 案例1: 代理方法无参数

```java
public interface Happy {// 协议,被代理者需要代理的方法,就定义在这里,然后让代理者和被代理者去实现
    // 被代理者实现: 为了确保和代理者实现的方法一致
    // 代理者实现: 为了增强被代理者的这些方法
    public abstract void happy();
}


public class AAA implements Happy {

    public void happy(){
        System.out.println("AAA在happy...");
    }

}


public class CCC {
    public static void main(String[] args) {
        /*
            案例: AAA要找CCC一起happy
            代理模式的定义：被代理者没有能力或者不愿意去完成某件事情，那么就需要找个人代替自己去完成这件事,这个人就是代理者,
            所以代理模式包含了3个角色: 被代理角色     代理角色    抽象角色(协议)
         */


        /*
            问题:
                1.AAA不方便直接找CCC一起happy
                2.AAA的happy方法需要增强一下,例如:happy之前需要有前置条件,happy之后需要进行后续动作

            静态代理: 代理类是真实存在的,通过代理类产生代理对象
            动态代理: 代理类是不真实存在的,在程序运行中,直接产生代理对象
            前提: 被代理类需要实现接口
            动态代理实现获取代理对象:
                jdk提供一个Proxy类可以直接给实现接口类的对象直接生成代理对象
                Proxy.newProxyInstance(ClassLoader loader, Class<?>[] interfaces, InvocationHandler h)生成一个代理对象
                    参数1loader:被代理类的类加载器
                    参数2interfaces: 被代理类所有实现的接口的Class对象
                    参数3InvocationHandler: 执行处理类
                    前2个参数是为了帮助在jvm内部生成被代理类的代理对象,第3个参数用来监听代理对象调用的方法,帮助我们代理对象调用方法
         */
        System.out.println("=========================================");

        // 使用动态代理直接产生金莲的代理对象
        // 动态代理: 代理类是不真实存在的,但代理类是一定实现了被代理类的接口的
        // p:动态代理产生的代理对象 代理类是不真实存在的
        Happy p = (Happy) Proxy.newProxyInstance(AAA.class.getClassLoader(), AAA.class.getInterfaces(), new InvocationHandler() {
            @Override
            public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
                // 回调方法: 当代理对象调用了方法,就会来执行该invoke方法, 在该方法中就可以增强被代理类的方法
                // 参数1: 生成的代理对象 这里就是p这个代理对象 (慎用)
                // 参数2: 当前代理对象执行的方法 这里method就是happy()方法对象
                // 参数3: 当前代理对象执行的方法,传入的实际参数
                // 返回值:当前代理对象执行的方法的返回值
                // System.out.println("invoke");
                if (method.getName().equals("happy")){
                    System.out.println("BBB准备前置条件...");
                    // 通过反射来调用被代理对象的方法
                    method.invoke(jl);
                    System.out.println("BBB进行后续动作...");
                }
                return null;
            }
        });

        // 代理happy
        p.happy();// 无参数
    }
}

```

# 第五章JDK8新特性

## 知识点--方法引用

### 目标

- 什么是方法引用,方法引用的使用场景

### 讲解

#### 方法引用概述

- 方法引用使用一对冒号 **::** , 方法引用就是用来在一定的情况下,替换Lambda表达式

#### 方法引用基本使用

- 使用场景:
  - 如果一个Lambda表达式大括号中的代码和另一个方法中的代码一模一样,那么就可以使用方法引用把该方法引过来,从而替换Lambda表达式
  - 如果一个Lambda表达式大括号中的代码就是调用另一方法,那么就可以使用方法引用把该方法引过来,从而替换Lambda表达式

```java

public class Test {

    public static void show(){
        System.out.println("线程执行了");
    }

    public static void main(String[] args) {
        /*
            方法引用:
                概述:方法引用使用一对冒号 :: , 方法引用就是用来在一定的情况下,替换Lambda表达式
                使用场景:
                    1.如果Lambda表达式的大括号中的代码和另一个方法的方法体一模一样,那么就可以使用方法引用把该方法
                       直接引过来,从而替换Lambda表达式
                    2.如果Lambda表达式的大括号中的代码就是调用另一个方法,那么就可以使用方法引用把该方法
                       直接引过来,从而替换Lambda表达式
         */
        // 创建并启动线程
        new Thread(()->{
            System.out.println("线程执行了");
        }).start();

        // 发现上述的Lambda表达式大括号中的内容和Test类的show方法的方法体一模一样,符合方法引用替换Lambda表达式的场景
        new Thread(Test::show).start();

        System.out.println("=========================================");

        new Thread(()->{
            Test.show();
        }).start();

        // 发现上述的Lambda表达式大括号中的内容就是调用Test类的show方法,符合方法引用替换Lambda表达式的场景
        new Thread(Test::show).start();
    }
}

```

## 知识点--方法引用的分类

### 目标

- 能够正确书写方法引用

### 讲解

#### 构造方法引用

```java
public class Test2 {
    public static void main(String[] args) {
        //创建集合
        ArrayList<String> list = new ArrayList<>();
        list.add("aaa");
        list.add("bbb");
        list.add("ccc");

        // 需求: 把集合中的元素转换为Person对象,打印输出
        list.stream().map(s-> new Person(s)).forEach(s-> System.out.println(s));

        System.out.println("======================");
       
        list.stream().map(Person::new).forEach(s-> System.out.println(s));
	
    }
}
```

#### 静态方法引用

```java
public class Test2 {
    public static void main(String[] args) {
        //创建集合
        ArrayList<String> list = new ArrayList<>();
        list.add("110");
        list.add("111");
        list.add("112");

        // 需求:把集合中的元素转换为int类型,打印输出
        list.stream().map(s-> Integer.parseInt(s)).forEach(s-> System.out.println(s));

        System.out.println("======================");

        list.stream().map(Integer::parseInt).forEach(s-> System.out.println(s));

    }
}
```

#### 对象成员方法引用

- 成员方法有参数

  ```java
  public class Test2 {
      public static void main(String[] args) {
          //创建集合
          ArrayList<String> list = new ArrayList<>();
          list.add("aaa");
          list.add("bbb");
          list.add("ccc");
  
          // 需求:把集合中所有元素打印输出
          list.stream().forEach(s-> System.out.println(s));
  
          System.out.println("=================================");
          
          list.stream().forEach(System.out::println);
  
      }
  }
  ```

#### 类的成员方法引用

- 成员方法没有参数

  ```java
  public class Test2 {
      public static void main(String[] args) {
          //创建集合
          ArrayList<String> list = new ArrayList<>();
          list.add("aaa");
          list.add("bbb");
          list.add("ccc");
  
          // 需求: 把集合中的元素转换为该元素对应的字符长度,打印输出
          list.stream().map(s->s.length()).forEach(System.out::println);
  
          System.out.println("=================================");
  		//会默认的用参数s去调用String类中的length()方法
          list.stream().map(String::length).forEach(System.out::println);
  
      }
  }
  ```

### 小结

```
总结:使用方法引用的步骤
    1.分析要写的Lambda表达式的大括号中是否就是调用另一个方法
    2.如果是,就可以使用方法引用替换,如果不是,就不能使用方法引用
    3.确定引用的方法类型(构造方法,成员方法,静态方法,类的成员方法)
    4.按照对应的格式去引用:
        构造方法: 类名::new
        成员方法(有参数): 对象名::方法名
        静态方法: 类名::方法名
        类的成员方法\成员方法(无参数):  类名::方法名
```

## 知识点--Base64

### 目标

- 会使用Base64对数据进行编码和解码

### 讲解

#### Base64概述

- Base64是jdk8提出的一个新特性,可以用来进行按照一定规则编码和解码

#### Base64编码和解码的相关方法

- 编码的步骤:

  - 获取编码器
  - 调用方法进行编码

- 解码步骤:

  - 获取解码器
  - 调用方法进行解码

- Base64工具类提供了一套静态方法获取下面三种BASE64编解码器：

  - **基本：**输出被映射到一组字符A-Za-z0-9+/，编码不添加任何行标，输出的解码仅支持A-Za-z0-9+/。
  - **URL：**输出映射到一组字符A-Za-z0-9+_，输出是URL和文件。
  - **MIME：**输出隐射到MIME友好格式。输出每行不超过76字符，并且使用'\r'并跟随'\n'作为分割。编码输出最后没有行分割。

- 获取编码器和解码器的方法

  ```java
  static Base64.Decoder getDecoder() 基本型 base64 解码器。
  static Base64.Encoder getEncoder() 基本型 base64 编码器。
  
  static Base64.Decoder getMimeDecoder() Mime型 base64 解码器。
  static Base64.Encoder getMimeEncoder() Mime型 base64 编码器。
  
  static Base64.Decoder getUrlDecoder() Url型 base64 解码器。
  static Base64.Encoder getUrlEncoder() Url型 base64 编码器。
  ```

- 编码和解码的方法:

  ```java
  Encoder编码器:  encodeToString(byte[] bys)编码
  Decoder解码器:  decode(String str) 解码
  ```

#### 案例演示

- 基本

```java
public class Test1 {
    public static void main(String[] args) {
        // 使用基本型的编码器和解码器对数据进行编码和解码:
        // 1.获取编码器
        Base64.Encoder encoder = Base64.getEncoder();

        // 2.对字符串进行编码
        String str = "name=中国?password=123456";
        String str1 = encoder.encodeToString(str.getBytes());

        // 3.打印输出编码后的字符串
        System.out.println("编码后的字符串:"+str1);

        // 4.获取解码器
        Base64.Decoder decoder = Base64.getDecoder();

        // 5.对编码后的字符串进行解码
        byte[] bys = decoder.decode(str1);
        String str2 = new String(bys);

        // 6.打印输出解码后的字符串
        System.out.println("解码后的字符串:"+str2);
    }
}
```

- URL

```JAVA
public class Test2 {
    public static void main(String[] args) {

        // 使用URL型的编码器和解码器对数据进行编码和解码:
        // 1.获取编码器
        Base64.Encoder encoder = Base64.getUrlEncoder();

        // 2.对字符串进行编码
        String str = "name=中国?password=123456";
        String str1 = encoder.encodeToString(str.getBytes());

        // 3.打印输出编码后的字符串
        System.out.println("编码后的字符串:"+str1);

        // 4.获取解码器
        Base64.Decoder decoder = Base64.getUrlDecoder();

        // 5.对编码后的字符串进行解码
        byte[] bys = decoder.decode(str1);
        String str2 = new String(bys);

        // 6.打印输出解码后的字符串
        System.out.println("解码后的字符串:"+str2);
    }
}

```

- MIME

```java
public class Test3 {
    public static void main(String[] args) {
        // 使用MIME型的编码器和解码器对数据进行编码和解码:
        // 1.获取编码器
        Base64.Encoder encoder = Base64.getMimeEncoder();

        // 2.对字符串进行编码
        String str = "";
        for (int i = 0; i < 100; i++) {
            str += i;
        }
        System.out.println("编码前的字符串:"+str);

        String str1 = encoder.encodeToString(str.getBytes());

        // 3.打印输出编码后的字符串
        System.out.println("编码后的字符串:"+str1);

        // 4.获取解码器
        Base64.Decoder decoder = Base64.getMimeDecoder();

        // 5.对编码后的字符串进行解码
        byte[] bys = decoder.decode(str1);
        String str2 = new String(bys);

        // 6.打印输出解码后的字符串
        System.out.println("解码后的字符串:"+str2);
    }
}
```

