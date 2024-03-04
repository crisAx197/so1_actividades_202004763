#!/bin/bash

PIPE1="/tmp/pipe1"
PIPE2="/tmp/pipe2"

[ ! -p $PIPE1 ] && mkfifo $PIPE1
[ ! -p $PIPE2 ] && mkfifo $PIPE2

send_message() {
    local pipe=$1
    local message=$2
    echo "$message" > $pipe
}

receive_message() {
    local pipe=$1
    local message
    if read -t 0 <$pipe; then
        read message <$pipe
        echo $message
    fi
}

chat() {
    local pipe_in=$1
    local pipe_out=$2
    local name=$3
    while true; do
        read -p "[$name]: " message
        send_message $pipe_out "[$name]: $message"
        if [[ "$message" == "exit" ]]; then
            break
        fi
        received_message=$(receive_message $pipe_in)
        if [ -n "$received_message" ]; then
            echo "$received_message"
        fi
    done
}

chat $PIPE1 $PIPE2 "User1" &
chat $PIPE2 $PIPE1 "User2"

rm -f $PIPE1
rm -f $PIPE2
