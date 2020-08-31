/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/03 19:40:02 by mjiam         #+#    #+#                 */
/*   Updated: 2020/07/10 22:13:49 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int	atoi_test(const char *str, int str_base, int answer)
{
	int	n = 0;

	n = ft_atoi_base(str, str_base);
	printf("String: %s, base %d\nReturn: %d, should be: %d\n",
			str, str_base, n, answer);
	if (n == answer)
		printf("" TURQ "(OK)" RES "\n");
	else
		printf("" RED "(KO)" RES "\n");
	return (0);
}

int	bonus(char *av)
{
	if (!strcmp(av, "atoi"))
	{
		printf("" WHITE "ft_atoi_base test" RES "\n");
		printf("===================\n");
		atoi_test("21E", 16, 542);
		atoi_test("-042", 10, -42);
		atoi_test("0-42", 10, 0);
		atoi_test("024", 4, 2);
		atoi_test("024", 2, 0);
		atoi_test("0", 10, 0);
		atoi_test("-0", 10, 0);
		atoi_test("--42", 10, 0);
		atoi_test("    42", 10, 42);
		atoi_test("   +42", 10, 42);
		atoi_test("-+-42", 10, 0);
		atoi_test("  \t\n42", 10, 42);
		atoi_test("42DONE  !", 10, 42);
		atoi_test("foo", 10, 0);
		atoi_test("15690b80B", 2, 1);
		atoi_test("15690b80B", 13, 1161801327);
		atoi_test("7FFFFFFE", 16, 2147483646);
		atoi_test("7ffffffe", 16, 2147483646);
		printf("===================\n");
	}
	return (0);
}
