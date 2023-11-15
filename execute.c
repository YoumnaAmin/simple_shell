#include "main.h"

/**
 * execute - main execute stream
 * @argv: command to executed
*/
void execute(char **argv)
{
	char *cmd, *path_comd;
	pid_t child_pid;
	int status;
	/*extern char **environ;*/

	cmd = argv[0];
	path_comd = get_path(cmd);
	if (strcmp(cmd, "env") == 0)
	{
		print_env();
		return; }
	if (strcmp(cmd, "cd") == 0)
	{
		_cd(argv);
		return; }
	if (path_comd == NULL)
	{
	fprintf(stderr, "./hsh: 1: %s: not found\n", cmd);
	exit(127); }
	child_pid = fork();
	if (child_pid == -1)
	{
	perror("fork");
	exit(EXIT_FAILURE); }
	else if (child_pid == 0)
	{
	if (execve(path_comd, argv, environ) == -1)
	{
	fprintf(stderr, "./hsh: 1: %s: Permission denied\n", cmd);
	exit(126); } }
	else
	{
	wait(&status);
	if (WIFEXITED(status))
	{
	int exit_status = WEXITSTATUS(status);

	if (exit_status != 0)
	{
	exit(2); } }
	else if (WIFSIGNALED(status))
	{
	fprintf(stderr, "%s: terminated by signal %d", cmd, WTERMSIG(status));
	exit(EXIT_FAILURE); } }
	}
