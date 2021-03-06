DESCRIPTION = "A QDialog shell frontend"
SECTION = "opie/shell"
PRIORITY = "optional"
LICENSE = "GPL"
APPNAME = "opie-sh"
APPTYPE = "binary"
PR = "r3"

S = "${WORKDIR}/${APPNAME}"

inherit opie

# FILES bin/opie-sh apps/Opie-SH/opie-sh.desktop pics/opie-sh/*.png help/opie-sh/*.html
do_install() {
	install -d ${D}${palmtopdir}/bin
	install -m 0755 ${WORKDIR}/${APPNAME}/scripts/*.sh ${D}${palmtopdir}/bin/
	install -m 0755 ${WORKDIR}/bin/opie-sh-howto.sh ${D}${palmtopdir}/bin/
        install -d ${D}${palmtopdir}/pics/${APPNAME}/
        install -m 0644 ${WORKDIR}/pics/${APPNAME}/*.png ${D}${palmtopdir}/pics/${APPNAME}/
        install -d ${D}${palmtopdir}/pics/opie-sh-scripts/
        install -m 0644 ${WORKDIR}/pics/opie-sh-scripts/*.png ${D}${palmtopdir}/pics/opie-sh-scripts/
	install -d ${D}${palmtopdir}/apps/Opie-SH/
	install -m 0644 ${WORKDIR}/apps/Opie-SH/*.desktop ${D}${palmtopdir}/apps/Opie-SH/
	install -d ${D}${palmtopdir}/help/${APPNAME}/
	install -m 0644 ${WORKDIR}/help/${APPNAME}/*.html ${D}${palmtopdir}/help/${APPNAME}/
	install -d ${D}${palmtopdir}/share/config
	install -m 0644 ${WORKDIR}/share/config/*.cfg  ${D}${palmtopdir}/share/config/
	rm -f ${D}${palmtopdir}/pics/opie-sh-scripts/kbdctrl.png
}

PACKAGES += " opie-sh-microkbd opie-sh-diskfree opie-sh-fsmounter opie-sh-hostlist \
opie-sh-killproc opie-sh-launcher-refresh opie-sh-logviewer opie-sh-rsynchelper \
opie-sh-servicemanager opie-sh-ssh-askpass opie-sh-stowawayctrl opie-sh-usbnetctrl \
opie-sh-wavelanchooser "

RDEPENDS_opie-sh-microkbd = "opie-sh"
RDEPENDS_opie-sh-diskfree = "opie-sh"
RDEPENDS_opie-sh-fsmounter = "opie-sh"
RDEPENDS_opie-sh-hostlist = "opie-sh"
RDEPENDS_opie-sh-killproc = "opie-sh"
RDEPENDS_opie-sh-launcher-refresh = "opie-sh"
RDEPENDS_opie-sh-logviewer = "opie-sh"
RDEPENDS_opie-sh-rsynchelper = "opie-sh"
RDEPENDS_opie-sh-servicemanager = "opie-sh"
RDEPENDS_opie-sh-ssh-askpass = "opie-sh"
RDEPENDS_opie-sh-stowawayctrl = "opie-sh"
RDEPENDS_opie-sh-usbnetctrl = "opie-sh"
RDEPENDS_opie-sh-wavelanchooser = "opie-sh"

FILES_opie-sh-microkbd = " ${palmtopdir}/bin/microkbd.sh ${palmtopdir}/apps/Opie-SH/microkbd.desktop ${palmtopdir}/pics/opie-sh-scripts/keyz-cfg.png"
FILES_opie-sh-diskfree = " ${palmtopdir}/bin/diskfree.sh ${palmtopdir}/apps/Opie-SH/diskfree.desktop ${palmtopdir}/pics/opie-sh-scripts/diskfree.png"
FILES_opie-sh-fsmounter = " ${palmtopdir}/bin/filesystem_mounter.sh ${palmtopdir}/pics/opie-sh-scripts/fsmounter.png ${palmtopdir}/apps/Opie-SH/filesystem_mounter.desktop"
FILES_opie-sh-hostlist = " ${palmtopdir}/bin/hostlist.sh ${palmtopdir}/pics/opie-sh-scripts/hostlist.png ${palmtopdir}/apps/Opie-SH/hostlist.desktop ${palmtopdir}/share/config/hostlist.cfg"
FILES_opie-sh-killproc = " ${palmtopdir}/bin/killproc.sh ${palmtopdir}/apps/Opie-SH/killproc.desktop ${palmtopdir}/pics/opie-sh-scripts/killproc.png"
FILES_opie-sh-launcher-refresh = " ${palmtopdir}/bin/launcher_refresh.sh ${palmtopdir}/pics/opie-sh-scripts/launcher_refresh.png ${palmtopdir}/apps/Opie-SH/launcher_refresh.desktop"
FILES_opie-sh-logviewer = " ${palmtopdir}/bin/logviewer.sh ${palmtopdir}/apps/Opie-SH/logviewer.desktop ${palmtopdir}/pics/opie-sh-scripts/logviewer.png"
FILES_opie-sh-rsynchelper = " ${palmtopdir}/bin/rsyncme.sh ${palmtopdir}/apps/Opie-SH/rsyncme.desktop ${palmtopdir}/pics/opie-sh-scripts/rsyncme.png ${palmtopdir}/share/config/rsyncme.cfg"
FILES_opie-sh-servicemanager = " ${palmtopdir}/bin/service_manager.sh ${palmtopdir}/apps/Opie-SH/service_manager.desktop ${palmtopdir}/pics/opie-sh-scripts/service_manager.png"
FILES_opie-sh-ssh-askpass = " ${palmtopdir}/bin/opie-sh-ssh-askpass.sh"
FILES_opie-sh-stowawayctrl = " ${palmtopdir}/bin/stowctrl.sh ${palmtopdir}/apps/Opie-SH/stowctrl.desktop ${palmtopdir}/pics/opie-sh-scripts/stowctrl.png"
FILES_opie-sh-usbnetctrl = " ${palmtopdir}/bin/usbnetctrl.sh ${palmtopdir}/apps/Opie-SH/usbnetctrl.desktop ${palmtopdir}/pics/opie-sh-scripts/usbnetctrl.png"
FILES_opie-sh-wavelanchooser = " ${palmtopdir}/bin/opie-sh-wavelanchooser.sh ${palmtopdir}/apps/Opie-SH/opie-sh-wavelanchooser.desktop ${palmtopdir}/pics/opie-sh-scripts/qtwavelan.png"
FILES_${PN} = " ${palmtopdir}/bin/opie-sh-howto.sh ${bindir}/opie-sh ${palmtopdir}/apps/Opie-SH/opie-sh.desktop ${palmtopdir}/pics/opie-sh/*.png ${palmtopdir}/help/opie-sh/*.html"

