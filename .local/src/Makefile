all: # mkdir dwl dwlb someblocks wbg dmenu-wayland
	
#mkdir: 
	mkdir -p ${HOME}/.local
	mkdir -p ${HOME}/.local/bin

#dwl: dwl/dwl
	cd dwl && make
	cp -f dwl/dwl ${HOME}/.local/bin/

#dwlb: dwlb/dwlb
	cd dwlb && make
	cp -f dwlb/dwlb ${HOME}/.local/bin/

#someblocks: someblocks/someblocks
	cd someblocks && make
	cp -f someblocks/someblocks ${HOME}/.local/bin/

#wbg: wbg/build/wbg
	cd wbg && meson --buildtype=release build && ninja -C build
	cp -f wbg/build/wbg ${HOME}/.local/bin/

#dmenu-wayland:
	cd dmenu-wayland && meson --buildtype=release build && ninja -C build
	cp -f dmenu-wayland/build/dmenu-wl ${HOME}/.local/bin/
	cp -f dmenu-wayland/build/dmenu-wl_path ${HOME}/.local/bin/
	
clean:
	rm -rf ${HOME}/.local/bin
	cd dwl && make clean
	cd dwlb && make clean
	cd someblocks && make clean