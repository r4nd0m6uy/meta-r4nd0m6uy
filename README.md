Generic yocto meta-layer containing useful recipes for my own purpose.

# git-server-image
A *git-server-image* is available to install a minimalistic git server with gitolite.

To initialize gitolite, scp your ssh public key on the target and initialize gitolite as git
user as follow:

> ssh root@<ip> # gitgit

> su git

> /var/lib/gitolite/gitolite setup -pk <my_public_key.pub>

Then you should be able to clone the gitolite-admin repository:

> git clone git@<ip>:gitolite-admin

For obvious security reason, I should not remind you to **deactivate or update the root
password!**

## TODO
* Add cgit
