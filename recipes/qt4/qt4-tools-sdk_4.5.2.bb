DESCRIPTION = "SDK tools for Qt/[X11|Mac|Embedded] version 4.x"
DEPENDS = "zlib-native dbus-native"
SECTION = "libs"
HOMEPAGE = "http://www.trolltech.com"
PRIORITY = "optional"
LICENSE = "LGPLv2.1 GPLv3"

inherit sdk

SRC_URI = "ftp://ftp.trolltech.com/qt/source/qt-embedded-linux-opensource-src-${PV}.tar.bz2 \
           file://configure-lflags.patch \
           file://qt-config.patch \
           file://g++.conf \
           file://linux.conf"
S = "${WORKDIR}/qt-embedded-linux-opensource-src-${PV}"

# FIXME: make it work with "${STAGING_BINDIR_NATIVE}/pkg-config --cflags dbus-1"
EXTRA_OECONF = "-prefix ${prefix} \
                -qt-libjpeg -qt-gif -system-zlib \
                -no-libjpeg -no-libpng \
                -no-accessibility \
                -no-cups \
                -no-exceptions  \
                -no-nas-sound \
                -no-nis \
                -verbose -release -fast -static \
                -qt3support \
                -I${STAGING_DIR_NATIVE}/usr/include \
                -I${STAGING_DIR_NATIVE}/usr/include/dbus-1.0 \
                -I${STAGING_DIR_NATIVE}/usr/lib/dbus-1.0/include"

# yank default -e, otherwise we get the following error:
# moc_qbuffer.cpp: No such file or directory
EXTRA_OEMAKE = " "

do_configure() {
   (echo o; echo yes) | ./configure ${EXTRA_OECONF} || die "Configuring qt failed. EXTRA_OECONF was ${EXTRA_OECONF}"
}

TOBUILD = "\
  src/tools/bootstrap \
  src/tools/moc \
  src/corelib \
  src/sql \
  src/dbus \
  src/qt3support \
  src/xml \
  src/tools/uic \
  src/tools/rcc \
  src/network \
  src/gui \
  src/tools/uic3 \
  tools/linguist/lrelease \
  tools/linguist/lupdate \
  tools/qdbus \
"

do_compile() {
    for i in ${TOBUILD}; do
        cd ${S}/$i && oe_runmake CC="${CC}" CXX="${CXX}"
    done
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 bin/qmake ${D}${bindir}/qmake2
    for i in moc uic uic3 rcc lrelease lupdate qdbuscpp2xml qdbusxml2cpp; do
        install -m 0755 bin/${i} ${D}${bindir}/${i}4
    done
}


SRC_URI[md5sum] = "62186345c609a72b89f16d83bc7a130f"
SRC_URI[sha256sum] = "272301a27e2f7bcd44c8d09f496e1c749c80b86d9489ea9c30bb265bf2dd02fc"
