
AUTOMAKE_OPTIONS = foreign

# _LTLIBRARIES 是 Automake 支持 Libtool 的原语
lib_LTLIBRARIES = libinly.la
libinly_la_SOURCES = CInly.cpp CAesWrapper.cpp
libinly_la_CPPFLAGS = $(AM_CPPFLAGS) -Wall
libinly_la_CXXFLAGS=$(AM_CFLAGS) `pkg-config cryptopp  --cflags`

# 可以通过 _LDFLAGS 传递选项给 Libtool 
libinly_la_LDFLAGS = `pkg-config cryptopp  --libs` -lboost_filesystem-mt

# 不合适在这里指定，还是得由./configure时进行配置
#includedir=${prefix}/include/inly/
nobase_include_HEADERS = inly.h inly_core.h CInly.h

noinst_HEADERS = CAesWrapper.h
