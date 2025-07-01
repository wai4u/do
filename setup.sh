export DEBIAN_FRONTEND=noninteractive
apt update&&apt install -y vim vim-gtk3 git
cp .vimrc ~/.vimrc
echo "PS1='\w$ '" >>~/.bashrc