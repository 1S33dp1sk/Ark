#!/bin/bash


## accounts for testing
# 1)
# pub :: 0xf39fd6e51aad88f6f4ce6ab8827279cfffb92266
# pvt :: 0xac0974bec39a17e36ba4a6b4d238ff944bacb478cbed5efcae784d7bf4f2ff80
# 2)
# pub :: 0x70997970c51812dc3a010c7d01b50e0d17dc79c8
# pvt :: 0x59c6995e998f97a5a0044966f0945389dc9e86dae88c7a8412f4603b6b78690d
# 3)
# pub :: 0x3c44cdddb6a900fa2b585dd299e03d12fa4293bc
# pvt :: 0x5de4111afa1a4b94908f83103eb1f1706367c2e68ca870fc3fb9a804cdab365a


case $1 in 
	deploy)
		npx hardhat run scripts/initial.ts --network cid4321
		npx hardhat run scripts/initial.ts --network cid1234
		;;
	receiver)
		npx hardhat run scripts/secondary.ts --network cid1234
		;;
	call)
		npx hardhat run scripts/aether_call.ts --network cid1234
		;;
	mine)
		npx hardhat run scripts/aether_mine.ts --network cid1234
		;;
	start)
		gnome-terminal --window --title "EVM CID#1234" -- ganache-cli --p 1234 -l 10000000 --account "0xac0974bec39a17e36ba4a6b4d238ff944bacb478cbed5efcae784d7bf4f2ff80,100000000000000000000" --account "0x7c852118294e51e653712a81e05800f419141751be58f605c371e15141b007a6,100000000000000000000"
		gnome-terminal --window --title "EVM CID#4321" -- ganache-cli --p 4321 -l 10000000 --account "0xac0974bec39a17e36ba4a6b4d238ff944bacb478cbed5efcae784d7bf4f2ff80,100000000000000000000" --account "0x7c852118294e51e653712a81e05800f419141751be58f605c371e15141b007a6,100000000000000000000"
		;;
	silent-start)
		gnome-terminal --window --title "EVM CID#1234" -- ganache-cli --p 1234 -l 10000000 --account "0xac0974bec39a17e36ba4a6b4d238ff944bacb478cbed5efcae784d7bf4f2ff80,100000000000000000000" --account "0x7c852118294e51e653712a81e05800f419141751be58f605c371e15141b007a6,100000000000000000000" &>/dev/null & disown
		gnome-terminal --window --title "EVM CID#4321" -- ganache-cli --p 4321 -l 10000000 --account "0xac0974bec39a17e36ba4a6b4d238ff944bacb478cbed5efcae784d7bf4f2ff80,100000000000000000000" --account "0x7c852118294e51e653712a81e05800f419141751be58f605c371e15141b007a6,100000000000000000000" &>/dev/null & disown
		;;
	compile)
		npx hardhat compile
		;;
	test)
		npx hardhat test
		;;
	status)
		PVAR=$(pgrep -f ganache)
		if [[ -z "$PVAR" ]]; then
			printf "OFFLINE\n"
		else
			printf "ONLINE\n"
		fi
		;;
	kill)
		PVAR=$(pgrep -f ganache)
		kill -9 ${PVAR} &>/dev/null
		;;
	hub)
		printf "\n 0xAetherHub on ChainId : 1234\n"
		npx hardhat run scripts/hub_details.ts --network cid1234
		printf "\n 0xAetherHub on ChainId : 4321\n"
		npx hardhat run scripts/hub_details.ts --network cid4321
		;;
	*)
		printf "\n No such command \n"
		;;
esac























