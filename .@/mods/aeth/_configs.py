
class _0xANodeErr( Exception ):
	def __init__( self , errorNo:int , errorStr:str , *args:tuple ):
		self._message = 'ConfigurationError :: Errorno %s -> %s : %s'%( str( errorNo ) , errorStr , _formatArgs( args ) )
		super().__init__( self._message )

class Colors:
	NC='\033[0m'
	VIOLET='\033[1;94m'
	EVIOLET='\033[1;35m'
	AVIOLET='\033[1;36m'
	GREY='\033[1;37m'
	DARK_GREY='\033[0;37m'
	GREEN='\033[1;32m'
	RED='\033[0;31m'
	YELLOW='\033[1;33m'


class Contracts:
	AETHER_NODE= 	"AETHER_NODE"
	AETHER_PROXY= 	"AETHER_PROXY"
	AETHER_DAO= 	"AETHER_DAO"
	AETHER_TOKEN= 	"AETHER_TOKEN"
	AETHER_BOND= 	"AETHER_BOND"
	AETHER_HUB= 	"AETHER_HUB"
	AETHER_FACTORY= "AETHER_FACTORY"
	AETHER_KEEPER= 	"AETHER_KEEPER"

class DaoVars:
	PROPOSAL_TIME = 'proposalTime'
	SIGNERS_THRESHOLD = 'signersThreshold'
	NODE_THRESHOLD = 'nodeThreshold'
	NODE_STAKING_TIME = 'nodeStakingTime'
	BOND_MATURITY_TIME = 'bondMaturityTime'
	TRANSACTION_THRESHOLD = 'transactionThreshold'
	HOLDER_THRESHOLD = 'holderThreshold'
	REWARDS_TREASURY = 'rewardsTreasury'
	TREASURY_THRESHOLD = 'treasuryThreshold'
	DEPLETION_MULTIPLIER = 'depletionMultiplier'
	DEPLETION_DIVISOR = 'depletionDivisor'
	REWARD_LEDGER = 'rewardLedger'
	GAS_PRICE = 'gasPrice'
	TARGET_GAS = 'targetGas'
	TARGET_TRANSACTIONS = 'targetTransactions'
	MAX_BPB = 'MaxBPB'
	MAX_TPB = 'MaxTPB'