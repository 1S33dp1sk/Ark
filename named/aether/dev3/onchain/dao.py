

def w3_blocksPerBlock( self , chainId ):

	return execViewCall( self.w3_contract( chainId , AETHER_HUB ) , 'BLOCKS_PB' )

