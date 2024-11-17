#include "../../inc/minishell.h"

static char	*strip_quotes(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	new_str = malloc(ft_strlen(str) + 1);
	if (!new_str)
		return (NULL);
	j = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] != '"' && str[i] != '\'')
			new_str[j++] = str[i];
	}
	new_str[j] = '\0';
	return (new_str);
}

char	exit_error(char *arg, const char *msg)
{
	g_quest_mark = 255;
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd((char *) msg, 2);
	return (EXIT_FAILURE);
}

void	exit_d(char **args)
{
	char	*stripped;

	ft_putstr_fd("exit\n", 1);
	if (args[1])
	{
		stripped = strip_quotes(args[1]);
		if (!stripped)
		{
			exit_error(args[1], "memory allocation error\n");
			exit(g_quest_mark);
		}
		handle_exit_argument(args, stripped);
	}
	else
		g_quest_mark = 0;
	exit(g_quest_mark);
}
