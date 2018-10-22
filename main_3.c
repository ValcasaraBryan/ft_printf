#include "libft/includes/libft.h"
#include "includes/ft_printf.h"
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "en_US.UTF-8");

	//printf(" - %d\n", ft_printf("%C", 0x11ffff));
	//printf(" - %d\n", printf("%C", 0x11ffff));
	printf(" - %d\n", ft_printf("%d, %#x, %S , %010C", 0xdb02, 0xdb02, L"👉 👅", (wint_t)-2));
	printf(" - %d\n", printf("%d, %#x, %S , %010C", 0xdb02, 0xdb02, L"👉 👅", (wint_t)-2));
	//printf(" - %d\n", ft_printf("%C", 0x11ffff));
  	//printf(" - %d\n", printf("%C", 0x11ffff));
  
	return (0);
}
