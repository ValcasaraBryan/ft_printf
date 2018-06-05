#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int ret;

	ret = 0;
	while (format[ret] == '%' || format[ret])
		write(1, format + ret++, 1);

//	if (format[ret] == '%' && format[ret + 1] == 's')
//		write(1, ,1);

	return (ret);
}
