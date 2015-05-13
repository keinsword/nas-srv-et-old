/*
 * errors.h
 *
 *  Created on: Apr 19, 2015
 *      Author: keinsword
 */

#ifndef ERRORS_H_
#define ERRORS_H_

#define INCORRECT_ARGS -1
#define SOCKET_ERR -2
#define FD_BLOCKING_ERR -3
#define SET_SOCK_OPT_ERR -4
#define BIND_ERR -5
#define LISTEN_ERR -6
#define ACCEPT_ERR -7
#define NO_MORE_PLACE -8
#define IDENTIFY_ERR -9
#define READ_ERR -10
#define CHECKSUM_ERR -11
#define SERVICE_ERR -12
#define SEND_ERR -13
#define CONNECT_ERR -14
#define HOST_IS_OFFLINE -15
#define PART_SEND_ERR -16
#define EXITPR -17
#define CONFIG_ERR -18
#define CONNECT_OF_ERR -19
#define PART_READ_ERR -20
#define INVALID_SIGNATURE -21

#define READ_AGAIN 1
#define CLIENT_IS_OFFLINE 2

typedef struct {
	short errCode;
	char *errDesc;
	short isCritical;
}error;

extern error errTable[20];

void handleErr(short errCode);

#endif /* ERRORS_H_ */
