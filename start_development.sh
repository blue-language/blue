#!/usr/bin/env bash

mkdir -p ${HOME}/.docker ${HOME}/.ssh
touch ${HOME}/.gitconfig

docker run -it \
    --env HISTFILE=${PWD}/.zsh_history \
    --privileged \
    --rm \
    --user `id -u`:`id -g` \
    --volume /var/run/docker.sock:/var/run/docker.host.sock \
    --volume ${HOME}/.gitconfig:/home/developer/.gitconfig \
    --volume ${HOME}/.ssh:/home/developer/.ssh \
    --volume ${PWD}:${PWD} \
    --workdir ${PWD} \
    sandrohuber/blue-language:latest
