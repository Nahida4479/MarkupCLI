#!/bin/bash

set -e

OS="$(uname -s)"

case "$OS" in
    Linux*) PLATFORM="ubuntu-latest" ;;
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

echo "Latest version: $LATEST_TAG"

BINARY_NAME="MarkupCLI++-$PLATFORM-latest"
DOWNLOAD_URL="https://github.com/$REPO/releases/download/$LATEST_TAG/$BINARY_NAME"

echo "Downloading from: $DOWNLOAD_URL"

curl -sSL -o MarkupCLI++ "$DOWNLOAD_URL"

chmod +x MarkupCLI++

sudo mv MarkupCLI++ /usr/local/bin/MarkupCLI++

echo "MarkupCLI++ $LATEST_TAG installed successfully"

