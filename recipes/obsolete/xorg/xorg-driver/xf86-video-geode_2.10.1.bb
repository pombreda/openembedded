require xorg-driver-video.inc
DESCRIPTION = "X.org server -- Geode GX2/LX display driver"
PE = "1"
PR = "${INC_PR}.0"

SRC_URI[archive.md5sum] = "e307ab55a2a81d7868506df789f76dfb"
SRC_URI[archive.sha256sum] = "9b6ef818e402e2c1b7b2f36eff657b8104c67d738f10d4d7d39c7bc118a8c650"

COMPATIBLE_HOST = "i.86.*-linux"
