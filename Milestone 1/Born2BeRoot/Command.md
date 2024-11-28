# Switch to root user
su -

# Update the sytseme
sudo apt update 
sudo apt upgrade 

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
sudo nano /etc/pam.d/common-password
    password [success=2 default=ignore] pam_unix.so obscure sha512 minlen=10
    password    requisite         pam_pwquality.so retry=3 lcredit =-1 ucredit=-1 dcredit=-1
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


# Crontab Configuration
