/**
* _int_char - Convert Integer To Char
* @n: Int To Convert
* Return: Char Pointer
*/
char *_int_char(unsigned int n)
{
int len, i;
i = 0;
len = 0;
char *mem;
len = intlen(n);
mem = malloc(len + 1);
*mem = '\0';
for (i = 0; n / 10; i++)
{
mem[i]  = (n % 10)  + '0';
n /= 10;
}
mem[i] = (n % 10) + '0';
_rev(mem, len);
mem[i + 1] = '\0';
return (mem);
}
/**
* _rev - Reverse Array
* @arr:Array To Reverse
* @len:Length Of Array
* Return: Void(Reverse Array)
*/



void _rev(char *arr, int len)
{
int i = 0;
char a;

for (i = 0; i < (len / 2);  i++)
{
a = arr[i];
arr[i] = arr[len - 1 - i];
arr[len - 1 - i] = a;
}
}
