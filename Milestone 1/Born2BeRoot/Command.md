# Switch to root user
su -

# Update the sytseme
apt update 
apt upgrade 

# Install sudo and configure strict rules
sudo apt install sudo
sudo visudo
    Defaults    passwd_tries=3
    Defaults    badpass_message="Try again..."
    Defaults    logfile="/var/log/sudo/sudo.log"
    Defaults    log_input,log_output
    Defaults    requiretty
    Defaults    secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"

# Manage users
sudo usermod -aG sudo login
getent group sudo
sudo addgroup user42
sudo usermod -aG user42 login
getent group user42
sudo visudo
    login    ALL=(ALL) ALL
sudo adduser new_username new_group

# SSH
sudo apt update 
sudo apt upgrade 
sudo apt install openssh-server
service ssh restart
sudo nano /etc/ssh/sshd_config
    Port 4242
    PermiRootLogin no
service ssh restart

# UFW
sudo apt install ufw
sudo ufw enable
sudo ufw allow 4242
sudo ufw status

# Setup strong password policy
sudo nano /etc/login.defs
    PASS_MAX_DAYS   30
    PASS_MIN_DAYS   2
    PASS_WARN_AGE   7
sudo apt install libpam-pwquality
[ Method 1 ]
sudo nano /etc/security/pwquality.conf
    minlen = 10           # Minimum password length.
    ucredit = -1          # At least 1 uppercase letter required.
    lcredit = -1          # At least 1 lowercase letter required.
    dcredit = -1          # At least 1 digit required.
    maxrepeat = 3         # Maximum consecutive identical characters allowed.
    usercheck=0           # Not include the name of the user.
    difok = 7             # Requires 7 characters different from the old password.
    enforce_for_root      # Enforces the policy for root passwords.
[ Method 2 ]
sudo nano /etc/pam.d/common-password
    password    requisite         pam_pwquality.so minlen=10 lcredit =-1 ucredit=-1 dcredit=-1
    maxrepeat=3 usercheck=0 difok=7 enforce_for_root
sudo reboot

# Change Password
chage -l login
sudo passwd root

# Change Hostname
hostnamectl set-hostname new_hostname
sudo nano /etc/hosts
    127.0.0.1       localhost
    127.0.0.1       new_hostname
sudo reboot

# Create monitoring.sh
• The architecture of your operating system and its kernel version:
    uname -a
• The number of physical processors:
    grep "physical id" /proc/cpuinfo | sort | uniq | wc -l
• The number of virtual processors:
    grep "processor" /proc/cpuinfo | wc -l
• The current available RAM on your server and its utilization rate as a percentage:
    free RAM: free -m | awk '/Mem:/ {printf $4}'
    usage RAM: free -m | awk '/Mem:/ {printf $3}' --> $memory_used
    total RAM: free -m | awk '/Mem:/ {printf $2}' -->  $memory_total
    porcentage RAM: awk "BEGIN {printf \"%.2f\", $memory_used/$memory_total*100}"
• The current available memory on your server and its utilization rate as a percentage.

• The current utilization rate of your processors as a percentage:
    top -bn1 | awk '/Cpu\(s\)/ {printf "%.1f%%", $2 + $4}'
• The date and time of the last reboot:
    who -b | awk '{print $3 " " $4}'
• Whether LVM is active or not:
    [ $(lsblk | grep "lvm" | wc -l) -gt 0 ] && echo "yes" || echo "no"
• The number of active connections:
    ss -Ht state established | wc -l
• The number of users using the server:
    users | wc -w
• The IPv4 address of your server and its MAC (Media Access Control) address:
• The number of commands executed with the sudo program:
# Crontab Configuration
