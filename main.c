#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (ft_strlen(s2) == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i])
		i++;

	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	create_repository_py()
{
	system("touch main.py > /dev/null 2>&1");
	system("mkdir conexao > /dev/null 2>&1");
	system("mkdir dados > /dev/null 2>&1");
	system("mkdir models > /dev/null 2>&1");
	system("touch conexao/conexao.py > /dev/null 2>&1");
	system("touch dados/dados.py > /dev/null 2>&1");
	system("touch models/models.py > /dev/null 2>&1");
	system("python3 -m venv venv > /dev/null 2>&1");
	system("venv/bin/pip3 install SQLAlchemy==2.0.20 python-dotenv==1.0.0");
}

void	install_lib_py(char *str)
{
	if (ft_strcmp("bot-web",str) == 0)
		system("venv/bin/pip3 install selenium==4.8.2");
	if (ft_strcmp("bot-web-data",str) == 0)
	{
		system("venv/bin/pip3 install selenium==4.8.2");
		system("venv/bin/pip3 install pandas==2.1.4");
	}
	else if (ft_strcmp("api",str) == 0)
		system("venv/bin/pip3 install fastapi==0.108.0");
	system("venv/bin/pip3 freeze > requirements.txt");
}

int	write_file_py()
{
	FILE *file = fopen("conexao/conexao.py", "w");
	FILE *file1 = fopen("dados/dados.py","w");
	FILE *file2 = fopen("models/models.py","w");
	FILE *file3 = fopen("main.py", "w");

	if (!file || !file1 || !file2 || !file3)
	{
		free(file);
		file = NULL;
		free(file1);
		file1 = NULL;
		free(file2);
		file2 = NULL;
		free(file3);
		file3 = NULL;
		return 0;
	}
	fprintf(file, "import os\nimport sqlalchemy as sa\n\n\n");
	fprintf(file, "def conexao()\n");
	fprintf(file, "\tserver = os.getenv(\"ADDR_SERVER_\")\n");
	fprintf(file, "\tdatabase = os.getenv(\"DB_\")\n");
	fprintf(file, "\tusername = os.getenv(\"SERVER_USER_\")\n");
	fprintf(file, "\tpassword = os.getenv(\"SERVER_PSSW_\")\n");
	fprintf(file, "\tport     = os.getenv(\"PORT_SERVER_\")\n");
	fprintf(file, "\tdriver_sql = os.getenv(\"DRIVER_PYTHON\")\n\n");
	fprintf(file, "\tengine = sa.create_engine(f'postgresql+psycopg2://{username}:{password}@{server}:{port}/{database}')\n");
	fprintf(file, "\tengine = sa.create_engine(f'mssql+pyodbc://{username}:{password}@{server}:{port}/{database}?driver={driver_sql}&Encrypt=no', connect_args={'connect_timeout': 15})\n");
	fprintf(file, "\treturn engine");
	fclose(file);

	fprintf(file3,"from conexao.conexao import *\nfrom dotenv import load_dotenv\nload_dotenv()\n");
	fclose(file3);
	fprintf(file1,"from conexao.conexao import *\n");
	fclose(file1);
	fprintf(file2,"from conexao.conexao import *\n");
	fclose(file2);

	return 1;
}

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
			write_file_py();
			printf("repositorio criado com sucesso!\n");
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
		verify_lang(argv);
}
