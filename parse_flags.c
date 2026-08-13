#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

parse_flag(int argc, char **argv)
{
    int i;
    char **tokens;

    if (!argv)
        return (0);
    i = 1;
    while (argv[i])
    {
        tokens = ft_split(argv[i], " ")
        i++;
    }
    
}
