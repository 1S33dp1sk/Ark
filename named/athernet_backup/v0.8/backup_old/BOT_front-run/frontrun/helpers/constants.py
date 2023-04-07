generic_abi = """[{"constant": true,"inputs": [],"name": "name","outputs": [ {"name": "", "type": "string"}],"payable": false,"type": "function"},{"constant": true,"inputs": [],"name": "decimals","outputs": [{"name": "","type": "uint8"}],"payable": false,"type": "function"},{"constant": true,"inputs": [{"name": "_owner","type": "address"}],"name": "balanceOf","outputs": [{"name": "balance","type": "uint256"}],"payable": false,"type": "function" },{"constant": true, "inputs": [],"name": "symbol","outputs": [{"name": "","type": "string"}],"payable": false,"type": "function"}]"""
sell_abi = '[{"inputs":[{"internalType":"string","name":"_NAME","type":"string"},{"internalType":"string","name":"_SYMBOL","type":"string"},{"internalType":"uint256","name":"_DECIMALS","type":"uint256"},{"internalType":"uint256","name":"_supply","type":"uint256"},{"internalType":"uint256","name":"_txFee","type":"uint256"},{"internalType":"uint256","name":"_lpFee","type":"uint256"},{"internalType":"uint256","name":"_MAXAMOUNT","type":"uint256"},{"internalType":"uint256","name":"SELLMAXAMOUNT","type":"uint256"},{"internalType":"address","name":"routerAddress","type":"address"},{"internalType":"address","name":"tokenOwner","type":"address"}],"stateMutability":"nonpayable","type":"constructor"},{"anonymous":false,"inputs":[{"indexed":true,"internalType":"address","name":"owner","type":"address"},{"indexed":true,"internalType":"address","name":"spender","type":"address"},{"indexed":false,"internalType":"uint256","name":"value","type":"uint256"}],"name":"Approval","type":"event"},{"anonymous":false,"inputs":[{"indexed":false,"internalType":"uint256","name":"minTokensBeforeSwap","type":"uint256"}],"name":"MinTokensBeforeSwapUpdated","type":"event"},{"anonymous":false,"inputs":[{"indexed":true,"internalType":"address","name":"previousOwner","type":"address"},{"indexed":true,"internalType":"address","name":"newOwner","type":"address"}],"name":"OwnershipTransferred","type":"event"},{"anonymous":false,"inputs":[{"indexed":false,"internalType":"uint256","name":"tokensSwapped","type":"uint256"},{"indexed":false,"internalType":"uint256","name":"ethReceived","type":"uint256"},{"indexed":false,"internalType":"uint256","name":"tokensIntoLiqudity","type":"uint256"}],"name":"SwapAndLiquify","type":"event"},{"anonymous":false,"inputs":[{"indexed":false,"internalType":"bool","name":"enabled","type":"bool"}],"name":"SwapAndLiquifyEnabledUpdated","type":"event"},{"anonymous":false,"inputs":[{"indexed":true,"internalType":"address","name":"from","type":"address"},{"indexed":true,"internalType":"address","name":"to","type":"address"},{"indexed":false,"internalType":"uint256","name":"value","type":"uint256"}],"name":"Transfer","type":"event"},{"inputs":[],"name":"_liquidityFee","outputs":[{"internalType":"uint256","name":"","type":"uint256"}],"stateMutability":"view","type":"function"},{"inputs":[],"name":"_maxTxAmount","outputs":[{"internalType":"uint256","name":"","type":"uint256"}],"stateMutability":"view","type":"function"},{"inputs":[],"name":"_owner","outputs":[{"internalType":"address","name":"","type":"address"}],"stateMutability":"view","type":"function"},{"inputs":[],"name":"_taxFee","outputs":[{"internalType":"uint256","name":"","type":"uint256"}],"stateMutability":"view","type":"function"},{"inputs":[{"internalType":"address","name":"owner","type":"address"},{"internalType":"address","name":"spender","type":"address"}],"name":"allowance","outputs":[{"internalType":"uint256","name":"","type":"uint256"}],"stateMutability":"view","type":"function"},{"inputs":[{"internalType":"address","name":"spender","type":"address"},{"internalType":"uint256","name":"amount","type":"uint256"}],"name":"approve","outputs":[{"internalType":"bool","name":"","type":"bool"}],"stateMutability":"nonpayable","type":"function"},{"inputs":[{"internalType":"address","name":"account","type":"address"}],"name":"balanceOf","outputs":[{"internalType":"uint256","name":"","type":"uint256"}],"stateMutability":"view","type":"function"},{"inputs":[],"name":"claimTokens","outputs":[],"stateMutability":"nonpayable","type":"function"},{"inputs":[],"name":"decimals","outputs":[{"internalType":"uint256","name":"","type":"uint256"}],"stateMutability":"view","type":"function"},{"inputs":[{"internalType":"address","name":"spender","type":"address"},{"internalType":"uint256","name":"subtractedValue","type":"uint256"}],"name":"decreaseAllowance","outputs":[{"internalType":"bool","name":"","type":"bool"}],"stateMutability":"nonpayable","type":"function"},{"inputs":[{"internalType":"uint256","name":"tAmount","type":"uint256"}],"name":"deliver","outputs":[],"stateMutability":"nonpayable","type":"function"},{"inputs":[{"internalType":"address","name":"account","type":"address"}],"name":"excludeFromFee","outputs":[],"stateMutability":"nonpayable","type":"function"},{"inputs":[{"internalType":"address","name":"account","type":"address"}],"name":"excludeFromReward","outputs":[],"stateMutability":"nonpayable","type":"function"},{"inputs":[],"name":"geUnlockTime","outputs":[{"internalType":"uint256","name":"","type":"uint256"}],"stateMutability":"view","type":"function"},{"inputs":[{"internalType":"address","name":"account","type":"address"}],"name":"includeInFee","outputs":[],"stateMutability":"nonpayable","type":"function"},{"inputs":[{"internalType":"address","name":"account","type":"address"}],"name":"includeInReward","outputs":[],"stateMutability":"nonpayable","type":"function"},{"inputs":[{"internalType":"address","name":"spender","type":"address"},{"internalType":"uint256","name":"addedValue","type":"uint256"}],"name":"increaseAllowance","outputs":[{"internalType":"bool","name":"","type":"bool"}],"stateMutability":"nonpayable","type":"function"},{"inputs":[{"internalType":"address","name":"account","type":"address"}],"name":"isExcludedFromFee","outputs":[{"internalType":"bool","name":"","type":"bool"}],"stateMutability":"view","type":"function"},{"inputs":[{"internalType":"address","name":"account","type":"address"}],"name":"isExcludedFromReward","outputs":[{"internalType":"bool","name":"","type":"bool"}],"stateMutability":"view","type":"function"},{"inputs":[{"internalType":"uint256","name":"time","type":"uint256"}],"name":"lock","outputs":[],"stateMutability":"nonpayable","type":"function"},{"inputs":[],"name":"name","outputs":[{"internalType":"string","name":"","type":"string"}],"stateMutability":"view","type":"function"},{"inputs":[],"name":"numTokensSellToAddToLiquidity","outputs":[{"internalType":"uint256","name":"","type":"uint256"}],"stateMutability":"view","type":"function"},{"inputs":[],"name":"owner","outputs":[{"internalType":"address","name":"","type":"address"}],"stateMutability":"view","type":"function"},{"inputs":[{"internalType":"uint256","name":"tAmount","type":"uint256"},{"internalType":"bool","name":"deductTransferFee","type":"bool"}],"name":"reflectionFromToken","outputs":[{"internalType":"uint256","name":"","type":"uint256"}],"stateMutability":"view","type":"function"},{"inputs":[],"name":"renounceOwnership","outputs":[],"stateMutability":"nonpayable","type":"function"},{"inputs":[{"internalType":"uint256","name":"liquidityFee","type":"uint256"}],"name":"setLiquidityFeePercent","outputs":[],"stateMutability":"nonpayable","type":"function"},{"inputs":[{"internalType":"uint256","name":"maxTxPercent","type":"uint256"}],"name":"setMaxTxPercent","outputs":[],"stateMutability":"nonpayable","type":"function"},{"inputs":[{"internalType":"uint256","name":"swapNumber","type":"uint256"}],"name":"setNumTokensSellToAddToLiquidity","outputs":[],"stateMutability":"nonpayable","type":"function"},{"inputs":[{"internalType":"bool","name":"_enabled","type":"bool"}],"name":"setSwapAndLiquifyEnabled","outputs":[],"stateMutability":"nonpayable","type":"function"},{"inputs":[{"internalType":"uint256","name":"taxFee","type":"uint256"}],"name":"setTaxFeePercent","outputs":[],"stateMutability":"nonpayable","type":"function"},{"inputs":[],"name":"swapAndLiquifyEnabled","outputs":[{"internalType":"bool","name":"","type":"bool"}],"stateMutability":"view","type":"function"},{"inputs":[],"name":"symbol","outputs":[{"internalType":"string","name":"","type":"string"}],"stateMutability":"view","type":"function"},{"inputs":[{"internalType":"uint256","name":"rAmount","type":"uint256"}],"name":"tokenFromReflection","outputs":[{"internalType":"uint256","name":"","type":"uint256"}],"stateMutability":"view","type":"function"},{"inputs":[],"name":"totalFees","outputs":[{"internalType":"uint256","name":"","type":"uint256"}],"stateMutability":"view","type":"function"},{"inputs":[],"name":"totalSupply","outputs":[{"internalType":"uint256","name":"","type":"uint256"}],"stateMutability":"view","type":"function"},{"inputs":[{"internalType":"address","name":"recipient","type":"address"},{"internalType":"uint256","name":"amount","type":"uint256"}],"name":"transfer","outputs":[{"internalType":"bool","name":"","type":"bool"}],"stateMutability":"nonpayable","type":"function"},{"inputs":[{"internalType":"address","name":"sender","type":"address"},{"internalType":"address","name":"recipient","type":"address"},{"internalType":"uint256","name":"amount","type":"uint256"}],"name":"transferFrom","outputs":[{"internalType":"bool","name":"","type":"bool"}],"stateMutability":"nonpayable","type":"function"},{"inputs":[{"internalType":"address","name":"newOwner","type":"address"}],"name":"transferOwnership","outputs":[],"stateMutability":"nonpayable","type":"function"},{"inputs":[],"name":"uniswapV2Pair","outputs":[{"internalType":"address","name":"","type":"address"}],"stateMutability":"view","type":"function"},{"inputs":[],"name":"uniswapV2Router","outputs":[{"internalType":"contract IUniswapV2Router02","name":"","type":"address"}],"stateMutability":"view","type":"function"},{"inputs":[],"name":"unlock","outputs":[],"stateMutability":"nonpayable","type":"function"},{"stateMutability":"payable","type":"receive"}]'
ps_abi = '[{"inputs":[{"internalType":"address","name":"_factory","type":"address"},{"internalType":"address","name":"_WETH","type":"address"}],"stateMutability":"nonpayable","type":"constructor"},{"inputs":[],"name":"WETH","outputs":[{"internalType":"address","name":"","type":"address"}],"stateMutability":"view","type":"function"},{"inputs":[{"internalType":"address","name":"tokenA","type":"address"},{"internalType":"address","name":"tokenB","type":"address"},{"internalType":"uint256","name":"amountADesired","type":"uint256"},{"internalType":"uint256","name":"amountBDesired","type":"uint256"},{"internalType":"uint256","name":"amountAMin","type":"uint256"},{"internalType":"uint256","name":"amountBMin","type":"uint256"},{"internalType":"address","name":"to","type":"address"},{"internalType":"uint256","name":"deadline","type":"uint256"}],"name":"addLiquidity","outputs":[{"internalType":"uint256","name":"amountA","type":"uint256"},{"internalType":"uint256","name":"amountB","type":"uint256"},{"internalType":"uint256","name":"liquidity","type":"uint256"}],"stateMutability":"nonpayable","type":"function"},{"inputs":[{"internalType":"address","name":"token","type":"address"},{"internalType":"uint256","name":"amountTokenDesired","type":"uint256"},{"internalType":"uint256","name":"amountTokenMin","type":"uint256"},{"internalType":"uint256","name":"amountETHMin","type":"uint256"},{"internalType":"address","name":"to","type":"address"},{"internalType":"uint256","name":"deadline","type":"uint256"}],"name":"addLiquidityETH","outputs":[{"internalType":"uint256","name":"amountToken","type":"uint256"},{"internalType":"uint256","name":"amountETH","type":"uint256"},{"internalType":"uint256","name":"liquidity","type":"uint256"}],"stateMutability":"payable","type":"function"},{"inputs":[],"name":"factory","outputs":[{"internalType":"address","name":"","type":"address"}],"stateMutability":"view","type":"function"},{"inputs":[{"internalType":"uint256","name":"amountOut","type":"uint256"},{"internalType":"uint256","name":"reserveIn","type":"uint256"},{"internalType":"uint256","name":"reserveOut","type":"uint256"}],"name":"getAmountIn","outputs":[{"internalType":"uint256","name":"amountIn","type":"uint256"}],"stateMutability":"pure","type":"function"},{"inputs":[{"internalType":"uint256","name":"amountIn","type":"uint256"},{"internalType":"uint256","name":"reserveIn","type":"uint256"},{"internalType":"uint256","name":"reserveOut","type":"uint256"}],"name":"getAmountOut","outputs":[{"internalType":"uint256","name":"amountOut","type":"uint256"}],"stateMutability":"pure","type":"function"},{"inputs":[{"internalType":"uint256","name":"amountOut","type":"uint256"},{"internalType":"address[]","name":"path","type":"address[]"}],"name":"getAmountsIn","outputs":[{"internalType":"uint256[]","name":"amounts","type":"uint256[]"}],"stateMutability":"view","type":"function"},{"inputs":[{"internalType":"uint256","name":"amountIn","type":"uint256"},{"internalType":"address[]","name":"path","type":"address[]"}],"name":"getAmountsOut","outputs":[{"internalType":"uint256[]","name":"amounts","type":"uint256[]"}],"stateMutability":"view","type":"function"},{"inputs":[{"internalType":"uint256","name":"amountA","type":"uint256"},{"internalType":"uint256","name":"reserveA","type":"uint256"},{"internalType":"uint256","name":"reserveB","type":"uint256"}],"name":"quote","outputs":[{"internalType":"uint256","name":"amountB","type":"uint256"}],"stateMutability":"pure","type":"function"},{"inputs":[{"internalType":"address","name":"tokenA","type":"address"},{"internalType":"address","name":"tokenB","type":"address"},{"internalType":"uint256","name":"liquidity","type":"uint256"},{"internalType":"uint256","name":"amountAMin","type":"uint256"},{"internalType":"uint256","name":"amountBMin","type":"uint256"},{"internalType":"address","name":"to","type":"address"},{"internalType":"uint256","name":"deadline","type":"uint256"}],"name":"removeLiquidity","outputs":[{"internalType":"uint256","name":"amountA","type":"uint256"},{"internalType":"uint256","name":"amountB","type":"uint256"}],"stateMutability":"nonpayable","type":"function"},{"inputs":[{"internalType":"address","name":"token","type":"address"},{"internalType":"uint256","name":"liquidity","type":"uint256"},{"internalType":"uint256","name":"amountTokenMin","type":"uint256"},{"internalType":"uint256","name":"amountETHMin","type":"uint256"},{"internalType":"address","name":"to","type":"address"},{"internalType":"uint256","name":"deadline","type":"uint256"}],"name":"removeLiquidityETH","outputs":[{"internalType":"uint256","name":"amountToken","type":"uint256"},{"internalType":"uint256","name":"amountETH","type":"uint256"}],"stateMutability":"nonpayable","type":"function"},{"inputs":[{"internalType":"address","name":"token","type":"address"},{"internalType":"uint256","name":"liquidity","type":"uint256"},{"internalType":"uint256","name":"amountTokenMin","type":"uint256"},{"internalType":"uint256","name":"amountETHMin","type":"uint256"},{"internalType":"address","name":"to","type":"address"},{"internalType":"uint256","name":"deadline","type":"uint256"}],"name":"removeLiquidityETHSupportingFeeOnTransferTokens","outputs":[{"internalType":"uint256","name":"amountETH","type":"uint256"}],"stateMutability":"nonpayable","type":"function"},{"inputs":[{"internalType":"address","name":"token","type":"address"},{"internalType":"uint256","name":"liquidity","type":"uint256"},{"internalType":"uint256","name":"amountTokenMin","type":"uint256"},{"internalType":"uint256","name":"amountETHMin","type":"uint256"},{"internalType":"address","name":"to","type":"address"},{"internalType":"uint256","name":"deadline","type":"uint256"},{"internalType":"bool","name":"approveMax","type":"bool"},{"internalType":"uint8","name":"v","type":"uint8"},{"internalType":"bytes32","name":"r","type":"bytes32"},{"internalType":"bytes32","name":"s","type":"bytes32"}],"name":"removeLiquidityETHWithPermit","outputs":[{"internalType":"uint256","name":"amountToken","type":"uint256"},{"internalType":"uint256","name":"amountETH","type":"uint256"}],"stateMutability":"nonpayable","type":"function"},{"inputs":[{"internalType":"address","name":"token","type":"address"},{"internalType":"uint256","name":"liquidity","type":"uint256"},{"internalType":"uint256","name":"amountTokenMin","type":"uint256"},{"internalType":"uint256","name":"amountETHMin","type":"uint256"},{"internalType":"address","name":"to","type":"address"},{"internalType":"uint256","name":"deadline","type":"uint256"},{"internalType":"bool","name":"approveMax","type":"bool"},{"internalType":"uint8","name":"v","type":"uint8"},{"internalType":"bytes32","name":"r","type":"bytes32"},{"internalType":"bytes32","name":"s","type":"bytes32"}],"name":"removeLiquidityETHWithPermitSupportingFeeOnTransferTokens","outputs":[{"internalType":"uint256","name":"amountETH","type":"uint256"}],"stateMutability":"nonpayable","type":"function"},{"inputs":[{"internalType":"address","name":"tokenA","type":"address"},{"internalType":"address","name":"tokenB","type":"address"},{"internalType":"uint256","name":"liquidity","type":"uint256"},{"internalType":"uint256","name":"amountAMin","type":"uint256"},{"internalType":"uint256","name":"amountBMin","type":"uint256"},{"internalType":"address","name":"to","type":"address"},{"internalType":"uint256","name":"deadline","type":"uint256"},{"internalType":"bool","name":"approveMax","type":"bool"},{"internalType":"uint8","name":"v","type":"uint8"},{"internalType":"bytes32","name":"r","type":"bytes32"},{"internalType":"bytes32","name":"s","type":"bytes32"}],"name":"removeLiquidityWithPermit","outputs":[{"internalType":"uint256","name":"amountA","type":"uint256"},{"internalType":"uint256","name":"amountB","type":"uint256"}],"stateMutability":"nonpayable","type":"function"},{"inputs":[{"internalType":"uint256","name":"amountOut","type":"uint256"},{"internalType":"address[]","name":"path","type":"address[]"},{"internalType":"address","name":"to","type":"address"},{"internalType":"uint256","name":"deadline","type":"uint256"}],"name":"swapETHForExactTokens","outputs":[{"internalType":"uint256[]","name":"amounts","type":"uint256[]"}],"stateMutability":"payable","type":"function"},{"inputs":[{"internalType":"uint256","name":"amountOutMin","type":"uint256"},{"internalType":"address[]","name":"path","type":"address[]"},{"internalType":"address","name":"to","type":"address"},{"internalType":"uint256","name":"deadline","type":"uint256"}],"name":"swapExactETHForTokens","outputs":[{"internalType":"uint256[]","name":"amounts","type":"uint256[]"}],"stateMutability":"payable","type":"function"},{"inputs":[{"internalType":"uint256","name":"amountOutMin","type":"uint256"},{"internalType":"address[]","name":"path","type":"address[]"},{"internalType":"address","name":"to","type":"address"},{"internalType":"uint256","name":"deadline","type":"uint256"}],"name":"swapExactETHForTokensSupportingFeeOnTransferTokens","outputs":[],"stateMutability":"payable","type":"function"},{"inputs":[{"internalType":"uint256","name":"amountIn","type":"uint256"},{"internalType":"uint256","name":"amountOutMin","type":"uint256"},{"internalType":"address[]","name":"path","type":"address[]"},{"internalType":"address","name":"to","type":"address"},{"internalType":"uint256","name":"deadline","type":"uint256"}],"name":"swapExactTokensForETH","outputs":[{"internalType":"uint256[]","name":"amounts","type":"uint256[]"}],"stateMutability":"nonpayable","type":"function"},{"inputs":[{"internalType":"uint256","name":"amountIn","type":"uint256"},{"internalType":"uint256","name":"amountOutMin","type":"uint256"},{"internalType":"address[]","name":"path","type":"address[]"},{"internalType":"address","name":"to","type":"address"},{"internalType":"uint256","name":"deadline","type":"uint256"}],"name":"swapExactTokensForETHSupportingFeeOnTransferTokens","outputs":[],"stateMutability":"nonpayable","type":"function"},{"inputs":[{"internalType":"uint256","name":"amountIn","type":"uint256"},{"internalType":"uint256","name":"amountOutMin","type":"uint256"},{"internalType":"address[]","name":"path","type":"address[]"},{"internalType":"address","name":"to","type":"address"},{"internalType":"uint256","name":"deadline","type":"uint256"}],"name":"swapExactTokensForTokens","outputs":[{"internalType":"uint256[]","name":"amounts","type":"uint256[]"}],"stateMutability":"nonpayable","type":"function"},{"inputs":[{"internalType":"uint256","name":"amountIn","type":"uint256"},{"internalType":"uint256","name":"amountOutMin","type":"uint256"},{"internalType":"address[]","name":"path","type":"address[]"},{"internalType":"address","name":"to","type":"address"},{"internalType":"uint256","name":"deadline","type":"uint256"}],"name":"swapExactTokensForTokensSupportingFeeOnTransferTokens","outputs":[],"stateMutability":"nonpayable","type":"function"},{"inputs":[{"internalType":"uint256","name":"amountOut","type":"uint256"},{"internalType":"uint256","name":"amountInMax","type":"uint256"},{"internalType":"address[]","name":"path","type":"address[]"},{"internalType":"address","name":"to","type":"address"},{"internalType":"uint256","name":"deadline","type":"uint256"}],"name":"swapTokensForExactETH","outputs":[{"internalType":"uint256[]","name":"amounts","type":"uint256[]"}],"stateMutability":"nonpayable","type":"function"},{"inputs":[{"internalType":"uint256","name":"amountOut","type":"uint256"},{"internalType":"uint256","name":"amountInMax","type":"uint256"},{"internalType":"address[]","name":"path","type":"address[]"},{"internalType":"address","name":"to","type":"address"},{"internalType":"uint256","name":"deadline","type":"uint256"}],"name":"swapTokensForExactTokens","outputs":[{"internalType":"uint256[]","name":"amounts","type":"uint256[]"}],"stateMutability":"nonpayable","type":"function"},{"stateMutability":"payable","type":"receive"}]'
ps_token_info = 'https://api.pancakeswap.info/api/v2/tokens/' # concat token address 
ps_swap_addr = '0x10ED43C718714eb63d5aA57B78B54704E256024E'
ps_factory_addr = '0xcA143Ce32Fe78f1f7019d7d551a6402fC5350c73'
ps_factory_abi = '[{"inputs":[{"internalType":"address","name":"_feeToSetter","type":"address"}],"payable":false,"stateMutability":"nonpayable","type":"constructor"},{"anonymous":false,"inputs":[{"indexed":true,"internalType":"address","name":"token0","type":"address"},{"indexed":true,"internalType":"address","name":"token1","type":"address"},{"indexed":false,"internalType":"address","name":"pair","type":"address"},{"indexed":false,"internalType":"uint256","name":"","type":"uint256"}],"name":"PairCreated","type":"event"},{"constant":true,"inputs":[],"name":"INIT_CODE_PAIR_HASH","outputs":[{"internalType":"bytes32","name":"","type":"bytes32"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":true,"inputs":[{"internalType":"uint256","name":"","type":"uint256"}],"name":"allPairs","outputs":[{"internalType":"address","name":"","type":"address"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":true,"inputs":[],"name":"allPairsLength","outputs":[{"internalType":"uint256","name":"","type":"uint256"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":false,"inputs":[{"internalType":"address","name":"tokenA","type":"address"},{"internalType":"address","name":"tokenB","type":"address"}],"name":"createPair","outputs":[{"internalType":"address","name":"pair","type":"address"}],"payable":false,"stateMutability":"nonpayable","type":"function"},{"constant":true,"inputs":[],"name":"feeTo","outputs":[{"internalType":"address","name":"","type":"address"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":true,"inputs":[],"name":"feeToSetter","outputs":[{"internalType":"address","name":"","type":"address"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":true,"inputs":[{"internalType":"address","name":"","type":"address"},{"internalType":"address","name":"","type":"address"}],"name":"getPair","outputs":[{"internalType":"address","name":"","type":"address"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":false,"inputs":[{"internalType":"address","name":"_feeTo","type":"address"}],"name":"setFeeTo","outputs":[],"payable":false,"stateMutability":"nonpayable","type":"function"},{"constant":false,"inputs":[{"internalType":"address","name":"_feeToSetter","type":"address"}],"name":"setFeeToSetter","outputs":[],"payable":false,"stateMutability":"nonpayable","type":"function"}]'
ps_pair_abi = '[{"inputs":[],"payable":false,"stateMutability":"nonpayable","type":"constructor"},{"anonymous":false,"inputs":[{"indexed":true,"internalType":"address","name":"owner","type":"address"},{"indexed":true,"internalType":"address","name":"spender","type":"address"},{"indexed":false,"internalType":"uint256","name":"value","type":"uint256"}],"name":"Approval","type":"event"},{"anonymous":false,"inputs":[{"indexed":true,"internalType":"address","name":"sender","type":"address"},{"indexed":false,"internalType":"uint256","name":"amount0","type":"uint256"},{"indexed":false,"internalType":"uint256","name":"amount1","type":"uint256"},{"indexed":true,"internalType":"address","name":"to","type":"address"}],"name":"Burn","type":"event"},{"anonymous":false,"inputs":[{"indexed":true,"internalType":"address","name":"sender","type":"address"},{"indexed":false,"internalType":"uint256","name":"amount0","type":"uint256"},{"indexed":false,"internalType":"uint256","name":"amount1","type":"uint256"}],"name":"Mint","type":"event"},{"anonymous":false,"inputs":[{"indexed":true,"internalType":"address","name":"sender","type":"address"},{"indexed":false,"internalType":"uint256","name":"amount0In","type":"uint256"},{"indexed":false,"internalType":"uint256","name":"amount1In","type":"uint256"},{"indexed":false,"internalType":"uint256","name":"amount0Out","type":"uint256"},{"indexed":false,"internalType":"uint256","name":"amount1Out","type":"uint256"},{"indexed":true,"internalType":"address","name":"to","type":"address"}],"name":"Swap","type":"event"},{"anonymous":false,"inputs":[{"indexed":false,"internalType":"uint112","name":"reserve0","type":"uint112"},{"indexed":false,"internalType":"uint112","name":"reserve1","type":"uint112"}],"name":"Sync","type":"event"},{"anonymous":false,"inputs":[{"indexed":true,"internalType":"address","name":"from","type":"address"},{"indexed":true,"internalType":"address","name":"to","type":"address"},{"indexed":false,"internalType":"uint256","name":"value","type":"uint256"}],"name":"Transfer","type":"event"},{"constant":true,"inputs":[],"name":"DOMAIN_SEPARATOR","outputs":[{"internalType":"bytes32","name":"","type":"bytes32"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":true,"inputs":[],"name":"MINIMUM_LIQUIDITY","outputs":[{"internalType":"uint256","name":"","type":"uint256"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":true,"inputs":[],"name":"PERMIT_TYPEHASH","outputs":[{"internalType":"bytes32","name":"","type":"bytes32"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":true,"inputs":[{"internalType":"address","name":"","type":"address"},{"internalType":"address","name":"","type":"address"}],"name":"allowance","outputs":[{"internalType":"uint256","name":"","type":"uint256"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":false,"inputs":[{"internalType":"address","name":"spender","type":"address"},{"internalType":"uint256","name":"value","type":"uint256"}],"name":"approve","outputs":[{"internalType":"bool","name":"","type":"bool"}],"payable":false,"stateMutability":"nonpayable","type":"function"},{"constant":true,"inputs":[{"internalType":"address","name":"","type":"address"}],"name":"balanceOf","outputs":[{"internalType":"uint256","name":"","type":"uint256"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":false,"inputs":[{"internalType":"address","name":"to","type":"address"}],"name":"burn","outputs":[{"internalType":"uint256","name":"amount0","type":"uint256"},{"internalType":"uint256","name":"amount1","type":"uint256"}],"payable":false,"stateMutability":"nonpayable","type":"function"},{"constant":true,"inputs":[],"name":"decimals","outputs":[{"internalType":"uint8","name":"","type":"uint8"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":true,"inputs":[],"name":"factory","outputs":[{"internalType":"address","name":"","type":"address"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":true,"inputs":[],"name":"getReserves","outputs":[{"internalType":"uint112","name":"_reserve0","type":"uint112"},{"internalType":"uint112","name":"_reserve1","type":"uint112"},{"internalType":"uint32","name":"_blockTimestampLast","type":"uint32"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":false,"inputs":[{"internalType":"address","name":"_token0","type":"address"},{"internalType":"address","name":"_token1","type":"address"}],"name":"initialize","outputs":[],"payable":false,"stateMutability":"nonpayable","type":"function"},{"constant":true,"inputs":[],"name":"kLast","outputs":[{"internalType":"uint256","name":"","type":"uint256"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":false,"inputs":[{"internalType":"address","name":"to","type":"address"}],"name":"mint","outputs":[{"internalType":"uint256","name":"liquidity","type":"uint256"}],"payable":false,"stateMutability":"nonpayable","type":"function"},{"constant":true,"inputs":[],"name":"name","outputs":[{"internalType":"string","name":"","type":"string"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":true,"inputs":[{"internalType":"address","name":"","type":"address"}],"name":"nonces","outputs":[{"internalType":"uint256","name":"","type":"uint256"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":false,"inputs":[{"internalType":"address","name":"owner","type":"address"},{"internalType":"address","name":"spender","type":"address"},{"internalType":"uint256","name":"value","type":"uint256"},{"internalType":"uint256","name":"deadline","type":"uint256"},{"internalType":"uint8","name":"v","type":"uint8"},{"internalType":"bytes32","name":"r","type":"bytes32"},{"internalType":"bytes32","name":"s","type":"bytes32"}],"name":"permit","outputs":[],"payable":false,"stateMutability":"nonpayable","type":"function"},{"constant":true,"inputs":[],"name":"price0CumulativeLast","outputs":[{"internalType":"uint256","name":"","type":"uint256"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":true,"inputs":[],"name":"price1CumulativeLast","outputs":[{"internalType":"uint256","name":"","type":"uint256"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":false,"inputs":[{"internalType":"address","name":"to","type":"address"}],"name":"skim","outputs":[],"payable":false,"stateMutability":"nonpayable","type":"function"},{"constant":false,"inputs":[{"internalType":"uint256","name":"amount0Out","type":"uint256"},{"internalType":"uint256","name":"amount1Out","type":"uint256"},{"internalType":"address","name":"to","type":"address"},{"internalType":"bytes","name":"data","type":"bytes"}],"name":"swap","outputs":[],"payable":false,"stateMutability":"nonpayable","type":"function"},{"constant":true,"inputs":[],"name":"symbol","outputs":[{"internalType":"string","name":"","type":"string"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":false,"inputs":[],"name":"sync","outputs":[],"payable":false,"stateMutability":"nonpayable","type":"function"},{"constant":true,"inputs":[],"name":"token0","outputs":[{"internalType":"address","name":"","type":"address"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":true,"inputs":[],"name":"token1","outputs":[{"internalType":"address","name":"","type":"address"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":true,"inputs":[],"name":"totalSupply","outputs":[{"internalType":"uint256","name":"","type":"uint256"}],"payable":false,"stateMutability":"view","type":"function"},{"constant":false,"inputs":[{"internalType":"address","name":"to","type":"address"},{"internalType":"uint256","name":"value","type":"uint256"}],"name":"transfer","outputs":[{"internalType":"bool","name":"","type":"bool"}],"payable":false,"stateMutability":"nonpayable","type":"function"},{"constant":false,"inputs":[{"internalType":"address","name":"from","type":"address"},{"internalType":"address","name":"to","type":"address"},{"internalType":"uint256","name":"value","type":"uint256"}],"name":"transferFrom","outputs":[{"internalType":"bool","name":"","type":"bool"}],"payable":false,"stateMutability":"nonpayable","type":"function"}]'
wbnb_addr = '0xbb4CdB9CBd36B01bD1cBaEBF2De08d9173bc095c'
tokens = [
    {
      "name": "PancakeSwap Token",
      "symbol": "CAKE",
      "address": "0x0E09FaBB73Bd3Ade0a17ECC321fD13a19e81cE82",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x0e09fabb73bd3ade0a17ecc321fd13a19e81ce82.png"
    },
    {
      "name": "Cardano Token",
      "symbol": "ADA",
      "address": "0x3EE2200Efb3400fAbB9AacF31297cBdD1d435D47",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x3ee2200efb3400fabb9aacf31297cbdd1d435d47.png"
    },
    {
      "name": "AdEx Network",
      "symbol": "ADX",
      "address": "0x6bfF4Fb161347ad7de4A625AE5aa3A1CA7077819",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x6bfF4Fb161347ad7de4A625AE5aa3A1CA7077819.png"
    },
    {
      "name": "My Neigbor Alice",
      "symbol": "ALICE",
      "address": "0xAC51066d7bEC65Dc4589368da368b212745d63E8",
      "chainId": 56,
      "decimals": 6,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xac51066d7bec65dc4589368da368b212745d63e8.png"
    },
    {
      "name": "AlpaToken",
      "symbol": "ALPA",
      "address": "0xc5E6689C9c8B02be7C49912Ef19e79cF24977f03",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xc5e6689c9c8b02be7c49912ef19e79cf24977f03.png"
    },
    {
      "name": "Alpaca",
      "symbol": "ALPACA",
      "address": "0x8F0528cE5eF7B51152A59745bEfDD91D97091d2F",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x8f0528ce5ef7b51152a59745befdd91d97091d2f.png"
    },
    {
      "name": "AlphaToken",
      "symbol": "ALPHA",
      "address": "0xa1faa113cbE53436Df28FF0aEe54275c13B40975",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xa1faa113cbe53436df28ff0aee54275c13b40975.png"
    },
    {
      "name": "Ampleforth",
      "symbol": "AMPL",
      "address": "0xDB021b1B247fe2F1fa57e0A87C748Cc1E321F07F",
      "chainId": 56,
      "decimals": 9,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xDB021b1B247fe2F1fa57e0A87C748Cc1E321F07F.png"
    },
    {
      "name": "Ankr",
      "symbol": "ANKR",
      "address": "0xf307910A4c7bbc79691fD374889b36d8531B08e3",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xf307910a4c7bbc79691fd374889b36d8531b08e3.png"
    },
    {
      "name": "anyMTLX",
      "symbol": "anyMTLX",
      "address": "0x5921DEE8556c4593EeFCFad3CA5e2f618606483b",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x5921dee8556c4593eefcfad3ca5e2f618606483b.png"
    },
    {
      "name": "APYSwap",
      "symbol": "APYS",
      "address": "0x37dfACfaeDA801437Ff648A1559d73f4C40aAcb7",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x37dfACfaeDA801437Ff648A1559d73f4C40aAcb7.png"
    },
    {
      "name": "ARPA",
      "symbol": "ARPA",
      "address": "0x6F769E65c14Ebd1f68817F5f1DcDb61Cfa2D6f7e",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x6f769e65c14ebd1f68817f5f1dcdb61cfa2d6f7e.png"
    },
    {
      "name": "AS Roma",
      "symbol": "ASR",
      "address": "0x80D5f92C2c8C682070C95495313dDB680B267320",
      "chainId": 56,
      "decimals": 2,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x80d5f92c2c8c682070c95495313ddb680b267320.png"
    },
    {
      "name": "Automata",
      "symbol": "ATA",
      "address": "0xA2120b9e674d3fC3875f415A7DF52e382F141225",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xA2120b9e674d3fC3875f415A7DF52e382F141225.png"
    },
    {
      "name": "Atletico de Madrid",
      "symbol": "ATM",
      "address": "0x25E9d05365c867E59C1904E7463Af9F312296f9E",
      "chainId": 56,
      "decimals": 2,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x25e9d05365c867e59c1904e7463af9f312296f9e.png"
    },
    {
      "name": "Cosmos Token",
      "symbol": "ATOM",
      "address": "0x0Eb3a705fc54725037CC9e008bDede697f62F335",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x0eb3a705fc54725037cc9e008bdede697f62f335.png"
    },
    {
      "name": "AUTOv2",
      "symbol": "AUTO",
      "address": "0xa184088a740c695E156F91f5cC086a06bb78b827",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xa184088a740c695e156f91f5cc086a06bb78b827.png"
    },
    {
      "name": "Axie Infinity Shard",
      "symbol": "AXS",
      "address": "0x715D400F88C167884bbCc41C5FeA407ed4D2f8A0",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x715D400F88C167884bbCc41C5FeA407ed4D2f8A0.png"
    },
    {
      "name": "BabyCake",
      "symbol": "BABYCAKE",
      "address": "0xdB8D30b74bf098aF214e862C90E647bbB1fcC58c",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xdB8D30b74bf098aF214e862C90E647bbB1fcC58c.png"
    },
    {
      "name": "Bakery Token",
      "symbol": "BAKE",
      "address": "0xE02dF9e3e622DeBdD69fb838bB799E3F168902c5",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xe02df9e3e622debdd69fb838bb799e3f168902c5.png"
    },
    {
      "name": "AllianceBlock",
      "symbol": "bALBT",
      "address": "0x72fAa679E1008Ad8382959FF48E392042A8b06f7",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x72faa679e1008ad8382959ff48e392042a8b06f7.png"
    },
    {
      "name": "BAND Protocol Token",
      "symbol": "BAND",
      "address": "0xAD6cAEb32CD2c308980a548bD0Bc5AA4306c6c18",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xad6caeb32cd2c308980a548bd0bc5aa4306c6c18.png"
    },
    {
      "name": "Basic Attention Token",
      "symbol": "BAT",
      "address": "0x101d82428437127bF1608F699CD651e6Abf9766E",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x101d82428437127bf1608f699cd651e6abf9766e.png"
    },
    {
      "name": "bBADGER",
      "symbol": "bBADGER",
      "address": "0x1F7216fdB338247512Ec99715587bb97BBf96eae",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x1f7216fdb338247512ec99715587bb97bbf96eae.png"
    },
    {
      "name": "Conflux",
      "symbol": "bCFX",
      "address": "0x045c4324039dA91c52C55DF5D785385Aab073DcF",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x045c4324039dA91c52C55DF5D785385Aab073DcF.png"
    },
    {
      "name": "Bitcoin Cash Token",
      "symbol": "BCH",
      "address": "0x8fF795a6F4D97E7887C79beA79aba5cc76444aDf",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x8ff795a6f4d97e7887c79bea79aba5cc76444adf.png"
    },
    {
      "name": "bDIGG",
      "symbol": "bDIGG",
      "address": "0x5986D5c77c65e5801a5cAa4fAE80089f870A71dA",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x5986d5c77c65e5801a5caa4fae80089f870a71da.png"
    },
    {
      "name": "bDollar",
      "symbol": "BDO",
      "address": "0x190b589cf9Fb8DDEabBFeae36a813FFb2A702454",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x190b589cf9Fb8DDEabBFeae36a813FFb2A702454.png"
    },
    {
      "name": "Bella Protocol",
      "symbol": "BEL",
      "address": "0x8443f091997f06a61670B735ED92734F5628692F",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x8443f091997f06a61670b735ed92734f5628692f.png"
    },
    {
      "name": "Belt",
      "symbol": "BELT",
      "address": "0xE0e514c71282b6f4e823703a39374Cf58dc3eA4f",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xE0e514c71282b6f4e823703a39374Cf58dc3eA4f.png"
    },
    {
      "name": "Beacon ETH",
      "symbol": "BETH",
      "address": "0x250632378E573c6Be1AC2f97Fcdf00515d0Aa91B",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x250632378e573c6be1ac2f97fcdf00515d0aa91b.png"
    },
    {
      "name": "b.earnfi",
      "symbol": "BFI",
      "address": "0x81859801b01764D4f0Fa5E64729f5a6C3b91435b",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x81859801b01764D4f0Fa5E64729f5a6C3b91435b.png"
    },
    {
      "name": "Beefy.finance",
      "symbol": "BIFI",
      "address": "0xCa3F508B8e4Dd382eE878A314789373D80A5190A",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xCa3F508B8e4Dd382eE878A314789373D80A5190A.png"
    },
    {
      "name": "BLINk",
      "symbol": "BLK",
      "address": "0x63870A18B6e42b01Ef1Ad8A2302ef50B7132054F",
      "chainId": 56,
      "decimals": 6,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x63870A18B6e42b01Ef1Ad8A2302ef50B7132054F.png"
    },
    {
      "name": "Binamon",
      "symbol": "BMON",
      "address": "0x08ba0619b1e7A582E0BCe5BBE9843322C954C340",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x08ba0619b1e7A582E0BCe5BBE9843322C954C340.png"
    },
    {
      "name": "Multiplier",
      "symbol": "bMXX",
      "address": "0x4131b87F74415190425ccD873048C708F8005823",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x4131b87f74415190425ccd873048c708f8005823.png"
    },
    {
      "name": "OPEN Governance Token",
      "symbol": "bOPEN",
      "address": "0xF35262a9d427F96d2437379eF090db986eaE5d42",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xF35262a9d427F96d2437379eF090db986eaE5d42.png"
    },
    {
      "name": "BoringDAO",
      "symbol": "BORING",
      "address": "0xffEecbf8D7267757c2dc3d13D730E97E15BfdF7F",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xffEecbf8D7267757c2dc3d13D730E97E15BfdF7F.png"
    },
    {
      "name": "ROOBEE",
      "symbol": "bROOBEE",
      "address": "0xE64F5Cb844946C1F102Bd25bBD87a5aB4aE89Fbe",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xe64f5cb844946c1f102bd25bbd87a5ab4ae89fbe.png"
    },
    {
      "name": "Berry",
      "symbol": "BRY",
      "address": "0xf859Bf77cBe8699013d6Dbc7C2b926Aaf307F830",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xf859Bf77cBe8699013d6Dbc7C2b926Aaf307F830.png"
    },
    {
      "name": "BSCPad",
      "symbol": "BSCPAD",
      "address": "0x5A3010d4d8D3B5fB49f8B6E57FB9E48063f16700",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x5A3010d4d8D3B5fB49f8B6E57FB9E48063f16700.png"
    },
    {
      "name": "BSCEX",
      "symbol": "BSCX",
      "address": "0x5Ac52EE5b2a633895292Ff6d8A89bB9190451587",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x5ac52ee5b2a633895292ff6d8a89bb9190451587.png"
    },
    {
      "name": "Binance Pegged Bitcoin",
      "symbol": "BTCB",
      "address": "0x7130d2A12B9BCbFAe4f2634d864A1Ee1Ce3Ead9c",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x7130d2a12b9bcbfae4f2634d864a1ee1ce3ead9c.png"
    },
    {
      "name": "Standard BTC Hashrate Token",
      "symbol": "BTCST",
      "address": "0x78650B139471520656b9E7aA7A5e9276814a38e9",
      "chainId": 56,
      "decimals": 17,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x78650b139471520656b9e7aa7a5e9276814a38e9.png"
    },
    {
      "name": "Bittrue",
      "symbol": "BTR",
      "address": "0x5a16E8cE8cA316407c6E6307095dc9540a8D62B3",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x5a16E8cE8cA316407c6E6307095dc9540a8D62B3.png"
    },
    {
      "name": "Bittorrent",
      "symbol": "BTT",
      "address": "0x8595F9dA7b868b1822194fAEd312235E43007b49",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x8595f9da7b868b1822194faed312235e43007b49.png"
    },
    {
      "name": "Bunny Token",
      "symbol": "BUNNY",
      "address": "0xC9849E6fdB743d08fAeE3E34dd2D1bc69EA11a51",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xc9849e6fdb743d08faee3e34dd2d1bc69ea11a51.png"
    },
    {
      "name": "Burger Swap",
      "symbol": "BURGER",
      "address": "0xAe9269f27437f0fcBC232d39Ec814844a51d6b8f",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xae9269f27437f0fcbc232d39ec814844a51d6b8f.png"
    },
    {
      "name": "Binance Pegged BUSD",
      "symbol": "BUSD",
      "address": "0xe9e7CEA3DedcA5984780Bafc599bD69ADd087D56",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xe9e7cea3dedca5984780bafc599bd69add087d56.png"
    },
    {
      "name": "BUX",
      "symbol": "BUX",
      "address": "0x211FfbE424b90e25a15531ca322adF1559779E45",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x211ffbe424b90e25a15531ca322adf1559779e45.png"
    },
    {
      "name": "Coin98",
      "symbol": "C98",
      "address": "0xaEC945e04baF28b135Fa7c640f624f8D90F1C3a6",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xaEC945e04baF28b135Fa7c640f624f8D90F1C3a6.png"
    },
    {
      "name": "CanYaCoin",
      "symbol": "CAN",
      "address": "0x007EA5C0Ea75a8DF45D288a4debdD5bb633F9e56",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x007ea5c0ea75a8df45d288a4debdd5bb633f9e56.png"
    },
    {
      "name": "ChainGuardians",
      "symbol": "CGG",
      "address": "0x1613957159E9B0ac6c80e824F7Eea748a32a0AE2",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x1613957159e9b0ac6c80e824f7eea748a32a0ae2.png"
    },
    {
      "name": "Tranchess",
      "symbol": "CHESS",
      "address": "0x20de22029ab63cf9A7Cf5fEB2b737Ca1eE4c82A6",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x20de22029ab63cf9A7Cf5fEB2b737Ca1eE4c82A6.png"
    },
    {
      "name": "Chromia",
      "symbol": "CHR",
      "address": "0xf9CeC8d50f6c8ad3Fb6dcCEC577e05aA32B224FE",
      "chainId": 56,
      "decimals": 6,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xf9CeC8d50f6c8ad3Fb6dcCEC577e05aA32B224FE.png"
    },
    {
      "name": "Compound Finance",
      "symbol": "COMP",
      "address": "0x52CE071Bd9b1C4B00A0b92D298c512478CaD67e8",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x52ce071bd9b1c4b00a0b92d298c512478cad67e8.png"
    },
    {
      "name": "Contentos",
      "symbol": "COS",
      "address": "0x96Dd399F9c3AFda1F194182F71600F1B65946501",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x96dd399f9c3afda1f194182f71600f1b65946501.png"
    },
    {
      "name": "Cream",
      "symbol": "CREAM",
      "address": "0xd4CB328A82bDf5f03eB737f37Fa6B370aef3e888",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xd4cb328a82bdf5f03eb737f37fa6b370aef3e888.png"
    },
    {
      "name": "CertiK Token",
      "symbol": "CTK",
      "address": "0xA8c2B8eec3d368C0253ad3dae65a5F2BBB89c929",
      "chainId": 56,
      "decimals": 6,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xa8c2b8eec3d368c0253ad3dae65a5f2bbb89c929.png"
    },
    {
      "name": "Cyclone",
      "symbol": "CYC",
      "address": "0x810EE35443639348aDbbC467b33310d2AB43c168",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x810ee35443639348adbbc467b33310d2ab43c168.png"
    },
    {
      "name": "Binance Pegged DAI",
      "symbol": "DAI",
      "address": "0x1AF3F329e8BE154074D8769D1FFa4eE058B1DBc3",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x1af3f329e8be154074d8769d1ffa4ee058b1dbc3.png"
    },
    {
      "name": "Dego.Finance",
      "symbol": "DEGO",
      "address": "0x3FdA9383A84C05eC8f7630Fe10AdF1fAC13241CC",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x3fda9383a84c05ec8f7630fe10adf1fac13241cc.png"
    },
    {
      "name": "Deri",
      "symbol": "DERI",
      "address": "0xe60eaf5A997DFAe83739e035b005A33AfdCc6df5",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xe60eaf5A997DFAe83739e035b005A33AfdCc6df5.png"
    },
    {
      "name": "DeXe",
      "symbol": "DEXE",
      "address": "0x039cB485212f996A9DBb85A9a75d898F94d38dA6",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x039cb485212f996a9dbb85a9a75d898f94d38da6.png"
    },
    {
      "name": "DefiDollar DAO",
      "symbol": "DFD",
      "address": "0x9899a98b222fCb2f3dbee7dF45d943093a4ff9ff",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x9899a98b222fcb2f3dbee7df45d943093a4ff9ff.png"
    },
    {
      "name": "DFuture",
      "symbol": "DFT",
      "address": "0x42712dF5009c20fee340B245b510c0395896cF6e",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x42712dF5009c20fee340B245b510c0395896cF6e.png"
    },
    {
      "name": "Decentral Games",
      "symbol": "DG",
      "address": "0x9Fdc3ae5c814b79dcA2556564047C5e7e5449C19",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x9Fdc3ae5c814b79dcA2556564047C5e7e5449C19.png"
    },
    {
      "name": "Ditto",
      "symbol": "DITTO",
      "address": "0x233d91A0713155003fc4DcE0AFa871b508B3B715",
      "chainId": 56,
      "decimals": 9,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x233d91A0713155003fc4DcE0AFa871b508B3B715.png"
    },
    {
      "name": "Dodo",
      "symbol": "DODO",
      "address": "0x67ee3Cb086F8a16f34beE3ca72FAD36F7Db929e2",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x67ee3cb086f8a16f34bee3ca72fad36f7db929e2.png"
    },
    {
      "name": "Dogecoin",
      "symbol": "DOGE",
      "address": "0xbA2aE424d960c26247Dd6c32edC70B295c744C43",
      "chainId": 56,
      "decimals": 8,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xbA2aE424d960c26247Dd6c32edC70B295c744C43.png"
    },
    {
      "name": "Dopple Finance",
      "symbol": "DOP",
      "address": "0x844FA82f1E54824655470970F7004Dd90546bB28",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x844fa82f1e54824655470970f7004dd90546bb28.png"
    },
    {
      "name": "Polkadot Token",
      "symbol": "DOT",
      "address": "0x7083609fCE4d1d8Dc0C979AAb8c869Ea2C873402",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x7083609fce4d1d8dc0c979aab8c869ea2c873402.png"
    },
    {
      "name": "Dusk",
      "symbol": "DUSK",
      "address": "0xB2BD0749DBE21f623d9BABa856D3B0f0e1BFEc9C",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xb2bd0749dbe21f623d9baba856d3b0f0e1bfec9c.png"
    },
    {
      "name": "Dvision Network",
      "symbol": "DVI",
      "address": "0x758FB037A375F17c7e195CC634D77dA4F554255B",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x758FB037A375F17c7e195CC634D77dA4F554255B.png"
    },
    {
      "name": "Elrond",
      "symbol": "EGLD",
      "address": "0xbF7c81FFF98BbE61B40Ed186e4AfD6DDd01337fe",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xbf7c81fff98bbe61b40ed186e4afd6ddd01337fe.png"
    },
    {
      "name": "EOS Token",
      "symbol": "EOS",
      "address": "0x56b6fB708fC5732DEC1Afc8D8556423A2EDcCbD6",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x56b6fb708fc5732dec1afc8d8556423a2edccbd6.png"
    },
    {
      "name": "Ellipsis",
      "symbol": "EPS",
      "address": "0xA7f552078dcC247C2684336020c03648500C6d9F",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xa7f552078dcc247c2684336020c03648500c6d9f.png"
    },
    {
      "name": "Binance Pegged ETH",
      "symbol": "ETH",
      "address": "0x2170Ed0880ac9A755fd29B2688956BD959F933F8",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x2170ed0880ac9a755fd29b2688956bd959f933f8.png"
    },
    {
      "name": "Easy V2",
      "symbol": "EZ",
      "address": "0x5512014efa6Cd57764Fa743756F7a6Ce3358cC83",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x5512014efa6Cd57764Fa743756F7a6Ce3358cC83.png"
    },
    {
      "name": "Filecoin",
      "symbol": "FIL",
      "address": "0x0D8Ce2A99Bb6e3B7Db580eD848240e4a0F9aE153",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x0d8ce2a99bb6e3b7db580ed848240e4a0f9ae153.png"
    },
    {
      "name": "Refinable",
      "symbol": "FINE",
      "address": "0x4e6415a5727ea08aAE4580057187923aeC331227",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x4e6415a5727ea08aae4580057187923aec331227.png"
    },
    {
      "name": "ForTube",
      "symbol": "FOR",
      "address": "0x658A109C5900BC6d2357c87549B651670E5b0539",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x658A109C5900BC6d2357c87549B651670E5b0539.png"
    },
    {
      "name": "Formation Finance",
      "symbol": "FORM",
      "address": "0x25A528af62e56512A19ce8c3cAB427807c28CC19",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x25A528af62e56512A19ce8c3cAB427807c28CC19.png"
    },
    {
      "name": "fry.world",
      "symbol": "FRIES",
      "address": "0x393B312C01048b3ed2720bF1B090084C09e408A1",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x393B312C01048b3ed2720bF1B090084C09e408A1.png"
    },
    {
      "name": "Frontier Token",
      "symbol": "FRONT",
      "address": "0x928e55daB735aa8260AF3cEDadA18B5f70C72f1b",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x928e55daB735aa8260AF3cEDadA18B5f70C72f1b.png"
    },
    {
      "name": "Fuel",
      "symbol": "FUEL",
      "address": "0x2090c8295769791ab7A3CF1CC6e0AA19F35e441A",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x2090c8295769791ab7A3CF1CC6e0AA19F35e441A.png"
    },
    {
      "name": "Gourmet Galaxy",
      "symbol": "GUM",
      "address": "0xc53708664b99DF348dd27C3Ac0759d2DA9c40462",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xc53708664b99DF348dd27C3Ac0759d2DA9c40462.png"
    },
    {
      "name": "Hacken",
      "symbol": "HAI",
      "address": "0xaA9E582e5751d703F85912903bacADdFed26484C",
      "chainId": 56,
      "decimals": 8,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xaA9E582e5751d703F85912903bacADdFed26484C.png"
    },
    {
      "name": "Hakka Finance",
      "symbol": "HAKKA",
      "address": "0x1D1eb8E8293222e1a29d2C0E4cE6C0Acfd89AaaC",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x1d1eb8e8293222e1a29d2c0e4ce6c0acfd89aaac.png"
    },
    {
      "name": "HARD",
      "symbol": "HARD",
      "address": "0xf79037F6f6bE66832DE4E7516be52826BC3cBcc4",
      "chainId": 56,
      "decimals": 6,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xf79037f6f6be66832de4e7516be52826bc3cbcc4.png"
    },
    {
      "name": "Helmet.insure",
      "symbol": "Helmet",
      "address": "0x948d2a81086A075b3130BAc19e4c6DEe1D2E3fE8",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x948d2a81086a075b3130bac19e4c6dee1d2e3fe8.png"
    },
    {
      "name": "MetaHero",
      "symbol": "HERO",
      "address": "0xD40bEDb44C081D2935eebA6eF5a3c8A31A1bBE13",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xD40bEDb44C081D2935eebA6eF5a3c8A31A1bBE13.png"
    },
    {
      "name": "Hedget",
      "symbol": "HGET",
      "address": "0xC7d8D35EBA58a0935ff2D5a33Df105DD9f071731",
      "chainId": 56,
      "decimals": 6,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xC7d8D35EBA58a0935ff2D5a33Df105DD9f071731.png"
    },
    {
      "name": "Hoo",
      "symbol": "HOO",
      "address": "0xE1d1F66215998786110Ba0102ef558b22224C016",
      "chainId": 56,
      "decimals": 8,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xe1d1f66215998786110ba0102ef558b22224c016.png"
    },
    {
      "name": "Hot Cross Token",
      "symbol": "HOTCROSS",
      "address": "0x4FA7163E153419E0E1064e418dd7A99314Ed27b6",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x4FA7163E153419E0E1064e418dd7A99314Ed27b6.png"
    },
    {
      "name": "Hotbit",
      "symbol": "HTB",
      "address": "0x4e840AADD28DA189B9906674B4Afcb77C128d9ea",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x4e840AADD28DA189B9906674B4Afcb77C128d9ea.png"
    },
    {
      "name": "HYFI",
      "symbol": "HYFI",
      "address": "0x9a319b959e33369C5eaA494a770117eE3e585318",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x9a319b959e33369C5eaA494a770117eE3e585318.png"
    },
    {
      "name": "Horizon Protocol",
      "symbol": "HZN",
      "address": "0xC0eFf7749b125444953ef89682201Fb8c6A917CD",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xC0eFf7749b125444953ef89682201Fb8c6A917CD.png"
    },
    {
      "name": "Impossible Finance",
      "symbol": "IF",
      "address": "0xB0e1fc65C1a741b4662B813eB787d369b8614Af1",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xB0e1fc65C1a741b4662B813eB787d369b8614Af1.png"
    },
    {
      "name": "Injective Protocol",
      "symbol": "INJ",
      "address": "0xa2B726B1145A4773F68593CF171187d8EBe4d495",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xa2B726B1145A4773F68593CF171187d8EBe4d495.png"
    },
    {
      "name": "IoTeX",
      "symbol": "IOTX",
      "address": "0x9678E42ceBEb63F23197D726B29b1CB20d0064E5",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x9678e42cebeb63f23197d726b29b1cb20d0064e5.png"
    },
    {
      "name": "Itam",
      "symbol": "ITAM",
      "address": "0x04C747b40Be4D535fC83D09939fb0f626F32800B",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x04c747b40be4d535fc83d09939fb0f626f32800b.png"
    },
    {
      "name": "Juggernaut Finance",
      "symbol": "JGN",
      "address": "0xC13B7a43223BB9Bf4B69BD68Ab20ca1B79d81C75",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xc13b7a43223bb9bf4b69bd68ab20ca1b79d81c75.png"
    },
    {
      "name": "Juventus",
      "symbol": "JUV",
      "address": "0xC40C9A843E1c6D01b7578284a9028854f6683b1B",
      "chainId": 56,
      "decimals": 2,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xc40c9a843e1c6d01b7578284a9028854f6683b1b.png"
    },
    {
      "name": "Kalmar",
      "symbol": "KALM",
      "address": "0x4BA0057f784858a48fe351445C672FF2a3d43515",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x4BA0057f784858a48fe351445C672FF2a3d43515.png"
    },
    {
      "name": "KAVA",
      "symbol": "KAVA",
      "address": "0x5F88AB06e8dfe89DF127B2430Bba4Af600866035",
      "chainId": 56,
      "decimals": 6,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x5F88AB06e8dfe89DF127B2430Bba4Af600866035.png"
    },
    {
      "name": "Kattana",
      "symbol": "KTN",
      "address": "0xDAe6c2A48BFAA66b43815c5548b10800919c993E",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xDAe6c2A48BFAA66b43815c5548b10800919c993E.png"
    },
    {
      "name": "Qian Governance Token",
      "symbol": "KUN",
      "address": "0x1A2fb0Af670D0234c2857FaD35b789F8Cb725584",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x1A2fb0Af670D0234c2857FaD35b789F8Cb725584.png"
    },
    {
      "name": "Lien",
      "symbol": "LIEN",
      "address": "0x5d684ADaf3FcFe9CFb5ceDe3abf02F0Cdd1012E3",
      "chainId": 56,
      "decimals": 8,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x5d684adaf3fcfe9cfb5cede3abf02f0cdd1012e3.png"
    },
    {
      "name": "Linear Finance",
      "symbol": "LINA",
      "address": "0x762539b45A1dCcE3D36d080F74d1AED37844b878",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x762539b45a1dcce3d36d080f74d1aed37844b878.png"
    },
    {
      "name": "ChainLink Token",
      "symbol": "LINK",
      "address": "0xF8A0BF9cF54Bb92F17374d9e9A321E6a111a51bD",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xf8a0bf9cf54bb92f17374d9e9a321e6a111a51bd.png"
    },
    {
      "name": "Litentry",
      "symbol": "LIT",
      "address": "0xb59490aB09A0f526Cc7305822aC65f2Ab12f9723",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xb59490ab09a0f526cc7305822ac65f2ab12f9723.png"
    },
    {
      "name": "Lympo Market Token",
      "symbol": "LMT",
      "address": "0x9617857E191354dbEA0b714d78Bc59e57C411087",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x9617857e191354dbea0b714d78bc59e57c411087.png"
    },
    {
      "name": "Litecoin Token",
      "symbol": "LTC",
      "address": "0x4338665CBB7B2485A8855A139b75D5e34AB0DB94",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x4338665cbb7b2485a8855a139b75d5e34ab0db94.png"
    },
    {
      "name": "LTO Network",
      "symbol": "LTO",
      "address": "0x857B222Fc79e1cBBf8Ca5f78CB133d1b7CF34BBd",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x857b222fc79e1cbbf8ca5f78cb133d1b7cf34bbd.png"
    },
    {
      "name": "lUSD",
      "symbol": "lUSD",
      "address": "0x23e8a70534308a4AAF76fb8C32ec13d17a3BD89e",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x23e8a70534308a4AAF76fb8C32ec13d17a3BD89e.png"
    },
    {
      "name": "Mirror AMZN Token",
      "symbol": "mAMZN",
      "address": "0x3947B992DC0147D2D89dF0392213781b04B25075",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x3947B992DC0147D2D89dF0392213781b04B25075.png"
    },
    {
      "name": "Unmarshal",
      "symbol": "MARSH",
      "address": "0x2FA5dAF6Fe0708fBD63b1A7D1592577284f52256",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x2FA5dAF6Fe0708fBD63b1A7D1592577284f52256.png"
    },
    {
      "name": "Mask Network",
      "symbol": "MASK",
      "address": "0x2eD9a5C8C13b93955103B9a7C167B67Ef4d568a3",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x2eD9a5C8C13b93955103B9a7C167B67Ef4d568a3.png"
    },
    {
      "name": "Math",
      "symbol": "MATH",
      "address": "0xF218184Af829Cf2b0019F8E6F0b2423498a36983",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xf218184af829cf2b0019f8e6f0b2423498a36983.png"
    },
    {
      "name": "Mobox",
      "symbol": "MBOX",
      "address": "0x3203c9E46cA618C8C1cE5dC67e7e9D75f5da2377",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x3203c9E46cA618C8C1cE5dC67e7e9D75f5da2377.png"
    },
    {
      "name": "Mirror COIN",
      "symbol": "mCOIN",
      "address": "0x49022089e78a8D46Ec87A3AF86a1Db6c189aFA6f",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x49022089e78a8D46Ec87A3AF86a1Db6c189aFA6f.png"
    },
    {
      "name": "MacaronSwap",
      "symbol": "MCRN",
      "address": "0xacb2d47827C9813AE26De80965845D80935afd0B",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xacb2d47827C9813AE26De80965845D80935afd0B.png"
    },
    {
      "name": "Mirror GOOGL Token",
      "symbol": "mGOOGL",
      "address": "0x62D71B23bF15218C7d2D7E48DBbD9e9c650B173f",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x62D71B23bF15218C7d2D7E48DBbD9e9c650B173f.png"
    },
    {
      "name": "Mirror Finance",
      "symbol": "MIR",
      "address": "0x5B6DcF557E2aBE2323c48445E8CC948910d8c2c9",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x5b6dcf557e2abe2323c48445e8cc948910d8c2c9.png"
    },
    {
      "name": "Mix",
      "symbol": "MIX",
      "address": "0xB67754f5b4C704A24d2db68e661b2875a4dDD197",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xB67754f5b4C704A24d2db68e661b2875a4dDD197.png"
    },
    {
      "name": "Mirror NFLX Token",
      "symbol": "mNFLX",
      "address": "0xa04F060077D90Fe2647B61e4dA4aD1F97d6649dc",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xa04F060077D90Fe2647B61e4dA4aD1F97d6649dc.png"
    },
    {
      "name": "Meter",
      "symbol": "MTRG",
      "address": "0xBd2949F67DcdC549c6Ebe98696449Fa79D988A9F",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xbd2949f67dcdc549c6ebe98696449fa79d988a9f.png"
    },
    {
      "name": "Mirror TSLA Token",
      "symbol": "mTSLA",
      "address": "0xF215A127A196e3988C09d052e16BcFD365Cd7AA3",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xF215A127A196e3988C09d052e16BcFD365Cd7AA3.png"
    },
    {
      "name": "MX Token",
      "symbol": "MX",
      "address": "0x9F882567A62a5560d147d64871776EeA72Df41D3",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x9F882567A62a5560d147d64871776EeA72Df41D3.png"
    },
    {
      "name": "NAR Token",
      "symbol": "NAR",
      "address": "0xA1303E6199b319a891b79685F0537D289af1FC83",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xa1303e6199b319a891b79685f0537d289af1fc83.png"
    },
    {
      "name": "Nerve Finance",
      "symbol": "NRV",
      "address": "0x42F6f551ae042cBe50C739158b4f0CAC0Edb9096",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x42f6f551ae042cbe50c739158b4f0cac0edb9096.png"
    },
    {
      "name": "Nuls",
      "symbol": "NULS",
      "address": "0x8CD6e29d3686d24d3C2018CEe54621eA0f89313B",
      "chainId": 56,
      "decimals": 8,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x8cd6e29d3686d24d3c2018cee54621ea0f89313b.png"
    },
    {
      "name": "NerveNetwork",
      "symbol": "NVT",
      "address": "0xf0E406c49C63AbF358030A299C0E00118C4C6BA5",
      "chainId": 56,
      "decimals": 8,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xf0e406c49c63abf358030a299c0e00118c4c6ba5.png"
    },
    {
      "name": "Nyanswop Token",
      "symbol": "NYA",
      "address": "0xbFa0841F7a90c4CE6643f651756EE340991F99D5",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xbfa0841f7a90c4ce6643f651756ee340991f99d5.png"
    },
    {
      "name": "O3 Swap",
      "symbol": "O3",
      "address": "0xEe9801669C6138E84bD50dEB500827b776777d28",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xEe9801669C6138E84bD50dEB500827b776777d28.png"
    },
    {
      "name": "Oddz",
      "symbol": "ODDZ",
      "address": "0xCD40F2670CF58720b694968698A5514e924F742d",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xcd40f2670cf58720b694968698a5514e924f742d.png"
    },
    {
      "name": "OG",
      "symbol": "OG",
      "address": "0xf05E45aD22150677a017Fbd94b84fBB63dc9b44c",
      "chainId": 56,
      "decimals": 2,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xf05e45ad22150677a017fbd94b84fbb63dc9b44c.png"
    },
    {
      "name": "Oin Finance",
      "symbol": "OIN",
      "address": "0x658E64FFcF40D240A43D52CA9342140316Ae44fA",
      "chainId": 56,
      "decimals": 8,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x658E64FFcF40D240A43D52CA9342140316Ae44fA.png"
    },
    {
      "name": "Harmony One",
      "symbol": "ONE",
      "address": "0x03fF0ff224f904be3118461335064bB48Df47938",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x03ff0ff224f904be3118461335064bb48df47938.png"
    },
    {
      "name": "BigOne Token",
      "symbol": "ONE",
      "address": "0x04BAf95Fd4C52fd09a56D840bAEe0AB8D7357bf0",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x04BAf95Fd4C52fd09a56D840bAEe0AB8D7357bf0.png"
    },
    {
      "name": "Ontology Token",
      "symbol": "ONT",
      "address": "0xFd7B3A77848f1C2D67E05E54d78d174a0C850335",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xfd7b3a77848f1c2d67e05e54d78d174a0c850335.png"
    },
    {
      "name": "The Orbs Network",
      "symbol": "ORBS",
      "address": "0xeBd49b26169e1b52c04cFd19FCf289405dF55F80",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xeBd49b26169e1b52c04cFd19FCf289405dF55F80.png"
    },
    {
      "name": "pBTC",
      "symbol": "pBTC",
      "address": "0xeD28A457A5A76596ac48d87C0f577020F6Ea1c4C",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xed28a457a5a76596ac48d87c0f577020f6ea1c4c.png"
    },
    {
      "name": "PolyCrowns",
      "symbol": "pCWS",
      "address": "0xbcf39F0EDDa668C58371E519AF37CA705f2bFcbd",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xbcf39f0edda668c58371e519af37ca705f2bfcbd.png"
    },
    {
      "name": "Perlin X",
      "symbol": "PERL",
      "address": "0x0F9E4D49f25de22c2202aF916B681FBB3790497B",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x0f9e4d49f25de22c2202af916b681fbb3790497b.png"
    },
    {
      "name": "Polkamon",
      "symbol": "PMON",
      "address": "0x1796ae0b0fa4862485106a0de9b654eFE301D0b2",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x1796ae0b0fa4862485106a0de9b654eFE301D0b2.png"
    },
    {
      "name": "PNT",
      "symbol": "PNT",
      "address": "0xdaacB0Ab6Fb34d24E8a67BfA14BF4D95D4C7aF92",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xdaacb0ab6fb34d24e8a67bfa14bf4d95d4c7af92.png"
    },
    {
      "name": "pTokens OPEN",
      "symbol": "pOPEN",
      "address": "0xaBaE871B7E3b67aEeC6B46AE9FE1A91660AadAC5",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xaBaE871B7E3b67aEeC6B46AE9FE1A91660AadAC5.png"
    },
    {
      "name": "Moonpot",
      "symbol": "POTS",
      "address": "0x3Fcca8648651E5b974DD6d3e50F61567779772A8",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x3Fcca8648651E5b974DD6d3e50F61567779772A8.png"
    },
    {
      "name": "Prometeus",
      "symbol": "PROM",
      "address": "0xaF53d56ff99f1322515E54FdDE93FF8b3b7DAFd5",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xaf53d56ff99f1322515e54fdde93ff8b3b7dafd5.png"
    },
    {
      "name": "Paris Saint-Germain",
      "symbol": "PSG",
      "address": "0xBc5609612b7C44BEf426De600B5fd1379DB2EcF1",
      "chainId": 56,
      "decimals": 2,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xbc5609612b7c44bef426de600b5fd1379db2ecf1.png"
    },
    {
      "name": "QuarkChain Token",
      "symbol": "QKC",
      "address": "0xA1434F1FC3F437fa33F7a781E041961C0205B5Da",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xA1434F1FC3F437fa33F7a781E041961C0205B5Da.png"
    },
    {
      "name": "QIAN second generation dollar",
      "symbol": "QSD",
      "address": "0x07AaA29E63FFEB2EBf59B33eE61437E1a91A3bb2",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x07aaa29e63ffeb2ebf59b33ee61437e1a91a3bb2.png"
    },
    {
      "name": "QUSD Stablecoin",
      "symbol": "QUSD",
      "address": "0xb8C540d00dd0Bf76ea12E4B4B95eFC90804f924E",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xb8C540d00dd0Bf76ea12E4B4B95eFC90804f924E.png"
    },
    {
      "name": "Rabbit Finance",
      "symbol": "RABBIT",
      "address": "0x95a1199EBA84ac5f19546519e287d43D2F0E1b41",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x95a1199EBA84ac5f19546519e287d43D2F0E1b41.png"
    },
    {
      "name": "Ramp DEFI",
      "symbol": "RAMP",
      "address": "0x8519EA49c997f50cefFa444d240fB655e89248Aa",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x8519ea49c997f50ceffa444d240fb655e89248aa.png"
    },
    {
      "name": "Reef",
      "symbol": "REEF",
      "address": "0xF21768cCBC73Ea5B6fd3C687208a7c2def2d966e",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xf21768ccbc73ea5b6fd3c687208a7c2def2d966e.png"
    },
    {
      "name": "renBTC",
      "symbol": "renBTC",
      "address": "0xfCe146bF3146100cfe5dB4129cf6C82b0eF4Ad8c",
      "chainId": 56,
      "decimals": 8,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xfCe146bF3146100cfe5dB4129cf6C82b0eF4Ad8c.png"
    },
    {
      "name": "renDOGE",
      "symbol": "renDOGE",
      "address": "0xc3fEd6eB39178A541D274e6Fc748d48f0Ca01CC3",
      "chainId": 56,
      "decimals": 8,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xc3fed6eb39178a541d274e6fc748d48f0ca01cc3.png"
    },
    {
      "name": "renZEC",
      "symbol": "renZEC",
      "address": "0x695FD30aF473F2960e81Dc9bA7cB67679d35EDb7",
      "chainId": 56,
      "decimals": 8,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x695FD30aF473F2960e81Dc9bA7cB67679d35EDb7.png"
    },
    {
      "name": "REVV",
      "symbol": "REVV",
      "address": "0x833F307aC507D47309fD8CDD1F835BeF8D702a93",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x833F307aC507D47309fD8CDD1F835BeF8D702a93.png"
    },
    {
      "name": "RFOX",
      "symbol": "RFOX",
      "address": "0x0a3A21356793B49154Fd3BbE91CBc2A16c0457f5",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x0a3a21356793b49154fd3bbe91cbc2a16c0457f5.png"
    },
    {
      "name": "SafeMoon",
      "symbol": "SAFEMOON",
      "address": "0x8076C74C5e3F5852037F31Ff0093Eeb8c8ADd8D3",
      "chainId": 56,
      "decimals": 9,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x8076c74c5e3f5852037f31ff0093eeb8c8add8d3.png"
    },
    {
      "name": "bDollar Share",
      "symbol": "sBDO",
      "address": "0x0d9319565be7f53CeFE84Ad201Be3f40feAE2740",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x0d9319565be7f53CeFE84Ad201Be3f40feAE2740.png"
    },
    {
      "name": "SafePal Token",
      "symbol": "SFP",
      "address": "0xD41FDb03Ba84762dD66a0af1a6C8540FF1ba5dfb",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xd41fdb03ba84762dd66a0af1a6c8540ff1ba5dfb.png"
    },
    {
      "name": "CryptoBlades Skill Token",
      "symbol": "SKILL",
      "address": "0x154A9F9cbd3449AD22FDaE23044319D6eF2a1Fab",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x154A9F9cbd3449AD22FDaE23044319D6eF2a1Fab.png"
    },
    {
      "name": "SPARTAN PROTOCOL TOKEN",
      "symbol": "SPARTA",
      "address": "0xE4Ae305ebE1AbE663f261Bc00534067C80ad677C",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xe4ae305ebe1abe663f261bc00534067c80ad677c.png"
    },
    {
      "name": "Splintershards",
      "symbol": "SPS",
      "address": "0x1633b7157e7638C4d6593436111Bf125Ee74703F",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x1633b7157e7638C4d6593436111Bf125Ee74703F.png"
    },
    {
      "name": "StableXSwap",
      "symbol": "STAX",
      "address": "0x0Da6Ed8B13214Ff28e9Ca979Dd37439e8a88F6c4",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x0da6ed8b13214ff28e9ca979dd37439e8a88f6c4.png"
    },
    {
      "name": "Sushi",
      "symbol": "SUSHI",
      "address": "0x947950BcC74888a40Ffa2593C5798F11Fc9124C4",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x947950bcc74888a40ffa2593c5798f11fc9124c4.png"
    },
    {
      "name": "Suterusu",
      "symbol": "SUTER",
      "address": "0x4CfbBdfBd5BF0814472fF35C72717Bd095ADa055",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x4cfbbdfbd5bf0814472ff35c72717bd095ada055.png"
    },
    {
      "name": "Swampy",
      "symbol": "SWAMP",
      "address": "0xc5A49b4CBe004b6FD55B30Ba1dE6AC360FF9765d",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xc5a49b4cbe004b6fd55b30ba1de6ac360ff9765d.png"
    },
    {
      "name": "SWGToken",
      "symbol": "SWG",
      "address": "0xe792f64C582698b8572AAF765bDC426AC3aEfb6B",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xe792f64c582698b8572aaf765bdc426ac3aefb6b.png"
    },
    {
      "name": "Swingby",
      "symbol": "SWINGBY",
      "address": "0x71DE20e0C4616E7fcBfDD3f875d568492cBE4739",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x71DE20e0C4616E7fcBfDD3f875d568492cBE4739.png"
    },
    {
      "name": "Switcheo",
      "symbol": "SWTH",
      "address": "0x250b211EE44459dAd5Cd3bCa803dD6a7EcB5d46C",
      "chainId": 56,
      "decimals": 8,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x250b211EE44459dAd5Cd3bCa803dD6a7EcB5d46C.png"
    },
    {
      "name": "Swipe",
      "symbol": "SXP",
      "address": "0x47BEAd2563dCBf3bF2c9407fEa4dC236fAbA485A",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x47bead2563dcbf3bf2c9407fea4dc236faba485a.png"
    },
    {
      "name": "Tau Bitcoin",
      "symbol": "tBTC",
      "address": "0x2cD1075682b0FCCaADd0Ca629e138E64015Ba11c",
      "chainId": 56,
      "decimals": 9,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x2cD1075682b0FCCaADd0Ca629e138E64015Ba11c.png"
    },
    {
      "name": "Tau DOGE",
      "symbol": "tDOGE",
      "address": "0xe550a593d09FBC8DCD557b5C88Cea6946A8b404A",
      "chainId": 56,
      "decimals": 8,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xe550a593d09fbc8dcd557b5c88cea6946a8b404a.png"
    },
    {
      "name": "Tenet",
      "symbol": "TEN",
      "address": "0xdFF8cb622790b7F92686c722b02CaB55592f152C",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xdff8cb622790b7f92686c722b02cab55592f152c.png"
    },
    {
      "name": "TitanSwap",
      "symbol": "TITAN",
      "address": "0xe898EDc43920F357A93083F1d4460437dE6dAeC2",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xe898EDc43920F357A93083F1d4460437dE6dAeC2.png"
    },
    {
      "name": "TokoCrypto",
      "symbol": "TKO",
      "address": "0x9f589e3eabe42ebC94A44727b3f3531C0c877809",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x9f589e3eabe42ebc94a44727b3f3531c0c877809.png"
    },
    {
      "name": "Alien Worlds",
      "symbol": "TLM",
      "address": "0x2222227E22102Fe3322098e4CBfE18cFebD57c95",
      "chainId": 56,
      "decimals": 4,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x2222227e22102fe3322098e4cbfe18cfebd57c95.png"
    },
    {
      "name": "TokenPocket",
      "symbol": "TPT",
      "address": "0xECa41281c24451168a37211F0bc2b8645AF45092",
      "chainId": 56,
      "decimals": 4,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xeca41281c24451168a37211f0bc2b8645af45092.png"
    },
    {
      "name": "Unitrade",
      "symbol": "TRADE",
      "address": "0x7af173F350D916358AF3e218Bdf2178494Beb748",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x7af173f350d916358af3e218bdf2178494beb748.png"
    },
    {
      "name": "Tron",
      "symbol": "TRX",
      "address": "0x85EAC5Ac2F758618dFa09bDbe0cf174e7d574D5B",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x85eac5ac2f758618dfa09bdbe0cf174e7d574d5b.png"
    },
    {
      "name": "True USD",
      "symbol": "TUSD",
      "address": "0x14016E85a25aeb13065688cAFB43044C2ef86784",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x14016e85a25aeb13065688cafb43044c2ef86784.png"
    },
    {
      "name": "Trust Wallet",
      "symbol": "TWT",
      "address": "0x4B0F1812e5Df2A09796481Ff14017e6005508003",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x4b0f1812e5df2a09796481ff14017e6005508003.png"
    },
    {
      "name": "Tixl",
      "symbol": "TXL",
      "address": "0x1FFD0b47127fdd4097E54521C9E2c7f0D66AafC5",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x1ffd0b47127fdd4097e54521c9e2c7f0d66aafc5.png"
    },
    {
      "name": "UpBots",
      "symbol": "UBXT",
      "address": "0xBbEB90cFb6FAFa1F69AA130B7341089AbeEF5811",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xbbeb90cfb6fafa1f69aa130b7341089abeef5811.png"
    },
    {
      "name": "Unifi Token",
      "symbol": "UNFI",
      "address": "0x728C5baC3C3e370E372Fc4671f9ef6916b814d8B",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x728C5baC3C3e370E372Fc4671f9ef6916b814d8B.png"
    },
    {
      "name": "Uniswap",
      "symbol": "UNI",
      "address": "0xBf5140A22578168FD562DCcF235E5D43A02ce9B1",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xbf5140a22578168fd562dccf235e5d43a02ce9b1.png"
    },
    {
      "name": "Binance Pegged USD Coin",
      "symbol": "USDC",
      "address": "0x8AC76a51cc950d9822D68b83fE1Ad97B32Cd580d",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x8ac76a51cc950d9822d68b83fe1ad97b32cd580d.png"
    },
    {
      "name": "Binance Pegged USDT",
      "symbol": "USDT",
      "address": "0x55d398326f99059fF775485246999027B3197955",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x55d398326f99059ff775485246999027b3197955.png"
    },
    {
      "name": "USDX",
      "symbol": "USDX",
      "address": "0x1203355742e76875154C0D13eB81DCD7711dC7d9",
      "chainId": 56,
      "decimals": 6,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x1203355742e76875154c0d13eb81dcd7711dc7d9.png"
    },
    {
      "name": "UST Token",
      "symbol": "UST",
      "address": "0x23396cF899Ca06c4472205fC903bDB4de249D6fC",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x23396cF899Ca06c4472205fC903bDB4de249D6fC.png"
    },
    {
      "name": "VAI Stablecoin",
      "symbol": "VAI",
      "address": "0x4BD17003473389A42DAF6a0a729f6Fdb328BbBd7",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x4bd17003473389a42daf6a0a729f6fdb328bbbd7.png"
    },
    {
      "name": "Venus Reward Token",
      "symbol": "VRT",
      "address": "0x5F84ce30DC3cF7909101C69086c50De191895883",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x5F84ce30DC3cF7909101C69086c50De191895883.png"
    },
    {
      "name": "Yieldwatch",
      "symbol": "WATCH",
      "address": "0x7A9f28EB62C791422Aa23CeAE1dA9C847cBeC9b0",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x7a9f28eb62c791422aa23ceae1da9c847cbec9b0.png"
    },
    {
      "name": "Wault",
      "symbol": "WAULTx",
      "address": "0xB64E638E60D154B43f660a6BF8fD8a3b249a6a21",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xB64E638E60D154B43f660a6BF8fD8a3b249a6a21.png"
    },
    {
      "name": "WBNB Token",
      "symbol": "WBNB",
      "address": "0xbb4CdB9CBd36B01bD1cBaEBF2De08d9173bc095c",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xbb4cdb9cbd36b01bd1cbaebf2de08d9173bc095c.png"
    },
    {
      "name": "BitWell Token",
      "symbol": "WELL",
      "address": "0xf07a32Eb035b786898c00bB1C64d8c6F8E7a46D5",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xf07a32Eb035b786898c00bB1C64d8c6F8E7a46D5.png"
    },
    {
      "name": "WaultSwap",
      "symbol": "WEX",
      "address": "0xa9c41A46a6B3531d28d5c32F6633dd2fF05dFB90",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xa9c41A46a6B3531d28d5c32F6633dd2fF05dFB90.png"
    },
    {
      "name": "WINk",
      "symbol": "WIN",
      "address": "0xaeF0d72a118ce24feE3cD1d43d383897D05B4e99",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xaef0d72a118ce24fee3cd1d43d383897d05b4e99.png"
    },
    {
      "name": "Wrapped MASS",
      "symbol": "WMASS",
      "address": "0x7e396BfC8a2f84748701167c2d622F041A1D7a17",
      "chainId": 56,
      "decimals": 8,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x7e396bfc8a2f84748701167c2d622f041a1d7a17.png"
    },
    {
      "name": "Wootrade",
      "symbol": "WOO",
      "address": "0x4691937a7508860F876c9c0a2a617E7d9E945D4B",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x4691937a7508860F876c9c0a2a617E7d9E945D4B.png"
    },
    {
      "name": "Wall Street Games",
      "symbol": "WSG",
      "address": "0xA58950F05FeA2277d2608748412bf9F802eA4901",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xA58950F05FeA2277d2608748412bf9F802eA4901.png"
    },
    {
      "name": "Soteria",
      "symbol": "wSOTE",
      "address": "0x541E619858737031A1244A5d0Cd47E5ef480342c",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x541e619858737031a1244a5d0cd47e5ef480342c.png"
    },
    {
      "name": "Xcademy",
      "symbol": "XCAD",
      "address": "0x431e0cD023a32532BF3969CddFc002c00E98429d",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x431e0cd023a32532bf3969cddfc002c00e98429d.png"
    },
    {
      "name": "Exeedme",
      "symbol": "XED",
      "address": "0x5621b5A3f4a8008c4CCDd1b942B121c8B1944F1f",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x5621b5a3f4a8008c4ccdd1b942b121c8b1944f1f.png"
    },
    {
      "name": "XEND",
      "symbol": "XEND",
      "address": "0x4a080377f83D669D7bB83B3184a8A5E61B500608",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x4a080377f83D669D7bB83B3184a8A5E61B500608.png"
    },
    {
      "name": "xMARK",
      "symbol": "xMARK",
      "address": "0x26A5dFab467d4f58fB266648CAe769503CEC9580",
      "chainId": 56,
      "decimals": 9,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x26a5dfab467d4f58fb266648cae769503cec9580.png"
    },
    {
      "name": "XRP Token",
      "symbol": "XRP",
      "address": "0x1D2F0da169ceB9fC7B3144628dB156f3F6c60dBE",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x1d2f0da169ceb9fc7b3144628db156f3f6c60dbe.png"
    },
    {
      "name": "Tezos Token",
      "symbol": "XTZ",
      "address": "0x16939ef78684453bfDFb47825F8a5F714f12623a",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x16939ef78684453bfdfb47825f8a5f714f12623a.png"
    },
    {
      "name": "Venus Token",
      "symbol": "XVS",
      "address": "0xcF6BB5389c92Bdda8a3747Ddb454cB7a64626C63",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xcf6bb5389c92bdda8a3747ddb454cb7a64626c63.png"
    },
    {
      "name": "yearn.finance",
      "symbol": "YFI",
      "address": "0x88f1A5ae2A3BF98AEAF342D26B30a79438c9142e",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x88f1a5ae2a3bf98aeaf342d26b30a79438c9142e.png"
    },
    {
      "name": "YFII.finance Token",
      "symbol": "YFII",
      "address": "0x7F70642d88cf1C4a3a7abb072B53B929b653edA5",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x7f70642d88cf1c4a3a7abb072b53b929b653eda5.png"
    },
    {
      "name": "Zcash Token",
      "symbol": "ZEC",
      "address": "0x1Ba42e5193dfA8B03D15dd1B86a3113bbBEF8Eeb",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x1ba42e5193dfa8b03d15dd1b86a3113bbbef8eeb.png"
    },
    {
      "name": "ZeroSwapToken",
      "symbol": "ZEE",
      "address": "0x44754455564474A89358B2C2265883DF993b12F0",
      "chainId": 56,
      "decimals": 18,
      "logoURI": "https://tokens.pancakeswap.finance/images/0x44754455564474a89358b2c2265883df993b12f0.png"
    },
    {
      "name": "Zilliqa",
      "symbol": "ZIL",
      "address": "0xb86AbCb37C3A4B64f74f59301AFF131a1BEcC787",
      "chainId": 56,
      "decimals": 12,
      "logoURI": "https://tokens.pancakeswap.finance/images/0xb86abcb37c3a4b64f74f59301aff131a1becc787.png"
    }]
