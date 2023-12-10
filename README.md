# dotfiles-vm
set of WM configurations for a virtual machine

загружаемся с livecd

```
sudo su
```

имеем диск /dev/vda

```
cfdisk /dev/vda
```

```
dos
1. swap    = RAM + 1-4G
2. /       = main
```

создаем фс
```
mkswap -L SWAP /dev/vda1
mkfs.ext4 -L ROOT /dev/vda2
```

```
swapon /dev/disk/by-label/SWAP
mount /dev/disk/by-label/ROOT /mnt
```

dinitctl start ntpd


```
basestrap /mnt base base-devel dinit seatd-dinit
basestrap /mnt linux 
// linux-headers
fstabgen -U /mnt >> /mnt/etc/fstab
```

```
artix-chroot /mnt
```

```
# for BIOS systems
pacman -S grub 
grub-install --recheck /dev/vda
grub-mkconfig -o /boot/grub/grub.cfg
````

пароль root
```
passwd 
// 1234
```

пакеты для работы с инетом
```
pacman -S dhcpcd
pacman -S dhcpcd-dinit
```





dinitctl start dhcpcd
dinitctl enable dhcpcd

pacman -S artix-archlinux-support
/etc/pacman.conf
```
# Arch
[extra]
Include = /etc/pacman.d/mirrorlist-arch

[community]
Include = /etc/pacman.d/mirrorlist-arch

[multilib]
Include = /etc/pacman.d/mirrorlist-arch
```
pacman -Sy archlinux-keyring artix-keyring
rm -r /etc/pacman.d/gnupg
pacman-key --init
pacman-key --populate archlinux artix
pacman -Scc
pacman -Syyu


locale-gen
echo "ИМЯХОСТА" > /etc/hostname
echo "127.0.0.1 localhost" > /etc/hosts
echo "::1       localhost" >> /etc/hosts
echo "Welcome to Artix" > /etc/motd

useradd -m -G wheel -s /bin/bash user
passwd
// 1234

sed '/%wheel ALL=(ALL:ALL) NOPASSWD: ALL/s/^#//' -i /etc/sudoers


## Настройка env

Добавим возможность использовать `.profile` для пользовательских `env`. А так же возможность добавлять пользовательские бинарные приложения.
```bash
echo 'export PATH="$HOME/.local/bin:$PATH"' > /etc/profile.d/home-local-bin.sh
echo -e '# Load profile from home\n[[ -f $HOME/.profile ]] && . $HOME/.profile' >> /etc/profile
```


sudo pacman -S wget git
wget https://aur.archlinux.org/cgit/aur.git/snapshot/yay.tar.gz
tar -xvf yay.tar.gz
makepkg -i


echo "LIBSEAT_BACKEND=seatd" >> /etc/enviroment
dinitctl start seatd
dinitctl enable seatd

usermod -aG seat user
usermod -aG video user


sudo pacman -S ttf-nerd-fonts-symbols 
sudo pacman -S ttf-roboto-mono

fc-cache -f -v
fc-list



sudo pacman -S libinput wayland wlroots wayland-protocols pkg-config libxkbcommon fcft pixman
sudo pacman -S meson libpng libjpeg libwebp tllist cairo pango

git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ${ZSH_CUSTOM:-.config/oh-my-zsh/custom}/plugins/zsh-syntax-highlighting
git clone https://github.com/zsh-users/zsh-autosuggestions ${ZSH_CUSTOM:-.config/oh-my-zsh/custom}/plugins/zsh-autosuggestions

----

sudo pacman -S chrony chrony-openrc
sudo rc-service chrony restart
sudo rc-update add chrony 


sudo pacman -S p7zip unrar

sudo pacman -S fuse-common fuse3 fuse2

sudo pacman -S htop micro mc
sudo pacman -S foot wl-clipboard
sudo pacman -S mpv imv zathura
sudo pacman -S zathura-pdf-poppler zathura-djvu

sudo pacman -S bat chafa
yay -S lf-bin

----

/etc/conf.d/agetty.tty1
agetty_options="-J -a ИМЯ"
