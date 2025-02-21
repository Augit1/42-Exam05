#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int	error(char *s)
{
	int	i = 0;

	while (s[i])
		i++;
	return (write(2, s, i));
}

int	cd(char *path, int i)
{
	if (i != 2)
	{
		error("error: cd: bad arguments\n");
		return (1);
	}
	if (chdir(path) == -1)
	{
		error("error: cd: cannot change directory to ");
		error(path);
		error("\n");
		return (1);
	}
	return (0);
}

void	set_pipe(int has_pipe, int *fd, int end)
{
	if (has_pipe
		&& ((dup2(fd[end], end) == -1)
		|| (close(fd[0]) == -1)
		|| (close(fd[1]) == -1)))
	{
		error("error: fatal\n");
		exit(1);
	}
}

int	exec(char **argv, int i, char **envp)
{
	int		fd[2];
	int		status = 0;
	int 	has_pipe;
	pid_t	pid;

	has_pipe = argv[i] && !strcmp(argv[i], "|");
	if (!has_pipe && !strcmp(*argv, "cd"))
		return (cd(*argv, i));
	if (has_pipe && (pipe(fd) == -1))
	{
		error("error: fatal\n");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		error("error: fatal\n");
		exit(1);
	}
	if (!pid)
	{
		argv[i] = 0;
		if (!strcmp(*argv, "cd"))
			exit(cd(*argv, i));
		set_pipe(has_pipe, fd, 1);
		execve(*argv, argv, envp);
		error("error: cannot execute ");
		error(*argv);
		error("\n");
		exit(1);
	}
	waitpid(pid, &status, 0);
	set_pipe(has_pipe, fd, 0);
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int	main(int argc, char **argv, char **envp)
{
	int	status = 0;
	int	i = 0;

	if (argc < 2)
		return (0);
	while (argv[i])
	{
		argv += i + 1;
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (i)
			status = exec(argv, i, envp);
	}
	return (status);
}
