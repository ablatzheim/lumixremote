/*
File:       FotoAutomat.h
Autor:      Andreas Blatzheim
Purpose:    Keep information required for foto Application 
            The foto application is tent to take automatically pictures with a given camara via remote control.
            There several settings used within the application to manage the ammount of pictures and 
            the time between to snapshots. 

Revision:   0.1 Creation of file 
*/

// Display is fixed within Library as 4th device on I2C bus
#define lcd_col 16
#define lcd_row 2

// some generic definitions
#define hour_max    24
#define minutes_max 60
#define secends_max 60
#define count_max   99


// class definition


