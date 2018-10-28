#include "libft/includes/libft.h"
#include "includes/ft_printf.h"

int main(void)
{
	//printf("%s\n", currentName);
//	char c;
	wchar_t	s[4];
	s[0] = 'S';
	s[1] = 256;
	s[2] = 'u';
	s[3] = '\0';
	setlocale(LC_CTYPE, "");
//	printf(" |1 :%d\n", ft_printf("%C", 0x53));
//	printf(" |1 :%d\n", printf("%C", 0x53));
	printf(" |1 :%d\n", ft_printf("%hhS, %hhS", 0, L"米米"));
	printf(" |1 :%d\n", printf("%hhS, %hhS", 0, L"米米"));
//	printf(" |2 :%d\n", ft_printf("%C", 0xd800));
//	printf(" |2 :%d\n", printf("%C", 0xd800));

//	printf(" |3 :%d\n", ft_printf("%C", 0x81000));
//	printf(" |3 :%d\n", printf("%C", 0x81000));

//	printf(" |4 :%d\n", ft_printf("%C", '\0'));
//	printf(" |4 :%d\n", printf("%C", '\0'));

//	printf(" |1 :%d\n", ft_printf("%C", 0x6f));
//	printf(" |1 :%d\n", printf("%C", 0x6f));
//	printf(" |2 :%d\n", ft_printf("%lc", 0x4e6));
//	printf(" |2 :%d\n", printf("%lc", 0x4e6));
//	printf(" |3 :%d\n", ft_printf("%lc", 0x1e40));
//	printf(" |3 :%d\n", printf("%lc", 0x1e40));
//	printf(" |4 :%d\n", ft_printf("%lc", 0x40501));
//	printf(" |4 :%d\n", printf("%lc", 0x40501));
//	printf(" |5 :%d\n", ft_printf("%C", 0x11ffff));
//	printf(" |5 :%d\n", printf("%C", 0x11ffff));
//	printf(" |6 :%d\n", ft_printf("%C", 0));
//	printf(" |6 :%d\n", printf("%C", 0));
//	printf(" |7 :%d\n", ft_printf("%C", (wint_t)-2));
//	printf(" |7 :%d\n", printf("%C", (wint_t)-2));
//	printf(" |8 :%d\n", ft_printf("%C", 0xd800));
//	printf(" |8 :%d\n", printf("%C", 0xd800));
//	printf(" |9 :%d\n", ft_printf("%C", 0xdb02));
//	printf(" |9 :%d\n", printf("%C", 0xdb02));
//	printf(" |10:%d\n", ft_printf("%C", 0xdfff));
//	printf(" |10:%d\n", printf("%C", 0xdfff));
//	printf(" |11:%d\n", ft_printf("%C", 0xbffe));
//	printf(" |11:%d\n", printf("%C", 0xbffe));
//	printf(" |12:%d\n", ft_printf("%lc", 254));
//	printf(" |12:%d\n", printf("%lc", 254));
//	printf(" |13:%d, %X\n", ft_printf("%lc", 255), 255);
//	printf(" |13:%d\n", printf("%lc", 255));
//	printf(" |13:%d\n", ft_printf("%C", 83));
//	printf(" |13:%d\n", printf("%C", 83));
//	printf(" |14:%d\n", ft_printf("%C", 500));
//	printf(" |14:%d\n", printf("%C", 500));
//	printf(" |15:%d\n", ft_printf("%C", 263425));
//	printf(" |15:%d\n", printf("%C", 263425));
//	printf(" |15:%d\n", ft_printf("%C", L'ÏM-^ZM-^T'));
//	printf(" |15:%d\n", ft_printf("%C", L'ÏM-^ZM-^T'));
//	printf(" |16:%d\n", ft_printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플'));
//	printf(" |16:%d\n", printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플'));
//	printf(" |14:%d\n", ft_printf("%C", 256));
//	printf(" |14:%d\n", printf("%C", 256));
//	printf(" |15:%d\n", ft_printf("%C", 0xe000));
//	printf(" |15:%d\n", printf("%C", 0xe000));
//	printf(" |16:%d\n", ft_printf("%5lc", 350));
//	printf(" |16:%d\n", printf("%5lc", 350));
//	printf(" |17:%d\n", ft_printf("%-8C", 1350));
//	printf(" |17:%d\n", printf("%-8C", 1350));
//	printf(" |18:%d\n", ft_printf("%-1C", 2250));
//	printf(" |18:%d\n", printf("%-1C", 2250));
//	printf(" |19:%d\n", ft_printf("%8C et coco %C titi %lc", 3250, 0x11ffff, 'a'));
//	printf(" |19:%d\n", printf("%8C et coco %C titi %lc", 3250, 0x11ffff, 'a'));
//	printf(" |20:%d\n", ft_printf("%---8C et coco %1C titi", 3250, 0xffff));
//	printf(" |20:%d\n", printf("%---8C et coco %1C titi", 3250, 0xffff));
//	printf(" |21:%d\n", ft_printf("%6C et coco %C titi %C tyty", 3250, 0xd800, 'u'));
//	printf(" |21:%d\n", printf("%6C et coco %C titi %C tyty", 3250, 0xd800, 'u'));
//	printf(" |22:%d\n", ft_printf("yo%2C%-12lc et %C titi %C tyty", 'u', 254, 256, 'a'));
//	printf(" |22:%d\n", printf("yo%2C%-12lc et %C titi %C tyty", 'u', 254, 256, 'a'));

//	printf(" |23:%d\n", ft_printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256));
//	printf(" |23:%d\n", ft_printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256));

	return (0);
}