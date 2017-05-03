Docker Image Repo:
https://hub.docker.com/r/heartcase/ece4574_final/

pull:

docker pull heartcase/ece4574_final

run:
xhost local:root
docker run -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY=$DISPLAY -v /dev/shm:/dev/shm -v ~/src:/root --device /dev/dri --name qt_creator --rm --entrypoint /opt/Qt/Tools/QtCreator/bin/qtcreator heartcase/ece4574_final:latest

sorce:https://nicroland.wordpress.com/2015/12/06/running-qtcreator-in-docker/

Instruction:
Pull the image
Run the container, this will open the Qt creator window
to run test for unit test
open the project /4574_final/DesktopApp/DesktopAppTesting/unitTest/DesktopAppTest/
build and run the test.
to run test for Integration test with api
open the project /4574_final/DesktopApp/DesktopAppTesting/IntegrationTest/DesktopAppIntegrationTest/
build and run the test.

Dylan Zeigler
Boyang Li
