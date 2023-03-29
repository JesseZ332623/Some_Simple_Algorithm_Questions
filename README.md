 计算机二级C语言程序设计编程题
 --------------------------------------------------------------------------------------------------------------
 前段时间去考了计算机二级C语言程序设计，难度不高（也就是大一C语言期末考试的难度），但是偏题，怪题实在太多，都是一些a+=a++*b+b--%10;之类的题目（《C陷阱与缺陷》狂喜），就挺无语的φ(*￣0￣)
 
 但是我的程序题可没有少刷，所以我把我刷过的程序题发布在[Github.com](https://github.com/)上，并挑几道有趣的题目并附上详细的说明。
 
 文件说明：
 ---------------------------------------------------------------------------------------------------------------
 
    Functions.c     我刷过的二级编程题
    

一些有趣的题目：
----------------------------------------------------------------------------------------------------------------

    01.
    /*将一个只有0或1组成的字符串转换成十进制 例：传入"101100" 返回 44*/
    ```C     
    int Change_Bin_To_Dec(char *str)
    {
        int index, dec_number = 0;

        for (index = 0; str[index] != '\0'; ++index)
        {

            dec_number = dec_number * 2 + (str[index] - '0');
        }        

            return dec_number;
    }
    ```
     
    
    这个函数采用循环来遍历传入的二进制字符串。对于每一个字符，做如下处理：

    通过乘以2来移动当前的十进制数，因为在二进制数中，每一个位上的数都是2的幂次方。

    首先将初始值dec_number设为0。
    然后，它每读取一个二进制位，就将当前的dec_number乘以2（左移一位），并将其加上（str[index] - '0'），其中str[index]是当前循环的字符。
    由于字符0~9的ASCII码是连续的，'0'的ASCII码是48，因此将字符'0'减去后，得到的就是0到9之间的数。

    如果输入二进制字符串为"101100"，那么循环的过程如下：

    index = 0 时，dec_number = 0*2+1 = 1
    index = 1 时，dec_number = 1*2+0 = 2
    index = 2 时，dec_number = 2*2+1 = 5
    index = 3 时，dec_number = 5*2+1 = 11
    index = 4 时，dec_number = 11*2+0 = 22
    index = 5 时，dec_number = 22*2+0 = 44

    所以返回的结果是44，即字符串"101100"的十进制值。
    
    (这种方法真的很妙，一般我做这种题目都是先把101100转成一个整数然后计算pow(2,5) + pow(2,3) + pow(2,2)的值，从没想过可以这么操作[捂脸])
    
-------------------------------------------------------------------------------------------------------------------------------------------

    02.
    /*移动一维数组中的内容，若数组中有n个整数，要求把下标从 0 ~ p(n-1)的数组元素平移到数组最后*/
    /*若数组原始内容为：     1，2，3，4，5，6，7，8，9，10. | p = 3*/
    /*则移动后的数组内容为： 5，6，7，8，9，10，1，2，3，4*/
    
    void Move_Array_Element(int *array, int p, int arr_size)
    {
        int move_loop = 0;
        int array_index = 0;
        int array_element = 0;

        for (move_loop = 0; move_loop <= p; ++move_loop)
        {
            array_element = array[0];

            for (array_index = 1; array_index < arr_size; ++array_index)
            {
                array[array_index - 1] = array[array_index];
            }

            array[arr_size - 1] = array_element;
        }
    }
    
    这个函数可以通过循环的方式将数组中的元素向左移动p个位置。
    对于数组的前p个元素，它们都要向左移动一个位置。
    为了实现这个移动，函数将数组的第一个元素存储在变量array_element中，并将数组中的其他元素向左移动一个位置。
    然后，将array_element存储在数组的最后一个元素中，这样，数组中的元素就会向左移动一个位置。
    重复这个过程p次，就可以将数组中的元素向左移动p个位置。
    
    如果传入的数组array[5]的元素为 array[5] = {1,2,3,4,5} 且 p = 2 函数运行过程如下：
    
    move_loop = 0 时，将array[0]的值1赋值给array_element，内循环将数组向前移一位,跳出内循环后再把array[0]的值赋给数组的最后一位。
    此时数组元素为：{2,3,4,5,1}
    
    move_loop = 1 时，将array[0]的值2赋值给array_element，内循环将数组向前移一位,跳出内循环后再把array[0]的值赋给数组的最后一位。
    此时数组元素为：{3,4,5,1,2}
    
    move_loop = 2 时，将array[0]的值3赋值给array_element，内循环将数组向前移一位,跳出内循环后再把array[0]的值赋给数组的最后一位。
    此时数组元素为：{4,5,1,2,3}
    
    最后数组array[5]的元素为：array[5] = {4,5,1,2,3};
    
    tips:该函数的循环次数为p+1，而非p次。
    这是因为每次循环都将数组的第一个元素移动到数组的最后一个元素，则总共需要移动p个元素，
    并且最后一次移动将数组的第一个元素移动到最后一个元素的位置，因此需要循环p+1次。

License
-----------------------------------------------------------------------------------------------------------------
[MIT](https://choosealicense.com/licenses/mit/) © [JesseZ332623](https://github.com/JesseZ332623)

Date:2023.3.28

Author:JesseZ332623

EOF

