 *******************
 * Install and use *
 *******************

From the directory containing this README.txt:

make

By default, data is imported in /tmp/kalenji_import. You can modify it by creating a .kalenji_readerrc file in your home (see Configuration File for more details). If the directory doesn't exist, it will be created.

To import data from your watch, ensure it's properly connected then launch:

./kalenji_reader

GPX files created can then be imported in your favorite software. HTML files created can be displayed in a browser supporting java script provided you are connected to internet. KML files can be read in Google Earth or any other software supporting it.

 **************
 * Debug mode *
 **************

In case you encounter a core dump, please reproduce it in debug before submitting an issue. To do so, use make debug instead of make. Also use ulimit to allow the OS creating corefiles in case your distribution disable it by default.

make debug
ulimit -c 1000000
./kalenji_reader 2>&1 | tee kalenji_reader_output.txt

This way, program output will also be written in the file kalenji_reader_output.txt. You can attach this file and the core to a bug report to provide more information on what was the problem.

 **********************
 * Configuration file *
 **********************

 * Where to place your configuration file

     You can modify the default behavior of kalenji_reader by putting a .kalenji_readerrc file in your home directory.
     For example for a user called toto, the configuration file will be:

       /home/toto/.kalenjirc

 * Options available

   - Output directory
      Name: directory
      Default value: /tmp/kalenji_import

      You can configure the directory where the imported file will be put. 
      For example, if the user toto wants the import to be done in a subdirectory Running of his home directory, he will put the following in his configuration file:

        directory=/home/toto/Running

   - Default import behavior
      Name: import
      Default value: all

      You can decide whether you prefer to always:
       be prompted for sessions to import each time you run kalenji_import
          import=ask
       import all sessions available on the watch
          import=all

      The latter is longer if you don't want all sessions but it asks less questions so if you erase the sessions from your watch after importing them you will probably prefer it.

   - Default trigger type
      Name: trigger
      Default value: manual

      The information of the kind of event that triggered the end of a lap is, as far as I know, not given by the watch. 
      This setting provide the value that will always be used. It must be one of:

        manual: user pressing the "end of lap" button of the watch
        distance: a distance being run
        time: a time being elapsed
        location: a given location being reached (not possible with those watch)
        hr: a given heartrate being reached (not possible with those watch) 

   - Filters
      Name: filters
      Default value: UnreliablePoints,EmptyLaps

      List of filters to apply on imported data before exporting it. A list of filters separated by coma. Use 'none' for no filter.
      Filters can be:
       - EmptyLaps: Remove laps with null distance or null duration
       - UnreliablePoints: Remove points for which the device gives a low reliability
       - NullHeartrate: Copy heartrate from previous point for points that have null value of heartrate
       - FixElevation: Use GoogleMap API to determine the correct elevation of all points of the session
       - ComputeSessionStats: Compute information at session level from points (distance, duration, max and average speed, ascent, descent ...)
       - ReducePoints: Reduce the number of points by removing points that are not far from being aligned. This is usefull when needing to upload a route that has more than 200 points to the watch.

   - Outputs
      Name: outputs
      Default value: GPX,GoogleMap

      List of formats to which data should be exported.
      Outputs can be:
       - GPX: GPX format, an XML file conforming to GPX and GPXDATA standards
       - GoogleMap: an HTML page containing necessary code to display the route on a google map
       - GoogleStaticMap: an URL using Google API to produce a static picture of the route. As the API limit URL size, it is a simplified version for long routes
       - KML: a file to be opened in Google Earth. It could also work with other software supporting KML files. 
       - Kalenji: to export a route to the device

   - Log transactions
      Name: log_transactions
      Default value: yes

      If set to yes, the raw information read from the watch is logged in hexadecimal in log files. 
      The purpose is to allow reimporting the data later even if it has been removed from the watch. It can also be usefull for debugging purpose.
      It's advised to keep it activated it as it is a way to save raw data, allowing to reimport it if a bug is fix or a new functionality activated.

      By default, the log files are created in a subdirectory logs of the output directory but this can be configured with configuration variable described next.

   - Log transactions directory
      Name: log_transactions_directory
      Default value: logs subdirectory in output directory

      The directory where raw data from the watch is logged if this functionality is activated. 

 ************************
 * Command line options *
 ************************

   - -h: help
     Show the usual help message giving supported options

   - -c: configuration file
     Provide the configuration file to use instead of ~/.kalenji_readerrc"
                 
   - -d: output directory
     Directory to which output files should be produced. Override value of "directory" given in configuration file.

   - -f: filters
     Comma separated list of filters to apply on data before the export. Override value of "filters" given in configuration file.

   - -o: outputs
     Comma separated list of output formats to produce for each session. Override value of "filters" given in configuration file.

   - -t: trigger
     Provide the type of trigger. Override value of "trigger" given in configuration file.

   - -D: device
     Type of device to use. For now, can be either 'GPX' to convert a GPX file or 'Kalenji' to import from a Kalenji watch

   - -i: input file
     Provide input file. This is mandatory for device 'GPX'. When used with device 'Kalenji' this allows to import from logs of a previous import.

