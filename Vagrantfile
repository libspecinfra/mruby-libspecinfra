# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure("2") do |config|
  config.vm.define :xenial64 do |c|
    c.vm.box = "ubuntu/xenial64"
    c.vm.provision :shell, inline: <<-EOF
      curl https://sh.rustup.rs -sSf | su -l ubuntu -c "sh -s -- -y"
      apt-get update
      apt-get install -y gcc libssl-dev pkg-config cmake \
        libdbus-glib-1-dev rake bison nginx ruby-dev ruby-bundler
      if [ ! -s /usr/local/lib/libspecinfra.so ]; then
        ln -s /vagrant/specinfra/target/debug/libspecinfra.so \
         /usr/local/lib/
      fi
      curl https://sh.rustup.rs -sSf | sh -s -- -y
      ldconfig
    EOF
  end

  config.vm.define :centos7 do |c|
    c.vm.box = "centos/7"
    c.vm.provision :shell, inline: <<-EOF
      curl https://sh.rustup.rs -sSf | su -l vagrant -c "sh -s -- -y"
      yum install -y gcc openssl-devel cmake dbus-devel
    EOF
  end

  config.vm.network "private_network", ip: "192.168.10.100"
  config.vm.synced_folder "..", "/vagrant", type: "nfs"
end
