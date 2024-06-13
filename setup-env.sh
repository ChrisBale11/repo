#!/bin/bash
#this script is used to set up the environment for build the rpms

# install the necessary tools
dnf install rpmdevtools

# assign the workplace
RPM_WORKPLACE="`pwd`/rpmbuild"
echo "%_topdir ${RPM_WORKPLACE}" > ~/.rpmmacros

# initialize the rpms tree where we build rpms
rpmdev-setuptree

