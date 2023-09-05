#include "simpleLogger.h"

#include <boost/log/core/core.hpp>
#include <boost/log/expressions/formatters/date_time.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/trivial.hpp>
#include <boost/core/null_deleter.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/log/common.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/utility/setup.hpp>
#include <random>
#include <fstream>
#include <ostream>
#include <iostream>

#include <unistd.h>
#include <signal.h>

#include <boost/log/trivial.hpp>
#include <boost/log/sources/global_logger_storage.hpp>
namespace logging = boost::log;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace sinks = boost::log::sinks;
namespace attrs = boost::log::attributes;
namespace logkw = logging::keywords;

BOOST_LOG_ATTRIBUTE_KEYWORD(line_id, "LineID", unsigned int)
BOOST_LOG_ATTRIBUTE_KEYWORD(timestamp, "TimeStamp", boost::posix_time::ptime)
BOOST_LOG_ATTRIBUTE_KEYWORD(severity, "Severity", logging::trivial::severity_level)

BOOST_LOG_GLOBAL_LOGGER_INIT(logger, src::severity_logger_mt)
{
    src::severity_logger_mt<boost::log::trivial::severity_level> logger;

    // add attributes
    logger.add_attribute("LineID", attrs::counter<unsigned int>(1)); // lines are sequentially numbered
    logger.add_attribute("TimeStamp", attrs::local_clock());         // each log line gets a timestamp

    typedef sinks::synchronous_sink<sinks::text_ostream_backend> text_sink;
    boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();

    logging::formatter formatter = expr::stream
                                   << std::setw(7) << std::setfill('0') << line_id << std::setfill(' ') << " | "
                                   << expr::format_date_time(timestamp, "%Y-%m-%d, %H:%M:%S.%f") << " "
                                   << "[" << logging::trivial::severity << "]"
                                   << " - " << expr::smessage;
    sink->set_formatter(formatter);

    logging::add_file_log("/home/shrief/Desktop/File_Handler_Modified/run_logs.txt", logkw::open_mode = std::ios::app)
        ->set_formatter(formatter);

    // only messages with severity >= SEVERITY_THRESHOLD are written
    sink->set_filter(severity >= SEVERITY_THRESHOLD);

    // "register" our sink
    logging::core::get()->add_sink(sink);
    logging::keywords::auto_flush = true;
    return logger;
}
