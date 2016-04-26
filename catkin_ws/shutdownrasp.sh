#!/bin/bash

sshpass -p 'ubuntu' ssh ubuntu@bluerov -t 'echo ubuntu | sudo -S shutdown -h now'
