#include<math.h>
#include<stdio.h>
#include"libft.h"



static int ft_basic_pow(int base, int exp)
{
    int i;
    int res;
    
    i = 1;
    res = base;
    while(i < exp)
    {
        res = res * base;
        i += 1;
    }
    return(res);
}

static double ft_float_pow(double base, int exp)
{
    return(1); //to do
}

static double ft_reverse_pow(double base, double exp)
{
    return(1); //to do
}

double ft_pow(double base, double exp)
{
    if(ft_truncf(base) < base)
    {
        if(ft_truncf(exp) < exp)
            return(ft_reverse_pow(base, exp));
        return(ft_float_pow(base, exp));
    }
    if(ft_truncf(exp) < exp)
        return(ft_reverse_pow(base, exp));
    return(ft_basic_pow(base, exp));
}

/*int main()
{
    double base = 1 / 2;
    double exp  = 2;
    printf("%f", ft_pow(base, exp));
}*/