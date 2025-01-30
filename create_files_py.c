#include "create_repository.h"

void	create_repository_py()
{
	printf("creating repository\n");
	system("touch main.py > /dev/null 2>&1");
	system("mkdir conexao > /dev/null 2>&1");
	system("mkdir dados > /dev/null 2>&1");
	system("mkdir models > /dev/null 2>&1");
	system("touch conexao/conexao.py > /dev/null 2>&1");
	system("touch dados/dados.py > /dev/null 2>&1");
	system("touch models/models.py > /dev/null 2>&1");
	printf("installing python virtual environment\n");
	system("python3 -m venv venv > /dev/null 2>&1");
	printf("installing libraries\n");
	system("venv/bin/pip3 install SQLAlchemy==2.0.20 python-dotenv==1.0.0 > /dev/null 2>&1");
}

void	install_lib_py(char *str)
{
	if (ft_strcmp("bot-web",str) == 0)
		system("venv/bin/pip3 install selenium==4.8.2 > /dev/null 2>&1");
	if (ft_strcmp("bot-web-data",str) == 0)
	{
		system("venv/bin/pip3 install selenium==4.8.2 > /dev/null 2>&1");
		system("venv/bin/pip3 install pandas==2.1.4 > /dev/null 2>&1");
	}
	else if (ft_strcmp("api",str) == 0)
		system("venv/bin/pip3 install fastapi==0.108.0 uvicorn==0.25.0 > /dev/null 2>&1");
	printf("adding library versions to the requirements.txt file\n");
	system("venv/bin/pip3 freeze > requirements.txt");
}

int		write_lines(FILE *file, char *file_path)
{
	int	fd;
	char *line;

	fd = open(file_path, O_RDONLY);
    line = get_next_line(fd);
    while (line != NULL)
    {
		fprintf(file,"%s", line);
        free(line);
        line = get_next_line(fd);
    }
	close(fd);
}

int		write_file_py(char *str)
{
	FILE *file_conexao;
	FILE *file_dados;
	FILE *file_main;
	FILE *file_models;

	printf("writing in the files\n");
	if (!ft_strcmp("api", str))
	{
		file_main = fopen("main.py", "w");
		if (!file_main)
			return 0;
		write_lines(file_main, "/home/toddy/myProject/create_py/main_api_py.txt");
		fclose(file_main);
	}
	else if (!ft_strcmp("bot-web", str))
	{
		file_main = fopen("main.py", "w");
		if (!file_main)
			return 0;
		write_lines(file_main, "/home/toddy/myProject/create_py/main_web_py.txt");
		fclose(file_main);
	}
	else
	{
		file_main = fopen("main.py", "w");
		fprintf(file_main, "from conexao.conexao import *");
		fclose(file_main);
	}
	file_conexao = fopen("conexao/conexao.py", "w");
	if (!file_conexao)
		return 0;
	write_lines(file_conexao, "/home/toddy/myProject/create_py/conexao_py.txt");
	fclose(file_conexao);

	file_dados = fopen("dados/dados.py","w");
	fprintf(file_dados, "from conexao.conexao import *");
	fclose(file_dados);

	file_models = fopen("models/models.py","w");
	fprintf(file_models, "from conexao.conexao import *");
	fclose(file_models);
	return 1;
}
