
echo "Abdullah shaikh - 21k-4783 "
echo "NETWORK INFORAMTION OF MY DEVICE IS :"
echo "----------------------------------------------------------------------------------------"

ip=$(ip addr show | grep -Eo '[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}' | head -1)
echo "IP address: $ip"
host=$(hostname)
echo "Hostname: $host"
mac_address=$(ip link show | grep -Po '(?<=link/ether\s)\S+')
echo "MAC address: $mac_address"
mask=$(ip addr show | grep -Eo '[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}' | head -2 | tail -1)
echo "Subnet mask: $mask"
gateway=$(ip route show default | awk '/default/ {print $3}')
echo "Default gateway: $gateway"
echo "----------------------------------------------------------------------------------------"
