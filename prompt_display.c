nclude "main.h"
/**
 *  * prompt_display - main
 *   * Return: always 0
 *    */

int prompt_display(void)
{
		ssize_t r = 0;
			char *line = NULL;
				size_t len = 0;
					char *comment;
						/*char *status_str;
						 * 	int status;*/
						char *prompt = "($) ";

							if (isatty(0))
								    {
									        printf("%s", prompt);
										    }
								r = getline(&line, &len, stdin);
									if (spaces_only(line) == 1)
											{
														free(line);
																exit(0);
																	}
										if (r == -1)
												{
														/*printf("\n");*/
														exit(0);
															}
											comment = _strchr(line, '#');
											    if (comment != NULL)
												        {
														    *comment = '\0';
														        }
											        if (strcmp(line, "exit\n") == 0)
													    {
														    		free(line);
																        exit(0);
																	    }
													/*else if (strncmp(line, "exit", 5) == 0)
													 *     {
													 *             status_str = line + 5;
													 *                     status = atoi(status_str);
													 *                             printf("Exiting with status: %d\n", status);
													 *                                     free(line);
													 *                                             exit(0);
													 *                                                 }*/
													split_command(r, &line);
														free(line);
															return (0);
}