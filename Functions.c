/*Functions.c*/

/*Create by Jesse_EC on 2023.3.28*/
/*Copyright © 2023 Jesse_EC All rights reserved.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

void Be_Big(char *str);
void Move_Array_Element(int *array, int p, int arr_size);
int Get_Fector_Count(int number);
float Keep_two_digits(float number);
double Calculation_Foluma(int n);
void Get_Cols_String(char (*dou_str)[4], char *re_str);
void Get_New_Array_In_Long_Number(long number, long *array);
int Get_Number_Digite(long int number);
int *Get_Number_Digite_Value(long int number);
void _Get_New_Strings(char *s, char t[]);
int Find_Charector_In_String(const char *string);
char *Delete_String_Element(char *string, char delete_element, int str_size);

/*将目标字符串索引为奇数的字母转化为大写*/
void Be_Big(char *str)
{
    int str_length = 0;
    int str_index = 0;
    char *str_ptr = NULL;

    str_ptr = str;

    while (*str_ptr++ != '\0')
    {
        str_length++;
    }

    for (str_index = 1; str_index < str_length; str_index += 2)
    {
        if (str[str_index] >= 'a' && str[str_index] <= 'z')
        {
            str[str_index] = str[str_index] - 'a' + 'A';
        }
    }
}

/*移动一维数组中的内容，若数组中有n个整数，要求把下标从 0-p(n-1)的数组元素平移到数组最后*/
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

/*传入一个整数（n < 1000 并且）输出这个整数的因数之和（不包括 1 和 n 本身）*/
int Get_Fector_Count(int number)
{
    int factor_count = 0;
    int division_number = 0;

    if (number < 1000)
    {
        for (division_number = 2; division_number < number; ++division_number)
        {
            if (number % division_number == 0)
            {
                factor_count += division_number;
            }
        }
    }
    else
    {
        printf("The number [%d] > 1000\n", number);
        return -1;
    }

    return factor_count;
}

/*将一个多位小数四舍五入成2位小数 例：传入1234.567 函数返回1234.570000*/
float Keep_two_digits(float number)
{
    return (int)(number * 100 + 0.5) / 100.0;
}

double Calculation_Foluma(int n)
{
    double total_value = 1.00000;
    double product_value = 1.00000;
    int loop = 0;

    if (n < 1 || n > 100)
    {
        return -1;
    }

    for (loop = 1; loop <= n; ++loop)
    {
        product_value = product_value * loop;

        total_value += 1.0000 / product_value;
    }

    return total_value;
}

// 将 M 行 N 列的二维字符串按列的顺序依次放到字符串中
//  W W W W
//  S S S S
//  H H H H
/*应用函数后的字符串为：*/
// WSHWSHWSHWSH
void Get_Cols_String(char dou_str[3][4], char *re_str)
{
    int null_position = 0;
    int o_index = 0;
    int in_index = 0;

    for (o_index = 0; o_index < 4; ++o_index)
    {
        for (in_index = 0; in_index < 3; ++in_index)
        {
            re_str[null_position++] = dou_str[in_index][o_index];
        }
    }
    re_str[null_position] = '\0';
}

// 从低位开始依次取长整型变量 number 上奇数位的数，构成一个新的数放在 array 中
void Get_New_Array_In_Long_Number(long number, long *array)
{
    long add_number = 10;
    number /= 10;

    *array = number % 10;
    while (number > 0)
    {
        number = number / 100;

        *array = number % 10 * add_number + *array;

        add_number *= 10;
    }
}

/*计算一个整数共有几位并返回*/
int Get_Number_Digite(long int number)
{
    int number_digite = 0;

    while (number > 0)
    {
        number /= 10;
        ++number_digite;
    }

    return number_digite;
}

/*计算一个整数各个位数的值，存入一个数组中并返回 例：传入12345 返回数组 array[5] = {1,2,3,4,5}*/
int *Get_Number_Digite_Value(long int number)
{
    int number_digite = Get_Number_Digite(number);
    int *number_array = (int *)malloc(number_digite * sizeof(int));

    if (number_digite <= 0 || number_digite >= LONG_MAX)
    {
        fprintf(stderr, "The number is too big or too small(0 <= number < %ld) .......\n", LONG_MAX);
        exit(EXIT_FAILURE);
    }
    while (number_digite)
    {
        number_array[number_digite] = number % 10;
        number /= 10;

        --number_digite;
    }

    return number_array;
}

/*使用Get_Number_Digite_Value() 和Get_Number_Digite() 函数*/
void Use_Gigit_Functions()
{
    while (true)
    {
        long int number = 0L;
        int number_digit = 0;

        printf("Enter the number (0 < number < [%ld]):\n", LONG_MAX);
        if (scanf("%ld", &number) != 1)
        {

            fprintf(stderr, "Enter too much number!!\n");
            exit(EXIT_FAILURE);
        }

        number_digit = Get_Number_Digite(number);

        int *number_array = (int *)malloc(number_digit * sizeof(int));

        number_array = Get_Number_Digite_Value(number);

        printf("\nThe number digit is:[%d].\n", number_digit);

        puts("The number_array contence is:");
        for (int index = 1; index <= number_digit; ++index)
        {
            printf("[%d] ", number_array[index]);
        }

        putchar('\n');

        free(number_array);
        if (getchar() == '\n')
        {
            continue;
        }
    }
}

/*传入一个字符串，将该字符串内ASCII码值为奇数的字符放到一个新字符串中*/
/*例子：传入ABCDEFG123456 新字符串为：BDF246*/
void _Get_New_Strings(char *s, char t[])
{
    int str_length = 0;
    int t_index = 0;

    str_length = strlen(s);

    for (int index = 0; index < str_length; ++index)
    {
        if (s[index] % 2 == 0)
        {
            t[t_index++] = s[index];
        }
    }
    t[t_index] = '\0';
}

int Change_Bin_To_Dec(char *str)
{
    int index, dec_number = 0;

    for (index = 0; str[index] != '\0'; ++index)
    {
        dec_number = dec_number * 2 + (str[index] - '0');
    }

    return dec_number;
}

char *Delete_String_Element(char *string, char delete_element, int str_size)
{
    int point = 0;
    for (int index = 0; index < str_size; index++)
    {
        if (string[index] == delete_element)
        {
            continue; // 若当前字符为要删除的字符，则直接跳过继续进行循环
        }
        else
        {
            string[point] = string[index]; // 当前字符为非删除字符，则往前覆盖
            point++;                       // 有效字符标号位置递增
        }
    }
    string[point] = '\0'; // 循环结束，最后一个字符为结束符

    return string;
}

int Find_Charector_In_String(const char *string)
{
    int number_index = 0;

    while (*string != '\0')
    {
        if (*string >= '0' && *string <= '9')
        {
            ++number_index;
        }
        string++;
    }

    return number_index;
}

int main(int argc, char const *argv[])
{
    printf("#[%s]\n", __FILE__);
    printf("#[%s] [%s]\n", __DATE__, __TIME__);

    return 0;
}
