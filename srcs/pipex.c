/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoo <jaewoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:55:25 by jaewoo            #+#    #+#             */
/*   Updated: 2022/06/20 10:43:45 by jaewoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process(char **argv, char **envp, int *fd)
{
	int	data;

	data = open(argv[1], O_RDONLY, 0777);
	if (data == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(data, STDIN_FILENO);
	close(fd[0]);
	execute(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int	data;

	data = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (data == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(data, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid1;
	int		fd[2];

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid1 = fork();
		if (pid1 == -1)
			error();
		if (pid1 == 0)
			child_process(argv, envp, fd);
		waitepid(pid1, NULL, 0);
		parent_process(argv, envp, fd);
	}
	else
	{
		ft_putstr_fd("arguments error\n", 2);
		ft_putstr_fd("ex) ./pipex file1 cmd1 cmd2 file2\n", 1);
	}
	return (0);
}
