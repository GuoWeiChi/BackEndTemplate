## rest风格测试

```java
package controller;

import com.hashnode.PaymentMain8001;
import com.hashnode.model.CommonResult;
import com.hashnode.model.Payment;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;
import org.junit.jupiter.params.provider.ValueSource;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.web.client.TestRestTemplate;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;

@SpringBootTest(webEnvironment = SpringBootTest.WebEnvironment.RANDOM_PORT,classes = PaymentMain8001.class)
public class RandomPortTest {
    @Autowired
    private TestRestTemplate restTemplate;

    @ParameterizedTest
    @CsvSource({",zzzzz"})
    public void testcreate(Long id,String serial){
        Payment payment = new Payment(id, serial);
        CommonResult resutl = restTemplate.postForObject("/payment/create",payment, CommonResult.class);
        System.out.println(resutl);
    }

    @ParameterizedTest
    @ValueSource(longs = {1} )
    public void testgetPaymentById(Long id){
        CommonResult resutl = restTemplate.getForObject("/payment/get/" + id, CommonResult.class);
        System.out.println(resutl);
    }

}
```

## ModelAndView请求风格

```java
package web;

import com.hashnode.model.CommonResult;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;
import org.junit.jupiter.params.provider.ValueSource;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.AutoConfigureMockMvc;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.test.web.servlet.MockMvcBuilder;
import org.springframework.test.web.servlet.request.MockMvcRequestBuilders;
import org.springframework.web.servlet.ModelAndView;

import java.net.URI;
import java.util.Map;

@SpringBootTest(webEnvironment = SpringBootTest.WebEnvironment.MOCK)
@AutoConfigureMockMvc
public class MockEnvTest {
    @Autowired
    private MockMvc mvc;

    @Test
    public void testIndex() throws Exception{
        ModelAndView modelAndView = mvc.perform(MockMvcRequestBuilders.get(new URI("/"))).andReturn().getModelAndView();

    }

    @ParameterizedTest
    @CsvSource({",zzzzz"})
    public void testcreate(Long id,String serial) throws Exception{
        mvc.perform(MockMvcRequestBuilders.post(new URI("/payment/create"))
                .param("id",String.valueOf(id))
                .param("serial",serial)).andReturn().getModelAndView();
    }

    @ParameterizedTest
    @ValueSource(longs = {1} )
    public void testgetPaymentById(Long id) throws Exception{
        mvc.perform(MockMvcRequestBuilders.get("/getPayment?id={0}",id))
                .andReturn().getModelAndView();
    }
}
```

## 数据库service测试

```java
package service;


import com.hashnode.PaymentMain8001;
import com.hashnode.model.Payment;
import com.hashnode.service.PaymentService;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.LinkedHashMap;
import java.util.List;

@SpringBootTest(webEnvironment = SpringBootTest.WebEnvironment.NONE,classes = PaymentMain8001.class)
public class ServiceTest {
    @Autowired
    private PaymentService paymentService;

    @Test
    public void testgetAllPayment(){
        List<Payment> result = paymentService.getAllPayment();
        for (int i=0;i<result.size();i++){
            System.out.println(result.get(i));
        }
    }

    @ParameterizedTest
//    @CsvSource({"2,ccc","1,aaa","null,aaa"})
    @CsvSource({",ccc"})
    public void testInsert(Long id,String serial){
//        Payment payment = new Payment(id, serial);
        Payment payment = new Payment("aaa");
//        Integer result = paymentService.createPayment(payment);
        Integer result = paymentService.createPaymentSelective(payment);
        System.out.println(payment.getId());
        System.out.println(result);
    }

}
```