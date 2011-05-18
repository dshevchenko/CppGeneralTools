// wait.hpp
// ~~~~~~~~
// 
// Copyright (C) 2011 Denis Shevchenko (for @ dshevchenko.biz)
//
// Distributed under the Boost Software License, version 1.0
// (see http://www.boost.org/LICENSE_1_0.txt)

#ifndef CPP_GENERAL_TOOLS_WAIT_HPP
#define CPP_GENERAL_TOOLS_WAIT_HPP

#include <boost/thread.hpp>
#include <boost/assert.hpp>

namespace cpp_general_tools {

struct wait {
    void operator()( const time_t pause ) const {
        if ( 0 == pause ) return;
        boost::xtime xt;
        boost::xtime_get( &xt, boost::TIME_UTC );
        xt.sec += pause;
        boost::thread::sleep( xt );
    }
};

struct wait_in_fractions_of_second {
    void operator()( const double pause ) const {
        BOOST_ASSERT ( pause > 0.0 );
        boost::xtime xt;
        boost::xtime_get( &xt, boost::TIME_UTC );
        xt.nsec += static_cast< unsigned long int >( pause * 1000000000 );
        boost::thread::sleep( xt );
    }
};

} // namespace cpp_general_tools

#endif // CPP_GENERAL_TOOLS_WAIT_HPP
