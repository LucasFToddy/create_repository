#include "create_repository.h"


int	verify_lang(char **str)
{
	int check_lang;
	if(ft_strcmp("python",str[1]) == 0)
	{
		check_lang = system("python3 --version > /dev/null 2>&1");
		if (check_lang == 0)
		{
			create_repository_py();
			install_lib_py(str[2]);
			write_file_py(str[2]);
			printf("repository created successfully!\n");
		}
	}
	else if (ft_strcmp("go",str[1]) == 0)
	{
		check_lang = system("go version > /dev/null 2>&1");
		if (check_lang == 0)
		{
			printf("pera");
		}
	}
	else if(ft_strcmp("-help", str[1]) == 0)
	{
		printf("python and go are the supported languages\n");
		printf("correct way to use the application:\n");
		printf("create_repo [language] [bot or api]\n");
		printf("For bots, write bot, for api, write api.\n");
		printf("If it is Python and it is for a bot that is an automation for the web, type bot-web, and if you are going to use pandas for the web bot, use bot-web-pandas. If it is for data analysis, use bot-pandas.\n");
		printf("If it is Go or Golang and it is for a bot, just use bot. If it is for an API, use api.\n");
	}
	else
	{
		printf("Unsupported language: %s\n", str[1]);
		printf("use -help to check options\n");
		return 0;
	}

	return 1;
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		// printf("teste gnl\n");
		verify_lang(argv);
	}
	// int	fd;
	// char *teste;

	// fd = open("main_api_py.txt", O_RDONLY);
    // teste = get_next_line(fd);
    // while (teste != NULL)
    // {
    //     printf("%s", teste);
    //     free(teste);
    //     teste = get_next_line(fd);
    // }
	// close(fd);

}
