#!/bin/bash
echo "Esse script precisa ser executado como sudo."

APP_NAME="repository_init"
INSTALL_DIR="/usr/share/$APP_NAME"
BIN_DIR="/usr/bin"
FILES_PYTHON="create_py"

echo "installing repository launcher $APP_NAME..."

make
make run

mkdir -p $INSTALL_DIR

cp -r $FILES_PYTHON $INSTALL_DIR

cp $APP_NAME $BIN_DIR/
chmod +x $BIN_DIR/$APP_NAME

repository_init -help

