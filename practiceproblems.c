#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


void max(const int array[], int n)
{
    int biggest_num = 0;
    for(int i = 0; i < n; i++)
    {
        if(biggest_num < array[i])
        {
            biggest_num = array[i];
        }
    }
    printf("the biggest number is: %d", biggest_num);

}

int sum_max2(const int array[], int n) //
{
    int largest = array[0], second_largest = array[1];
    int i;
    
    // find the two largest values in the array
    for (i = 1; i < n; i++) {
        if (array[i] > largest) {
            second_largest = largest;
            largest = array[i];
        }
        else if (array[i] > second_largest) {
            second_largest = array[i];
        }
    }
    
    return largest + second_largest;
    
}

void reverse(char str[]) //
{
    int length_string = strlen(str);

    for(int i = 0; i < length_string/2; i++)
    {
        char temp = str[i];
        str[i] = str[length_string - i -1];
        str[length_string - i -1] = temp;
    }

}

int str_find(const char* str, char c)
{   
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == c)
        {
            return i;
        }
        i++;
    }
    return -1;

}

bool is_palindrome(const char* str) //
{
    int n = strlen(str);
    for(int i = 0; i < (n-1)/2; i++)
    { 
        if(str[i] != str[n-1-i])
        {
            return false;
        }
    }
    return true; 
}

int simple_calc(const char* str) //STUDY THIS, not necessairly the switch cases
{
    int num1, num2;
    char op;

    // extract the first number
    num1 = atoi(str);

    // skip past the first number and extract the operator
    while (*str >= '0' && *str <= '9') {
        str++;
    }
    op = *str;

    // extract the second number
    num2 = atoi(++str);

    // calculate the result
    switch(op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 == 0) {
                printf("Error: division by zero\n");
                return 0;
            }
            return num1 / num2;
        default:
            printf("Error: invalid operator\n");
            return 0;
    }
}

void binary_to_int(const char* binary) //
{
    //10011011 = 155.... where 2^7 + 2^4 + 2^3...
    int len = strlen(binary);
    int decimal = 0;
    int power = 1;

    for(int i = len-1; i >= 0; i--)
    {
        if(binary[i] == '1')
        {
            decimal += power;
            // printf("the decimal: %d\n", decimal);
            
        }
        power *= 2;
        // printf("the power: %d\n", power);
    }
}

void int_to_binary(const char* integ) //
{
    int num = atoi(integ); // convert string to int
    int bin = 0, rem, base = 1;
    
    while (num > 0) {
        rem = num % 2;
        bin += rem * base;
        num /= 2;
        base *= 10;
    }
    
    return bin;
}

int* create_const_array(int len, int val)
{
    int* return_arr = malloc(sizeof(int)*len);

    for(int i = 0; i < len; i++)
    {
        return_arr[i] = val;
    }
    return return_arr;
}

int* reverse_ar(const int* ar, int len)
{  
    int* reversed_arr = malloc(sizeof(int)*len);

    int counter = 0;
    for(int i = len-1; i >= 0; i--)
    {
        reversed_arr[counter] = ar[i];
    }
    return reversed_arr;
}

int longest_odd_subpalindrome(const char* str) {
  int n = strlen(str);
  int max_length = 1;
  for (int c=0; c<n; c++) 
  {
    int i=0;
    while (c-i>=0 && c+i<=n-1 && str[c-i]==str[c+i])
      i++;
    if (max_length < 2*i-1)
      max_length = 2*i-1;
  }
  return max_length;
}  
 
int longest_even_subpalindrome(const char* str) {
    int len = strlen(str);
    int max_len = 0;
    for (int i = 0; i < len - 1; i++) {
        if (str[i] == str[i + 1]) {
            int left = i;
            int right = i + 1;
            while (left >= 0 && right < len && str[left] == str[right]) {
                if ((right - left + 1) % 2 == 0) {
                    if (right - left + 1 > max_len) {
                        max_len = right - left + 1;
                    }
                }
                left--;
                right++;
            }
        }
    }
    return max_len;
}

