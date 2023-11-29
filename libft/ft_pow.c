#include"libft.h"
#include<stdio.h>



static long long ft_basic_pow(int base, int exp)
{
    int i;
    long long res;
    if(exp == 0)
        return(1);
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
    long a;
    long b;
    double long res;
    if(exp == 0)
        return(1);
    a = base * ft_basic_pow(10, 6);
    b = 1000000;
    res = ft_basic_pow(a, fabs(exp)) / ft_basic_pow(b, fabs(exp));
    if(exp < 0)
        return(1 / res);
    return(res);
}

static double ft_reverse_pow(double base, double exp)
{
    double rad;
    long num;
    long dem;
    
    num = exp * ft_basic_pow(10, 6);
    dem = 1000000;

    if(exp == 0)
        return(1);
    rad = ft_float_pow(base, ) //to do
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

int main()
{
    double base = 8;
    double exp  = 0;
    printf("%f", ft_pow(base, exp));
}