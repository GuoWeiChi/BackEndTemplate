

# gitee上传

https://gitee.com/codinginn

**gitee秘钥**
参考同级目录下的解决Typora…pdf

picgo配置如图所示:

![image-20211222092250834](gitee以及github上传图床教程.assets/image-20211222092250834.png)

# github图床使用教程

**1.创建Repository**

![image-20211218133019919](./记录.assets/image-20211218133019919.png)

![image-20211218133052594](./记录.assets/image-20211218133052594.png)

**2.生成Token用于操作Github repository**

![image-20211218133142573](./记录.assets/image-20211218133142573.png)

进入页面后，点击**Developer settings**按钮

![image-20211218133215551](./记录.assets/image-20211218133215551.png)

点击**Personal access tokens**按钮

![image-20211218133247051](./记录.assets/image-20211218133247051.png)

填写描述，选择**repo**权限，然后点击Generate token按钮

![image-20211218133335075](./记录.assets/image-20211218133335075.png)

> 注：创建成功后，会生成一串token，这串token之后不会再显示。

**githubtoken：**

```
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
```

**修改github分支名为master**

![image-20211218132621105](./记录.assets/image-20211218132621105.png)

![image-20211218132707991](记录.assets/image-20211218132707991.png)

**创建新目录**

![image-20211218135030703](./记录.assets/image-20211218135030703.png)

**picgo做如下配置：**

![image-20211218134849425](./记录.assets/image-20211218134849425.png)

```cmd
GuoWeiChi/MarkdownImgAsset
master
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
imgStore/
https://raw.githubusercontent.com/GuoWeiChi/MarkdownImgAsset/master
```

