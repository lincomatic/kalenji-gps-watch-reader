#ifndef _BOM_POINT_H
#define _BOM_POINT_H

#include <sstream>
#include <iostream>

class Point
{
	public:
		// TODO: Improve the way fiability is handled (0 / 3 doesn't make sense)
		Point() : _lat(0), _lon(0), _alt(0), _speed(0), _time(0), _tenth(0), _bpm(0), _fiability(3)
		{ _important = false; };

		Point(double lat, double lon, int16_t alt, double speed, time_t time, uint32_t tenth, uint16_t bpm, uint16_t fiability) 
			 : _lat(lat), _lon(lon), _alt(alt), _speed(speed), _time(time), _tenth(tenth), _bpm(bpm), _fiability(fiability)
		{ _important = false; };

		void setLatitude(double lat)     { _lat = lat; };
		void setLongitude(double lon)    { _lon = lon; };
		void setAltitude(int16_t alt)    { _alt = alt; };
		void setSpeed(double speed)      { _speed = speed; };
		void setHeartRate(uint16_t bpm)  { _bpm = bpm; };
		void setFiability(uint16_t f)    { _fiability = f; };
		void setImportant(bool i)        { _important = i; };
		void setTime(time_t time)        { _time = time; };

		double getLatitude()    { return _lat; };
		double getLongitude()   { return _lon; };
		int16_t getAltitude()   { return _alt; };
		double getSpeed()       { return _speed; };
		uint16_t getHeartRate() { return _bpm; };
		uint16_t getFiability() { return _fiability; };
		bool isImportant()      { return _important; };
		time_t getTime()        { return _time; };
		// TODO: Is it really the right place ? We may want to do it with any time ! To move in a "utils" part
		std::string getTimeAsString(bool human_readable=false)
		{  
			char buffer[256];
			tm *time_tm = localtime(&_time);
			std::stringstream format_string;
			if(human_readable)
				format_string << "%Y-%m-%d %H:%M:%S." << _tenth;
			else
				format_string << "%Y-%m-%dT%H:%M:%S." << _tenth << "Z";
			if(_tenth > 9)
			{
				std::cout << "Error: tenth bigger than 9 ! This is totally unexpected ... " << _tenth << std::endl;
			}
			strftime(buffer, 256, format_string.str().c_str(), time_tm);
			return std::string(buffer);
		};

	private:
		double   _lat;
		double   _lon;
		int16_t  _alt;
		double   _speed;
		time_t   _time;
		uint32_t _tenth;
		uint16_t _bpm;
		uint16_t _fiability;
		uint16_t _important;
};

#endif