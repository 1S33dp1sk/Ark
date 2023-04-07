#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char *getRandomHex(int value);

int main(int argc, char const *argv[])
{
	// validate integer
	int value = atoi(argv[1]);
	char *output = getRandomHex(value);
	printf("%s\n", output);
	return 0;
}

char * getRandomHex(int value)
{
	// Max hex length
	static char temp[100];
	int random  = 0;
	int hex_loop = (value*2) + 1;

	int check_limit = (100 / 2) - 1;
	if (value > check_limit)
	{
		printf("ConfigurationError:: Errorno 87 : Max length for hex strings is 100.\n");
		exit(-1);
	} 

	// To represent hex value
	temp[0] = '0'; temp[1] = 'x';
	if (value == 0)
	{
		return &temp[0];
	}

	// Ceed value for generating randomness based using time
	// May not be completely secure!!!
	srand(time(NULL)); 

	for (int i = 2; i <= hex_loop; i++)
	{
		random = rand() % 16; // 0 - 15 output range
		if (random >= 10)
		{
			temp[i] = random + 87;  // a - f
		}
		else if(random <= 9)
		{
			temp[i] = random + 48; // 0 - 9
		}
	}
	return &temp[0];
}