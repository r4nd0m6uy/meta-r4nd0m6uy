SUMMARY = "Gitolite git server"
DESCRIPTION = "Gitolite allows you to host Git repositories easily and securely."
AUTHOR = "Sitaram Chamarty <sitaramc@gmail.com>"
HOMEPAGE = "http://gitolite.com/"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=8283b295ef0d03af318faa2ed2c5d5c8"

RDEPENDS_${PN} = " \
  git \
  perl \
  openssh \
  perl-module-findbin \
  perl-module-lib \
  perl-module-file-path \
  perl-module-file-temp \
  perl-module-data-dumper \
  perl-module-bytes \
  perl-module-file-glob \
  perl-module-getopt-long \
  "
DEPENDS = "perl-native"

inherit useradd

GITOLITE_BRANCH ?= "master"
SRCREV ?= "${AUTOREV}"

SRC_URI = "\
  git://github.com/sitaramc/gitolite.git;branch=${GITOLITE_BRANCH} \
  "

GITOLITE_USER ?= "git"
GITOLITE_HOME_DIR ?= "/var/gitolite"
EXTRANATIVEPATH += "perl-native"

USERADD_PACKAGES = "${PN}"
USERADD_PARAM_${PN} = "--home-dir ${GITOLITE_HOME_DIR} --system --create-home --shell /bin/sh ${GITOLITE_USER}"

S = "${WORKDIR}/git"

do_compile() {
  mkdir -p ${S}/install-dir
  perl ${S}/install -to ${S}/install-dir
}

do_install() {
  install -d ${D}/${localstatedir}/lib/gitolite
  cp -R ${S}/install-dir/* ${D}/${localstatedir}/lib/gitolite
  chmod go+rX ${D}/${localstatedir}/lib/gitolite -R
}
