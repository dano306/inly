#!/bin/bash

aclocal
autoconf
libtoolize --automake --copy --debug --force
automake --add-missing
