#!/usr/bin/bash

echo "Viks Smart Contracts"
if [ -d vik/ ]; then x=$(ls vik/); fi;
for i in ${x}; do cp vik/$i/*.sol @charms/d.sol; done
ls @charms/d.sol