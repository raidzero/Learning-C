#!/bin/sh

NAME="$1"
echo "What is your name? "
if [ ! -z "$NAME" ]; then
	echo "You already told me your name, $NAME! Are you trying to confuse me?"
elif [ -z "$NAME" ]; then
	read NAME
	echo "Nice to meet you, $NAME"
fi

