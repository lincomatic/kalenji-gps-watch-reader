<wiki:gadget url="https://gcodeadsense.googlecode.com/svn/release/gCodeAdSense/gCodeAdSense.xml" width="728" height="90" up\_ad\_client="3040795652020570" up\_ad\_slot="3638377687" />

You can either install featured versions from a distributed package or current development version from SVN.

# Installing from package #

Download a package from [Downloads section](http://code.google.com/p/kalenji-gps-watch-reader/downloads/list)

For example, if you downloaded version 1.0:

```
tar -xvzf kalenji-gps-watch-reader-1.0.tar.gz
cd kalenji-gps-watch-reader
make
```

# Installing from SVN #

If you prefer to get the latest version, with bleeding edge features but also potentially more bugs:

```
svn checkout http://kalenji-gps-watch-reader.googlecode.com/svn/trunk/ kalenji-gps-watch-reader-read-only
cd kalenji-gps-watch-reader-read-only
make
```

# On Move 510 and 710 #

On Move 510 and On Move 710 watches are handled as USB mass storage devices so they require a specific configuration.

You need to either give the path to the mount point where the watch content is available with -p option or specify it using path option in your configuration file (see ConfigurationFile for details).

# Importing sessions from the watch #

By default, data is imported in /tmp/kalenji\_import. You can modify it by editing your ConfigurationFile. If the directory doesn't exist, it will be created.

**From the directory where you built the tool**:

```
./kalenji_reader
```

GPX files created can be imported in your favorite software.

# Exporting route to the watch #

This is supported for the following devices:
  * W Kalenji 300 GPS
  * CW Kalenji 700 GPS
  * GPS On Move 500
  * GPS On Move 700
  * Keymaze 700 Trail

Let's say you have a file myRoute.gpx containing the route you want to put on your watch. You can use the following command to do so:

```
./kalenji_reader -D GPX -i /path/to/myRoute.gpx -f FixElevation,ComputeSessionStats,ReducePoints -o Kalenji
```

Note that the same kind of command can be used with different -o option to convert a GPX file to apply a filter to a GPX file or to export it to another format. See ConfigurationFile and -h option for more details.

See [this FAQ element](http://code.google.com/p/kalenji-gps-watch-reader/wiki/FAQ#How_can_I_easily_create_GPX_files_to_upload_to_my_watch_?) for how to create a GPX file from Google Map.

# Debug mode #

In case you encounter a core and you want to report it, you will need to use debug mode to produce a file containing debug information.

Then rebuild and run the tool:
```
make debug
mkdir -p /tmp/kalenji_import
./kalenji_reader 2>&1 | tee kalenji_reader_output.txt
```

The output of kalenji\_reader will be written in kalenji\_reader\_output.txt. You can attach this file, an eventual core and logs of the import to a bug report to provide more information on the problem.


<<<<<<< .mine
<wiki:gadget url="https://gcodeadsense.googlecode.com/svn/release/gCodeAdSense/gCodeAdSense.xml" width="728" height="90" up\_ad\_client="3040795652020570" up\_ad\_slot="3638377687" />

<wiki:gadget url="https://gcodeadsense.googlecode.com/svn/release/gCodeAdSense/gCodeAdSense.xml" width="728" height="90" up\_ad\_client="3040795652020570" up\_ad\_slot="3638377687" />>>>>>>> .[r276](https://code.google.com/p/kalenji-gps-watch-reader/source/detail?r=276)