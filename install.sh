#!/bin/bash

set -e

OS="$(uname -s)"

case "$OS" in
    Linux*) PLATFORM="linux-latest" ;;
    Darwin*)    PLATFORM="macos-latest" ;;
    *)

    echo "Error: unsupported OS ($OS)."
    exit 1
    ;;

esac

echo "Detected platform: $PLATFORM"

REPO="Nahida4479/MarkupCLI"
LATEST_TAG=$(curl -s "https://api.github.com/repos/$REPO/releases/latest" | grep '"tag_name":' | cut -d '"' -f4)

if [ -z "$LATEST_TAG" ]; then
    echo "Error: could not determine the latest version."
    exit 1

fi 

VERSION_FILE="/usr/local/bin/.markupcli_version"

if [ -f "$VERSION_FILE" ]; then
    INSTALLED_VERSION=$(cat "$VERSION_FILE")
    if [ "$INSTALLED_VERSION" == "$LATEST_TAG" ]; then
    echo "MarkupCLI++ $LATEST_TAG is up to date. Nothing to do."
    exit 0
fi
echo "Updating from $INSTALLED_VERSION to $LATEST_TAG..."
fi


echo "Latest version: $LATEST_TAG"

BINARY_NAME="MarkupCLI++-$PLATFORM"
DOWNLOAD_URL="https://github.com/$REPO/releases/download/$LATEST_TAG/$BINARY_NAME"

echo "Downloading from: $DOWNLOAD_URL"

curl --progress-bar -f -L -o MarkupCLI++ "$DOWNLOAD_URL"

chmod +x MarkupCLI++

sudo mv MarkupCLI++ /usr/local/bin/MarkupCLI++
echo "$LATEST_TAG" | sudo tee /usr/local/bin/.markupcli_version > /dev/null

echo "MarkupCLI++ $LATEST_TAG installed successfully"
