/*
** EPITECH PROJECT, 2020
** test.c
** File description:
** TU
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../includes/bsprintf.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, string_with_flagstring, .init = redirect_all_std)
{
    my_printf("hello %s", "Ramirez");
    cr_assert_stdout_eq_str("hello Ramirez");
}

Test(my_printf, string_with_2flags, .init = redirect_all_std)
{
    my_printf("%s, né en %i", "Ramirez", 2002);
    cr_assert_stdout_eq_str("Ramirez, né en 2002");
}

Test(my_printf, string_with_manyflags, .init = redirect_all_std)
{
    my_printf("%s, né en %i, dans le district %c, %i à son actif", "Ramirez", 2002, 'B', -42);
    cr_assert_stdout_eq_str("Ramirez, né en 2002, dans le district B, -42 à son actif");
}

Test(my_printf, string_with_manyflags_and_doublepourcentage, .init = redirect_all_std)
{
    my_printf("%s, né en %i, dans le district %c, %%c", "Ramirez", 2002, 'B');
    cr_assert_stdout_eq_str("Ramirez, né en 2002, dans le district B, %c");
}

Test(my_printf, space, .init = redirect_all_std)
{
    my_printf(" ");
    cr_assert_stdout_eq_str(" ");
}

Test(my_printf, longstring_with_manyflags, .init = redirect_all_std)
{
    my_printf("my_printf : %s, né en %d, dans le district %c, dans le %o ème arrondissement, chance de contamination : %%27\n", "Ramirez", 2002, 'B', -18);
    cr_assert_stdout_eq_str("my_printf : Ramirez, né en 2002, dans le district B, dans le 22 ème arrondissement, chance de contamination : %27\n");
}

