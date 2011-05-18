// pimpl.hpp
// ~~~~~~~~~
// 
// Copyright (C) 2011 Denis Shevchenko (for @ dshevchenko.biz)
//
// Distributed under the Boost Software License, version 1.0
// (see http://www.boost.org/LICENSE_1_0.txt)

#ifndef CPP_GENERAL_TOOLS_PIMPL_HPP
#define CPP_GENERAL_TOOLS_PIMPL_HPP

#include <boost/scoped_ptr.hpp>

namespace cpp_general_tools {

#define PIMPL                                           \
    private:                                            \
        struct implementation;                          \
        const boost::scoped_ptr< implementation > impl;

} // namespace cpp_general_tools

#endif // CPP_GENERAL_TOOLS_PIMPL_HPP
