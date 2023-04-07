from dev3 import MORS


mors = MORS( __name__ , config='/home/kj/dev3/conf/output/config.json' )


@mors.event( 'ContractDeployed' )
def my_event( event_data ):
	print( 'Contract deployed @ : %s'%event_data.get( 'Contract' ) )
	print( 'With a PseudoProxy @ : %s'%event_data.get( 'Proxy' ) )
	print( 'Ticket ID used for deployement : %s'%event_data.get( 'DeploymentID' ) )


mors.run()