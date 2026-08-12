#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

parse_flag(int argc, char **argv)
{
    int i;

    if (!argv)
        return (0);
    i = 1;
    while (argv[i])
    {
        ft_split(argv[i], " ")
        i++;
    }
}

*str find_gap(char str)