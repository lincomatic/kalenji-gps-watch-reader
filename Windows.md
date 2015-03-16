<wiki:gadget url="https://gcodeadsense.googlecode.com/svn/release/gCodeAdSense/gCodeAdSense.xml" width="728" height="90" up\_ad\_client="3040795652020570" up\_ad\_slot="3638377687" />

# 1 - Installation of kalenji\_reader #

Unzip the content of the archive in the directory of your choice.

# 2 - Installation of WinUSB driver #

**This step is not needed (in fact, it MUST NOT BE DONE) for On Move 510 and On Move 710 watches**

**Note that after installing WinUSB driver, Geonaute Software will not recognize the watch anymore. You'll be able to use it again by uninstalling WinUSB driver and reinstalling the previous one. See _5 - Uninstall WinUSB driver_.** If you know a way to use both at the same time, please share it !

Launch zadig.exe. This is the installer for WinUSB driver. Accept to run it as Administrator.

In menu Options, click on List All Devices:
![https://kalenji-gps-watch-reader.googlecode.com/files/zadig_list_devices.png](https://kalenji-gps-watch-reader.googlecode.com/files/zadig_list_devices.png)

Then choose the device corresponding to your watch. As the name may not be very explicit, you can try the "List All Devices" with and without the watch plugged to check which device appears. The
![https://kalenji-gps-watch-reader.googlecode.com/files/zadig_choose_device.png](https://kalenji-gps-watch-reader.googlecode.com/files/zadig_choose_device.png)

You can check vendor ID and product ID to be sure this corresponds to your watch. Then click on "Install Driver" button.
![https://kalenji-gps-watch-reader.googlecode.com/files/zadig_install_driver.png](https://kalenji-gps-watch-reader.googlecode.com/files/zadig_install_driver.png)

# 3 - Creation of configuration file #

Check where your USERPROFILE directory is.
You can do this by running a command line:
Start Menu -> Execute
Type "cmd.exe".

Then in the shell windows that opened, type the following:
```
echo %USERPROFILE%
```

For example on Windows 7, I have C:\Users\username.

Go in this directory and create a file named kalenji\_reader.conf.

Fill this file with your configuration (cf ConfigurationFile).

For example:
```
directory=c:\temp\kalenji_import
import=ask
outputs=GPX,KML,GoogleMap
gpx_extensions=gpxdata
```

For On Move 510 and 710 you'll also need to precise where the watch is mounted as USB mass storage device. Typically:
```
source=Path
path=E:
```

# 4 - Usage #

Just launch kalenji\_reader.exe. You can create a shortcut to it to ease its usage.

# 5 - Uninstall WinUSB driver #

To uninstall WinUSB driver, go in Control Panel, in Device Manager. Look for your USB device (under Universal Serial Bus controllers).

![https://kalenji-gps-watch-reader.googlecode.com/files/zadig_uninstall_1.png](https://kalenji-gps-watch-reader.googlecode.com/files/zadig_uninstall_1.png)

Right click on it and select Properties. In the Driver tab, click Uninstall.

![https://kalenji-gps-watch-reader.googlecode.com/files/zadig_uninstall_2.png](https://kalenji-gps-watch-reader.googlecode.com/files/zadig_uninstall_2.png)

In the confirmation window, check the checkbox to delete the driver software and click OK.

![https://kalenji-gps-watch-reader.googlecode.com/files/zadig_uninstall_3.png](https://kalenji-gps-watch-reader.googlecode.com/files/zadig_uninstall_3.png)

Now, if you unplug and replug your device, the default driver should be reinstalled automatically and you'll be able to use Geonaute Software again.


<<<<<<< .mine
<wiki:gadget url="https://gcodeadsense.googlecode.com/svn/release/gCodeAdSense/gCodeAdSense.xml" width="728" height="90" up\_ad\_client="3040795652020570" up\_ad\_slot="3638377687" />

<wiki:gadget url="https://gcodeadsense.googlecode.com/svn/release/gCodeAdSense/gCodeAdSense.xml" width="728" height="90" up\_ad\_client="3040795652020570" up\_ad\_slot="3638377687" />>>>>>>> .[r276](https://code.google.com/p/kalenji-gps-watch-reader/source/detail?r=276)