# Truncate filename
FILE=$(basename ${URL})

# Set download directory
DEST=~/Downloads/$FILE

echo "Downloading idea-I$ed-$VERSION to $DEST..."

# Download binary
wget -cO ${DEST} ${URL} --read-timeout=5 --tries=0

echo "Download complete!"

# Set directory name
DIR="/opt/idea-I$ed-$VERSION"

echo "Installing to $DIR"

# Untar file
if mkdir ${DIR}; then
    tar -xzf ${DEST} -C ${DIR} --strip-components=1
fi

# Grab executable folder
BIN="$DIR/bin"

# Add permissions to install directory
chmod -R +rwx ${DIR}

# Set desktop shortcut path
DESK=/usr/share/applications/IDEA.desktop

# Add desktop shortcut
echo "[Desktop Entry]\nEncoding=UTF-8\nName=IntelliJ IDEA\nComment=IntelliJ IDEA\nExec=${BIN}/idea.sh\nIcon=${BIN}/idea.png\nTerminal=false\nStartupNotify=true\nType=Application" -e > ${DESK}

# Create symlink entry
ln -s ${BIN}/idea.sh /usr/local/bin/idea

echo "Done."  