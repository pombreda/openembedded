require ${PN}.inc
PR = "r1"

SRC_URI = "${HANDHELDS_CVS};tag=${TAG};module=opie/core/apps/calibrate \
           ${HANDHELDS_CVS};tag=${TAG};module=opie/noncore/settings/mediummount \
           ${HANDHELDS_CVS};tag=${TAG};module=opie/core/launcher \
           ${HANDHELDS_CVS};tag=${TAG};module=opie/pics \
           ${HANDHELDS_CVS};tag=${TAG};module=opie/apps \
           ${HANDHELDS_CVS};tag=${TAG};module=opie/root \
           ${HANDHELDS_CVS};tag=${TAG};module=opie/etc \
           file://nomax.patch;striplevel=3 \
           file://no-builtin-qss-startup.patch \
           file://kbdlocks-runtime.patch \
	   file://restart-from-bindir.patch \
           file://server-pro-old.patch \
	   file://firstuse-path.patch \
          "
