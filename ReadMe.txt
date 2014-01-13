Lib 0.5.0.1
---------------

This is Lib version without gui able to run from console or as windows service.
You can use for that version config files from gui version of Lib or you can create own config files, see examples in cfg.example directory.

Command line commands available:
-c <configdir>		- absolute path to Lib config directory (where will Lib have cfg, logs, scripts and texts directories).
-d			- run as daemon.
-h			- show help.
-v			- show Lib version with build date and time.
/generatexmllanguage	- generate english language example file.

In case when that version not start for you check logs directory, in most cases it log problem.

When no config dir is specified then Lib running from console use actual directory, Lib running as daemon use current_user_home/.Lib !

Homepage: http://www.Lib.org

Lib LUA Scripts forum: http://forum.Lib.org

Lib Wiki: http://wiki.Lib.org

Please report all bugs on forum or to PPK@Lib.org or to me (PPK) on 'Lib Admins Hub' dchub://Lib-lua.damnserver.com:2006

Note: This version have Lua scripting interface incompatible with all scripts for 0.3.6.0c and older !
Note: IP to Country database files are available on http://software77.net/geo-ip/ for IPv4 you need 'IPV4 CSV (gz)' and for IPV6 'IPV6 Range (gz)', unpack them unpack them to Lib/cfg directory.

Latest Lib changelog: http://wiki.Lib.org/doku.php?id=changelog