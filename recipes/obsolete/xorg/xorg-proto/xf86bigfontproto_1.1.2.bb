require xorg-proto-common.inc
PE = "1"
PR = "${INC_PR}.0"

SRC_URI[archive.md5sum] = "a318c1e86123832d7b0c95fc7d47ef35"
SRC_URI[archive.sha256sum] = "01b475b5b27709a738db6f94ce2ded37f5db0792e8d9318069ecf1690a15f124"

BBCLASSEXTEND = "native nativesdk sdk"
