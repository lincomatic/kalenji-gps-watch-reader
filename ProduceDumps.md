<wiki:gadget url="https://gcodeadsense.googlecode.com/svn/release/gCodeAdSense/gCodeAdSense.xml" width="728" height="90" up\_ad\_client="3040795652020570" up\_ad\_slot="3638377687" />

# Software required #

You need to install USBPcap in order to produce dumps. You can find it here:
http://desowin.org/usbpcap/index.html

Installation is straigt forward. Just allow the software to run (if asked) and accept licence terms. Remember where you put it (by default in C:\Program Files\USBPcap)

# Producing dumps #

To produce the dump of an import, you just need to:
**1- launch USBPcapCMD.exe**
It is in the directory you choose during the installation (by default C:\Program Files\USBPcap)
**2- select the device corresponding to your watch**
If you don't know which one it is, run USBPcap a first time without your device plugged. Then plug your device and run USBPcap again. Compare both output. The device that appeared is yours.

Just type the number of the tree containing your device. For example if you have this output:
```
1 \\.\USBPcap1
  \??\USB#ROOT_HUB20#4&1f26c964&0#{f18a0e88-c30c-11d0-8815-00a0c906bed8}
    [Port 1] Generic USB Hub
      [Port 4] Dell Wireless 380 Bluetooth 4.0 Module
        Bluetooth Device (RFCOMM Protocol TDI)
        Microsoft Bluetooth Enumerator
        Bluetooth Device (Personal Area Network)
      [Port 5] USB Composite Device
        Integrated Webcam
2 \\.\USBPcap2
  \??\USB#ROOT_HUB20#4&1a1a4c1e&0#{f18a0e88-c30c-11d0-8815-00a0c906bed8}
    [Port 1] Generic USB Hub
      [Port 7] Generic USB Hub
        [Port 1] USB Composite Device
          USB Audio Device
          USB Video Device
        [Port 2] USB Composite Device
          Plantronics C420-M
          USB Input Device
            HID-compliant consumer control device
            HID-compliant device
            HID-compliant device
3 \\.\USBPcap3
  \??\IUSB3#ROOT_HUB30#4&387a43b2&0#{f18a0e88-c30c-11d0-8815-00a0c906bed8}
    [Port 1] STM32 Virtual COM Port
    [Port 4] USB 2.0 MTT Hub
      [Port 1] USB Input Device
        HID-compliant mouse
      [Port 2] USB Composite Device
        USB Input Device
          HID Keyboard Device
        Microsoft Usbccid Smartcard Reader (WUDF)
          Smart card filter driver
```
and your device is **STM32 Virtual COM Port**, then press 3.
3- choose a file name
Use a significant name and put the .pcap extension in it.
4- do the import from your device normally
But before everything, unplug your device and replug it. This will allow to capture any initialization that would be done immediately after the device being plugged.
5- once the import is finished, go back to USBPcapCMD.exe window and press Ctrl-C.

The dump will be in the file with the name you gave at step 3.

# What dumps to produce #

In order to ease reverse engineering, it's a good idea to produce at least 3 dumps:
  * One where there is no session on the watch
  * One with only one very small session (lasting for less than one minute)
  * One with multiple sessions, with as much features used as possible (multilaps sessions, pauses ...)

For each dump, send also the GPX files corresponding to the imported sessions (so obviously, no GPX file for the first dump). Join any additional information you have, in particular:
  * Everything that a watch can display about a session or a lap (heartrate, speed, calories ... max and average, ascent, descent, ascent & descent speed ...). Not necessary for all sessions but at least for two.
  * Any information that you entered in you watch when configuring it: name, age, weight, max heartrate ...


<wiki:gadget url="https://gcodeadsense.googlecode.com/svn/release/gCodeAdSense/gCodeAdSense.xml" width="728" height="90" up\_ad\_client="3040795652020570" up\_ad\_slot="3638377687" />