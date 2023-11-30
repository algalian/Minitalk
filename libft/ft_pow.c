#include"libft.h"
#include<stdio.h>



static long long ft_basic_pow(int base, int exp)
{
    int i;
    long long res;
    
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
    t_ratio ratio;
    double long res;

    ratio = ft_ratio(base);
    res = ft_basic_pow(ratio.num, fabs(exp)) / ft_basic_pow(ratio.dem, fabs(exp));
    if(exp < 0)
        return(1 / res);
    return(res);
}

static double ft_reverse_pow(double base, double exp)
{
    double rad;
    double res;
    t_ratio ratio;

    ratio = ft_ratio(exp);
    rad = ft_float_pow(base, ratio.num);
    res = 0;
    while(ft_basic_pow(res, ratio.den) < rad)
        res++;
    while(ft_float_pow(res, ratio.den) < rad)
        res += 0.000001;
    return(res);
}

double ft_pow(double base, double exp)
{
    if(exp == 0)
    {
        if(base == 0)
        {
            ft_printf("0^0 undefined");
            exit(1);
        }
        return(1);
    }
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