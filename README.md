# Boldport Touchy API Demo firmware

Here you'll find a simple API written for Boldport project number 7 aka Touchy. The kit is based on an EFM8SB1 aka "Sleepy Bee" microcontroller. Be sure to check out the offical project page at https://www.boldport.com/products/touchy and be sure to sign up for the club at https://boldport.club - it's very much worth it!

## What's new/different?

This verion of the firmware adds quite a few capabilities over what the original "Simple" firmware did. First--and arguably most importantly--this firmware enables the microcontroller to properly sleep, which should preserve the life of the small button battery for a much longer period of time. The code was present in the original firmware but the feature was not enabled in the capsense library so, while the call was happening, the library wouldn't act on it, preventing the microcontroller from sleeping when it was idle. This behavior can be observed in this firmwire when, after about five seconds of no activity, the LEDs all simply turn off. Touching any sensor wakes the device and the LEDs will be restored to their previous state. In addition, two timers are now used to generate two independent PWM signals so that LEDs one and six (the outer two) can both be "dimmed". LEDs two through five can be toggled on and off with their respective buttons, while LEDs one and six are set to "opposite" intensities with the circle slider. Buttons one and six do something special...try them and find out what it is!

## Authors

The board's orignal firmware was written by Ronald Sousa @Opticalworm - @HashDefineElec - www.hashdefineelectronics.com<br />
The API was later written by Keith Burzinski @kbx81 kbx81x@gmail.com

## Project Page

The original project firmware page can be found at http://www.hashdefineelectronics.com/boldport-project-7-touchy/

## Setup

The project and API were developed using Silabs Simplicity Studio.

## Directories

<ul>
<li><b>HEX</b><br />
This is where the compiled version of the projects are stored. These are provided purely for convenience for those who want to get the board working quickly and with as little hassle as possible.

<li><b>BoldportTouchyAPIDemo</b><br />
This directory contins the project files and source code of the program which demonstrates the API and tests the basic functionality of the Touchy board. It uses Silabs CapsenseCircleSlider example project as its template and the Touchy API integrates the template's functionality.

<li><b>Bootloader</b><br />
Files/binaries to assist with loading the firmware image onto the device.
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
In the Browse window, find and click on the BoldportTouchyAPIDemo project directory and click OK<br />
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
