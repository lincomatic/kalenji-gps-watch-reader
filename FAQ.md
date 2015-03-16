<wiki:gadget url="https://gcodeadsense.googlecode.com/svn/release/gCodeAdSense/gCodeAdSense.xml" width="728" height="90" up\_ad\_client="3040795652020570" up\_ad\_slot="3638377687" />

# Tools around your watch #

## How do I replay my session in 3D in Google Earth ? ##
In google-earth, in the list on the left, select "Trajet" and click on the icon "Launch visit" just below the list on the right.

![https://kalenji-gps-watch-reader.googlecode.com/svn/downloads/images/Google%20Earth.png](https://kalenji-gps-watch-reader.googlecode.com/svn/downloads/images/Google%20Earth.png)

## How can I easily create GPX files to upload to my watch ? ##
You can use Google Maps to prepare your route and then use this wonderful bookmark script under firefox (unfortunately it doesn't seem to work with other browsers):
http://www.elsewhere.org/journal/gmaptogpx/

Once you have your GPX file, you can use the utility script kalenji\_export.sh available in scripts directory. It only takes the GPX file as parameter. It provides the features you'll usually want to use.

## Can I view all my sessions on one map ? ##
You can open multiple KML files in google earth. However, if you open a lot of them, it becomes slow. That's why I created a script to create a KML file listing the all the sessions. It doesn't contain the full detail but only the start point.

This script is available in scripts/ and is called create\_index\_map.sh. It must be called in the directory containing all KML files. The files can be in subdirectories and there can be other files, the script will filter to take only the ones that corresponds to sessions generated by kalenji\_reader.

## Can I use the scripts under Windows ? ##
Some scripts are available in scripts/ directory in the source tree and in source packages. They are not part of Windows distribution because they do not work out of the box on it.

However, it should be possible to use them with Cygwin. Note that it has not been tested at all, but should you try it, don't hesitate to give some feedback (positive or negative) on it !

# Technical difficulties #

## I have the following error message, what does it mean ? ##

### No known USB device found ###

This message occurs when using autodetection and your watch is not recognized. If it happens, first check if your watch is in the list of supported devices. If this is the case, check in your OS if your watch is visible (on linux, you can use lsusb command - on windows, check in device manager, accessible from control panel).

If you watch is not supported, you can have a look at ProduceDumps to provide some help to implement the support for it and open an issue or contact me by mail to send me the dumps.

You can try to force the usage of a given device type by using -D option in command line or by adding the device option in your .kalenji\_readerrc (see ConfigurationFile for more details and for a list of device names).

### Device not found or error opening USB device. Is your watch correctly plugged ? ###

Well, two possibilities. Either your watch is not correctly plugged, but if you came to the FAQ after seeing this message it's probably not the case, either your watch is not recognized by the program. Is your watch a W Kalenji 300 GPS or a CW Kalenji 700 GPS ? Note that these are not the same products as the Keymaze ones.

### libusb couldn't open USB device /dev/bus/usb/XXX/YYY: Permission denied. ###

You're running kalenji\_reader as a user that doesn't have necessary permissions on the USB device. There are three solutions:

  * you can run it as root
  * you can change permissions on /dev/bus/usb/XXX/YYY as root by running:

chmod a+rw /dev/bus/usb/XXX/YYY

However this will be lost after each reboot.

  * you can find how to configure permissions on USB devices in your distributions. This will usually consist in modifying udev configuration

<wiki:gadget url="https://gcodeadsense.googlecode.com/svn/release/gCodeAdSense/gCodeAdSense.xml" width="728" height="90" up\_ad\_client="3040795652020570" up\_ad\_slot="3638377687" />