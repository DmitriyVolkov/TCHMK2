// BigInt.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 
#include <malloc.h> 
#include "BigClass.h"

#pragma warning(disable : 4996)

int main(int argc, const char * argv[])
{
	BigIntClass a;
	BigIntClass b;
	BigIntClass Res;
	if (argc < 5 || argc>7)
	{
		printf("Incorrect arguments!\n");
		printf("[1file] [operation] [2file] [3file] [-b| 4 file] [4file]\n");
		printf("4 file is needed for the degree!\n");
		return 0;
	}
		
	if (argc>5 && (!strcmp(argv[5], "-b")))
	{
		a.ReadBinFile(argv[1]);
		b.ReadBinFile(argv[3]);
	}
	else
	{
		a.ReadTextFile(argv[1]);
		b.ReadTextFile(argv[3]);
	}

	if (argv[2][0] == '+')
		Res = a + b;
	if (argv[2][0] == '-')
		Res = a - b;
	if (argv[2][0] == '*')
		Res = a * b;
	if (argv[2][0] == '/')
		Res = a / b;
	if (argv[2][0] == '%')
		Res = a % b;
	if (argv[2][0] == '^')
	{
		BigIntClass c;
		if (!strcmp(argv[5], "-b"))
			c.ReadBinFile(argv[6]);
		else
			c.ReadTextFile(argv[5]);

		Res = degree(a, b, c);
		c.Clear();
	}

	if (argc>5 && (!strcmp(argv[5], "-b")))
		Res.WriteBinFile(argv[4]);
	else
		Res.WriteTextFile(argv[4]);

	a.Clear();
	b.Clear();
	Res.Clear();

	return 0;
}
