#!/bin/bash

git clone git@github.com:mks65/"$1".git
cd ./"$1"/4
git submodule add -b "$1" git@github.com:meowzebub/systems.git sikderShu
git add .
git commit -m "added submodule"
git push
cd ../../
rm -rf "$1"
