
Debian
====================
This directory contains files used to package bitzenyd/bitzeny-qt
for Debian-based Linux systems. If you compile bitzenyd/bitzeny-qt yourself, there are some useful files here.

## bitzeny: URI support ##


bitzeny-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install bitzeny-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your bitzeny-qt binary to `/usr/bin`
and the `../../share/pixmaps/bitzeny128.png` to `/usr/share/pixmaps`

bitzeny-qt.protocol (KDE)

