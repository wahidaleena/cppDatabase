#!/bin/sh

./environment

export APPLIC_NAME = whse_rcpt.exec
export DIR_PATH = ./

export APP_EXEC = ${DIR_PATH}${APPLIC_NAME}


wget -c ftp://$user_name:@password@$HOST/$filename

time ${APP_EXEC}

echo "DONE"