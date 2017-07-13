# Boldport Touchy API Demo and Fidget firmware

Here you'll find a simple API--and two projects based on it--written for Boldport Club project number 7, aptly named "Touchy". The kit is based on an EFM8SB1 aka "Sleepy Bee" microcontroller. Be sure to check out the offical project page at https://www.boldport.com/products/touchy and be sure to sign up for the club at https://boldport.club - it's very much worth it!

## What's new/different?

The API Demo verion of the firmware adds quite a few capabilities over what the original "Simple" firmware did:
<ul>
<li>First--and arguably most importantly--this firmware enables the microcontroller to properly sleep, which preserves the life of the small button battery for a significantly longer period of time. The code was present in the original firmware but the feature was not enabled in the capsense library (CSLib) so, despite that the API call was happening, the library would not act on it, preventing the microcontroller from sleeping when it was idle. With sleeping enabled, you'll now observe that the LEDs all simply turn off after about five seconds of no activity. Touching any sensor wakes the device and the LEDs will immediately be restored to their previous state.</li>
<li>Two timers (as opposed to just one in the original firmware) are now used to generate two independent PWM signals so that LEDs one and six (the outer two) can both be "dimmed".</li>
<li>LEDs two through five can be toggled on and off with their respective buttons, while LEDs one and six are set to "opposite" intensities with the circle slider.</li>
<li>Buttons one and six do something special...try them and find out what it is!</li>
</ul>

## What is this "Fidget" firmware?

Your Boldport Club Touchy kit will be your new favorite toy if you're one of those folks who just loves to fidget as you work/think/daydream/wander around aimlessly! Seriously, though...it just provides a few different ways to use the buttons and circular slider to manipulate the LEDs on the device. It's really just intended to make Touchy more enjoyable and fun after you've got it assembled. A "notes.txt" file can be found in the project folder which describes the functionality of the device with this firmware installed.

## Authors

The board's orignal firmware was written by Ronald Sousa @Opticalworm - @HashDefineElec - www.hashdefineelectronics.com<br />
The API, API Demo app, and Fidget firmware were later written by Keith Burzinski @kbx81 kbx81x@gmail.com

## Project Pages

The offical product/project homepage is at https://www.boldport.com/products/touchy<br />
The original project firmware page can be found at http://www.hashdefineelectronics.com/boldport-project-7-touchy/

## Setup

The projects and API found here were developed using Silabs Simplicity Studio version 9.53 in July of 2017.

## Directories

<ul>
<li><b>HEX</b><br />
This is where the compiled version of the projects are stored. These are provided purely for convenience for those who want to get the board working quickly and with as little hassle as possible.</li

<li><b>BoldportTouchyAPIDemo</b><br />
This directory contins the project files and source code of the program which demonstrates the API and tests the basic functionality of the Touchy board. It uses Silabs CapsenseCircleSlider example project as its template and the Touchy API integrates the template's functionality.</li>

<li><b>BoldportTouchyFidgetFirmware</b><br />
This directory contins the project files and source code of the Fidget firmware application which is based on the Touchy API and capsense libraries.</li>

<li><b>Bootloader</b><br />
Files/binaries to assist with loading the firmware image(s) onto the device.</li>
</ul>

### Demo Videos

Ronald Sousa created videos detailing the process of loading the firmware onto the board. They can be found on his Touchy project page at https://www.hashdefineelectronics.com/boldport-project-7-touchy/

## IDE

This project uses Silabs Simplicity Studio. The API was built with version 9.53 of Simplicity Studio.

## Importing projects to Simplicity Studio

It is possible to import this project into your instance of Simplicity Studio if you wish to modify the project and/or otherwise write your own application(s).<br /><br />

After installing Simplicity Studio:<br />
Right-click inside of the Project Explorer pane<br />
Click "Import" and then click "Import..." (again)<br />
Under the "General" folder, select "Existing Project into Workspace", then click Next<br />
Choose the "Select root directory" option and then click Browse...<br />
In the Browse window, find and click on the project directory and click OK<br />
Finally, ensure the check box for the project is selected and then click on Finish<br /><br />

This will bring the project into Simplicity Studio where you can modify as you wish.

## Other thoughts/things/stuff

<p>Getting Ronald's original "Simple" project working was a challenge; this was not because he did a bad job creating it, but more because of a number of challenges I had with Simplicity Studio along the way. It wouldn't surprise me if, after a few months, getting this one working again proves difficult, as well. That said, this project was quite fun to work with and write.</p>
<p>Please note that it will be necessary to acquire a license for the Keil compiler included with Simplicity Studio. The
 license is free but does require one to roll through the registration process. Click on the "Help" menu, then select
 "Licensing" and finally click on the "Keil 8051" item. This will open a window with a link which will direct you to their
 registraion page. Complete the process to acquire your license key.</p>
<p>Note that if you do not acquire a license for the Keil compiler, you'll end up with an overwhelming number of compiler
 errors complaining about address space errors and the like. I found it rather misleading the first time through, so do not
 overlook this important step! The code exceeds the size limit of the unlicensed or "restricted" version provided.</p>
 <p>Good luck and happy hacking!</p>
