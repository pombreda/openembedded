DEPENDS = "${DVB_PACKAGES}"
DVB_PACKAGES = "${MACHINE_TASK_PROVIDER} task-dvb"

IMAGE_INSTALL = "${DVB_PACKAGES}"
IMAGE_LINGUAS = ""

inherit image
