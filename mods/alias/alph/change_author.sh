#!/bin/bash


if [ ! -z $1 ]; then _name=$1; else _name="."; fi

echo $_name
if [ ! -d $_name/git ]; then echo "no git dir @${_name}\n"; else \
git -C $_name rebase -r --root --exec "git commit --amend --no-edit --reset-author"; \
fi