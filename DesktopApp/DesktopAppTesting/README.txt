Dockerizing QT tests are turning out to be a more complex process than expected. 
So one way to run these tests in a "Dockerized" fashion is to follow the following steps.
Otherwise, booting these tests up in qtcreator will work if all else fails.


Reteiving a qt IDE docker image:

-------Step 1.

clone qt project files from github

	git clone https://github.com/tonyt1/4574_Final.git

desktop app integration and unit testing exist under DesktopApp/DesktopAppTesting 


-------Step 2.

pull the qt IDE docker image from a nice man named zach

	docker pull zachdeibert/qt-creator

**thank you zach**


-------Step 3.

run the IDE gui

	docker run -v /tmp:/tmp zachdeibert/qt-creator $DISPLAY $USER

qtcreator should appear on the screen. Here is where I was running in to issues
with permissions and I was not able to access my home directory. I tried changing
permissions and the like and I could not get it to work. But you should be able to
pull up the project from the repository in step 1 and click run for the tests.


- Dylan Zeigler -
	