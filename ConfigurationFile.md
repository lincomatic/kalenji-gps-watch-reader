<wiki:gadget url="https://gcodeadsense.googlecode.com/svn/release/gCodeAdSense/gCodeAdSense.xml" width="728" height="90" up\_ad\_client="3040795652020570" up\_ad\_slot="3638377687" />

# Where to place your configuration file #

You can modify the default behavior of kalenji\_reader by creating a configuration file and setting your preferences in it.

On UNIX systems, the file must be called .kalenji\_readerrc file and placed in your home directory.

For example, for a user called toto, the configuration file will be:
```
/home/toto/.kalenjirc
```

On Windows, the file must be named kalenji\_reader.conf and put in %USERPROFILE%.

For example, on Windows 7, for a user called toto:
```
C:\Users\toto\kalenji_reader.conf
```

Alternatively, you place and name your file however/wherever you want and pass it to kalenji\_reader by using -c option.

# Options available #

## Support of OnMove100 ##
OnMove100 doesn't offer the possibility to delete sessions. The memory management is automatic, the watch erasing the oldest session to record a new one when it's full.

**In order to not loose data,** download regularly sessions from your watch to your computer.

To only import new sessions by default, you can put the following in your configuration file:
```
import=new
```

## Support of OnMove 510 and OnMove 710 ##
OnMove 510 and 710 are recognized as USB mass storage device. You should be able to configure your computer to automatically mount it at some place of your choice.
Then put the following in your configuration file:
```
source=Path
path=/mnt/point/of/your/device
```

## Device type ##
**Name:** device

**Default value:** auto

Specify the type of device to use. The value **auto** activates auto detection that tries to guess device. You should keep this default value unless you have a problem with autodetection.

To import from GPX file, you should prefer the usage of -D option in command line that accepts the same arguments. You can create an alias or a wrapper script to simplify its usage.

Supported devices are:
  * **CWKalenji500SD**: For CW Kalenji 500 SD, CW Kalenji 500 Play SD and W Kalenji 500 SD
  * **Kalenji**: For W Kalenji 300 GPS, CW Kalenji 700 GPS, On Move 500, On Move 700 and Keymaze 700 Trail
  * **Keymaze**: For Keymaze 500 and Keymaze 700
  * **OnMove100**: For On Move 100
  * **OnMove710**: For On Move 510 and On Move 710
  * **PylePGSPW1**: For Pyle PGSPW1
  * **GPX**: For GPX files

## Output directory ##
**Name:** directory

**Default value:** /tmp/kalenji\_import

You can configure the directory where the imported file will be put. For example, if the user toto wants the import to be done in a subdirectory Running of his home directory, he will put the following in his configuration file:

```
directory=/home/toto/Running
```

## Default import behavior ##
**Name:** import

**Default value:** new

You can decide whether you prefer to:
  * be prompted for sessions to import each time you run kalenji\_import
```
import=ask
```
  * import all sessions available on the watch
```
import=all
```
  * import only sessions for which not all output formats requested already exist
```
import=new
```

## Default trigger type ##
**Name:** trigger

**Default value:** manual

The information of the kind of event that triggered the end of a lap is, as far as I know, not given by the watch. This setting provide the value that will always be used. It must be one of:
  * **manual**: user pressing the "end of lap" button of the watch
  * **distance**: a distance being run
  * **time**: a time being elapsed
  * **location**: a given location being reached (not possible with those watch)
  * **hr**: a given heartrate being reached (not possible with those watch)

## Filters ##
**Name:** filters

**Default value:** UnreliablePoints,EmptyLaps

List of filters to apply on imported data before exporting it.
Available filters are:
  * **EmptyLaps**: Remove laps with null distance or null duration
  * **UnreliablePoints**: Remove points for which the device gives a low reliability (concerns the following devices: Keymaze 700 Trail, OnMove 500/510/700/710, W Kalenji 300, CW Kalenji 700)
  * **NullHeartrate**: Replace null heartrate measures by previous non-null value (usefull on some devices in case of temporary communication issues between heartrate sensor and watch)
  * **FixElevation**: Uses Google Elevation API to correct the elevation of points based on geographical information. Note that there is a limitation of 25 000 points per day, which corresponds to nearly 7 hours with the best "resolution" (one point per second)
  * **ComputeSessionStats**: Calculate duration, distance, average speed, max speed, ascent and descent using the raw information from points of the session.
  * **ComputeInstantSpeed**: Compute the instant speed for each point based on the distance (computed from coordinates) and the time. This is usefull on OnMove100 for which the data from the watch seems invalid (average speed instead of instant speed).
  * **ReducePoints**: Remove some points so that the route contains less than 200 points after the operation. This is useful before exporting a route to the watch. This keeps points considered as important (with comment in a GPX file) and remove points where they are not far from being aligned (the notion of "not far" adapting dynamically to reach the 200 limit).

## Outputs ##
**Name:** outputs

**Default value:** GPX,GoogleMap

List of formats to which data should be exported.
Outputs can be:
  * **GPX**: GPX format, an XML file conforming to GPX and GPXDATA standards
  * **Fitlog**: Fitlog format, an XML file conforming to Fitlog standard used, among others, by SportTracks
  * **TCX**: TCX format, an XML file conforming to the format introduced by Garmin training center
  * **GoogleMap**: an HTML page containing necessary code to display the route on a google map
  * **GoogleStaticMap**: a file containing an URL using Google API to produce a static picture of the route. As the API limit URL size, it is a simplified version for long routes
  * **KML**: a KML file readable, among others, by GoogleEarth
  * **CSV**: a CSV (comma separated values) file with one line per point of measure and only two columns: time and distance. The main purpose of this format is to compare sessions using create\_comparison\_curve.sh script.
  * **Kalenji**: export route to the watch

## GPX output options ##
**Name:** gpx\_extensions

**Default value:** gpxdata

If set to _none_, no extension of GPX file format is used.
If set to _gpxdata_, gpxdata extension is used to encode heartrate information for each point, and lap information.
If set to _gpxtpx_, gpxtpx extension is used to encode heartrate information for each point.
The variable can be set to _gpxdata,gpxtpx_ in order to encode data using both extensions.

## TCX output options ##
**Name:** tcx\_sport

**Default value:** Running

Activity to use to categorize the session in TCX file format. Should be one of:
  * **Running**
  * **Biking**
  * **Other**

## Log transactions ##
**Name:** log\_transactions

**Default value:** yes

If set to yes, the raw information read from the watch is logged in hexadecimal in log files. The purpose is to allow reimporting the data later even if it has been removed from the watch. It can also be usefull for debugging purpose.

By default, the log files are created in a subdirectory logs of the output directory but this can be configured with configuration variable described next.

## Log transactions directory ##
**Name:** log\_transactions\_directory

**Default value:** logs subdirectory in output directory

The directory where raw data from the watch is logged if this functionality is activated.

<wiki:gadget url="https://gcodeadsense.googlecode.com/svn/release/gCodeAdSense/gCodeAdSense.xml" width="728" height="90" up\_ad\_client="3040795652020570" up\_ad\_slot="3638377687" />