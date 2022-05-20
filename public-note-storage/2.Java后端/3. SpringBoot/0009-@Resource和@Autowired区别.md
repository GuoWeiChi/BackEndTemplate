## @Autowired

@Autowired为Spring提供的注解，只按照byType注入。

```java
public class TestServiceImpl {
  // 下面两种@Autowired只要使用一种即可
  @Autowired
  private UserDao userDao; // 用于字段上
  
  @Autowired
  public void setUserDao(UserDao userDao) { // 用于属性的方法上
    this.userDao = userDao;
  }
}
```

也可以同时指定类型以及bean的名字：

```java
public class TestServiceImpl {
  @Autowired
  @Qualifier("userDao")
  private UserDao userDao; 
}
```

## @Resource

@Resource装配顺序：

1. 如果同时指定了name和type，则从Spring上下文中找到唯一匹配的bean进行装配，找不到则抛出异常。

2. 如果指定了name，则从上下文中查找名称（id）匹配的bean进行装配，找不到则抛出异常。

3. 如果指定了type，则从上下文中找到类似匹配的唯一bean进行装配，找不到或是找到多个，都会抛出异常。

4. 如果既没有指定name，又没有指定type，则**自动按照byName**方式进行装配；如果**没有匹配**，则按**类型**进行匹配，如果匹配则自动装配。

```java
public class TestServiceImpl {
  // 下面两种@Resource只要使用一种即可
  @Resource(name="userDao")
  private UserDao userDao; // 用于字段上
  
  @Resource(name="userDao")
  public void setUserDao(UserDao userDao) { // 用于属性的setter方法上
    this.userDao = userDao;
  }
}
```

