from dataclasses import dataclass,field


LISTENER_TYPES = [ 'events' , 'blocknum' , 'blocknum_range' , 'blocknum_increment' ]

TRIGGERS = {
	'event' : 'on_event_emitted'
}


@dataclass
class Trigger:
	retro : None
	event_name : str 
	contract_name : str
	mirror_call : str
	back_chains : list[str]
	at : list[str]
	listener_type : str = TRIGGERS['event']