int main() 
{

    char* const binary = "10011011";
    binary_to_int(binary);

    int n = sizeof(int)*8;
    printf("%d", n);
    
    // int x = 1;
    // int* ptr1 = &x; //holds adress of x (1)
    // int y = 2;
    // int* ptr2 = &y; //holds address of y (2)

    // *ptr1 = 2; //changes x to 2
    // ptr2 = ptr1; //ptr2 now points to ptr1, which holds x (2)
    // ptr1 = &y; //ptr1 now holds adress of y (2)
    // *ptr1 = 3; //changes y to 3

    // printf("x = %d\n", x); //2
    // printf("y = %d\n", y); //3
    // printf("*ptr1 = %d\n", *ptr1); //3
    // printf("*ptr2 = %d\n", *ptr2); //2

    // int ar[4] = {1,2,3,4}; 
    // int* ptr1 = ar+1; //points to the second element in array
    // *(ptr1+2) = 5; //points to fourth (ar+1+2) and sets it eqal to 5
    // printf("*ptr1 = %d\n", *ptr1);
    // printf("ar[2] = %d\n", ar[2]); 
    // printf("ar[3] = %d\n", ar[3]);

    // int x = 1;
    // int y = 2;
    // int* ptr1 = &x; //ptr1 points to adress of x (1)
    // int* ptr2 = &y; //ptr2 points to address of y (2)

    // *ptr2 = 3; //ptr2 now points to 3, y = 3
    // ptr2 = ptr1; //ptr2 now holds address to ptr1 (x) (1)
    // *ptr2 = 4; // ptr2 now points to 4, x = 4

    // printf("%d %d\n", x, y);

    // int ar[3] = {10, 20, 30};
    // int* ptr1 = ar; //points to ar (10)
    // int* ptr2 = ar + 2; //points to (30)
    // *ptr1 = 5; //now its 5,20,30
    // ptr1 = ptr2 - 1; //ptr1 points to 20
    // printf("%d %d %d\n", ar[0], ar[1], ar[2]); 
    // *ptr2 = ar[0]; //changes the third element to 5
    // ar[0] = *ptr1; //20,20,5
    // printf("%d %d %d\n", ar[0], ar[1], ar[2]);

    // int x = 1;
    // int y = 2;

    // int* ptr1 = &x; //ptr1 points to adress of x,(1)
    // int* ptr2 = &y; //ptr2 points to adress of y,(2)
    // *ptr2 = 3; //changes y = 3
    // ptr2 = ptr1; //ptr2 now points to ptr1 which holds adress of x, ptr2 points to x
    // *ptr2 = 4; // changes x = 4

    // // x = 4, y = 3, ptr1 points to x, ptr2 points to x



    // char ca = 'a';
    // char cb = 'b';

    // char* const ptr1_char = &ca; //ptr1 points to ca (a)
    // char* ptr2_char = &cb; //ptr2 points to cb (b)
    // ptr2_char = ptr1_char; //ptr2 now points to ptr1, which holds a

    // printf("%c", *ptr1_char); //a
    // printf("%c", *ptr2_char); //a

    // const char c = 'a';

    // char* ptr_char = &c; //cannot modify c because it is a const
    // *ptr_char = 'B'; 
  
    // printf("%c", c);
    // const int ar[4] = {1,2,33,4};
    // max(ar, 4);

    // char ca = 'a';
    // char cb = 'b';

    // char* const ptr1_char = &ca;
    // char* ptr2_char = &cb;
    // ptr2_char = ptr1_char;
    // ptr1_char = ptr2_char; //wont compile because pointing to a non const pointer // cant change a const pointer

    // printf("%c", *ptr1_char);
    // printf("%c", *ptr2_char);
    // sum_max2(ar, 4);

    // printf("original: %s\n", str);

    // reverse(str);
    // printf("reversed: %s\n", str);

    // char str[] = "Hello, world!";
    // char c = 'o';

    // int index = str_find(str, c);
    // if (index != -1) {
    //     printf("The character '%c' was found at index %d in the string '%s'\n", c, index, str);
    // } else {
    //     printf("The character '%c' was not found in the string '%s'\n", c, str);
    // }

    // bool bool_val = is_palindrome(str);
    // if(bool_val == true)
    // {
    //     printf("hell yea");
    // }
    // else
    // {
    //     printf("hell nah");
    // }

    // char expression[] = "123+59";
    // int result = simple_calc(expression);
    // printf("%d\n", result);


    return 0;



}
