export DEBIAN_FRONTEND=noninteractive
apt update&&apt install -y python3 g++ xclip vim vim-gtk3
apt install -y git pip\
	&&pip install --break-system-packages online-judge-verify-helper\
	numpy scipy sympy networkx pandas
cat .bashrc >>~/.bashrc
cp .vimrc ~/.vimrc
