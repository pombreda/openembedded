require xorg-proto-common.inc
PE = "1"
PR = "${INC_PR}.0"

SRC_URI[archive.md5sum] = "95c29d9d10bf2868996c0c47a3b9a8dc"
SRC_URI[archive.sha256sum] = "30da0098a24578e645193464526cc4d5c2c7fecaf476d1b9dabe68118850adee"

BBCLASSEXTEND = "native nativesdk sdk"
