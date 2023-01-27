configuration_errors = {
	1:'The supplied url for chainId is not a wss endpoint.',
	2:'Cannot determine the chainId(s) supplied by the `rpc.conf.json` file.',
	3:'A connection to the WSS endpoint cannot be established.',
	4:'Unable to obtain all Aether contracts addresses from the router.',
	5:'Could not obtain a public address from the private key supplied.',
	6:'Enivroment path specified is not a directory.',
	7:'Enivroment path does not contain the required `rpc.conf.json` , `env.conf.json` files.',
	8:'Node configurations are not found.',
	9:'Mirror file not found',
	10:'Unkown chain Id',
	11:'Cannot create a blockchain reflection.',
	12:'Failed to initalize a binary mirror'
}

configuration_warnings = {
	1:'Unable to create EBM.\nDoes the ABI for <%s> compile?',
}


general_errors = {
	'no_file':'No such file.',
	'no_path':'No node path specified.',
	'not_bytes':'Not a bytes type'
}

node_errors = {
	0:'NodeID cannot be empty',
	1:'Not a valid Aether path',
	2:'Unable to find a correct configuration file',
	3:'Version of configuration file does not match the execution version',
	4:'Unable to create a dynamic web3 instance',
	5:'Aether cannot form the variable',
	6:'Aether cannot decode variable to bytes',
	7:'Not a valid node path',
	8:'Not a valid log path',
	9:'Execution file is not in the correct path',
	10:'Filters cannot be created with the supplied parameters',
	11:'Cache & J-Cache cannot be equal while collapsing and rebuilding',
	12:'Immutable status is already set',
	13:'Unable to cache transaction',
	14:'Could not fetch last aethering masterhash',
	15:'Cannot fetch last aethering block',
	16:'Unkown cache object',
	17:'Cannot create transaction',
	18:'Cannot create an aetherblock',
	19:'Unable to encode transaction',
	20:'Unable to encode block',
	21:'Unable to encode status',
	22:'Unable to find KchecK in cache',
}

node_warnings = {
	1:'No dynamic cache and no BLOCK-cache file not found',
	2:'Cannot append logs to file',
	3:'Ambigous transaction',
	4:'Masterhash not constant across blockchains, resolving',
	5:'Waiting for aetherer to submit the current block before resolving'
}

assert_strings = {
	1:'Invalid private key.',
	2:'Invalid public key',
	3:'No configured chains found, edit `template-rpc.conf` to add chain parameters.',
	4:'Unmapped chain to WSS endpoint',
	5:'Could not retrieve one or more web3 parameters.\nIs the url pointing to a WSS endpoint?',
	6:'Failed initiating a connection to the WSS endpoint.\nIs the url pointing to an active WSS endpoint?',
	7:'Cannot find a reflection from the list of functions on client.',
	8:'Unable to find a mirror for %s ABI.\nIs the file in the correct dir and exported correctly? aether/onchain/?',
	9:'Multiple reflections found for the same mirror on %ss\' ABI.\nPlease specify only a single one.'
}

