export DEBIAN_FRONTEND=noninteractive
apt update&&apt install -y python3 g++ xclip vim vim-gtk3
cat .bashrc >>~/.bashrc
cp .vimrc ~/.vimrc
