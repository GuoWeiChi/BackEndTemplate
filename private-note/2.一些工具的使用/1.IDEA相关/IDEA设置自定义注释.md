# IDEA设置自定义注释

![image-20211006191238683](./img/image-20211006191238683.png)

先添加Template Group然后添加Live Template

![image-20211006191338522](./img/image-20211006191338522.png)

设置自定义注释

```java
**
 * @Author cgw
 * @Description $todo$
 $param$
 $return$
 * @Date  $date$ $time$
 **/
```

做如下设置

![image-20211006191849568](img/image-20211006191849568.png)

+ param:

  ```java
  groovyScript("if(\"${_1}\".length() == 2) {return '';} else {def result=''; def params=\"${_1}\".replaceAll('[\\\\[|\\\\]|\\\\s]', '').split(',').toList();for(i = 0; i < params.size(); i++) {if(i==0){result+='* @param ' + params[i] + ': '}else{result+='\\n' + ' * @param ' + params[i] + ': '}}; return result;}", methodParameters()); 
  ```

+ return

```java
groovyScript("def returnType = \"${_1}\"; def result = '* @return: ' + returnType; return result;", methodReturnType()); 
```

![image-20211029105159427](IDEA设置自定义注释.assets/image-20211029105159427.png)

然后在代码中输入//再按tab就能自动注释了.

# IDEA设置打开多个文件显示多个tab

![image-20211006200151508](img/image-20211006200151508.png)

# 永久解决 Intellij idea 报错：Error : java 不支持发行版本5

![image-20211007090721477](img/image-20211007090721477.png)

![image-20211007090757865](img/image-20211007090757865.png)

```xml
 <profile>
      <id>development</id>
      <activation>
        <jdk>1.8</jdk>
        <activeByDefault>true</activeByDefault>
      </activation>
      <properties>
        <maven.compiler.source>1.8</maven.compiler.source>
        <maven.compiler.target>1.8</maven.compiler.target>
        <maven.compiler.compilerVersion>1.8</maven.compiler.compilerVersion>
      </properties>
    </profile>
```

# 显示工具栏

![image-20211027125856198](IDEA设置自定义注释.assets/image-20211027125856198.png)



# 复制模块

![image-20211029102002498](IDEA设置自定义注释.assets/image-20211029102002498.png)

![image-20211029102146216](IDEA设置自定义注释.assets/image-20211029102146216.png)



![image-20211029102216296](IDEA设置自定义注释.assets/image-20211029102216296.png)



选择

![image-20211029102248334](IDEA设置自定义注释.assets/image-20211029102248334.png)

![image-20211029102302217](IDEA设置自定义注释.assets/image-20211029102302217.png)

![image-20211029102314250](IDEA设置自定义注释.assets/image-20211029102314250.png)

![image-20211029102326008](IDEA设置自定义注释.assets/image-20211029102326008.png)



修改模块名字

![image-20211029102421388](IDEA设置自定义注释.assets/image-20211029102421388.png)

![image-20211029102508447](IDEA设置自定义注释.assets/image-20211029102508447.png)



# 插件

## maven项目转javaweb

![image-20211027125622261](IDEA设置自定义注释.assets/image-20211027125622261.png)

