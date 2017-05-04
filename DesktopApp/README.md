Dockerized container repo:
https://hub.docker.com/r/heartcase/desktop_app/

Virginia Tech
ECE 4574
Spring 2017
Final Project
Team 1

Tools:
Qt, lunixdeployqt, appimage

Pull:
docker pull heartcase/desktop_app

Run:
xhost +

app:
docker run -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY=$DISPLAY -v /dev/shm:/dev/shm -v ~/src:/root --name app -it --rm --entrypoint /home/app/DesktopAppTest heartcase/desktop_app

unit_test:
docker run -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY=$DISPLAY -v /dev/shm:/dev/shm -v ~/src:/root --name app -it --rm --entrypoint /home/unit_test/DesktopAppTest heartcase/desktop_app

integration_test:
docker run -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY=$DISPLAY -v /dev/shm:/dev/shm -v ~/src:/root --name app -it --rm --entrypoint /home/integration_test/DesktopAppTest heartcase/desktop_app

Boyang Li
Dylan Zeigler
