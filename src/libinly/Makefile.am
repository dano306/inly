
AUTOMAKE_OPTIONS = foreign

# _LTLIBRARIES 是 Automake 支持 Libtool 的原语
lib_LTLIBRARIES = libinly.la
libinly_la_SOURCES = CInly.cpp
libinly_la_CPPFLAGS = $(AM_CPPFLAGS) -Wall
libinly_la_CXXFLAGS=$(AM_CFLAGS) `pkg-config cryptopp  --cflags`

# 可以通过 _LDFLAGS 传递选项给 Libtool 
#libinly_la_LDFLAGS = 

# 通过 _LIBADD 可以指定库依赖关系
#libinly_la_LIBADD  = -lm `pkg-config cryptopp  --libs`

# 不合适在这里指定，还是得由./configure时进行配置
#includedir=${prefix}/include/inly/
nobase_include_HEADERS = CInly.h
