# Boldport Club's Touchy IO firmware

<p>First--and probably most importantly--the baud rate used is 115,200. Reading from and writing to (or receiving from and transmitting to, if you prefer) the Touchy device works as described below.</p>
<p>_Please beware...sleeping has been disabled in the EFM8's capsense library in this firmware! If you're powering Touchy with the battery, be careful as it'll drain your battery much more quickly than in the other firmwares I have in this repository._</p>

When writing/transmitting to Touchy with this firmware, always write four bytes as follows:
 - Byte 0: Bit 7 MUST be set (indicates start of frame).
           Bit 6 may be set to request that Touchy transmit its state, regardless of activity/state.
           Bits 0 and 5 indicate if Touchy should set intensities for LEDs 1 and 6, respectively.
 - Byte 1: Bits 0 through 5 indicate new states for LEDs 1 through 6, respectively.
 - Byte 2: Intensity for LED1, set only if indicated by bit 0 of byte 0.
 - Byte 3: Intensity for LED6, set only if indicated by bit 5 of byte 0.
<p>Note that bytes 2 and 3 must be sent even if they are not used. Other bits not accounted for above are ignored.</p>

When reading/receiving from Touchy with this firmware, four bytes will be sent as follows:
 - Byte 0: Bit 7 always set
           Bit 6 set if Touchy received a (re)transmit request
           Bit 5 set if Touchy received invalid data (RX error) -- host should write the data again.
 - Byte 1: Status of buttons. Bits 0 through 5 correspond to buttons 1 through 6, respectively.
 - Byte 2: MSB of angle of circle slider...
 - Byte 3: LSB of angle of circle slider. Range of slider is 0 to 359 degrees.
<p>Note that, in the event of a receive error, Touchy will transmit a block of data (as described above) regardless of a change of state of the buttons/slider.</p>
