from asyncio import sleep,gather


def active_filters( filter_list ):

	return list( filter( None , [i for i in filter_list] ) )


'''
	effeciency is needed here, when looping execution speeds vary
	thus be able to do any of the functionality after the eventFilters 
	are created and requested once, As websockets usually counts idle time 
	~300s or 5 minutes before the WSS endpoint stops serving, and closes
	idle connections.

	Simply:  
	X seconds = pollInterval + totalFilters/300  
'''
async def event_loop( self ):
	_chain_id = 0 
	for eventFilter in active_filters( self.w3_filters() ):
		if len( eventFilter ) >= 1:
			( filter_name , aether_filter ) = list( eventFilter.items() )[0]
			( 
				chain_id , 
				aether_main , 
				aether_contract , 
				aether_event , 
				filter_main
			) = filter_name.split('_')
			contract_name = '%s_%s'%( aether_main , aether_contract )

			eventEntries = aether_filter.get_new_entries()
			if len( eventEntries ) > 0:
				self.loop_interrupt = 0
				for aether_entry in eventEntries:
					self.handle_entry( chain_id , contract_name , aether_entry )
		await sleep( self.pollInterval )
	self.loop_interrupt += 1



async def main_loop( self ):
	self.loop_interrupt = 1
	self.pollInterval = 2
	while True:
		if self.loop_interrupt == 0:
			self.log_data( data='LOOP : <%s> -> uninteruptted.'%( str( self.loop_interrupt ) ) )
		await event_loop( self )
