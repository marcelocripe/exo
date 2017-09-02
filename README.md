# eXo project
 Qt frontend to MOC player

### What it does ###
 Allows you to control your MOC player via tray popup menu.

### Build and run ###
```
#!Bash
mkdir build && cd build
cmake ..
make
./src/exo
```
NOTE: you should link against the corresponding version of liblastfm or program will crash

### Build options: ###
```
#!
-DBUILD_DBUS=OFF     - disable DBus and MPRISv2 interfaces (enabled by default);
-DBUILD_LASTFM=OFF   - disable scrobber module (enabled by default);
```


### Features: ###
* Scrobbling to last.fm (optional)
* Lyrics from web
* Background mode
* DBus and MPRISv2 interfaces (optional)
* Bookmarks
* OSD (additional Python script)

### Screenshot ###
![Screenshot of the eXo app](https://bitbucket.org/repo/8Xb9ez/images/405669011-exo.png)

### Background mode (no GUI or X-session needed): ###
 Basic running `exo -d 2>/tmp/exo_errors.log &`

 Scrobbler authentication `exo -f` or `exo --force-reauth`

 Shutting down the app `qdbus tk.loimu.exo /Exo tk.loimu.exo.quitApplication` or just `pkill -2 exo`

### Tips: ###
 Create a global hotkey to see the lyrics at any time.
 `qdbus tk.loimu.exo /Exo tk.loimu.exo.showLyricsWindow` is the command you want.

### Installation on Ubuntu: ###
```
#!Bash
sudo add-apt-repository ppa:blaze/main
sudo apt-get update
sudo apt-get install exo-player
```
