DESCRIPTION = "Gitolite server image"
LICENSE = "GPLv3"

inherit core-image

IMAGE_FEATURES_append = "\
  ssh-server-openssh \
  package-management \
  gitolite \
  "

IMAGE_INSTALL = " \
  packagegroup-core-boot \
  "

# Root password
EXTRA_USERS_PARAMS = "usermod -P gitgit root;"
