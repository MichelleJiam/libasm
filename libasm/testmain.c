/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmain.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 14:21:08 by mjiam         #+#    #+#                 */
/*   Updated: 2020/11/04 16:54:12 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int	dup_test(char *str)
{
	char	*dst;
	char	*dst2;
	int 	err1, err2;
	size_t	add1, add2;

	dst = ft_strdup(str);
	err1 = errno;
	if (*str == '\0' || *str == '\n')
		printf("String: %s\nft_strdup: %s\n", (*str == '\n' ? "\\n" : "\\0"), dst);
	else
		printf("String: %s\nft_strdup: %s\n", str, dst);
	dst2 = strdup(str);
	err2 = errno;
	printf("Errno set to %d: %s\n", err1, strerror(err1));
	printf("Errno should be %d: %s\n", err2, strerror(err2));
	add1 = (size_t)str;
	add2 = (size_t)dst;
	printf("Address of src: 0x%zx\nAddress of dst: 0x%zx\n", add1, add2);
	if (!strcmp(dst, dst2) && add1 != add2)
		printf("" TURQ "(OK)" RES "\n");
	else
		printf("" RED "(KO)" RES "\n");
	free(dst);
	free(dst2);
	return (0);
}

int	read_test(int file, char *str, int len)
{
	int 	fd[2];
	int		ret1, ret2;
	int 	err1, err2;
	char	buf[10];

	bzero(buf, sizeof(buf));
	if (file != 42) 
	{
		for (int i = 0; i < 2; i++)
		{
			if ((fd[i] = open("read.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU)) < 0)
				return (-1);
			write(fd[i], str, len);
			close(fd[i]);
			if ((fd[i] = open("read.txt", O_RDONLY)) < 0)
				return (-1);
		}
	}
	if (file == 42)
		fd[0] = 42, fd[1] = 42;
	ret1 = ft_read(fd[0], buf, sizeof(buf));
	err1 = errno;
	printf("String read: %s || size given: %lu\n", buf, sizeof(buf));
	ret2 = read(fd[1], buf, sizeof(buf));
	err2 = errno;
	printf("String given: %s || bytes read: %d - %d\n",
			(*str == '\0' ? "(null)" : str), ret1, ret2);
	printf("Errno set to %d: %s\n", err1, strerror(err1));
	printf("Errno should be %d: %s\n", err2, strerror(err2));
	if (ret1 == ret2 && err1 == err2)
		printf("" TURQ "(OK)" RES "\n");
	else
		printf("" RED "(KO)" RES "\n");
	return (0);
}

int	wrt_test(int fd, char *str, int len)
{
	int	ret1;
	int	ret2;
	int err1;
	int err2;

	ret1 = ft_write(fd, str, len);
	ft_write(fd, "\n", 1);
	err1 = errno;
	ret2 = write(fd, str, len);
	err2 = errno;
	write(fd, "\n", 1);
	printf("String given: %s with len (%d)|| bytes written: %d - %d\n",
			(*str == '\0' ? "(null)" : str), len, ret1, ret2);
	printf("Errno set to %d: %s\n", err1, strerror(err1));
	printf("Errno should be %d: %s\n", err2, strerror(err2));
	if (ret1 == ret2 && err1 == err2)
		printf("" TURQ "(OK)" RES "\n");
	else
		printf("" RED "(KO)" RES "\n");
	return (0);
}

int	cmp_test(char *s1, char *s2)
{
	int	ret1;
	int	ret2;

	ret1 = ft_strcmp(s1, s2);
	ret2 = strcmp(s1, s2);
	printf("S1: [%s] vs S2: [%s] || ret: %d - %d\n",
		(*s1 == '\0' ? "(null)" : s1), (*s2 == '\0' ? "(null)" : s2), ret1, ret2);
	if (ret1 == ret2)
		printf("" TURQ "(OK)" RES "\n");
	else
		printf("" RED "(KO)" RES "\n");
	return (0);
}

int	cpy_test(char *src)
{
	char	dst[PATH_MAX];
	char	dst2[PATH_MAX];

	bzero(dst, 100);
	bzero(dst2, 100);
	if (*src == '\0' || *src == '\n')
		printf("String: %s\nft_strcpy: %s\n", (*src == '\n' ? "\\n" : "(null)"),
				ft_strcpy(dst, src));
	else
		printf("String: %s\nft_strcpy: %s\n", src, ft_strcpy(dst, src));
	strcpy(dst2, src);
	if (!strcmp(dst, dst2))
		printf("" TURQ "(OK)" RES "\n");
	else
		printf("" RED "(KO)" RES "\n");
	return (0);
}

int	len_test(char *str)
{
	int	ret1;
	int	ret2;

	ret1 = ft_strlen(str);
	ret2 = strlen(str);
	printf("String: %s || len: %d - %d\n",
		(*str == '\0' ? "(null)" : str), ret1, ret2);
	if (ret1 == ret2)
		printf("" TURQ "(OK)" RES "\n");
	else
		printf("" RED "(KO)" RES "\n");
	return (0);
}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		printf("Please provide test name\n");
		return (-1);
	}
	if (!strcmp(av[1], "strlen"))
	{
		printf("===================\n");
		printf("" WHITE "ft_strlen test" RES "\n");
		printf("===================\n");
		len_test("Hello, world!");
		len_test("");
		len_test("Hello \0 world");
		len_test("0123456789abcdefABCDEF0123456789abcdefABCDEF0123456789abcdefABCDEF0123456789abcdefABCDEF0123456789abcdefABCDEF0123456789abcdefABCDEF");
		printf("===================\n");
	}
	if (!strcmp(av[1], "strcpy"))
	{
		printf("" WHITE "ft_strcpy test" RES "\n");
		printf("===================\n");
		cpy_test("Hello, world!");
		cpy_test("");
		cpy_test("\n");
		cpy_test("Hello \0 world");
		cpy_test("0123456789abcdefABCDEF0123456789abcdefABCDEF0123456789abcdefABCDEF0123456789abcdefABCDEF0123456789abcdefABCDEF0123456789abcdefABCDEF");
		printf("===================\n");
	}
	if (!strcmp(av[1], "strcmp"))
	{
		printf("" WHITE "ft_strcmp test" RES "\n");
		printf("===================\n");
		cmp_test("Hello, world!", "Hello, world!");
		cmp_test("", "");
		cmp_test("Hello", "");
		cmp_test("", "Hello");
		cmp_test("abcdef", "ABCDEF");
		cmp_test("Hello", "Hell");
		printf("===================\n");
	}
	if (!strcmp(av[1], "write"))
	{
		printf("" WHITE "ft_write test" RES "\n");
		printf("===================\n");
		wrt_test(1, "Hello, world!", 14);
		wrt_test(1, "", 0);
		wrt_test(1, "Hello", -6);
		errno = 0;
		wrt_test(1, "Hello", 8);
		wrt_test(1, "Hello", 2);
		int fd = open("text", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
		if (fd < 0)
			return (-1);
		wrt_test(fd, "", 0);
		wrt_test(fd, "Hello", -6);
		errno = 0;
		wrt_test(fd, "Hello", 8);
		wrt_test(fd, "Hello", 2);
		wrt_test(42, "Bad FD: Hello", 6);
		printf("===================\n");
	}
	if (!strcmp(av[1], "read"))
	{
		printf("" WHITE "ft_read test" RES "\n");
		printf("===================\n");
		read_test(1, "Hello, world!", 14);
		read_test(1, "", 0);
		read_test(1, "He(newline)\nllo", 7);
		read_test(42, "Bad FD: Hello", 14);
		printf("===================\n");
	}
	if (!strcmp(av[1], "strdup"))
	{
		printf("" WHITE "ft_strdup test" RES "\n");
		printf("===================\n");
		dup_test("Hello, world!");
		dup_test("");
		dup_test("\0");
		dup_test("\n");
		dup_test("Hello \0 world");
		dup_test("0123456789abcdefABCDEF0123456789abcdefABCDEF0123456789abcdefABCDEF0123456789abcdefABCDEF0123456789abcdefABCDEF0123456789abcdefABCDEF");
		printf("===================\n");
	}
	if (!strcmp(av[1], "atoi"))
		bonus(av[1]);
	return (0);
}
