// stop_this_thread.hpp
// ~~~~~~~~~~~~~~~~~~~~
// 
// Copyright (C) 2011 Denis Shevchenko (for @ dshevchenko.biz)
//
// Distributed under the Boost Software License, version 1.0
// (see http://www.boost.org/LICENSE_1_0.txt)

#ifndef CPP_GENERAL_TOOLS_STOP_THIS_THREAD_HPP
#define CPP_GENERAL_TOOLS_STOP_THIS_THREAD_HPP

namespace cpp_general_tools {

template
    <
        typename Mutex
        , typename Condition
        , typename Lock
    >
class stop_this_thread {
    mutable Mutex     stop;
    mutable Condition cond;
public:
    void operator()() const {
        Lock lock( stop );
        cond.wait( lock );
    }
};

} // namespace cpp_general_tools

#endif // CPP_GENERAL_TOOLS_STOP_THIS_THREAD_HPP
