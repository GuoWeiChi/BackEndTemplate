# 8 Spring MVC之初体验

## 8.1 环境搭建之添加依赖

```groovy
dependencies {
    compile(project(":spring-webmvc"))
    // https://mvnrepository.com/artifact/javax.servlet/javax.servlet-api
    compileOnly group: 'javax.servlet', name: 'javax.servlet-api', version: '3.1.0'

    // https://mvnrepository.com/artifact/javax.servlet/jstl
    implementation group: 'javax.servlet', name: 'jstl', version: '1.2'


    testImplementation 'junit:junit:4.11'
    testImplementation 'junit:junit:4.12'
}
```

## 8.2 配置Srping MVC

webapp的WEB-INF目录下新建web.xml

+ web.xml

```xml
<?xml version="1.0" encoding="UTF-8"?>
<web-app xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
   xmlns="http://java.sun.com/xml/ns/javaee"
   xsi:schemaLocation="http://java.sun.com/xml/ns/javaee http://java.sun.com/xml/ns/javaee/web-app_2_5.xsd"
   version="2.5">
  <display-name>spring-mvc-sourcetest</display-name>

   <context-param>
      <param-name>contextConfigLocation</param-name>
      <param-value>classpath:applicationContext.xml</param-value>
   </context-param>

<!--   DispatcherServlet是子容器  父容器是Spring配置文件进行包扫描并保存所有组件的容器      子容器是SpringMVC配置文件进行包扫描并保存所有组件的容器   “<servlet-name>” 需要对应 “<servlet-name>”+“-servlet.xml”配置文件-->
   <servlet>
      <servlet-name>Springmvc</servlet-name>
      <servlet-class>org.springframework.web.servlet.DispatcherServlet</servlet-class>
      <load-on-startup>1</load-on-startup>
   </servlet>

   <servlet-mapping>
      <servlet-name>Springmvc</servlet-name>
      <url-pattern>/</url-pattern>
   </servlet-mapping>


  <welcome-file-list>
    <welcome-file>index.html</welcome-file>
    <welcome-file>index.jsp</welcome-file>
  </welcome-file-list>
   
   <listener>
      <listener-class>org.springframework.web.context.ContextLoaderListener</listener-class>
   </listener>

</web-app>
```

webapp的WEB-INF目录下Spingmvc-servlet.xml

+ Spingmvc-servlet.xml

```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
      xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
      xmlns:aop="http://www.springframework.org/schema/aop"
      xmlns:tx="http://www.springframework.org/schema/tx"
      xmlns:context="http://www.springframework.org/schema/context"
      xmlns:mvc="http://www.springframework.org/schema/mvc"
      xsi:schemaLocation="http://www.springframework.org/schema/beans
             http://www.springframework.org/schema/beans/spring-beans.xsd
             http://www.springframework.org/schema/tx
             http://www.springframework.org/schema/tx/spring-tx.xsd
              http://www.springframework.org/schema/aop
              http://www.springframework.org/schema/aop/spring-aop.xsd
                http://www.springframework.org/schema/context
              http://www.springframework.org/schema/context/spring-context.xsd http://www.springframework.org/schema/mvc http://www.springframework.org/schema/mvc/spring-mvc.xsd">

<!--   SpringMVC提供的一键式配置方法，配置此标签后SpringMVC会自动注册一些组件-->
   <mvc:annotation-driven/>
   <!--需要扫描的包-->
   <context:component-scan base-package="com.codingInn"/>

</beans>
```

resources目录下新建applicationContext.xml

+ applicationContext.xml

```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
      xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
      xmlns:tx="http://www.springframework.org/schema/tx"
      xsi:schemaLocation="http://www.springframework.org/schema/beans http://www.springframework.org/schema/beans/spring-beans.xsd
                     http://www.springframework.org/schema/tx http://www.springframework.org/schema/tx/spring-tx-2.5.xsd">

   <bean id="viewResolver" class="org.springframework.web.servlet.view.InternalResourceViewResolver">
      <property name="prefix" value="/jsp/"/>
      <property name="suffix" value=".jsp"/>
   </bean>

</beans>
```

接下来创建Controller和view：

+ GoController.java

```java
package com.codingInn.web.controller;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

@Controller
public class GoController {
   private final Log logger = LogFactory.getLog(GoController.class);
   //处理HEAD类型的"/"请求,此方法可以检测服务器的状态
   @RequestMapping(value = {"/"},method = {RequestMethod.HEAD})
   public String head(){
      return "go";
   }

   //处理get类型的“index”和"/"请求，如果配置了viewResolver,则对应的路径为"prefix+返回值+suffix"
   @RequestMapping(value = {"/go","/"},method = {RequestMethod.GET})
   public String index(Model model) throws Exception{
      logger.info("=========processed by index=======");
      model.addAttribute("msg","Go GO GO");
      return "go";
   }
}
```

在webapp目录下新建jsp目录，并在jsp目录中新建go.jsp

+ go.jsp

```jsp
<%--
  Created by IntelliJ IDEA.
  User: a7810
  Date: 2022/3/18
  Time: 14:00
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
${msg}
</body>
</html>
```

运行结果如下

![image-20220318144818757](imgs.assets/image-20220318144818757.png)