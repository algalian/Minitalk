#include"libft.h"
#include<stdio.h>


t_ratio ft_ratio(double n)
{
    t_ratio input;
    t_ratio output;
    int i;
    
    input.num = ft_fabs(n) * 100000;
    input.den = 100000;

    i = 1;
    output.num = input.num;
    output.den = input.den;
    while(output.num % i == 0 && output.den % i == 0)
    {
        output.num /= i;
        output.den /= i;
        i++;
    }
    return(output);
}

int main()
{
    t_ratio ratio;

    ratio = ft_ratio(0.8);

    printf("%i/%i\n", ratio.num, ratio.den);
}