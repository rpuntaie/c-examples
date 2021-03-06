#!/usr/bin/env bash

: '
bash tryall.sh
'

for d in */; do
    mkdir -p ../_build/$d
done
for d in */; do
for f in $d*.c*; do
    cmpl="$(grep -e"^g++ " $f)"
    if [[ -z "$cmpl" ]]; then
        cmpl="$(grep -e"^gcc " $f)"
        if [[ -z "$cmpl" ]]; then
            cmpl="$(grep -e"^clang " $f)"
        fi
    fi
    if [[ -n "$cmpl" ]]; then
        printf "$f"  && bash -c "$cmpl" &> /dev/null && printf "\n"  || printf " failed\n"
    fi
done
done
