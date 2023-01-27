#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _getChain_tag
{
	char *name;
	char *symbol;
	char *chainid;	
}_getChain_t;

_getChain_t _getChain(char *keyword);

int main(int argc, char *argv[])
{
	if (argc == 1){return 0;}

	_getChain_t chain = {0};
	chain = _getChain(argv[1]);

	printf("(%s, %s, %s)\n", chain.name, chain.chainid, chain.symbol);
	return 0;
}

_getChain_t _getChain(char *keyword)
{
	int index = -1;
	int len = strlen(keyword);
	int number = atoi(keyword);
	_getChain_t chain = {"None", "None", "None"};
	
	char *_name[5] = 
	{
		"'ETHEREUM'", "'BINANCE'", "'POLYGON'", "'FANTOM'", "'AVALANCHE'" 
	};

	char *_symbol[5] = 
	{
		"'ETH'", "'BNB'", "'MATIC'", "'FTM'", "'AVAX'"
	};

	char *_chainId[5] = 
	{
		"1", "56", "137", "250", "43114"
	};

	if ( (number <= 0) & (len < 4))
	{
		printf("ConfigurationError:: Errorno 12 : Invalid ChainId.\n");exit(-1);
	}

	else if ( number > 0  )  // Do 'number'
	{
		for (int i = 0; i < 5; i++)
		{
			if( strcmp(_chainId[i], keyword) == 0)
			{
				index = i;
				break;
			}
		}
		if(index == -1 ){printf("ConfigurationError:: Errorno 12 : Invalid ChainId.\n");exit(-1);}
	}

	else if (len == 4) // Do 'symbol'
	{
		for (int i = 0; i < 5; i++)
		{
			if( (strstr(_symbol[i], keyword) != NULL))
			{
				index = i;
				break;
			}
		}	
	}

	else if (len > 4) // Do 'name'
	{
		for (int i = 0; i < 5; i++)
		{
			if( (strstr(_name[i], keyword) != NULL)  )
			{
				index = i;
				break;
			}
		}		
	}

	if (index == -1){ return chain;}

	chain.name = _name[index];
	chain.symbol = _symbol[index];
	chain.chainid = _chainId[index];

	return chain;
}