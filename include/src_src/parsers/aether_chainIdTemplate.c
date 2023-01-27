#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _chainIdTemplate_tag
{
	char *chain_id;
	char *chain_name;
	char *chain_symbol;
	char *rpc;
}_chainIdTemplate_t;

_chainIdTemplate_t _chainIdTemplate(char *_name, char *_chainId, char *_symbol, char *_wssUrl);

int main(int argc, char *argv[])
{
	_chainIdTemplate_t chain = {0};

	if (!argc > 1){return 0;}

	if (argc == 5)
	{
		chain = _chainIdTemplate(argv[1], argv[2], argv[3], argv[4]);
	}

	else if (argc == 9)
	{
		char *id, *name, *symbol, *wssl;
		for (int i = 1; i <= 8; i+=2)
		{
			if( strcmp(argv[i],"-name") == 0)
			{	
				name = argv[i+1];
			}	
			else if (strcmp(argv[i],"-chainId") == 0)
			{
				id = argv[i+1];
			}
			else if (strcmp(argv[i],"-symbol") == 0)
			{
				symbol = argv[i+1];
			}
			else if (strcmp(argv[i],"-wssUrl") == 0)
			{
				wssl = argv[i+1];
			}
		}
		chain = _chainIdTemplate(name, id, symbol, wssl);
	}

	printf("{'%s' : {'chain_name': '%s', 'chain_symbol': '%s', 'rpc': '%s'}}", chain.chain_id, chain.chain_name, chain.chain_symbol, chain.rpc);

	return 0;
}

_chainIdTemplate_t _chainIdTemplate(char *_name, char * _chainId, char *_symbol, char *_wssUrl)
{
	_chainIdTemplate_t chain = {0};
	char _wss[4];	
	strcpy( _wss , "wss" );
	
	if (! strncmp( _wssUrl , _wss , 3 ) == 0 )
	{	
		printf("ConfigurationError:: Errorno 9 : The supplied url for chainId <%s> is not a wss endpoint.", _chainId);
		exit(-1);
	}

	chain.chain_id = _chainId;
	chain.chain_name = _name;
	chain.chain_symbol = _symbol;
	chain.rpc = _wssUrl;
	return chain;
}
