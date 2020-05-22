#! /bin/sh
ifconfig | grep -o "HWaddr.*"| sed "s/HWaddr //"
