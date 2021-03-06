DEFAULT_PREFERENCE = "-1"
LICENSE = "LGPLv2.1 GPLv3"

FILESPATHPKG .= ":qt-${PV}"

SRC_URI = "\
	ftp://ftp.trolltech.com/qt/source/qt-everywhere-opensource-src-${SRCVER}.tar.gz \
	file://0004-no-qmake.patch \
	file://hack-out-pg_config.patch \
	file://0006-freetype-host-includes.patch \
	file://0001-Added-Openembedded-crossarch-option.patch \
	file://0002-Disable-tools-assistant.patch \
	file://0003-Disable-examples-designer.patch \
	file://0004-Disable-exaqmples-dbus-remotecontrolledcar.patch \
	file://0005-Disable-examples-help.patch \
	file://0007-Disable-demos-qtdemos.patch \
	file://0008-Disable-examples-declarative.patch \
	file://demos.browser.add.mediaservices.lib.patch \
	file://add.xmlpatterns.lib.patch \
	file://g++.conf \
	file://linux.conf \
           "

S = "${WORKDIR}/qt-everywhere-opensource-src-${SRCVER}"

QT_LIB_NAMES += "QtDeclarative"
FILES_${QT_BASE_NAME}-tools                += "${bindir}/qml"

do_configure_prepend() {
    for pro in $(find ${S} -name "*.pro") ; do
        sed -i 's:$$QT_BUILD_TREE/bin/lrelease:${OE_QMAKE_LRELEASE}:g' $pro
    done

    sed -i s:SEDME:${S}: ${WORKDIR}/linux.conf
    sed -i \
    -e /QMAKE_MOC\ /d \
    -e /QMAKE_UIC\ /d \
    -e /QMAKE_UIC3\ /d \
    -e /QMAKE_RCC\ /d \
    ${S}/configure
}

do_configure_append() {
    sed -e '/QMAKE_TARGET /d' -e '/TARGET /d' -i ${S}/translations/Makefile
}

QT_GLFLAGS ?= ""
QT_CONFIG_FLAGS += " -xmlpatterns -no-rpath -qt3support -reduce-relocations -silent ${QT_GLFLAGS}"

do_compile() {
    # Fixup missing wsegl header in some SGX SDKs
    if ! [ -e ${STAGING_INCDIR}/wsegl.h ] ; then
        cp src/3rdparty/powervr/wsegl.h src/plugins/gfxdrivers/powervr/QWSWSEGL/
    fi

    unset CFLAGS CXXFLAGS
    install -m 0755 ${STAGING_BINDIR_NATIVE}/rcc4 ${S}/bin/rcc
    install -m 0755 ${STAGING_BINDIR_NATIVE}/moc4 ${S}/bin/moc
    install -m 0755 ${STAGING_BINDIR_NATIVE}/uic4 ${S}/bin/uic
    install -m 0755 ${STAGING_BINDIR_NATIVE}/lrelease4 ${S}/bin/lrelease

    oe_runmake ${EXTRA_ENV}
}

do_install_append() {
	install -d ${D}${bindir}
	for i in rcc uic moc ; do
		install -m 0755 ${S}/bin/$i ${D}${bindir}/
	done
}

SRC_URI[md5sum] = "1449443c2d33ab9fefbd37b7104d0cdf"
SRC_URI[sha256sum] = "e0196ee11f683a4ec2e3f85e52ab2f2455886a3bb3b711489176f97ecb9aacbf"
