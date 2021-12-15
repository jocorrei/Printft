#include "ft_printf.h"
#include "libft/libft.h"

int ft_printf(const char *str, ...)
{
    int len = 0;
    int i = 0;
    va_list args;
    int (*f[256]) (va_list args);

    va_start(args, str);
    init_array(f);
    while (str[i] != '\0')
    {
        if (str[i] == '%')
        {
            if (str[i + 1] == '%')
                len += printsign();
            else
                len += (*f[str[i + 1]]) (args);
            i++;
        }
        else
            len += ft_printchar(str[i]);
        i++;
    }
    va_end(args);
    return(len);
}

int main()
{
    int len;
    void *c = "hello";

    len = ft_printf(" %X", 200);
    printf("%d", len);
    return(0);
}