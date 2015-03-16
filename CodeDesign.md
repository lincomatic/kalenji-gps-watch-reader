<wiki:gadget url="https://gcodeadsense.googlecode.com/svn/release/gCodeAdSense/gCodeAdSense.xml" width="728" height="90" up\_ad\_client="3040795652020570" up\_ad\_slot="3638377687" />

# Introduction #

This software is organized in layers. The usual data flow is the following:

Source -> Device -> Bom -> Filters -> Output

Of course, only one single source and one single device can be used at a time. Multiple filters and multiple output can be used. All filters will be applied to the data in the order defined. The resulting data will be sent to all outputs.

## Examples ##

**Import from a Kalenji GPS watch**

Source = USB

Device = Kalenji

**Export a GPX to a Kalenji GPS watch**

Source = File

Device = GPX

Output = Kalenji

**Convert GPX to KML**

Source = File

Device = GPX

Output = KML

# Code source organisation #

At the root of the SVN repository, you can find a few files with self-explanatory names and two directories:
  * **src** that contains the source of the software
  * **protocol** that contains reverse engineering information about the protocols of the supported devices

## Layers ##

In src, there are directories corresponding to code layers. The following is true for all layers except bom:
  * objects are in a namespace having the same name as the directory
  * an interface with the name of the layer with first letter being uppercase is defined
  * all classes in the layer must inherit from the interface
  * two macros DECLARE\_XXX and REGISTER\_XXX where XXX is the name of the layer in uppercase are defined
  * Each object use DECLARE\_XXX in its class declaration and REGISTER\_XXX in its class definition to register the object
  * Each object has a method getName that returns the name that refers to the object. It is advised to return the class name.

## Registration internals ##

The registration is transparent for someone who wants to implement a new layer, but for those that are interested, here is how registration works.

Directly in src, there is a file Registry.h defining two template classes: LayerRegistry and LayerRegistrer.

**LayerRegistry** is a singleton (one per layer) mapping objects names to an instance of the corresponding class.
**LayerRegistrer** is a class that has a constructor that will register an object of its 2nd template paramater in the registry corresponding to its 1st template parameter using the method getName as the key

# Implementing a new device/filter/output #

To implement a new device, filter or output, the only thing to do is to add one class in the corresponding layer. This class must inherit from the interface of the layer and implement all the virtual method defined in it. Interfaces for device, filter and output are defined respectively in device/Device.h filter/Filter.h and output/Output.h

In all cases, a method getName must be implemented returning the name of the new object. This is the name that will be used to refer to it in configuration file or in options.

It's also necessary to use
  * the macro DECLARE\_DEVICE, DECLARE\_FILTER or DECLARE\_OUTPUT (depending on the layer) with the class name as parameter in the private part of the declaration of your class in the .h file
  * the macro REGISTER\_DEVICE, REGISTER\_FILTER or REGISTER\_OUTPUT (depending on the layer) with the class name as parameter in the .cc file

For the rest of the implementation, the best is to have a look at already existing objects !

The important thing here is that you don't need to do anything else. Once you've created your class, you just need to launch make and you can use this new object in the configuration or the options of the program.

<wiki:gadget url="https://gcodeadsense.googlecode.com/svn/release/gCodeAdSense/gCodeAdSense.xml" width="728" height="90" up\_ad\_client="3040795652020570" up\_ad\_slot="3638377687" />