 计算机二级C语言程序设计编程题
 --------------------------------------------------------------------------------------------------------------
 前段时间去考了计算机二级C语言程序设计，难度不高（也就是大一C语言期末考试的难度），但是偏题，怪题实在太多，都是一些a+=a++*b+b--%10;之类的题目（《C陷阱与缺陷》狂喜），就挺无语的φ(*￣0￣)
 
 但是我的程序题可没有少刷，所以我把我刷过的程序题发布在上面，并挑几道有趣的题目并附上详细的说明。
 
 文件说明：
 ---------------------------------------------------------------------------------------------------------------
 
    Functions.c     我刷过的二级编程题
    

一些有趣的题目：
----------------------------------------------------------------------------------------------------------------
01.
    /*将一个只有0或1组成的字符串转换成十进制 例：传入"101100" 返回 44*/
    
     int Change_Bin_To_Dec(char *str)
     {
         int index, dec_number = 0;

         for (index = 0; str[index] != '\0'; ++index)
         {

             dec_number = dec_number * 2 + (str[index] - '0');
         }        

         return dec_number;
     }
    
    该函数采用循环来遍历传入的二进制字符串。对于每一个字符，做如下处理：

    通过乘以2来移动当前的十进制数，因为在二进制数中，每一个位上的数都是2的幂次方。
    
    首先将初始值dec_number设为0。
    然后，它每读取一个二进制位，就将当前的dec_number乘以2（左移一位），并将其加上（str[index] - '0'），其中str[index]是当前循环的字符。
    由于字符0~9的ASCII码是连续的，'0'的ASCII码是48，因此将字符'0'减去后，得到的就是0到9之间的数。

    如果输入二进制字符串为"101100"，那么循环的过程如下：

      index = 0时，dec_number = 0*2+1 = 1
      index = 1时，dec_number = 1*2+0 = 2
      index = 2时，dec_number = 2*2+1 = 5
      index = 3时，dec_number = 5*2+1 = 11
      index = 4时，dec_number = 11*2+0 = 22
      index = 5时，dec_number = 22*2+0 = 44
    
    所以返回的结果是44，即字符串"101100"的十进制值。
    
    (这种方法真的很妙，一般我做这种题目都是先把101100转成一个整数然后计算pow(2,5) + pow(2,3) + pow(2,2)的值，从没想过可以这么操作[捂脸])

License
-----------------------------------------------------------------------------------------------------------------
[MIT](https://choosealicense.com/licenses/mit/) © [JesseZ332623](https://github.com/JesseZ332623)

Date:2023.3.28

Author:JesseZ332623

EOF

