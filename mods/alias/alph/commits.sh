#!/bin/bash

_base="temp"

if [ ! $0 ]; then _base=$0; fi

if [ -d .git ]; then _git=$(pwd); 
else 
	if [ -d .@ ]; then _git="$(pwd)/.@"; fi
fi

git -C $_git log > $_base
cat $_base | grep commit
