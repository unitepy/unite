#!/usr/bin/env bash

dpkg-deb -b unitepy unitepy.deb >> /dev/null 2>&1
echo "Package builded."