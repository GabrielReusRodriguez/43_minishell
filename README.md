# 43_minishell
Minishell de Badalona 43

- Para crear el nombre de fichero tmp aleatorio y unico, se puede usar la función C (man 3 mktemp )
   char *mktemp(char *template);


TODO: cuando hacemos ecit 1; exit 5 , ejecuta 1 pero el waitpid usa la listra de cmds de job asi que espera tb un wait para cada uno.