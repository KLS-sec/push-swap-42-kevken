#include <stdlib.h>

int	inst_comp(const char *s, char *argv, int ender)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < ender)
	{
		if(s[j] != argv[j])
			return (1);
		i++;
	}
	return (0);
}

int	inst_detector (int argc, char **argv)
{// si detecte qlqch lance tous les detecteurs (avec le +1 pour commencer a chercher les ellements)
	char s[9];
	char m[9];
	char c[10];
	char a[11];
	char b[8];
// trop de char declare, fonction a refaire
	char s = "--simple\0";
	char m = "--medium\0";
	char c = "--complex\0";
	char a = "--adaptive\0";
	char b = "--bench\0";
	if (inst_comp(*s , **argv[1], 9) == 0)
		return(1);
	if (inst_comp(*m , **argv[1], 9) == 0)
		return(2);
	if (inst_comp(*c , **argv[1], 10) == 0)
		return(3);
	if (inst_comp(*a , **argv[1], 11) == 0)
		return(0); //adaptive is already by default
	if (inst_comp(*b , **argv[1], 8) == 0)
		return(4);
	return(0);//return la valeur pour que la lecture commence au bon endroit
}

int inst_launcher (int argc, char **argv) //launch instructions from here or send back code
{
	int i;

	i = inst_detector(argc, argv);
	if (i == 1)
	if (i == 2)
	if (i == 3)
	if (i == 4)

	return();
}