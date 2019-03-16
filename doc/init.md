Sample init scripts and service configuration for bitzenyd
==========================================================

Sample scripts and configuration files for systemd, Upstart and OpenRC
can be found in the contrib/init folder.

    contrib/init/bitzenyd.service:    systemd service unit configuration
    contrib/init/bitzenyd.openrc:     OpenRC compatible SysV style init script
    contrib/init/bitzenyd.openrcconf: OpenRC conf.d file
    contrib/init/bitzenyd.conf:       Upstart service configuration file
    contrib/init/bitzenyd.init:       CentOS compatible SysV style init script

Service User
---------------------------------

All three Linux startup configurations assume the existence of a "bitzeny" user
and group.  They must be created before attempting to use these scripts.
The OS X configuration assumes bitzenyd will be set up for the current user.

Configuration
---------------------------------

At a bare minimum, bitzenyd requires that the rpcpassword setting be set
when running as a daemon.  If the configuration file does not exist or this
setting is not set, bitzenyd will shutdown promptly after startup.

This password does not have to be remembered or typed as it is mostly used
as a fixed token that bitzenyd and client programs read from the configuration
file, however it is recommended that a strong and secure password be used
as this password is security critical to securing the wallet should the
wallet be enabled.

If bitzenyd is run with the "-server" flag (set by default), and no rpcpassword is set,
it will use a special cookie file for authentication. The cookie is generated with random
content when the daemon starts, and deleted when it exits. Read access to this file
controls who can access it through RPC.

By default the cookie is stored in the data directory, but it's location can be overridden
with the option '-rpccookiefile'.

This allows for running bitzenyd without having to do any manual configuration.

`conf`, `pid`, and `wallet` accept relative paths which are interpreted as
relative to the data directory. `wallet` *only* supports relative paths.

For an example configuration file that describes the configuration settings,
see `contrib/debian/examples/bitzeny.conf`.

Paths
---------------------------------

### Linux

All three configurations assume several paths that might need to be adjusted.

Binary:              `/usr/bin/bitzenyd`  
Configuration file:  `/etc/bitzeny/bitzeny.conf`  
Data directory:      `/var/lib/bitzenyd`  
PID file:            `/var/run/bitzenyd/bitzenyd.pid` (OpenRC and Upstart) or `/var/lib/bitzenyd/bitzenyd.pid` (systemd)  
Lock file:           `/var/lock/subsys/bitzenyd` (CentOS)  

The configuration file, PID directory (if applicable) and data directory
should all be owned by the bitzeny user and group.  It is advised for security
reasons to make the configuration file and data directory only readable by the
bitzeny user and group.  Access to bitzeny-cli and other bitzenyd rpc clients
can then be controlled by group membership.

### Mac OS X

Binary:              `/usr/local/bin/bitzenyd`  
Configuration file:  `~/Library/Application Support/Bitzeny/bitzeny.conf`  
Data directory:      `~/Library/Application Support/Bitzeny`  
Lock file:           `~/Library/Application Support/Bitzeny/.lock`  

Installing Service Configuration
-----------------------------------

### systemd

Installing this .service file consists of just copying it to
/usr/lib/systemd/system directory, followed by the command
`systemctl daemon-reload` in order to update running systemd configuration.

To test, run `systemctl start bitzenyd` and to enable for system startup run
`systemctl enable bitzenyd`

### OpenRC

Rename bitzenyd.openrc to bitzenyd and drop it in /etc/init.d.  Double
check ownership and permissions and make it executable.  Test it with
`/etc/init.d/bitzenyd start` and configure it to run on startup with
`rc-update add bitzenyd`

### Upstart (for Debian/Ubuntu based distributions)

Drop bitzenyd.conf in /etc/init.  Test by running `service bitzenyd start`
it will automatically start on reboot.

NOTE: This script is incompatible with CentOS 5 and Amazon Linux 2014 as they
use old versions of Upstart and do not supply the start-stop-daemon utility.

### CentOS

Copy bitzenyd.init to /etc/init.d/bitzenyd. Test by running `service bitzenyd start`.

Using this script, you can adjust the path and flags to the bitzenyd program by
setting the BITZENYD and FLAGS environment variables in the file
/etc/sysconfig/bitzenyd. You can also use the DAEMONOPTS environment variable here.

### Mac OS X

Copy org.bitzeny.bitzenyd.plist into ~/Library/LaunchAgents. Load the launch agent by
running `launchctl load ~/Library/LaunchAgents/org.bitzeny.bitzenyd.plist`.

This Launch Agent will cause bitzenyd to start whenever the user logs in.

NOTE: This approach is intended for those wanting to run bitzenyd as the current user.
You will need to modify org.bitzeny.bitzenyd.plist if you intend to use it as a
Launch Daemon with a dedicated bitzeny user.

Auto-respawn
-----------------------------------

Auto respawning is currently only configured for Upstart and systemd.
Reasonable defaults have been chosen but YMMV.
