/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoo <jaewoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:44:19 by jaewoo            #+#    #+#             */
/*   Updated: 2022/06/20 11:15:10 by jaewoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	error(void)
{
	perror("ERROR!!");
	exit(EXIT_FAILURE);
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*path;
	char	*partition_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		partition_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(partition_path, cmd);
		free(partition_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = 0;
	while (paths[i++])
		free(paths[i]);
	free(paths);
	return (0);
}

void	execute(char *argv, char **envp)
{
	int		i;
	char	*path;
	char	**cmd;

	i = 0;
	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (!path)
	{
		while (cmd[i++])
			free(cmd[i]);
		free(cmd);
		error();
	}
	if (execve(path, cmd, envp) == -1)
		error();
}

int	get_next_line(char **line)
{
	int		i;
	int		r;
	char	c;
	char	*buffer;

	i = 0;
	r = 0;
	buffer = (char *)malloc(9999);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && (c != '\n') && (c != '\0'))
	{
		if ((c != '\n') && (c != '\0'))
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (r);
}
