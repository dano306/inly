#!/bin/bash

aclocal
autoconf
libtoolize --automake --copy --force #--debug
automake --add-missing
