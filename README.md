# C/C++ <--> Python interoperability
Experiments to learn interoperability mechanisms between C/C++ and Python.

Currently, the code uses ctypes to call into a small C++ library that generates a random uint32. In
the future, I'd like to look into the following:
- how using Boost.Python compares to ctypes
- how using SWIG compares to ctypes

My initial stab at this was using the CPython API directly. That API, while in depth, seemed _too_
in-depth for wrapping libraries that are fairly simple. Perhaps, down the line, I will revisit that
API if I ever need the level of control the CPython library offers.

Also, I am interested in wrapping native C++ code. One downside of ctypes and CPython is that they
require exposing C APIs for your code, which isn't great, since I want to program in C++.
