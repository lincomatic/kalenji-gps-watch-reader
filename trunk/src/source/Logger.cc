#include "Logger.h"

#include <iostream>
#include <iomanip>
#include <fstream>

namespace source
{
	void Logger::init(uint32_t vendorId, uint32_t productId)
	{
		// TODO: Throw an exception if _truesource is null
		_truesource->init(vendorId, productId);
	}

	void Logger::release()
	{
		// TODO: Throw an exception if _truesource is null
		_truesource->release();
	}

	bool Logger::read_data(unsigned char **oData, size_t *oLength)
	{
		// TODO: Throw an exception if _truesource is null
		bool result = _truesource->read_data(oData, oLength);

		std::ofstream log_file_stream(_logfilename.c_str(), std::ios_base::out | std::ios_base::app);
		log_file_stream << std::hex;
		for(int i = 0; i < *oLength; ++i)
		{
			log_file_stream << std::setw(2) << std::setfill('0') << (int) (*oData)[i] << " ";
		}
		log_file_stream << std::dec << std::endl;
		log_file_stream.close();
		return result;
	}

	void Logger::write_data(unsigned char *iData, size_t iLength)
	{
		// TODO: Throw an exception if _truesource is null
		_truesource->write_data(iData, iLength);

		// TODO: For now we don't want to display what is sent. But will we one day ? In a different file ?
		/*
		   std::ofstream log_file_stream(_logfilename.c_str(), std::ios_base::out | std::ios_base::app);
		   log_file_stream << "Sending data: " << std::endl;

		   log_file_stream << std::hex;
		   for(int i = 0; i < iLength; ++i)
		   {
		   log_file_stream << std::setw(2) << std::setfill('0') << (int) iData[i] << " ";
		   }
		   log_file_stream << std::dec << std::endl;
		 */
	}
}
