

echo "ENter the following credentials to set up samba server"
echo "ABdullah shaikh - 21k-4783"
read -p "Samba server-name : " server_name
read -p "Samba share-name : " share_name
read -p "Username for Samba access: " username
read -p "Password for the Samba user: " password

sudo apt-get update
sudo apt-get install samba -y
sudo useradd $username
sudo smbpasswd -a $username

# Configuration
sudo echo "[$share_name]" | sudo tee -a /etc/samba/smb.conf
sudo echo "path = /srv/$share_name" | sudo tee -a /etc/samba/smb.conf
sudo echo "valid users = $username" | sudo tee -a /etc/samba/smb.conf
sudo echo "read only = no" | sudo tee -a /etc/samba/smb.conf


sudo service smbd restart
if ps aux | grep smbd | grep -v grep; then
  echo "Samba server running hurray."
else
  echo "Samba server is not running sorry :( "
fi

