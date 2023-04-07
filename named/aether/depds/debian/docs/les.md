# LES


### Listen 

**L**isteners are activated by configuring triggers which come in 4 different flavors:

1.	Events    

2.	Blocks    

	+ Blocknumber    
	+ Block ranges    
	+ Block increments     


### Evaluate     

The functions attached to the triggers will be called(back) everytime the listeners are triggered, where the instance of all the passed contracts and the functions included is already initiated and there is no need to reinitiate the contract or the events to interact with the blockchain, as the functions are already embeded within the class instance of __LES__.     


### Send

To complete the feedback loop, we can utilize the functions passed to edit the state of which we are listing to, `non-payable` functions. 




## Example On __LES__


```python
@event.mors( 'Multiplier' )
def switch_multipler():
	# Do whatever 
```