bsc_sample_call = {
  "status": "pending",
  "monitorId": "GETH_56_D_PROD",
  "monitorVersion": "0.97.0",
  "pendingTimeStamp": "2021-08-17T18:50:32.553Z",
  "pendingBlockNumber": 10115468,
  "hash": "0x2dbd84a35b65b0fdfc0cf9ddd03d3dc466ce1cc0b333972adce09acb9b4d2e9d", # TXN Hash
  "from": "0xcA04D4c8805691Ca251Af3bc751429Ab884630d3", # Buyer
  "to": "0x10ED43C718714eb63d5aA57B78B54704E256024E", # Exchange Or Another Address
  "value": "0",
  "gas": 181087,
  "nonce": 78,
  "blockHash": None,
  "blockNumber": None,
  "v": "0x93",
  "r": "0x9b2bc65623829840825d047eafe9b4cd8e710ed32b2e670b3a4da9eed2386ae5",
  "s": "0x25ebf7936efe2f711296a6be6937df3a3f82e55245b26ce91a57d04bad7a8829",
  "input": "0x18cbafe50000000000000000000000000000000000000000001bd685dd559af911ea75e50000000000000000000000000000000000000000000000000034cea970200fde00000000000000000000000000000000000000000000000000000000000000a0000000000000000000000000ca04d4c8805691ca251af3bc751429ab884630d300000000000000000000000000000000000000000000000000000000611c060b0000000000000000000000000000000000000000000000000000000000000002000000000000000000000000bceee918077f63fb1b9e10403f59ca40c7061341000000000000000000000000bb4cdb9cbd36b01bd1cbaebf2de08d9173bc095c",
  "gasPrice": "5000000000",
  "gasPriceGwei": 5,
  "type": 0,
  "asset": "",
  "watchedAddress": "0x10ed43c718714eb63d5aa57b78b54704e256024e", # Exchange Or Another Address
  "direction": "incoming",
  "counterparty": "0xcA04D4c8805691Ca251Af3bc751429Ab884630d3", # Buyer
  "serverVersion": "0.119.1",
  "eventCode": "txPool",
  "timeStamp": "2021-08-17T18:50:32.548Z",
  "system": "ethereum",
  "network": "bsc-main",
  "contractCall": {
    "contractType": "Uniswap V2: Router 2",
    "contractAddress": "0x10ED43C718714eb63d5aA57B78B54704E256024E",
    "methodName": "swapExactTokensForETH",
    "params": {
      "amountIn": "33654052922714945103754725", # Value*1e-18 = 33,654,052.922714945103754725
      "amountOutMin": "14863925914898398", # value*1e-18 =  0.01493824554447289
      "path": [
        "0xbCeeE918077F63fB1B9e10403F59cA40C7061341", # Incoming Token
        "0xbb4CdB9CBd36B01bD1cBaEBF2De08d9173bc095c" # Outgoing Token
      ],
      "to": "0xcA04D4c8805691Ca251Af3bc751429Ab884630d3",
      "deadline": "1629226507"
    },
    "contractName": "PancakeSwap: Router v2"
  }}
