require xorg-lib-common.inc

DESCRIPTION = "X11 miscellaneous extension library"
DEPENDS += "xproto-native libx11-native xextproto-native libxau-native util-macros-native"
PROVIDES = ""
PR = "r1"
PE = "1"

XORG_PN = "libXext"

inherit native 

SRC_URI[archive.md5sum] = "9e51f9cb7e0a38c7099ac1c0de1a1add"
SRC_URI[archive.sha256sum] = "ac6a0ff69c52c9b6e2096e5f74e22c8b5eef11ade4e30411cffeb7df32fe4f74"