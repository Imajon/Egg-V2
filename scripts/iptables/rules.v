# Generated by iptables-save v1.4.14 on Sat Jan 11 00:54:00 2014
*nat
:PREROUTING ACCEPT [18:5203]
:INPUT ACCEPT [20:1518]
:OUTPUT ACCEPT [2:399]
:POSTROUTING ACCEPT [2:399]
-A PREROUTING -i wlan0 -p udp -m udp --dport 443 -j DNAT --to-destination 10.0.0.1:80
-A PREROUTING -i wlan0 -p udp -m udp --dport 53 -j DNAT --to-destination 10.0.0.1:80
-A PREROUTING -i wlan0 -p tcp -m tcp --dport 80 -j DNAT --to-destination 10.0.0.1:80
COMMIT
# Completed on Sat Jan 11 00:54:00 2014
# Generated by iptables-save v1.4.14 on Sat Jan 11 00:54:00 2014
*filter
:INPUT ACCEPT [1076:456528]
:FORWARD ACCEPT [0:0]
:OUTPUT ACCEPT [845:77354]
-A FORWARD -i wlan0 -o eth0 -j DROP
COMMIT
# Completed on Sat Jan 11 00:54:00 2014