#include "libft/includes/libft.h"
#include "includes/ft_printf.h"
#include <locale.h>

int main(void)
{
  setlocale(LC_ALL, "en_US.UTF-8");
  

  printf("%d\n", ft_printf("|%S|", L"ݗݜशব"));
  printf("%d\n", printf("|%S|", L"ݗݜशব"));
  return (0);
}
