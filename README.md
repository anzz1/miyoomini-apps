# miyoomini-apps
Apps for Miyoo Mini / Onion OS

## Build instructions

### 1. Boot to the miyoomini-toolchain docker image

#### A) Using [Docker](https://docs.docker.com/get-docker/) (Linux, MacOS, x86_64, ARM64)

1. Pull the miyoomini-toolchain docker image  
`docker pull mholdg16/miyoomini-toolchain:latest`

2. Boot to the image  
`docker run -it --rm -v $HOME/workspace:/root/workspace mholdg16/miyoomini-toolchain:latest /bin/bash`

#### B) Using [Vagrant](https://developer.hashicorp.com/vagrant/) / [VirtualBox](https://www.virtualbox.org/) (Windows, x86_64)

1. Install both [VirtualBox](https://www.virtualbox.org/wiki/Downloads) and [Vagrant](https://developer.hashicorp.com/vagrant/downloads)

2. Make a directory for the container  
`mkdir C:\vagrant\miyoomini-toolchain && cd /d C:\vagrant\miyoomini-toolchain`

3. Download the miyoomini-toolchain Vagrantfile  
`wget https://raw.githubusercontent.com/anzz1/miyoomini-resources/master/miyoomini-toolchain-vagrant/Vagrantfile`

4. Provision the virtual machine  
`vagrant up`

5. Boot up the virtual machine  
`vagrant up`

6. Connect to miyoomini-toolchain VM  
`vagrant ssh`  
or connect via SSH - IP: localhost:2222 / User: docker / Pass: empty  
  
   (after you're done, shut down the VM with `vagrant halt` or destroy it with `vagrant destroy`)


### 2. Build

1. Clone the repository
`git clone https://github.com/anzz1/miyoomini-apps.git`

2. Build the app  
`cd miyoomini-apps/ssh-server`  
`./build.sh`

3. The built binaries are in the `bin` folder
