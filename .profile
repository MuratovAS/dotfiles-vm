#!/bin/sh

# default editor
export EDITOR=micro
export VISUAL=micro
export MICRO_TRUECOLOR=1

# Electron
export XDG_CONFIG_HOME=$HOME/.config

# Java theme
export _JAVA_AWT_WM_NONREPARENTING=1

# Most pure GTK3 apps use wayland by default, but some,
# like Firefox, need the backend to be explicitely selected.
export MOZ_ENABLE_WAYLAND=1
export MOZ_DBUS_REMOTE=1
export GTK_CSD=0

# QT wayland
export QT_WAYLAND_DISABLE_WINDOWDECORATION="1"
export QT_QPA_PLATFORM="wayland"
#export QT_QPA_PLATFORMTHEME=qt5ct
#export QT_SCREEN_SCALE_FACTORS="2;1"
#export QT_QPA_PLATFORM="xcb"
#export QT_SCALE_FACTOR="2"

# fix for VMSVGA graphics controller 
#export WLR_NO_HARDWARE_CURSORS=1
#export XCURSOR_THEME="Breeze"

# launch WM
if [ "$(tty)" = "/dev/tty1" ] ; 
then
	killall someblocks wbg dwlb dwl
	
	export XDG_RUNTIME_DIR=$HOME/.xdg
	export XDG_SESSION_DESKTOP=dwl
	export XDG_CURRENT_DESKTOP=dwl

	mkdir -p $XDG_RUNTIME_DIR

	dbus-run-session dwl
fi
