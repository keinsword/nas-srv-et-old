#!/bin/bash

gcc -g3 nas-srv-et-app/server-app/server.c \
nas-srv-et-app/server-app/servFunctions.c \
nas-srv-et-lib/src/commonFunctions.c \
nas-srv-et-lib/src/crc.c \
nas-srv-et-lib/src/protocol.c \
nas-srv-et-lib/src/errors.c \
-lconfig -o server

gcc -g3 nas-srv-et-app/client-app/client.c \
nas-srv-et-app/client-app/clientFunctions.c \
nas-srv-et-lib/src/commonFunctions.c \
nas-srv-et-lib/src/crc.c \
nas-srv-et-lib/src/protocol.c \
nas-srv-et-lib/src/errors.c \
-o client
